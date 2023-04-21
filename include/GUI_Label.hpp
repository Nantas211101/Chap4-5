#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "GUI_Component.hpp"
#include "TextureManipulate.hpp"

#include <string>
#include <memory>

namespace GUI{

class Label: public Component{
    public: 
        typedef std::shared_ptr<Label> Ptr;

    public:
        Label(const std::string &text, const FontHolder &fonts);
        
        virtual bool isSelectable() const;
        void setText(const std::string &text);
        virtual void handleEvent(const sf::Event &event);
        virtual bool handleRealTimeInput(const sf::RenderWindow &window);
        virtual bool isSpeedButton();
        virtual bool isSpeedUp();

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;


    private:
        sf::Text mText;
};

}