#pragma once
#include "NodeData.hpp"
#include "SceneNode.hpp"
#include "TextureManipulate.hpp"

#include <SFML/Graphics.hpp>

class ArrowData : public SceneNode {
  public:
    ArrowData();

    void setStart(sf::Vector2f pos);
    void setEnd(sf::Vector2f pos);
    void setNextNode(NodeData* mNext);
    void setDrawFlag(bool flag);
    void update();
    virtual void drawCurrent(sf::RenderTarget& target,
                             sf::RenderStates states) const;
    
    void setBackToBegin(sf::Vector2f startPos, sf::Vector2f endPos, float radiusOfNode);
    void desetBackToBegin();

  private:
    sf::Vector2f mStart;
    sf::Vector2f mEnd;
    sf::RectangleShape mBody;
    sf::CircleShape mHead;
    bool isNotDraw;
    bool drawFlag;
    bool isStart;
    bool isEnd;
    NodeData* mNextNode;

    // The Back to begin arrow
    bool isCircleDraw;

    sf::RectangleShape mBody1;
    sf::RectangleShape mBody2;
    sf::RectangleShape mBody3;
    sf::CircleShape mHead1;

};