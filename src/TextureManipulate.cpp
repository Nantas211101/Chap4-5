#include "../include/TextureManipulate.hpp"

void setCenterOrigin(sf::Text &text){
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void setCenterOrigin(sf::Sprite &sprite){
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}