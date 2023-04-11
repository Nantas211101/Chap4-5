#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "GUI_Component.hpp"

namespace GUI{
class Label: public Component{
    public:
        Label(const std::string &text, const FontHolder &fonts);
        
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    private:
        auto isSelectable() -> bool const;
        void setText(const std::string &text);


    private:
        sf::Text mText;
};
}