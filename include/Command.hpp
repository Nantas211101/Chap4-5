#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Category.hpp"
#include <assert.h>

class SceneNode;

struct Command
{
    // Initialize
    Command();

    // Variables
    std::function<void(SceneNode &, sf::Time)> action;
    unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn){
    return [=] (SceneNode& node, sf::Time dt){
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);
    };
}

/*
Command moveLeft;
moveLeft.category = Category::PlayerAircraft;
moveLeft.action
 = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0));
*/