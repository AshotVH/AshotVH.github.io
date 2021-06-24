#include <vector>
#include <math.h>

class SphericEarthModel
{
private:
    const double PI = 3.14159265358979323846;
    //Array of angles in radians
    std::vector<double> angles;
    std::vector<std::vector<double>> distances;
    double bisector;

public:
    //radii - Array of radii in kilometers
    //angle_min, angle_max, angle_step in  degrees
    SphericEarthModel(const std::vector<double> &radii, double angle_min, double angle_max, double angle_step)
    {
        double angle = angle_min * PI / 180;
        unsigned int number_of_angles = (unsigned int)((angle_max - angle_min) / angle_step);
        for (int i = 0; i < number_of_angles; i++)
        {
            angles.push_back(angle);
            bisector = radii[0] * sin(angle);
            for (int j = radii.size() - 1; j >= 0; j--)
            {
                if (bisector < radii[j])
                {
                    double dist_sum = 0;
                    std::vector<double> l(j + 1);
                    for (int k = j; k >= 0; k--)
                    {
                        l[k] = sqrt(pow(radii[k], 2) - pow(bisector, 2)) - dist_sum;
                        dist_sum += l[k];
                    }
                    distances.push_back(l);
                    break;
                }
            }
            angle += angle_step * PI / 180;
        }
    }
    std::vector<std::vector<double>> GetDistances()
    {
        return this->distances;
    }
    std::vector<double> GetAngles()
    {
        return this->angles;
    }
};