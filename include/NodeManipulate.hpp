#pragma once
#include "Pos_ID.hpp"
#include "SceneNode.hpp"
#include "State.hpp"

#include <vector>

template <typename TypeNode> class NodeManipulate {

  public:
    void init(SceneNode& mSceneGraph, int n, State::Context context);
    void reset(SceneNode& mSceneGraph);
    void setPos(SceneNode& mSceneGraph);

  private:
    std::vector<TypeNode*> ptrSaver;
    Pos_ID IDHolder;
};

#include "../template/NodeManipulate.inl"