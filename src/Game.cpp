#include "../include/Game.h"

//===================================================================//
// Main function

Game::Game():
    mWindow(sf::VideoMode(640, 480), "World"), 
    mPlayer(),
    mWorld(mWindow){
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            if(!mIsPaused)
                update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch(event.type){
            case sf::Event::GainedFocus:
                mIsPaused = false;
                break;
            case sf::Event::LostFocus:
                mIsPaused = true;
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::processInput(){
    CommandQueue& commands = mWorld.getCommandQueue();

    sf::Event event;
    while(mWindow.pollEvent(event)){
        mPlayer.handleEvent(event, commands);

        if(event.type == sf::Event::Closed)
            mWindow.close();            
    }
    mPlayer.handleRealtimeInput(commands);
}

void Game::update(sf::Time deltaTime){
    // sf::Vector2f movement(0.f, 0.f);
    // // if(mIsMoveUp)
    // //     movement.y -= PlayerSpeed;
    // // if(mIsMoveDown)
    // //     movement.y += PlayerSpeed;
    // // if(mIsMoveLeft)
    // //     movement.x -= PlayerSpeed;
    // // if(mIsMoveRight)
    // //     movement.x += PlayerSpeed;
    
    // // Using the real time input
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //     movement.y -= PlayerSpeed;
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //     movement.y += PlayerSpeed;
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //     movement.x -= PlayerSpeed;
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //     movement.x += PlayerSpeed;
    // mPlayer.move(movement * deltaTime.asSeconds());
    mWorld.update(deltaTime);
}

void Game::render(){
    mWindow.clear();
    mWorld.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}
//===================================================//





// Additional function

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(key == sf::Keyboard::W)
        mIsMoveUp = isPressed;
    else if(key == sf::Keyboard::S)
        mIsMoveDown = isPressed;
    else if(key == sf::Keyboard::A)
        mIsMoveLeft = isPressed;
    else if(key == sf::Keyboard::D)
        mIsMoveRight = isPressed;
}
//=========================================================//