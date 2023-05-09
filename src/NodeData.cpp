#include "NodeData.hpp"

NodeData::NodeData(std::string n, const FontHolder& fonts, int sizeOfText,
                   int sizeOfShape)
    : mShape(), mDisplayText(n, fonts.get(Fonts::Main), sizeOfText) {
    mShape.setRadius(sizeOfShape);
    mShape.setFillColor(sf::Color::Blue);
    setCenterOrigin(mShape);

    mDisplayText.setFillColor(sf::Color::White);
    setCenterOrigin(mDisplayText);
}

void NodeData::drawCurrent(sf::RenderTarget& target,
                           const sf::RenderStates states) const {
    target.draw(mShape, states);
    target.draw(mDisplayText, states);
}

auto NodeData::takeRadius() -> float { return mShape.getRadius(); }

auto NodeData::takePosition() -> sf::Vector2f { return mShape.getPosition(); }

void NodeData::setPosition(sf::Vector2f pos) {
    setCenterOrigin(mShape, true);
    mShape.setPosition(pos);

    setCenterOrigin(mDisplayText);
    mDisplayText.setPosition({pos.x, pos.y - 10.f});
}

void NodeData::setPosition(float x, float y) { setPosition({x, y}); }

void NodeData::setRadius(float r) { mShape.setRadius(r); }

void NodeData::setValue(std::string value) { mDisplayText.setString(value); }

auto NodeData::getValue() -> std::string { return mDisplayText.getString(); }

void NodeData::setColor(sf::Color color){
    mShape.setFillColor(color);
}