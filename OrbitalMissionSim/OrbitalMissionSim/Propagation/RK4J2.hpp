#pragma once
#include "../Core/Vec3.hpp"

struct State
{
    Vec3 r;
    Vec3 v;
};

class RK4J2
{
public:
    State step(const State& s, double dt);

private:
    Vec3 accel(const Vec3& r);
};
