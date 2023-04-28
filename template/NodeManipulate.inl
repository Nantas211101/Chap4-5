#include "Constants.hpp"
#include "NodeManipulate.hpp"

#include <memory>

template <typename TypeNode>
void NodeManipulate<TypeNode>::init(SceneNode& mSceneGraph, int n,
                                    State::Context context) {
    IDHolder.init(n);
    for (int i = 0; i < n; ++i) {
        TypeNode* tmp = new TypeNode(*context.fonts, *context.textures);
        std::unique_ptr<TypeNode> mNode(tmp);
        mSceneGraph.attachChild(std::move(mNode));
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
void NodeManipulate<TypeNode>::setPos(SceneNode& mSceneGraph) {

    for (int i = 0; i < ptrSaver.size(); ++i) {
        int id = IDHolder.takeID(i);

        float posx = start_x + (id - 1) * add_x;
        float posy = start_y + add_y * Constants::posPadding_y;
        ptrSaver[i]->setPosNode({posx, posy});

        posx = start_x + id * add_x;
        posy = start_y + add_y * Constants::posPadding_y;
        ptrSaver[i]->setEnd({posx, posy});

        if (i == ptrSaver.size() - 1)
            ptrSaver[i]->setIsDrawArrow(false);
    }
}
