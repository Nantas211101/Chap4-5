#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "World.hpp"
#include "CommandQueue.hpp"
#include "Player.hpp"
#include "StringConvert.hpp"

const float PlayerSpeed = 100.f;
const auto TimePerFrame = sf::seconds(1.f /  60.f);
const std::string Path_Font = "resource/Sansation.ttf";
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
        void            updateStatic(sf::Time);
    // Big variable
    private:
        sf::RenderWindow mWindow;
        Player mPlayer;
        World mWorld;

    // For FPS showing variable
        sf::Font mFont;
        sf::Text mStayText;
        sf::Time mStayUpdateTime;
        std::size_t mStayNumFrames;

    // Small variable
    private:
        bool mIsMoveUp = false, mIsMoveDown = false, mIsMoveLeft = false, mIsMoveRight = false;
        bool mIsPaused = false;
};

