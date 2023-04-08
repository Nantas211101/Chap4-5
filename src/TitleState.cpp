#include "../include/TitleState.hpp"

TitleState::TitleState(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mText(),
    isShowText(true),
    mTextTimeEffected(sf::Time::Zero){
        // context.textures is a pointer so->
    mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
    mText.setFont(context.fonts->get(Fonts::Main));
    mText.setString("Press any key to begin");
    // Set center origin
    sf::FloatRect bounds = mText.getLocalBounds();
    mText.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    //
    mText.setPosition(context.window->getView().getSize() / 2.f);
}

bool TitleState::handleEvent(const sf::Event &event){
    if(event.type ==sf::Event::KeyPressed){
        requestStackPop(); // pop the title screen
        requestStackPush(States::Menu); // push the menu screen
    }

    return true;
}

bool TitleState::update(sf::Time elapsedTime){
    mTextTimeEffected += elapsedTime;
    if(mTextTimeEffected >= sf::seconds(0.5f)){
        isShowText = !isShowText; // reverse the state of the text
        mTextTimeEffected = sf::Time::Zero;
    }
    return true;
}

void TitleState::draw(){
    sf::RenderWindow &mWindow = *getContext().window;
    mWindow.draw(mBackgroundSprite);
    
    // Make the text blink blink
    if(isShowText)
        mWindow.draw(mText);
}