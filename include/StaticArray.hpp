#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "GUI_Container.hpp"
#include "GUI_Button.hpp"
#include "GUI_Label.hpp"
#include "GUI_InputButton.hpp"

#include <memory>

class StaticArray: public State{
    public:
        StaticArray(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);
        virtual bool handleRealTimeInput();
    
    private:
        void setStateButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action);
        void setLabel(Context context, int posx, int posy, const std::string &text);
        void setInputButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action);
    
    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
};