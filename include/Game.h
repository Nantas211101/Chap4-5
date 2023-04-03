#pragma once
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "CommandQueue.hpp"
#include "Player.hpp"

const float PlayerSpeed = 100.f;
const auto TimePerFrame = sf::seconds(1.f /  60.f);

class Game{
    public:
                        Game();
        void            run();

    // main function
    private:
        void            processEvents();
        void            processInput();
        void            update(sf::Time deltaTime);
        void            render();

    // addition function
    private:
        void            handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    // Big variable
    private:
        sf::RenderWindow mWindow;
        Player mPlayer;
        World mWorld;
    // Small variable
    private:
        bool mIsMoveUp = false, mIsMoveDown = false, mIsMoveLeft = false, mIsMoveRight = false;
        bool mIsPaused = false;
};

