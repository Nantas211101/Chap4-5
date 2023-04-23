#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Player.hpp"
#include "GUI_Container.hpp"
#include "GUI_Button.hpp"
#include "GUI_Label.hpp"
#include "ResourceIdentifiers.hpp"
#include "StringConvert.hpp"
#include <memory>
#include <array>

class SettingsState : public State{
    public:
        SettingsState(StateStack &stack, Context context);    

        virtual void draw();
        virtual bool update(sf::Time elapsedTime);
        virtual bool handleEvent(const sf::Event &event);
    private:
        void updateLabels();
        // aditional function
        void addButtonLabel(Player::Action action, float y, const std::string &text, Context context);

    private:
        sf::Sprite          mBackgroundSprite;
        GUI::Container      mGUIContainer;

        std::array<GUI::Button::Ptr, Player::CountMove>     mBindingButtons;
        std::array<GUI::Label::Ptr, Player::CountMove>      mBindingLabels; 
};