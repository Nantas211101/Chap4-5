#pragma once
#include <SFML/Graphics.hpp>
#include "GUI_Component.hpp"

namespace GUI{
class Container : public Component{
    public:
        Container();
        void pack(Component::Ptr component);
    private:
        std::vector<Ptr> mChildren;
};
}