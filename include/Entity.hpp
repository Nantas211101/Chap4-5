#pragma once
#include <SFML\Graphics.hpp>
#include "ResourceHolder.hpp"
#include "SceneNode.hpp"
// namespace Textures
// {
//     enum ID
//     {
//         Eagle,
//         Raptor,
//     };
// }

// typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder; 

class Entity : public SceneNode
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    auto getVelocity() -> sf::Vector2f const;

private:
    virtual void updateCurrent(sf::Time dt);

private:
    sf::Vector2f mVelocity;
};