#include "DoublyNode.hpp"
#include "State.hpp"

const float x_pad = 8.f;

DoublyNode::DoublyNode(const FontHolder& fonts, const TextureHolder& texture)
    : mDataNode(new NodeData("10", fonts)),
      mArrowNext(new ArrowData(false, 1)),
      mArrowPrev(new ArrowData(true, -1)) {
    std::unique_ptr<NodeData> dataNodePtr(mDataNode);
    std::unique_ptr<ArrowData> nextNodePtr(mArrowNext);
    std::unique_ptr<ArrowData> prevNodePtr(mArrowPrev);

    attachChild(std::move(dataNodePtr));
    attachChild(std::move(nextNodePtr));
    attachChild(std::move(prevNodePtr));
}

void DoublyNode::drawCurrent(sf::RenderTarget& target,
                             sf::RenderStates states) const {}

void DoublyNode::setPosNode(sf::Vector2f pos) {
    mDataNode->setPosition({pos.x + mDataNode->takeRadius(), pos.y});
    mArrowNext->setStart({pos.x + 2 * mDataNode->takeRadius(), pos.y});
    
    mArrowPrev->setEnd(pos);
    mArrowPrev->setStart({pos.x + 2 * mDataNode->takeRadius() - add_x - x_pad, pos.y});
}

void DoublyNode::setRadiusNode(float radius) { mDataNode->setRadius(radius); }

void DoublyNode::setNextNode(NodeData* mNext) {
    mArrowNext->setNextNode(mNext);
}

void DoublyNode::setEnd(sf::Vector2f pos) {
    mArrowNext->setEnd({pos.x + x_pad, pos.y});
}

void DoublyNode::setIsDrawArrow(bool flag, int type) { 
    mArrowNext->setDrawFlag(flag); 
    mArrowPrev->setDrawFlag(flag);
}

void DoublyNode::setValue(std::string value) { mDataNode->setValue(value); }

auto DoublyNode::getValue() -> std::string { return mDataNode->getValue(); }

void DoublyNode::setSelected() { mDataNode->setColor(sf::Color(253, 90, 30)); }

void DoublyNode::setDeselected() { mDataNode->setColor(sf::Color::Blue); }

void DoublyNode::setHeadNode() { mDataNode->setColor(sf::Color::Magenta); }

void DoublyNode::setLastNode(sf::Vector2f endpos) {}

void DoublyNode::desetLastNode() {}