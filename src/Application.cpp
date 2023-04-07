#include "include/Application.hpp"

void Application::registerStates(){
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);   
    mStateStack.pushState(States::Title);
}

void Application::processInput(){
    // Feeding events
    sf::Event event;
    while(mWindow.pollEvent(event)){
        mStateStack.handleEvent(event);

        if(mStateStack.isEmpty())
            mWindow.close();
    }
}

void Application::update(sf::Time dt){
    mStateStack.update(dt);
}

void Application::render(){
    mStateStack.draw();
}


