#include "../include/MenuState.hpp"

MenuState::MenuState(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mOptions(),
    mOptionIndex(0){
        sf::Texture &texture = context.textures->get(Textures::TitleScreen);
        sf::Font &font = context.fonts->get(Fonts::Main);
        mBackgroundSprite.setTexture(texture);

        sf::Text playOption;
        playOption.setFont(font);
        playOption.setString("Play");
        // Set center origin
        sf::FloatRect bounds = playOption.getLocalBounds();
        playOption.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        //
        playOption.setPosition(context.window->getView().getSize() / 2.f);
        mOptions.push_back(playOption);
}

void MenuState::setMenuText()