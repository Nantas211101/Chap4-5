#include "../include/Player.hpp"

void Player::handleRealtimeInput(CommandQueue& commands){
    const float playerSpeed = 30.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        Command moveUp;
        moveUp.category = Category::PlayerAircraft;
        moveUp.action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
        commands.push(moveUp);
    }
}