#include "../include/SettingsState.hpp"

SettingsState::SettingsState(StateStack &stack, Context context):
    State(stack, context),
    mGUIContainer(){
        mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
        mBindingButtons[Player::MoveLeft] = std::make_shared<GUI::Button>();


        // set the backButton
        // we set it in the setting state because only setting state have it
        auto backButton = std::make_shared<GUI::Button>();
        backButton->setPosition(80.f, 375.f);
        backButton->setText("Back");
        backButton->setCallback([this] (){
            requestStackPop();
        });

        mGUIContainer.pack(backButton);
}

// Additional function

void SettingsState::addButtonLabel(Player::Action action, float y, const std::string &text, Context context){
    mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    mBindingButton
}