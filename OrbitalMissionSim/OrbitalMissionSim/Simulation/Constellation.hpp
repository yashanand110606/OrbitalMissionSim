    #pragma once
#include "Satellite.hpp"
#include <vector>

class Constellation
{
public:
    void addSatellite(const Satellite& sat); // Declaration only
    void update(double dt);
    std::vector<Satellite>& sats();
    void clear();

private:
    std::vector<Satellite> sats_;
};
