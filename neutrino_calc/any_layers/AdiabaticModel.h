#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Eigen/Dense>
#include "SphericEarthModel.h"

class AdiabaticModel
{
protected:
    const double PI = 3.14159265358979323846;
    const double theta12 = 0.602138592;
    const double theta13 = 0.147480322;
    const double theta23 = 0.832522053;
    const double m0_sqr = 7.55 * pow(10, -17);
    const double s2_00_sqr = pow(sin(theta13), 4);
    const double s2_01_sqr = 0.5 * pow(sin(2 * theta13) * sin(theta23), 2);
    const double s2_11_sqr = pow(cos(theta13) * sin(theta23), 4);
    //delta in radians
    double delta;
    double energy_min;
    double energy_max;
    double energy_step;

    SphericEarthModel *model;
    std::vector<double> energies;
    int number_of_energies;
    Eigen::Matrix<std::complex<double>, 3, 3> u_delta;
    Eigen::Matrix<std::complex<double>, 3, 3> o_23;
    Eigen::Matrix<std::complex<double>, 3, 3> o_13;
    Eigen::Matrix<std::complex<double>, 3, 3> u_0;
    Eigen::Matrix<std::complex<double>, 3, 3> u_0_adjoint;
    Eigen::Matrix<std::complex<double>, 2, 2> a;
    Eigen::Matrix<std::complex<double>, 2, 2> matrix_1;
    Eigen::Matrix<std::complex<double>, 2, 2> matrix_2;
    Eigen::Matrix<std::complex<double>, 2, 2> matrix_3;
    Eigen::Matrix<std::complex<double>, 3, 3> a_completed;
    Eigen::Matrix<std::complex<double>, 3, 3> s1;
    std::vector<std::vector<double>> p_00;
    std::vector<std::vector<double>> p_01;
    std::vector<std::vector<double>> p_10;
    std::vector<std::vector<double>> p_11;

    double eps(double energy, double v_i)
    {
        return 2 * energy * v_i * pow(cos(this->theta13), 2) / this->m0_sqr;
    }
    double phi(double energy, double l_i, double v_i)
    {
        return (this->m0_sqr / (2 * energy)) * sqrt(pow(cos(2 * this->theta12) - eps(energy, v_i), 2) + pow(sin(2 * this->theta12), 2)) * l_i;
    }
    double theta_m(double energy, double l_i, double v_i)
    {
        return 0.5 * acos((cos(2 * this->theta12) - eps(energy, v_i)) / sqrt(pow((cos(2 * this->theta12) - eps(energy, v_i)), 2) + pow((sin(2 * this->theta12)), 2)));
    }

public:
    //argument delta in degrees
    AdiabaticModel(SphericEarthModel *model, const std::vector<double> &n_pot, double energy_min, double energy_max, double energy_step, double delta)
    {
        this->model = model;
        this->delta = delta * PI / 180;
        this->energy_min = energy_min;
        this->energy_max = energy_max;
        this->energy_step = energy_step;
        u_delta << 1, 0, 0,
            0, 1, 0,
            0, 0, std::complex<double>(cos(this->delta), sin(this->delta));
        o_23 << 1, 0, 0,
            0, cos(theta23), sin(theta23),
            0, -sin(theta23), cos(theta23);
        o_13 << cos(theta13), 0, sin(theta13),
            0, 1, 0,
            -sin(theta13), 0, cos(theta13);
        u_0 = o_23 * u_delta * o_13;
        u_0_adjoint = u_0.adjoint();
        const std::vector<std::vector<double>> &distances = model->GetDistances();
        const std::vector<double> &angles = model->GetAngles();
        double energy = energy_min;
        this->number_of_energies = (int)((energy_max - energy_min) / energy_step);
        for (int i = 0; i < number_of_energies; i++)
        {
            this->energies.push_back(energy);
            energy += energy_step;
        }
        for (int angle_idx = 0, angles_len = angles.size(); angle_idx < angles_len; angle_idx++)
        {
            std::vector<double> temp_00;
            std::vector<double> temp_01;
            std::vector<double> temp_10;
            std::vector<double> temp_11;
            for (auto &energy : energies)
            {
                matrix_1 << cos(theta_m(energy, distances[angle_idx][0], n_pot[0])), sin(theta_m(energy, distances[angle_idx][0], n_pot[0])),
                    -sin(theta_m(energy, distances[angle_idx][0], n_pot[0])), cos(theta_m(energy, distances[angle_idx][0], n_pot[0]));
                double phi_sum = 0;
                for (int i = 0, dist_len = distances[angle_idx].size(); i < dist_len; i++)
                {
                    phi_sum += phi(energy, distances[angle_idx][i], n_pot[i]);
                }
                matrix_2 << std::complex<double>(cos(0.5 * phi_sum), sin(0.5 * phi_sum)), 0,
                    0, std::complex<double>(cos(0.5 * phi_sum), -sin(0.5 * phi_sum));
                a = matrix_1 * matrix_2;
                a = a * a.transpose();
                a_completed << a(0, 0), a(0, 1), 0,
                    a(1, 0), a(1, 1), 0,
                    0, 0, 0;
                s1 = u_0 * a_completed * u_0_adjoint;
                temp_00.push_back(pow(abs(s1(0, 0)), 2) + s2_00_sqr);
                temp_01.push_back(pow(abs(s1(0, 1)), 2) + s2_01_sqr);
                temp_10.push_back(pow(abs(s1(1, 0)), 2) + s2_01_sqr);
                temp_11.push_back(pow(abs(s1(1, 1)), 2) + s2_11_sqr);
            }
            p_00.push_back(temp_00);
            p_01.push_back(temp_01);
            p_10.push_back(temp_10);
            p_11.push_back(temp_11);
        }
        std::cout << number_of_energies << std::endl;
        std::cout << p_01.size() << std::endl;
        std::cout << p_01[0].size() << std::endl;
        for (int i = 0; i < p_01.size(); i++)
        {
            for (int j = 0; j < p_01[i].size(); j++)
            {
                // std::cout << p_01[i].size() << std::endl;
            }
        }
    }

    void SaveToFile(std::string file_name, std::string p)
    {
        std::fstream fout;
        fout.open(file_name, std::ios::out);
        {
            auto angles = model->GetAngles();
            auto energy = energy_min;
            for (int angle_idx = 0, angle_len = angles.size(); angle_idx < angle_len; angle_idx++)
            {
                for (int energy_idx = 0; energy_idx < number_of_energies; energy_idx++)
                {
                    fout << angles[angle_idx] * 180 / PI << ", ";
                    fout << energies[energy_idx] << ", ";
                    if (p == "p_00")
                        fout << p_00[angle_idx][energy_idx] << "\n";
                    if (p == "p_01")
                        fout << p_01[angle_idx][energy_idx] << "\n";
                    if (p == "p_10")
                        fout << p_10[angle_idx][energy_idx] << "\n";
                    if (p == "p_11")
                        fout << p_11[angle_idx][energy_idx] << "\n";
                }
            }
        }
        fout.close();
    }
};