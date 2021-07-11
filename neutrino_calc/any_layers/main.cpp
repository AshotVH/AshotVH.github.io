#include <iostream>
#include "AdiabaticModel.h"
#include <math.h>
#include <chrono>

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

int main()
{
    auto t1 = high_resolution_clock::now();

    const double EARTH_RADIUS = 6371 * 5.07 * std::pow(10, 15);
    std::vector<double> radii = {EARTH_RADIUS, 0.937 * EARTH_RADIUS, 0.895 * EARTH_RADIUS, 0.546 * EARTH_RADIUS, 0.192 * EARTH_RADIUS};
    std::vector<double> neutrino_potensials = {1.29 * pow(10, -19), 1.47 * pow(10, -19), 1.88 * pow(10, -19), 4.0 * pow(10, -19),
                                               4.63 * pow(10, -19)};
    SphericEarthModel *earth_model = new SphericEarthModel(radii, 0, 90, 0.5);
    AdiabaticModel *adiabatic_model = new AdiabaticModel(earth_model, neutrino_potensials, 50, 950, 1, 90);
    adiabatic_model->SaveToFile("adiabatic_1_files/delta_05pi_p_00.txt", "p_00");
    adiabatic_model->SaveToFile("adiabatic_1_files/delta_05pi_p_01.txt", "p_01");
    adiabatic_model->SaveToFile("adiabatic_1_files/delta_05pi_p_10.txt", "p_10");
    adiabatic_model->SaveToFile("adiabatic_1_files/delta_05pi_p_11.txt", "p_11");

    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    std::cout << ms_int.count() << " ms" << std::endl;
}