#pragma once
#include <SFML/Graphics.hpp>
#include <StateStack.hpp>

class Application{

    public:
        Application();
        void run();

    public:
        void processInput();
        void update(sf::Time dt);
        void render();
    
    public:
        void updateStatic(sf::Time dt);
        void registerStates();


    private:
        StateStack mStateStack;
}