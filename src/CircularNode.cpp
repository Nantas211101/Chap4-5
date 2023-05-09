#include "CircularNode.hpp"
#include "State.hpp"

CircularNode::CircularNode(const FontHolder& fonts, const TextureHolder& texture)
    : mDataNode(new NodeData("10", fonts)), mArrow(new ArrowData()) {
    std::unique_ptr<NodeData> dataNodePtr(mDataNode);
    std::unique_ptr<ArrowData> nextNodePtr(mArrow);

    attachChild(std::move(dataNodePtr));
    attachChild(std::move(nextNodePtr));
}

void CircularNode::drawCurrent(sf::RenderTarget& target,
                            sf::RenderStates states) const {}

void CircularNode::setPosNode(sf::Vector2f pos) {
    mDataNode->setPosition({pos.x + mDataNode->takeRadius(), pos.y});
    mArrow->setStart({pos.x + 2 * mDataNode->takeRadius(), pos.y});
}

void CircularNode::setRadiusNode(float radius) { mDataNode->setRadius(radius); }

void CircularNode::setNextNode(NodeData* mNext) { mArrow->setNextNode(mNext); }

void CircularNode::setEnd(sf::Vector2f pos) { mArrow->setEnd({pos.x, pos.y}); }

void CircularNode::setIsDrawArrow(bool flag) { mArrow->setDrawFlag(flag); }

void CircularNode::setValue(std::string value) { mDataNode->setValue(value); }

auto CircularNode::getValue() -> std::string { return mDataNode->getValue(); }

void CircularNode::setSelected(){
    mDataNode->setColor(sf::Color(253, 90, 30));
}

void CircularNode::setDeselected(){
    mDataNode->setColor(sf::Color::Blue);
}

void CircularNode::setHeadNode(){
    mDataNode->setColor(sf::Color::Magenta);
}

void CircularNode::setLastNode(sf::Vector2f endpos){
    endpos = {add_x - mDataNode->takeRadius(), add_y}; // because init endpos is the begin of the  first node not the center of the first node
    sf::Vector2f startpos = mDataNode->takePosition();
    mArrow->setBackToBegin(startpos, endpos, mDataNode->takeRadius());
}

void CircularNode::desetLastNode(){
    mArrow->desetBackToBegin();
}