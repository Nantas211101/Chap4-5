#pragma once
#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "TextureManipulate.hpp"

class MenuState : public State{
    public:
        MenuState(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);
        void updateOptionText();

    private: // Additional
        void setMenuText(const std::string &text, const sf::Vector2f additionPos, const sf::Font &font, State::Context &context);

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