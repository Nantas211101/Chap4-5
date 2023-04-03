#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"
#include "Aircraft.hpp"

struct AircraftMover{
    AircraftMover(float vx, float vy);

    void operator() (Aircraft &aircraft, sf::Time) const;

    private:
        sf::Vector2f velocity;
};