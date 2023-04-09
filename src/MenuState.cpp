#include "../include/MenuState.hpp"

MenuState::MenuState(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mOptions(),
    mOptionIndex(0){
        sf::Texture &texture = context.textures->get(Textures::TitleScreen);
        sf::Font &font = context.fonts->get(Fonts::Main);
        mBackgroundSprite.setTexture(texture);

        // sf::Text playOption;
        // playOption.setFont(font);
        // playOption.setString("Play");
        // // Set center origin
        // sf::FloatRect bounds = playOption.getLocalBounds();
        // playOption.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
        // //
        // playOption.setPosition(context.window->getView().getSize() / 2.f);
        // mOptions.push_back(playOption);

        setMenuText("Play", sf::Vector2f(0.f, 0.f), font, context);
        setMenuText("Exit", sf::Vector2f(0.f, 30.f), font, context);

        updateOptionText();        
}

void MenuState::setMenuText(const std::string &text, const sf::Vector2f additionPos, const sf::Font &font, State::Context &context){
    sf::Text tOption;
    tOption.setFont(font);
    tOption.setString(text);
    // Set center origin
    // sf::FloatRect bounds = tOption.getLocalBounds();
    // tOption.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    setCenterOrigin(tOption);
    //
    tOption.setPosition(context.window->getView().getSize() / 2.f + additionPos);
    mOptions.push_back(tOption);
}

void MenuState::updateOptionText(){
    if(mOptions.empty())
        return;
    
    // iterate all texts
    for(sf::Text &text : mOptions)
        text.setColor(sf::Color::White);
    
    // Red the Seleting text
    mOptions[mOptionIndex].setColor(sf::Color::Red);
}

void MenuState::draw(){
    sf::RenderWindow &window = *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);

    for(sf::Text text : mOptions)
        window.draw(text);

}

bool MenuState::handleEvent(const sf::Event &event){
    if(event.type != sf::Event::KeyPressed)
        return false;
    
    if(event.key.code == sf::Keyboard::Return){
        // Don't be confuse sf::Keyboard::Return is sf::Keyboard::Enter :)))
        if(mOptionIndex == Play){
            requestStackPop(); // pop MenuState
            requestStackPush(States::Game); // Push GameState
        }
        else 
            requestStackPop(); // pop MenuState and usually the statestack will be empty and the game end (because before it the title screen have already pop)
    }
    else if(event.key.code == sf::Keyboard::Up){
        if(mOptionIndex > 0)
            --mOptionIndex;
        updateOptionText();
    }
    else if(event.key.code == sf::Keyboard::Down){
        if(mOptionIndex < mOptions.size() - 1)
            ++mOptionIndex;
        updateOptionText();
    }
    return true;
}

bool MenuState::update(sf::Time){
    //right now there is nothing in here
    return true;
}