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

    ///////// action

    bool pushFrontNode(SceneNode& mSceneGraph, std::string value,
                       State::Context context);
    bool pushMiddleNode(SceneNode& mSceneGraph, std::string value, int id,
                        State::Context context);
    bool pushBackNode(SceneNode& mSceneGraph, std::string value,
                      State::Context context);

    bool popFrontNode(SceneNode& mSceneGraph);
    bool popMiddleNode(SceneNode& mSceneGraph, int id);
    bool popBackNode(SceneNode& mSceneGraph);

    auto pushingNode(SceneNode& mSceneGraph, sf::Time dt, std::string value, int id,
                    State::Context context, const sf::Event& event) -> ActionState::ID;
    
    auto popingNode(SceneNode& mSceneGraph, sf::Time dt, int id,
                    const sf::Event& event) -> ActionState::ID;

    auto searchingNode(SceneNode& mSceneGraph, sf::Time dt, std::string value,
                       const sf::Event& event) -> ActionState::ID;

    auto accessingNode(SceneNode& mSceneGraph, sf::Time dt, int id,
                       const sf::Event& event) -> ActionState::ID;

    auto updatingNode(SceneNode& mSceneGraph, sf::Time dt, int id,
                      std::string value, const sf::Event& event)
        -> ActionState::ID;

    /////////

    auto takeCurrentState() -> NodesState::ID;
    auto takeCurrentActionType() -> NodesState::ActionType;

    void setIsSearching();
    void setIsAccessing();
    void setIsUpdating();
    void setIsPushing();
    void setIsPoping();

    void setIsStepByStep();
    void setIsRunAtOnce();

    void ChangeSpeed();

  private:
    void updateValueNode(int pos, std::string value);
    void updateCurrentSelected(sf::Time dt, const sf::Event& event);

  private:
    std::vector<TypeNode*> ptrSaver;
    Pos_ID OldIDHolder;
    Pos_ID NewIDHolder;
    sf::Time timeSinceStartSetPos; // still vo nghia
    sf::Time timeSinceLastUpdate;
    bool isStartSetPos = false;
    int currentSelected = 0; // This is ID
    int currentTimeID = 0;
    sf::Time TimePerUpdate = sf::seconds(1.f / 1.f);

    NodesState::ID currentState = NodesState::nothing;

    NodesState::ActionType currentActionType = NodesState::RunAtOnce;
};

#include "../template/NodeManipulate.inl"