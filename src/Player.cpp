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

void Player::handleEvent(const sf::Event& event, CommandQueue& commands){
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P){
        Command output;
        output.category = Category::PlayerAircraft;
        output.action = [] (SceneNode &s, sf::Time){
            std::cout   << s.getPosition().x << "," 
                        << s.getPosition().y << "\n";
        };
        commands.push(output);
    }
}