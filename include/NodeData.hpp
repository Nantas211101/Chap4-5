#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureManipulate.hpp"
#include "StringConvert.hpp"

#include <SFML/Graphics.hpp>
#include <string>

class NodeData{
    public:
        NodeData(int n, const FontHolder &fonts, int sizeOfText = 20, int sizeOfShape = 10);

        void draw(sf::RenderTarget &target, const sf::RenderStates states);
        auto takeRadius() -> float;
        auto takePosition() -> sf::Vector2f;
        void setPosition(sf::Vector2f pos);
        void setPosition(float x, float y);

    private:
        sf::CircleShape mShape;
        sf::Text mDisplayText;

};