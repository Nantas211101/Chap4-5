#include "../include/Player.hpp"

Player::Player(){
    mKeyBinding[sf::Keyboard::Left] = MoveLeft;
    mKeyBinding[sf::Keyboard::Right] = MoveRight;
    mKeyBinding[sf::Keyboard::Up] = MoveUp;
    mKeyBinding[sf::Keyboard::Down] = MoveDown;

    initAction();

    for(auto &pair : mActionBinding)
        pair.second.category = Category::PlayerAircraft;
}

void Player::handleRealtimeInput(CommandQueue& commands){
    for(auto pair : mKeyBinding){
        if(sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
    }
    //
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    //     Command moveUp;
    //     moveUp.category = Category::PlayerAircraft;
    //     moveUp.action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    //     commands.push(moveUp);
    // }
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands){
    if(event.type == sf::Event::KeyPressed){
        for(auto &pair : mKeyBinding)
            if(event.key.code == pair.first)
                commands.push(mActionBinding[pair.second]);
    }
}

void Player::assignKey(Action action, sf::Keyboard::Key key){
    for(auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); ++itr)
        if(itr->second == action)
            mKeyBinding.erase(itr);
    mKeyBinding[key] = action;
}

auto Player::getAssignedKey(Action action) -> sf::Keyboard::Key const{
    for(auto &pair : mKeyBinding)
        if(pair.second == action)
            return pair.first;
    return sf::Keyboard::Unknown;
}

bool Player::isRealtimeAction(Action action){
    if (action == MoveLeft || action == MoveRight || action == MoveUp || action == MoveDown) {
        return true;
    }
    return false;
}

void Player::initAction(){
    // Way 1 a little bit messy
    // mActionBinding[MoveLeft].action = [] (SceneNode &node, sf::Time dt){
    //     node.move(-playerSpeed * dt.asSeconds(), 0.f);
    // };

    // mActionBinding[MoveRight].action = [] (SceneNode &node, sf::Time dt){
    //     node.move(playerSpeed * dt.asSeconds(), 0.f);
    // };

    // mActionBinding[MoveUp].action = [] (SceneNode &node, sf::Time dt){
    //     node.move(0.f, -playerSpeed * dt.asSeconds());
    // };

    // mActionBinding[MoveDown].action = [] (SceneNode &node, sf::Time dt){
    //     node.move(0.f, playerSpeed * dt.asSeconds());
    // };

    // beautiful way
    mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f));
    mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, playerSpeed));
}