#include "../include/NodeData.hpp"

NodeData::NodeData(int n, const FontHolder& fonts, int sizeOfText,
                   int sizeOfShape)
    : mShape(), mDisplayText("", fonts.get(Fonts::Main), sizeOfText) {
    mShape.setRadius(sizeOfShape / 2);
    mShape.setFillColor(sf::Color::Blue);
    mShape.setOutlineColor(sf::Color::Yellow);
    mShape.setOutlineThickness(5.f);
    setCenterOrigin(mShape);

    mDisplayText.setString(toString(n));
    setCenterOrigin(mDisplayText);
}

void NodeData::draw(sf::RenderTarget &target, const sf::RenderStates states){
    target.draw(mShape, states);
    target.draw(mDisplayText, states);
    mShape.getRadius();
}

auto NodeData::takeRadius() -> float{
    return mShape.getRadius();
}

auto NodeData::takePosition() -> sf::Vector2f{
    return mShape.getPosition();
}

void NodeData::setPosition(sf::Vector2f pos){
    mShape.setPosition(pos);
}

void NodeData::setPosition(float x, float y){
    setPosition({x, y});
}
