#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "GUI_Container.hpp"
#include "GUI_Button.hpp"

#include <memory>
class Stack: public State{
    public:
        Stack(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);
        virtual bool handleRealTimeInput();
    
    private:
        void setStateButton(Context context, int x_times, int y_times, const std::string &text, std::function<void()> action);

    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
};