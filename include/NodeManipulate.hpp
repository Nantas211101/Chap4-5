#pragma once
#include "Pos_ID.hpp"
#include "SceneNode.hpp"
#include "State.hpp"

#include <SFML/Graphics.hpp>
#include <string>

#include <vector>

template <typename TypeNode> class NodeManipulate {

  public:
    void init(SceneNode& mSceneGraph, int n, State::Context context);
    void reset(SceneNode& mSceneGraph);
    void updatePos(SceneNode& mSceneGraph, sf::Time dt);
    bool attachNode(SceneNode& mSceneGraph, int id, std::string value, State::Context context);
    bool detachNode(SceneNode& mSceneGraph, int id);
    auto takeNumOfNode() -> int;

  private:
    std::vector<TypeNode*> ptrSaver;
    Pos_ID OldIDHolder;
    Pos_ID NewIDHolder;
    sf::Time timeSinceStartSetPos;
    bool isStartSetPos = false;;
};

#include "../template/NodeManipulate.inl"