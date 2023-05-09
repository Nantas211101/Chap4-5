#include "StackNode.hpp"

StackNode::StackNode(const FontHolder& fonts, const TextureHolder& texture)
    : mDataNode(new NodeData("10", fonts)), mArrow(new ArrowData()) {
    std::unique_ptr<NodeData> dataNodePtr(mDataNode);
    std::unique_ptr<ArrowData> nextNodePtr(mArrow);

    attachChild(std::move(dataNodePtr));
    attachChild(std::move(nextNodePtr));
}

void StackNode::drawCurrent(sf::RenderTarget& target,
                            sf::RenderStates states) const {}

void StackNode::setPosNode(sf::Vector2f pos) {
    mDataNode->setPosition({pos.x + mDataNode->takeRadius(), pos.y});
    mArrow->setStart({pos.x + 2 * mDataNode->takeRadius(), pos.y});
}

void StackNode::setRadiusNode(float radius) { mDataNode->setRadius(radius); }

void StackNode::setNextNode(NodeData* mNext) { mArrow->setNextNode(mNext); }

void StackNode::setEnd(sf::Vector2f pos) { mArrow->setEnd({pos.x, pos.y}); }

void StackNode::setIsDrawArrow(bool flag) { mArrow->setDrawFlag(flag); }

void StackNode::setValue(std::string value) { mDataNode->setValue(value); }

auto StackNode::getValue() -> std::string { return mDataNode->getValue(); }

void StackNode::setSelected() { mDataNode->setColor(sf::Color(253, 90, 30)); }

void StackNode::setDeselected() { mDataNode->setColor(sf::Color::Blue); }

void StackNode::setHeadNode() { mDataNode->setColor(sf::Color::Magenta); }

void StackNode::setLastNode(sf::Vector2f endpos) {}

void StackNode::desetLastNode() {}