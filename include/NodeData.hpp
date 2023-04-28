#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "TextureManipulate.hpp"

#include <SFML/Graphics.hpp>
#include <string>

class NodeData : public SceneNode {
  public:
    NodeData(std::string n, const FontHolder& fonts, int sizeOfText = 40,
             int sizeOfShape = 60);

    virtual void drawCurrent(sf::RenderTarget& target,
                             const sf::RenderStates states) const;
    auto takeRadius() -> float;
    auto takePosition() -> sf::Vector2f;
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    void setRadius(float r);
    void setValue(std::string value);
    auto getValue() -> std::string;

  private:
    sf::CircleShape mShape;
    sf::Text mDisplayText;
};