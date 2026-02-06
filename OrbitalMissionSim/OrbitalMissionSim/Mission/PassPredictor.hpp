#pragma once
#include "../Simulation/Satellite.hpp"
#include "GroundStation.hpp"

double elevationAngle(const Satellite&, const GroundStation&);
bool isVisible(const Satellite&, const GroundStation&);
