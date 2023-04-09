#include "../include/PauseState.hpp"

PauseState::PauseState(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mPausedText()
    mInstructionText(){
        // mBackgroundSprite quite useless with PauseState
        sf::Font &font = context.fonts->get(Fonts::Main);
        sf::Vector2f viewSize = context.window->getView().getSize(); // get the size of the view

        // Init the mPausedText
        mPausedText.setFont(font);
        mPausedText.setString("World Stopbu");
        mPausedText.setCharacterSize(70);
        //

        //

}

void PauseState::draw(){
    sf::RenderWindow &window = *getContext().window;
    window.setView(window.getDefaultView());
    
    // create background 
    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    backgroundShape.setSize(sf::Vector2f(window.getSize()));
    //

    window.draw(backgroundShape);
    window.draw(mPausedText);
    window.draw(mInstructionText);
}

bool PauseState::handleEvent(const sf::Event &event){
    if(event.type != sf::Event::KeyPressed)
        return false;
    if(event.key.code == sf::Keyboard::Escape){
        requestStackPop(); // pop the PauseState
    }
    else if(event.key.code == sf::Keyboard::BackSpace){
        requestStateClear(); 
        // below PauseState only have GameState but GameState may push another State so to be safe we should clear all the state 
        requestStackPush(States::Menu); // and return back to menu state
    }
    return false; // why return false at handleEvent and update
    // simply because PauseState will stop all other below state and return false will make the state stack will not touch the below state
}