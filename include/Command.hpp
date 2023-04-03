#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "SceneNode.hpp"
#include "Category.hpp"

struct Command
{
    // Initialize
    Command();

    // Variables
    std::function<void(SceneNode &, sf::Time)> action;
    unsigned int category;
};