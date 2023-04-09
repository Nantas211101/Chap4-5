#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "StateStack.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureManipulate.hpp"

const std::string Paused_text = "World Stopbu";
const std::string Instruction_text = "(Press Backspace to return to the menu)\n(Press Escape to return to the game)";

class PauseState : State{
    public:
        PauseState(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);

    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mPausedText;
        sf::Text mInstructionText;
};
