#include "Game.hpp"

//===================================================================//
// Main function

Game::Game():
    mWindow(sf::VideoMode(640, 480), "World"), 
    mPlayer(),
    mWorld(mWindow),
    mFont(),
    mStayText(),
    mStayUpdateTime(),
    mStayNumFrames(0){
        mWindow.setKeyRepeatEnabled(false);

        mFont.loadFromFile(Path_Font);
        mStayText.setFont(mFont);
        mStayText.setPosition(5.f, 5.f);
        mStayText.setCharacterSize(10);
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        // processInput(); 
        // delete this line because now process even have realtimeinput so to keep the fps we have to delte
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            if(!mIsPaused)
                update(TimePerFrame);
        }
        updateStatic(elapsedTime);
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
    CommandQueue& commands = mWorld.getCommandQueue(); // take reference so that it can be change

    sf::Event event;
    while(mWindow.pollEvent(event)){
        mPlayer.handleEvent(event, commands);
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
    mWindow.draw(mStayText);
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

// The FPS showing follow the SFML
void Game::updateStatic(sf::Time elapsedTime){
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
//=========================================================//