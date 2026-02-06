#define _USE_MATH_DEFINES
#include <cmath>
#include "TimeUtils.hpp"

double JulianDate(int y, int m, int d, int h, int min, double s)
{
    if (m <= 2) { y--; m += 12; }
    int A = y / 100;
    int B = 2 - A + A / 4;

    double JD = floor(365.25 * (y + 4716))
        + floor(30.6001 * (m + 1))
        + d + B - 1524.5;

    return JD + (h + min / 60.0 + s / 3600.0) / 24.0;
}

double GMST(double jd)
{
    double T = (jd - 2451545.0) / 36525.0;
    double g = 280.46061837 +
        360.98564736629 * (jd - 2451545.0) +
        0.000387933 * T * T -
        T * T * T / 38710000.0;

    g = fmod(g, 360.0);
    if (g < 0) g += 360;
    return g * M_PI / 180.0;
}
