#pragma once
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class Aircraft : public Entity // inherits indirectyly SceneNode
{
public:
    enum Type
    {
        Eagle,
        Raptor,
    };

public:
    explicit Aircraft(Type type, const TextureHolder &textures);
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    auto getCategory() -> unsigned int const;

private:
    Type mType;
    sf::Sprite mSprite;
};