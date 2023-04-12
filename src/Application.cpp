#include "../include/Application.hpp"


// Application quite similar to the Game.cpp
const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application():
    mWindow(sf::VideoMode(1440, 1000), "Game States World", sf::Style::Close),
    mTextures(),
    mFonts(),
    mPlayer(),
    mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer)),
    mStayText(),
    mStayUpdateTime(),
    mStayNumFrames(0){
        // Not let the key repeat
        mWindow.setKeyRepeatEnabled(false);
        
        // Loading resource
        mFonts.load(Fonts::Main, Path_Font);
        mTextures.load(Textures::TitleScreen, Path_TitleScreen);
        mTextures.load(Textures::Menu, Path_MenuScreen);
        mTextures.load(Textures::ButtonNormal, Path_ButtonNormal);
        mTextures.load(Textures::ButtonSelected, Path_ButtonSelected);
        mTextures.load(Textures::ButtonPressed, Path_ButtonPressed);

        // Set Font, position, and size for the text fps (this quite similar with the Game.hpp)
        mStayText.setFont(mFonts.get(Fonts::Main));
        mStayText.setPosition(5.f, 5.f);
        mStayText.setCharacterSize(10u);

        registerStates();
        // start with the title state
        mStateStack.pushState(States::Title);
}

void Application::registerStates(){
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);   
    mStateStack.registerState<SettingsState>(States::Settings);
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
    mWindow.clear();
    mStateStack.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStayText);
    mWindow.display();
}

void Application::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            update(TimePerFrame);

            // Maybe after update the stack will be empty
            if(mStateStack.isEmpty())
                mWindow.close();
        }

        updateStatic(elapsedTime);
        render();
    }
}

void Application::updateStatic(sf::Time elapsedTime){
    mStayUpdateTime += elapsedTime;
    mStayNumFrames += 1;

    if(mStayUpdateTime >= sf::seconds(1.0f)){
        mStayText.setString(
            "Frames / Second = " + toString(mStayNumFrames) + "\n" +
            // mStayNumFrames can be consider at Numofupdate
            "Time / Update = " + toString(mStayUpdateTime.asSeconds() / mStayNumFrames) + "us");
        // reset the mStay
        mStayUpdateTime -= sf::seconds(1.0f);
        mStayNumFrames = 0;
    }
}
