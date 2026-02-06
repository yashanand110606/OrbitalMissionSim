#pragma once
#include <SFML/Graphics.hpp>
#include "../Simulation/Constellation.hpp"
#include <deque>
#include <vector>

class Renderer
{
public:
    Renderer();

    bool running();
    void processEvents();
    void draw(Constellation& c);

private:
    void drawEarth();

    sf::RenderWindow window_;

    std::vector<std::deque<sf::Vector2f>> trails_;

    float zoom_ = 1.0f;
    sf::Vector2f cameraOffset_ = { 0.f,0.f };

    sf::Font font_;
};
