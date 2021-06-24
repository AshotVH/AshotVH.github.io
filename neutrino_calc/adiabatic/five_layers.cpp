#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <chrono>
using namespace std;
using namespace Eigen;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

double phi(double energy, double l_i, double v_i)
{
    const double theta12 = 0.602138592;
    const double m0_sqr = 7.55 * pow(10, -17);
    const double theta13 = 0.147480322;
    const double eps = 2 * energy * v_i * pow(cos(theta13), 2) / m0_sqr;
    return (m0_sqr / (2 * energy)) * sqrt(pow(cos(2 * theta12) - eps, 2) + pow(sin(2 * theta12), 2)) * l_i;
}
double theta_m(double energy, double l_i, double v_i)
{
    const double theta12 = 0.602138592;
    const double theta13 = 0.147480322;
    const double m0_sqr = 7.55 * pow(10, -17);
    const double eps = 2 * energy * v_i * pow(cos(theta13), 2) / m0_sqr;
    return 0.5 * acos((cos(2 * theta12) - eps) / sqrt(pow((cos(2 * theta12) - eps), 2) + pow((sin(2 * theta12)), 2)));
}
int main()
{
    auto t1 = high_resolution_clock::now();
    const double pi = 3.14159265358979323846;
    const double radius = 6.371 * 5.07 * pow(10, 18);
    array<double, 5> r = {radius, 0.937 * radius, 0.895 * radius, 0.546 * radius, 0.192 * radius};
    const double delta = pi;
    const double theta12 = 0.602138592;
    const double theta23 = 0.832522053;
    const double theta13 = 0.147480322;
    array<double, 5> v = {1.29 * pow(10, -19), 1.47 * pow(10, -19), 1.88 * pow(10, -19), 4.0 * pow(10, -19),
                          4.63 * pow(10, -19)};
    const double S2_00_sqr = pow(sin(theta13), 4);
    const double S2_01_sqr = 0.5 * pow(sin(2 * theta13) * sin(theta23), 2);
    const double S2_11_sqr = pow(cos(theta13) * sin(theta23), 4);
    const double m0_sqr = 7.55 * pow(10, -17); // # MeV^2
    Matrix<complex<double>, 3, 3> U_delta;
    Matrix<complex<double>, 3, 3> O_23;
    Matrix<complex<double>, 3, 3> O_13;
    Matrix<complex<double>, 3, 3> U_0;
    Matrix<complex<double>, 3, 3> U_0_adjoint;
    U_delta << 1, 0, 0,
        0, 1, 0,
        0, 0, complex<double>(cos(delta), sin(delta));
    O_23 << 1, 0, 0,
        0, cos(theta23), sin(theta23),
        0, -sin(theta23), cos(theta23);
    O_13 << cos(theta13), 0, sin(theta13),
        0, 1, 0,
        -sin(theta13), 0, cos(theta13);
    U_0 = O_23 * U_delta * O_13;
    U_0_adjoint = U_0.adjoint();
    const double angle_min = 0;
    const double angle_max = pi / 2;
    const int number_of_angles = 180;
    array<double, number_of_angles> angles;
    {
        double angle = 0;
        double step = (angle_max - angle_min) / number_of_angles;
        for (int i = 0, len = angles.size(); i < len; i++)
        {
            angles[i] = angle;
            angle += step;
        }
    }
    const int energy_min = 50;
    const int energy_max = 950;
    const int energy_step = 1;
    const int number_of_energies = (energy_max - energy_min) / energy_step;
    array<int, number_of_energies> energies;
    {
        double energy = energy_min;
        for (int i = 0, len = energies.size(); i < len; i++)
        {
            energies[i] = energy;
            energy += energy_step;
        }
    }
    Matrix<complex<double>, 2, 2> A;
    Matrix<complex<double>, 2, 2> Matrix_1;
    Matrix<complex<double>, 2, 2> Matrix_2;
    Matrix<complex<double>, 2, 2> Matrix_3;
    Matrix<complex<double>, 3, 3> A_completed;
    Matrix<complex<double>, 3, 3> S1;
    array<array<double, number_of_energies>, number_of_angles> p_00;
    array<array<double, number_of_energies>, number_of_angles> p_01;
    array<array<double, number_of_energies>, number_of_angles> p_10;
    array<array<double, number_of_energies>, number_of_angles> p_11;

    for (int angle_index = 0; angle_index < number_of_angles; angle_index++)
    {
        double b = radius * sin(angles[angle_index]);
        if (b < r[4])
        {
            array<double, 5> l;
            l[4] = sqrt(pow(r[4], 2) - pow(b, 2));
            l[3] = sqrt(pow(r[3], 2) - pow(b, 2)) - l[4];
            l[2] = sqrt(pow(r[2], 2) - pow(b, 2)) - l[4] - l[3];
            l[1] = sqrt(pow(r[1], 2) - pow(b, 2)) - l[4] - l[3] - l[2];
            l[0] = sqrt(pow(r[0], 2) - pow(b, 2)) - l[4] - l[3] - l[2] - l[1];
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                Matrix_1 << cos(theta_m(energies[energy_index], l[0], v[0])), sin(theta_m(energies[energy_index], l[0], v[0])),
                    -sin(theta_m(energies[energy_index], l[0], v[0])), cos(theta_m(energies[energy_index], l[0], v[0]));
                // Matrix_3 << cos(theta_m(energies[energy_index], l[4], v[4])), -sin(theta_m(energies[energy_index], l[4], v[4])),
                // sin(theta_m(energies[energy_index], l[4], v[4])), cos(theta_m(energies[energy_index], l[4], v[4]));
                double phi_sum = 0;
                for (int i = 0; i <= 4; i++)
                {
                    phi_sum += phi(energies[energy_index], l[i], v[i]);
                }
                Matrix_2 << complex<double>(cos(0.5 * phi_sum), sin(0.5 * phi_sum)), 0,
                    0, complex<double>(cos(0.5 * phi_sum), -sin(0.5 * phi_sum));
                A = Matrix_1 * Matrix_2;
                A = A * A.transpose();
                A_completed << A(0, 0), A(0, 1), 0,
                    A(1, 0), A(1, 1), 0,
                    0, 0, 0;
                S1 = U_0 * A_completed * U_0_adjoint;
                p_00[angle_index][energy_index] = pow(abs(S1(0, 0)), 2) + S2_00_sqr;
                p_01[angle_index][energy_index] = pow(abs(S1(0, 1)), 2) + S2_01_sqr;
                p_10[angle_index][energy_index] = pow(abs(S1(1, 0)), 2) + S2_01_sqr;
                p_11[angle_index][energy_index] = pow(abs(S1(1, 1)), 2) + S2_11_sqr;
            }
        }
        else if (b < r[3])
        {
            array<double, 4> l;
            l[3] = sqrt(pow(r[3], 2) - pow(b, 2));
            l[2] = sqrt(pow(r[2], 2) - pow(b, 2)) - l[3];
            l[1] = sqrt(pow(r[1], 2) - pow(b, 2)) - l[3] - l[2];
            l[0] = sqrt(pow(r[0], 2) - pow(b, 2)) - l[3] - l[2] - l[1];
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                Matrix_1 << cos(theta_m(energies[energy_index], l[0], v[0])), sin(theta_m(energies[energy_index], l[0], v[0])),
                    -sin(theta_m(energies[energy_index], l[0], v[0])), cos(theta_m(energies[energy_index], l[0], v[0]));
                // Matrix_3 << cos(theta_m(energies[energy_index], l[3], v[3])), -sin(theta_m(energies[energy_index], l[3], v[3])),
                //     sin(theta_m(energies[energy_index], l[3], v[3])), cos(theta_m(energies[energy_index], l[3], v[3]));
                double phi_sum = 0;
                for (int i = 0; i <= 3; i++)
                {
                    phi_sum += phi(energies[energy_index], l[i], v[i]);
                }
                Matrix_2 << complex<double>(cos(0.5 * phi_sum), sin(0.5 * phi_sum)), 0,
                    0, complex<double>(cos(0.5 * phi_sum), -sin(0.5 * phi_sum));
                A = Matrix_1 * Matrix_2;
                A = A * A.transpose();
                A_completed << A(0, 0), A(0, 1), 0,
                    A(1, 0), A(1, 1), 0,
                    0, 0, 0;
                S1 = U_0 * A_completed * U_0_adjoint;
                p_00[angle_index][energy_index] = pow(abs(S1(0, 0)), 2) + S2_00_sqr;
                p_01[angle_index][energy_index] = pow(abs(S1(0, 1)), 2) + S2_01_sqr;
                p_10[angle_index][energy_index] = pow(abs(S1(1, 0)), 2) + S2_01_sqr;
                p_11[angle_index][energy_index] = pow(abs(S1(1, 1)), 2) + S2_11_sqr;
            }
        }
        else if (b < r[2])
        {
            array<double, 3> l;
            l[2] = sqrt(pow(r[2], 2) - pow(b, 2));
            l[1] = sqrt(pow(r[1], 2) - pow(b, 2)) - l[2];
            l[0] = sqrt(pow(r[0], 2) - pow(b, 2)) - l[2] - l[1];
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                Matrix_1 << cos(theta_m(energies[energy_index], l[0], v[0])), sin(theta_m(energies[energy_index], l[0], v[0])),
                    -sin(theta_m(energies[energy_index], l[0], v[0])), cos(theta_m(energies[energy_index], l[0], v[0]));
                // Matrix_3 << cos(theta_m(energies[energy_index], l[2], v[2])), -sin(theta_m(energies[energy_index], l[2], v[2])),
                //     sin(theta_m(energies[energy_index], l[2], v[2])), cos(theta_m(energies[energy_index], l[2], v[2]));
                double phi_sum = 0;
                for (int i = 0; i <= 2; i++)
                {
                    phi_sum += phi(energies[energy_index], l[i], v[i]);
                }
                Matrix_2 << complex<double>(cos(0.5 * phi_sum), sin(0.5 * phi_sum)), 0,
                    0, complex<double>(cos(0.5 * phi_sum), -sin(0.5 * phi_sum));
                A = Matrix_1 * Matrix_2;
                A = A * A.transpose();
                A_completed << A(0, 0), A(0, 1), 0,
                    A(1, 0), A(1, 1), 0,
                    0, 0, 0;
                S1 = U_0 * A_completed * U_0_adjoint;
                p_00[angle_index][energy_index] = pow(abs(S1(0, 0)), 2) + S2_00_sqr;
                p_01[angle_index][energy_index] = pow(abs(S1(0, 1)), 2) + S2_01_sqr;
                p_10[angle_index][energy_index] = pow(abs(S1(1, 0)), 2) + S2_01_sqr;
                p_11[angle_index][energy_index] = pow(abs(S1(1, 1)), 2) + S2_11_sqr;
            }
        }
        else if (b < r[1])
        {
            array<double, 2> l;
            l[1] = sqrt(pow(r[1], 2) - pow(b, 2));
            l[0] = sqrt(pow(r[0], 2) - pow(b, 2)) - l[1];
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                Matrix_1 << cos(theta_m(energies[energy_index], l[0], v[0])), sin(theta_m(energies[energy_index], l[0], v[0])),
                    -sin(theta_m(energies[energy_index], l[0], v[0])), cos(theta_m(energies[energy_index], l[0], v[0]));
                // Matrix_3 << cos(theta_m(energies[energy_index], l[1], v[1])), -sin(theta_m(energies[energy_index], l[1], v[1])),
                // sin(theta_m(energies[energy_index], l[1], v[1])), cos(theta_m(energies[energy_index], l[1], v[1]));
                double phi_sum = 0;
                for (int i = 0; i <= 1; i++)
                {
                    phi_sum += phi(energies[energy_index], l[i], v[i]);
                }
                Matrix_2 << complex<double>(cos(0.5 * phi_sum), sin(0.5 * phi_sum)), 0,
                    0, complex<double>(cos(0.5 * phi_sum), -sin(0.5 * phi_sum));
                A = Matrix_1 * Matrix_2;
                A = A * A.transpose();
                A_completed << A(0, 0), A(0, 1), 0,
                    A(1, 0), A(1, 1), 0,
                    0, 0, 0;
                S1 = U_0 * A_completed * U_0_adjoint;
                p_00[angle_index][energy_index] = pow(abs(S1(0, 0)), 2) + S2_00_sqr;
                p_01[angle_index][energy_index] = pow(abs(S1(0, 1)), 2) + S2_01_sqr;
                p_10[angle_index][energy_index] = pow(abs(S1(1, 0)), 2) + S2_01_sqr;
                p_11[angle_index][energy_index] = pow(abs(S1(1, 1)), 2) + S2_11_sqr;
            }
        }
        else
        {
            double l = sqrt(pow(r[0], 2) - pow(b, 2));
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                Matrix_1 << cos(theta_m(energies[energy_index], l, v[0])), sin(theta_m(energies[energy_index], l, v[0])),
                    -sin(theta_m(energies[energy_index], l, v[0])), cos(theta_m(energies[energy_index], l, v[0]));
                // Matrix_3 = Matrix_1.transpose();
                complex<double> phi_00(cos(0.5 * phi(energies[energy_index], l, v[0])), sin(0.5 * phi(energies[energy_index], l, v[0])));
                complex<double> phi_11(cos(0.5 * phi(energies[energy_index], l, v[0])), -sin(0.5 * phi(energies[energy_index], l, v[0])));
                Matrix_2 << phi_00, 0,
                    0, phi_11;
                A = Matrix_1 * Matrix_2;
                A = A * A.transpose();
                A_completed << A(0, 0), A(0, 1), 0,
                    A(1, 0), A(1, 1), 0,
                    0, 0, 0;
                S1 = U_0 * A_completed * U_0_adjoint;
                p_00[angle_index][energy_index] = pow(abs(S1(0, 0)), 2) + S2_00_sqr;
                p_01[angle_index][energy_index] = pow(abs(S1(0, 1)), 2) + S2_01_sqr;
                p_10[angle_index][energy_index] = pow(abs(S1(1, 0)), 2) + S2_01_sqr;
                p_11[angle_index][energy_index] = pow(abs(S1(1, 1)), 2) + S2_11_sqr;
            }
        }
    }
    fstream fout;
    fout.open("delta_pi_p_11.txt", ios::out);
    {

        double angle_deg = 0;
        const double angle_min_deg = 0;
        const double angle_min_max = 90;
        const double angle_step_deg = 0.5;
        for (int angle_index = 0; angle_index < number_of_angles; angle_index++)
        {
            for (int energy_index = 0; energy_index < number_of_energies; energy_index++)
            {
                fout << angle_deg << ", ";
                fout << energies[energy_index] << ", ";
                fout << p_11[angle_index][energy_index] << "\n";
            }
            angle_deg += angle_step_deg;
        }
    }
    fout.close();
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    cout << ms_int.count() << " ms" << endl;
    return 0;
}