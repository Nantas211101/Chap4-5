#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "GUI_Container.hpp"
#include "GUI_Button.hpp"
#include "GUI_Label.hpp"
#include "GUI_InputButton.hpp"
#include "GUI_SpeedButton.hpp"

#include <memory>

const int NumInitButton = 7;

class Stack: public State{
    public:
        Stack(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event &event);
        virtual bool handleRealTimeInput();
    
    private:
        void setStateButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action);
        void setLabel(Context context, int posx, int posy, const std::string &text);
        void setInputButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action);
        void resetButton(int size);
        void printedError(const std::string &text);

    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
        
};