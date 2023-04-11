#pragma once
#include <SFML/Graphics.hpp>
#include "GUI_Component.hpp"

#include <memory>
#include <vector>

namespace GUI{

class Container : public Component{
    public:
        typedef std::shared_ptr<Container> Ptr;

    public:
        Container();
        
        void pack(Component::Ptr component);
        virtual bool isSelectable() const;
        virtual void handleEvent(const sf::Event &event);

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        auto hasSelection() -> bool const;
        void select(std::size_t index);
        void selectNext();
        void selectPrev();

    private:
        std::vector<Component::Ptr> mChildren;
        int mSeletedChild;
};

}