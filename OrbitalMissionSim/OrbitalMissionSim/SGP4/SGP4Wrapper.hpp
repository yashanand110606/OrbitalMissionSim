#pragma once

#include "SGP4/TLE.hpp"
#include "../Core/Vec3.hpp"

class SGP4Wrapper
{
public:
    bool loadTLE(const TLE& tle);

    void propagate(double minutesSinceEpoch,
        Vec3& posECI,
        Vec3& velECI);

private:
    bool loaded_ = false;
};
