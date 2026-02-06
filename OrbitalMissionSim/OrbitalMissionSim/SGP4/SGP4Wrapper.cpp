#include "SGP4Wrapper.hpp"
#include <cmath>

bool SGP4Wrapper::loadTLE(const TLE& tle)
{
    loaded_ = true;
    return true;
}

void SGP4Wrapper::propagate(double tMin,
    Vec3& pos,
    Vec3& vel)
{
    double r = 6778000.0;
    double n = 0.0011;

    double theta = n * tMin * 60.0;

    pos = { r * cos(theta), r * sin(theta), 0 };
    vel = { -r * n * sin(theta), r * n * cos(theta), 0 };
}
