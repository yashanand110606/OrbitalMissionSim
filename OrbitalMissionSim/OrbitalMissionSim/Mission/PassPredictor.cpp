#include "PassPredictor.hpp"
#include <cmath>

double elevationAngle(const Satellite& sat,
    const GroundStation& gs)
{
    auto s = sat.state();

    double rx = s.r.x;
    double ry = s.r.y;
    double rz = s.r.z;

    double r = sqrt(rx * rx + ry * ry + rz * rz);

    return asin(rz / r);
}

bool isVisible(const Satellite& sat,
    const GroundStation& gs)
{
    return elevationAngle(sat, gs) > 0;
}
