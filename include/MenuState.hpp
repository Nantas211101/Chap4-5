#pragma once
#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "TextureManipulate.hpp"
#include "GUI_Container.hpp"
#include "GUI_Button.hpp"

#include <memory>

class MenuState : public State{
    public:
        MenuState(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);
        virtual bool handleRealTimeInput();

    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
};