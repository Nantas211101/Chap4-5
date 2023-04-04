#include "../include/Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

auto Entity::getVelocity() -> sf::Vector2f const
{
    return mVelocity;
}

void Entity::updateCurrent(sf::Time dt){
    move(mVelocity * dt.asSeconds());
}

void Entity::accelerate(sf::Vector2f velocity){
    setVelocity(getVelocity() + velocity);
}

void Entity::accelerate(float vx, float vy){
    sf::Vector2f tmpVelocity = getVelocity();
    setVelocity(tmpVelocity.x + vx, tmpVelocity.y + vy);
}

