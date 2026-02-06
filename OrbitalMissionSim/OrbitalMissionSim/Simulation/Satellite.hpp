#pragma once
#include "../Propagation/RK4J2.hpp"

class Satellite
{
public:
    Satellite(State init);

    void update(double dt);
    State state() const;

private:
    State state_;
    RK4J2 propagator_;
};
