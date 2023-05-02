#pragma once
#include "NodesSaverIdentifiers.hpp"
#include "Pos_ID.hpp"
#include "SceneNode.hpp"
#include "State.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

template <typename TypeNode> class NodeManipulate {

  public:
    void init(SceneNode& mSceneGraph, std::vector<std::string> arr,
              State::Context context);

    void reset(SceneNode& mSceneGraph);
    void resetColor(SceneNode& mSceneGraph);
    void resetSelected();
    void resetState();

    void updatePos(SceneNode& mSceneGraph, sf::Time dt);
    bool attachNode(SceneNode& mSceneGraph, int id, std::string value,
                    State::Context context);
    bool detachNode(SceneNode& mSceneGraph, int id);

    auto takeNumOfNode() -> int;
    auto takeValueOfNode(int id) -> std::string;

    // action
   
    bool pushBackNode(SceneNode& mSceneGraph, std::string value,
                      State::Context context);

    auto searchingNode(SceneNode& mSceneGraph, sf::Time dt, std::string value)
        -> ActionState::ID;

    auto accessingNode(SceneNode& mSceneGraph, sf::Time dt, int id)
        -> ActionState::ID;

    auto updatingNode(SceneNode& mSceneGraph, sf::Time dt, int id,
                      std::string value) -> ActionState::ID;

    //
    
    auto takeCurrentState() -> NodesState::ID;

    void setIsSearching();
    void setIsAccessing();
    void setIsUpdating();

  private:
    void updateValueNode(int pos, std::string value);
  
  private:
    std::vector<TypeNode*> ptrSaver;
    Pos_ID OldIDHolder;
    Pos_ID NewIDHolder;
    sf::Time timeSinceStartSetPos;
    sf::Time timeSinceLastUpdate;
    bool isStartSetPos = false;
    int currentSelected = 0; // This is ID

    NodesState::ID currentState = NodesState::nothing;
};

#include "../template/NodeManipulate.inl"