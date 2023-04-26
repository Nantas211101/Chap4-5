#include "../include/ArrowData.hpp"
const float Thickness = 20.f;

ArrowData::ArrowData()
    : mStart(),
      mEnd(),
      mBody(),
      mHead(Thickness, 3),
      isNotDraw(false),
      drawFlag(true),
      isStart(false),
      isEnd(false),
      mNextNode(nullptr) {

    mBody.setFillColor(sf::Color::Black);

    mHead.setFillColor(sf::Color::Black);
}

void ArrowData::setStart(sf::Vector2f pos) {
    isStart = true;
    mStart = pos;
    update();
}

void ArrowData::setEnd(sf::Vector2f pos) {
    isEnd = true;
    mEnd = {pos.x - 3.f / 2.f * Thickness, pos.y};
    update();
}

void ArrowData::setNextNode(NodeData* mNext) {
    mNextNode = mNext;
    sf::Vector2f nextPos = mNextNode->takePosition();
    float nextRadius = mNextNode->takeRadius();
    setEnd({nextPos.x - nextRadius, nextPos.y});
}

void ArrowData::setDrawFlag(bool flag) { drawFlag = flag; }

void ArrowData::update() {
    isNotDraw = (isStart && isEnd);
    if (!isNotDraw)
        return;

    mBody.setSize({mEnd.x - mStart.x, Thickness});
    setLeftCenterOrigin(mBody);
    mBody.setPosition(mStart);

    setCenterOrigin(mHead);
    mHead.setPosition(mEnd.x + 1.f / 3.f * Thickness, mEnd.y);
    mHead.setRotation(90);
}

void ArrowData::drawCurrent(sf::RenderTarget& target,
                            sf::RenderStates states) const {
    if (!drawFlag)
        return;
    target.draw(mBody, states);
    target.draw(mHead, states);
}