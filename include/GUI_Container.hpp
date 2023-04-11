#pragma once
#include <SFML/Graphics.hpp>
#include "GUI_Component.hpp"

namespace GUI{
class Container : public Component{
    public:
        Container();
        void pack(Component::Ptr component);
        void handleEvent(const sf::Event &event);
    private:
        auto isSelectable() -> bool const;
        auto hasSelection() -> bool const;
        void select(std::size_t index);
        void selectNext();
        void selectPrev();

    private:
        std::vector<Ptr> mChildren;
        int mSeletedChild;
};
}