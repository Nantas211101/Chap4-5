#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Command.hpp"
#include "CommandQueue.hpp"
#include "AircraftMover.hpp"

class Player
{
    public:
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealtimeInput(CommandQueue& commands);
};