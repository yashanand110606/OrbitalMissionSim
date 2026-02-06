#include "Constellation.hpp"

void Constellation::addSatellite(const Satellite& sat)
{
    sats_.push_back(sat);
}

void Constellation::update(double dt)
{
    for (auto& s : sats_)
        s.update(dt);
}

std::vector<Satellite>& Constellation::sats()
{
    return sats_;
}
void Constellation::clear()
{
    sats_.clear();
}
