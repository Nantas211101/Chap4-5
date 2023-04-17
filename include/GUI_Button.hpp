#pragma once
#include <SFML/Graphics.hpp>
#include "GUI_Component.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureManipulate.hpp"

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace GUI{

class Button : public Component{
    public:
        typedef std::shared_ptr<Button> Ptr;
        typedef std::function<void()> Callback;

    public:
        Button(const FontHolder &fonts, const TextureHolder &textures);

        void setCallback(Callback callback);
        void setText(const std::string &text);
        void setToggle(bool flag);

        // selection
        virtual bool isSelectable() const;
        virtual void select();
        virtual void deselect();        
        
        // Activation
        virtual void activate();
        virtual void deactivate();

        virtual void handleEvent(sf::Event &event);
        // virtual void handleRealTimeInput();

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        Callback                mCallback;
        const sf::Texture&      mNormalTexture;
        const sf::Texture&      mSelectedTexture;
        const sf::Texture&      mPressedTexture;
        sf::Sprite              mSprite;
        sf::Text                mText;
        bool                    mIsToggle;
};

}