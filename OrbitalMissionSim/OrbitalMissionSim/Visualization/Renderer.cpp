#include <SFML/Graphics/Font.hpp>
#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer()
    : window_(sf::VideoMode({ 1000u,1000u }), "Orbital Engine v1")
{
    // Correct way to load a font in SFML
    if (font_.openFromFile("arial.ttf")) {
        std::cerr << "Failed to load font: arial.ttf" << std::endl;
    }
}

bool Renderer::running()
{
    return window_.isOpen();
}

void Renderer::processEvents()
{
    while (auto event = window_.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window_.close();

        if (event->is<sf::Event::MouseWheelScrolled>())
        {
            auto scroll = event->getIf<sf::Event::MouseWheelScrolled>();
            if (scroll && scroll->delta > 0)
                zoom_ *= 1.1f;
            else
                zoom_ *= 0.9f;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        cameraOffset_.x -= 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        cameraOffset_.x += 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        cameraOffset_.y -= 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        cameraOffset_.y += 5;
}

void Renderer::drawEarth()
{
    float earthRadius = (6378137.f / 20000.f) * zoom_;

    sf::CircleShape earth(earthRadius);

    earth.setOrigin(sf::Vector2f(
        earthRadius,
        earthRadius
    ));

    earth.setPosition(sf::Vector2f(
        500.f + cameraOffset_.x,
        500.f + cameraOffset_.y
    ));

    earth.setFillColor(sf::Color(20, 40, 120));

    window_.draw(earth);
}


void Renderer::draw(Constellation& c)
{
    window_.clear(sf::Color::Black);

    drawEarth();

    if (trails_.size() != c.sats().size())
        trails_.resize(c.sats().size());

    int satIndex = 0;

    for (auto& sat : c.sats())
    {
        auto state = sat.state();

        float x = 500.f + cameraOffset_.x +
            static_cast<float>(state.r.x / 20000.0 * zoom_);

        float y = 500.f + cameraOffset_.y +
            static_cast<float>(state.r.y / 20000.0 * zoom_);

        trails_[satIndex].push_back(sf::Vector2f(x, y));

        if (trails_[satIndex].size() > 2000)
            trails_[satIndex].pop_front();

        sf::Color col(
            100 + satIndex * 40,
            200 - satIndex * 30,
            255 - satIndex * 20
        );

        sf::CircleShape dot(3.f);
        dot.setFillColor(col);
        dot.setPosition(sf::Vector2f(x, y));
        window_.draw(dot);

        for (auto& p : trails_[satIndex])
        {
            sf::CircleShape t(1.f);
            t.setFillColor(col);
            t.setPosition(p);
            window_.draw(t);
        }

        sf::Text label(font_, std::to_string(satIndex), 12);
        label.setFillColor(sf::Color::White);
        label.setPosition(sf::Vector2f(x + 5, y + 5));
        window_.draw(label);

        satIndex++;
    }

    window_.display();
}
