#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Command.hpp"
#include "CommandQueue.hpp"
#include "AircraftMover.hpp"
const float playerSpeed = 50.f;

class Player
{
    public:
        Player();

    public:
        enum Action{
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown,
        };
        
        void assignKey(Action action, sf::Keyboard::Key key);
        auto getAssignedKey(Action action) -> sf::Keyboard::Key const;

    public:
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealtimeInput(CommandQueue& commands);

    private:
        static bool isRealtimeAction(Action action);

    private:
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, Command>           mActionBinding;
};