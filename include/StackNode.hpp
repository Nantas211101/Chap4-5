#pragma once
#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureManipulate.hpp"
#include "NodeData.hpp"
#include "ArrowData.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class StackNode : public SceneNode {
    public:
        explicit StackNode(const FontHolder &fonts, const TextureHolder &texture);
        virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
        void setPosNode(sf::Vector2f pos);
        void setRadiusNode(float radius);
        void setNextNode(NodeData *mNext);
        void setEnd(sf::Vector2f pos);

    private:
        NodeData *mDataNode;
        ArrowData *mArrow;
};