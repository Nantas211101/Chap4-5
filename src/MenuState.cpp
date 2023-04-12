#include "../include/MenuState.hpp"

MenuState::MenuState(StateStack &stack, Context context):
    State(stack, context),
    mGUIContainer(),
    mBackgroundSprite(),
    mOptions(),
    mOptionIndex(0){
        sf::Texture &texture = context.textures->get(Textures::Menu);
        // sf::Font &font = context.fonts->get(Fonts::Main);
        mBackgroundSprite.setTexture(texture);
        
        // set Button play
        auto playButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        playButton->setPosition(100, 250);
        playButton->setText("Play");
        playButton->setCallback([this] (){
            requestStackPop();
            requestStackPush(States::Game);
        });

        // Set Button setting
        auto settingsButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        settingsButton->setPosition(100, 300);
        settingsButton->setText("Setting");
        settingsButton->setCallback([this] (){
            requestStackPush(States::Settings);
        });

        // set Button exit
        auto exitButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        settingsButton->setPosition(100, 300);
        settingsButton->setText("Exit");
        settingsButton->setCallback([this] (){
            requestStackPop();
        });

        mGUIContainer.pack(playButton);
        mGUIContainer.pack(settingsButton);
        mGUIContainer.pack(exitButton);  
}

void MenuState::draw(){
    sf::RenderWindow &window = *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);

}

bool MenuState::update(sf::Time){
    //right now there is nothing in here
    return true;
}

bool MenuState::handleEvent(const sf::Event &event){
    mGUIContainer.handleEvent(event);
    return false;
}
