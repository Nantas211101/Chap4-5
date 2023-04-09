#include "../include/LoadingState.hpp"

LoadingState::LoadingState(StateStack &stack, Context context):
    State(stack, context){
        sf::RenderWindow &window = *getContext().window;
        sf::Font &font = context.fonts->get(Fonts::Main);
        sf::Vector2f viewSize = window.getView().getSize();

        // Init the loadingtext
        mLoadingText.setFont(font);
        mLoadingText.sexString(Loading_text);
        setCenterOrigin(mLoadingText);
        mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f + yShiftText);

        // Init the progressbarbackground
        mProgressBarBackground.setFillColor(sf::Color::White);
        mProgressBarBackground.setSize(sf::Vector2f(viewSize.x - 20, 10));
        mProgressBarBackground.setPosition(10, mLoadingText.getPosition().y + yShiftBar);

        // Init the progressbar
        mProgressBar.setFillColor(sf::Color(100, 100, 100));
        mProgressBar.setSize(sf::Vector2f(200, 10));
        mProgressBar.setPosition(10, mLoadingText.getPosition().y + yShiftBar);

        setComplete(0.f); // set 0%
        mLoadingTask.execute() // start the loading 
}

void LoadingState::draw(){
    sf::RenderWindow &window = *getContext().window;
    
    window.setView(window.getDefaultView());
    window.draw(mLoadingText);
    window.draw(mProgressBarBackground);
    window.draw(mProgressBar);
}

bool LoadingState::update(sf::Time elapsedTime){
    // update the fill bar of end it 
    if(mLoadingTask.isFinished()){
        requestStackPop();
        requestStackPush(States::Game);
    }
    else{
        setComplete(mLoadingTask.getPercentComplete());
    }
    return true;
}

bool LoadingState::handleEvent(const sf::Event &event){
    return true;
}

void LoadingState::setComplete(float percent){
    if(percent >= 1.f) // Bounding
        percent = 1.f;

    mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBarBackground.getSize().y));
}