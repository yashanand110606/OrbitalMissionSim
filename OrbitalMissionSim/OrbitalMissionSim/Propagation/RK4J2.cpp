#include "RK4J2.hpp"
#include "../Core/Constants.hpp"
#include <cmath>

Vec3 RK4J2::accel(const Vec3& r)
{
    double rmag = norm(r);
    double mu = Constants::MU;

    Vec3 a = r * (-mu / pow(rmag, 3));

    double z2 = r.z * r.z;
    double r2 = rmag * rmag;

    double factor =
        1.5 * Constants::J2 * mu *
        Constants::RE * Constants::RE /
        pow(rmag, 5);

    a.x += factor * r.x * (5 * z2 / r2 - 1);
    a.y += factor * r.y * (5 * z2 / r2 - 1);
    a.z += factor * r.z * (5 * z2 / r2 - 3);

    return a;
}

State RK4J2::step(const State& s, double dt)
{
    State k1{ s.v, accel(s.r) };

    State s2{ s.r + k1.r * (dt / 2), s.v + k1.v * (dt / 2) };
    State k2{ s2.v, accel(s2.r) };

    State s3{ s.r + k2.r * (dt / 2), s.v + k2.v * (dt / 2) };
    State k3{ s3.v, accel(s3.r) };

    State s4{ s.r + k3.r * dt, s.v + k3.v * dt };
    State k4{ s4.v, accel(s4.r) };

    State out;
    out.r = s.r + (k1.r + k2.r * 2 + k3.r * 2 + k4.r) * (dt / 6);
    out.v = s.v + (k1.v + k2.v * 2 + k3.v * 2 + k4.v) * (dt / 6);

    return out;
}
