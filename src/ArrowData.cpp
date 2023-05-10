#include "ArrowData.hpp"
#include "State.hpp"
const float Thickness = 20.f;
const int y_shift = 15.f;

ArrowData::ArrowData(bool flag, int padding)
    : mStart(),
      mEnd(),
      mBody(),
      mHead(Thickness, 3),
      isNotDraw(false),
      drawFlag(true),
      isStart(false),
      isEnd(false),
      mNextNode(nullptr),
      isCircleDraw(false),
      mBody1(),
      mBody2(),
      mBody3(),
      mHead1(Thickness, 3),
      revFlag(0), 
      y_padding(0) {

    mBody.setFillColor(sf::Color::Black);
    mBody1.setFillColor(sf::Color::Black);
    mBody2.setFillColor(sf::Color::Black);
    mBody3.setFillColor(sf::Color::Black);

    mHead.setFillColor(sf::Color::Black);
    mHead1.setFillColor(sf::Color::Black);

    revFlag = flag;
    y_padding = padding;
}

void ArrowData::setStart(sf::Vector2f pos) {
    isStart = true;
    if (revFlag) {
        mStart = {pos.x + 3.f / 2.f * Thickness, pos.y};
    } else
        mStart = pos;
    update();
}

void ArrowData::setEnd(sf::Vector2f pos) {
    isEnd = true;
    if (revFlag) {
        mEnd = pos;
    } else
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

    if (revFlag) {
        mBody.setSize({mEnd.x - mStart.x, Thickness});
        setRightCenterOrigin(mBody);
        mBody.setPosition({mEnd.x, mEnd.y + y_padding * y_shift});

        setCenterOrigin(mHead);
        mHead.setPosition(mStart.x - 1.f / 3.f * Thickness, mEnd.y + y_padding * y_shift);
        mHead.setRotation(-90);
    } else {
        mBody.setSize({mEnd.x - mStart.x, Thickness});
        setLeftCenterOrigin(mBody);
        mBody.setPosition({mStart.x, mStart.y  + y_padding * y_shift});

        setCenterOrigin(mHead);
        mHead.setPosition(mEnd.x + 1.f / 3.f * Thickness, mEnd.y + y_padding * y_shift);
        mHead.setRotation(90);
    }
}

void ArrowData::drawCurrent(sf::RenderTarget& target,
                            sf::RenderStates states) const {
    if (!drawFlag)
        return;
    if (!isCircleDraw) {
        target.draw(mBody, states);
        target.draw(mHead, states);
    } else {
        target.draw(mBody1, states);
        target.draw(mBody2, states);
        target.draw(mBody3, states);
        target.draw(mHead1, states);
    }
}

void ArrowData::setBackToBegin(sf::Vector2f startPos, sf::Vector2f endPos,
                               float radiusOfNode) {
    isCircleDraw = true;

    ///////////////////// body1
    mBody1.setSize({Thickness, add_x * 2});
    setTopCenterOrigin(mBody1);
    mBody1.setPosition(startPos.x, startPos.y + radiusOfNode);
    //

    //////////////////// body2
    mBody2.setSize({startPos.x - endPos.x, Thickness});
    setRightCenterOrigin(mBody2);
    mBody2.setPosition({mBody1.getPosition().x + Thickness / 2.f,
                        mBody1.getPosition().y + mBody1.getSize().y});
    //

    /////////////////// body3
    mBody3.setSize({Thickness, add_x * 2 - Thickness * 3.f / 2.f});
    setDownCenterOrigin(mBody3);
    mBody3.setPosition(
        {mBody2.getPosition().x - mBody2.getSize().x + Thickness / 2.f,
         mBody2.getPosition().y});
    //

    ////////////////// mHead1
    setCenterOrigin(mHead1);
    mHead1.setPosition(
        {mBody3.getPosition().x, mBody3.getPosition().y - mBody3.getSize().y -
                                     1.f / 3.f * Thickness - 5.f});
}

void ArrowData::desetBackToBegin() { isCircleDraw = false; }
