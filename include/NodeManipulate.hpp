#pragma once
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

    bool pushBackNode(SceneNode& mSceneGraph, std::string value,
                      State::Context context);

    auto searchingNode(SceneNode& mSceneGraph, sf::Time dt, std::string value)
        -> int;

    auto accessingNode(SceneNode& mSceneGraph, sf::Time dt, int id) -> int;

    auto takeCurrentState() -> int;

    void setIsSearching();
    void setIsAccessing();

  private:
    std::vector<TypeNode*> ptrSaver;
    Pos_ID OldIDHolder;
    Pos_ID NewIDHolder;
    sf::Time timeSinceStartSetPos;
    sf::Time timeSinceLastUpdate;
    bool isStartSetPos = false;
    int currentSelected = 0;

    // -1 : isAccesing
    // 0 : nothing
    // 1 : isSearching
    int currentState = 0;
};

#include "../template/NodeManipulate.inl"