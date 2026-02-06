#include "Satellite.hpp"

Satellite::Satellite(State init)
    : state_(init)
{
}

void Satellite::update(double dt)
{
    state_ = propagator_.step(state_, dt);
}

State Satellite::state() const
{
    return state_;
}
