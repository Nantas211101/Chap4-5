#pragma once
#include <SFML/Graphics.hpp>

const float PlayerSpeed = 100.f;
const auto TimePerFrame = sf::seconds(1.f /  60.f);

class Game{
    public:
                        Game();
        void            run();

    // main function
    private:
        void            processEvents();
        void            update(sf::Time deltaTime);
        void            render();

    // addition function
    private:
        void            handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    // Big variable
    private:
        sf::RenderWindow mWindow;
        sf::Texture mTexture;
        sf::Sprite mPlayer;

    // Small variable
    private:
        bool mIsMoveUp = false, mIsMoveDown = false, mIsMoveLeft = false, mIsMoveRight = false;
        bool mIsPaused = false;
};

