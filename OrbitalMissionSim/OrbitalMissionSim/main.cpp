#include "Core/Constants.hpp"
#include "Simulation/Constellation.hpp"
#include "Visualization/Renderer.hpp"
#include <fstream>

int main()
{
    Renderer renderer;

    Constellation constellation;

    double dt = 1.0;
    double simSpeed = 1.0;
    double simTime = 0.0;

    // ===== 4 SATELLITE INITIAL STATES =====
    State base;
    base.r = { Constants::RE + 400000, 0, 0 };
    base.v = { 0, 7670, 0 };

    for (int i = 0; i < 4; i++)
    {
        State s = base;

        s.v.y += i * 50;

        // Tilt orbit plane
        double tilt = i * 0.05;

        s.v.z += tilt * 200;
        s.r.z += tilt * 100000;

        constellation.addSatellite(Satellite(s));
    }

    std::ofstream logFile("orbit_log.csv");

    // ===== MAIN LOOP =====
    while (renderer.running())
    {
        renderer.processEvents();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            simSpeed *= 1.01;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            simSpeed *= 0.99;

        double dtScaled = dt * simSpeed;
        simTime += dtScaled;

        constellation.update(dtScaled);

        renderer.draw(constellation);

        for (const auto& sat : constellation.sats())
        {
            auto st = sat.state();
            logFile << simTime << ","
                << st.r.x << ","
                << st.r.y << ","
                << st.r.z << "\n";
        }
    }

    return 0;
}
