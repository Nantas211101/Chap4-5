#pragma once
#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "State.hpp"
#include "ResourceIdentifiers.hpp"

class MenuState : public State{
    public:
        MenuState(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);

    private:
        void setup_menu_text(const std::string &text, const sf::Vector2f additionPos);

    private:
        enum OptionNames{
            Play,
            Exit,
        };
    
    private:
        sf::Sprite mBackgroundSprite;

        std::vector<sf::Text> mOptions;
        std::size_t mOptionIndex;
};