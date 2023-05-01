#include "Constants.hpp"
#include "NodeManipulate.hpp"

#include <memory>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
const sf::Time TimePerUpdate = sf::seconds(1.f / 5.f);

template <typename TypeNode>
void NodeManipulate<TypeNode>::init(SceneNode& mSceneGraph,
                                    std::vector<std::string> arr,
                                    State::Context context) {
    int n = arr.size();
    OldIDHolder.init(n);
    NewIDHolder.init(n);
    ptrSaver.clear();
    for (int i = 0; i < n; ++i) {
        TypeNode* tmp = new TypeNode(*context.fonts, *context.textures);
        std::unique_ptr<TypeNode> mNode(tmp);
        mSceneGraph.attachChild(std::move(mNode));
        tmp->setValue(arr[i]);
        ptrSaver.push_back(std::move(tmp));
    }
}

template <typename TypeNode>
void NodeManipulate<TypeNode>::reset(SceneNode& mSceneGraph) {
    for (TypeNode* mNode : ptrSaver) {
        mSceneGraph.detachChild(*mNode);
    }
    ptrSaver.clear();
}

template <typename TypeNode>
void NodeManipulate<TypeNode>::resetColor(SceneNode& mSceneGraph) {
    for (TypeNode* mNode : ptrSaver) {
        mNode->setDeselected();
    }
}

template <typename TypeNode> void NodeManipulate<TypeNode>::resetSelected() {
    currentSelected = 0;
}

template <typename TypeNode> void NodeManipulate<TypeNode>::resetState() {
    currentState = 0;
}

template <typename TypeNode>
void NodeManipulate<TypeNode>::updatePos(SceneNode& mSceneGraph, sf::Time dt) {

    for (int i = 0; i < ptrSaver.size(); ++i) {
        int newID = NewIDHolder.takeID(i);
        // int oldID = OldIdHolder.takeID(i);

        float posx = start_x + (newID - 1) * add_x;
        float posy = start_y + add_y * Constants::posPadding_y;

        ptrSaver[i]->setPosNode({posx, posy});

        posx = start_x + newID * add_x;
        posy = start_y + add_y * Constants::posPadding_y;
        ptrSaver[i]->setEnd({posx, posy});

        if (newID == ptrSaver.size()) {
            ptrSaver[i]->setIsDrawArrow(false);
        } else
            ptrSaver[i]->setIsDrawArrow(true);
    }
}

template <typename TypeNode>
bool NodeManipulate<TypeNode>::attachNode(SceneNode& mSceneGraph, int id,
                                          std::string value,
                                          State::Context context) {
    if (ptrSaver.size() == Constants::MAXI::numOfNode)
        return false;

    if (!NewIDHolder.attachID(id))
        return false;

    TypeNode* tmp = new TypeNode(*context.fonts, *context.textures);
    std::unique_ptr<TypeNode> mNode(tmp);
    mSceneGraph.attachChild(std::move(mNode));
    tmp->setValue(value);
    ptrSaver.push_back(std::move(tmp));
    return true;
}

template <typename TypeNode>
bool NodeManipulate<TypeNode>::detachNode(SceneNode& mSceneGraph, int id) {
    if (ptrSaver.empty())
        return false;

    int pos = NewIDHolder.detachID(id);
    if (pos == -1)
        return false;

    mSceneGraph.detachChild(*ptrSaver[pos]);
    ptrSaver.erase(ptrSaver.end() - (ptrSaver.size() - pos));
    return true;
}

template <typename TypeNode>
auto NodeManipulate<TypeNode>::takeNumOfNode() -> int {
    return ptrSaver.size();
}

template <typename TypeNode>
auto NodeManipulate<TypeNode>::takeValueOfNode(int id) -> std::string {
    int pos = NewIDHolder.findID(id);
    return ptrSaver[pos]->getValue();
}

template <typename TypeNode>
bool NodeManipulate<TypeNode>::pushBackNode(SceneNode& mSceneGraph,
                                            std::string value,
                                            State::Context context) {
    return attachNode(mSceneGraph, takeNumOfNode() + 1, value, context);
}

template <typename TypeNode>
auto NodeManipulate<TypeNode>::searchingNode(SceneNode& mSceneGraph,
                                             sf::Time dt, std::string value)
    -> int {
    if (currentSelected == 0) {
        timeSinceLastUpdate = sf::Time::Zero;
        ++currentSelected;
    } else {
        timeSinceLastUpdate += dt;
        if (timeSinceLastUpdate > TimePerUpdate) {
            ++currentSelected;
            timeSinceLastUpdate -= TimePerUpdate;
        }
    }

    if (currentSelected > takeNumOfNode()) {
        resetSelected();
        resetState();
        return -1; // khong tim duoc
    }

    int pos = NewIDHolder.findID(currentSelected);
    resetColor(mSceneGraph);
    ptrSaver[pos]->setSelected();

    std::string currentValue = ptrSaver[pos]->getValue();
    if (currentValue == value) {
        resetSelected();
        resetState();
        return 1; // da tim duoc
    }

    return 0; // dang tim
}

template <typename TypeNode>
auto NodeManipulate<TypeNode>::accessingNode(SceneNode& mSceneGraph,
                                             sf::Time dt, int id) -> int {
    if (currentSelected == 0) {
        timeSinceLastUpdate = sf::Time::Zero;
        ++currentSelected;
    } else {
        timeSinceLastUpdate += dt;
        if (timeSinceLastUpdate > TimePerUpdate) {
            ++currentSelected;
            timeSinceLastUpdate -= TimePerUpdate;
        }
    }

    if (currentSelected > takeNumOfNode()) {
        resetSelected();
        resetState();
        return -1; // so can tim out of range
    }

    int pos = NewIDHolder.findID(currentSelected);
    resetColor(mSceneGraph);
    ptrSaver[pos]->setSelected();

    if (id == currentSelected) {
        resetSelected();
        resetState();
        return 1; // da access xong
    }

    return 0; // dang access
}

template <typename TypeNode>
auto NodeManipulate<TypeNode>::takeCurrentState() -> int {
    return currentState;
}

template <typename TypeNode> void NodeManipulate<TypeNode>::setIsSearching() {
    currentState = 1;
}

template <typename TypeNode> void NodeManipulate<TypeNode>::setIsAccessing() {
    currentState = -1;
}