#pragma once

#include <vector>
#include <memory>

template<typename TypeNode>
class NodeManipulate{
    
    public:
        void init(int n);

    private:
        std::vector<TypeNode*> ptrSaver;
}