#include "../include/NodeData.hpp"

NodeData::NodeData(int n, const FontHolder& fonts, int sizeOfText,
                   int sizeOfShape)
    : mShape(), mDisplayText(toString(n), fonts.get(Fonts::Main), sizeOfText) {
    mShape.setRadius(sizeOfShape / 2);
    mShape.setFillColor(sf::Color::Blue);
    setCenterOrigin(mShape);
    // mShape.setOutlineColor(sf::Color::Red);
    // mShape.setOutlineThickness(5.f);

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