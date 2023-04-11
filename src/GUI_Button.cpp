#include "../include/GUI_Button.hpp"

namespace GUI{

Button::Button(const FontHolder &fonts, const TextureHolder &textures):
    mCallback(),
    {
        mSprite.setTexture(mNormalTexture);
        mText.setPosition(sf::Vector2f(mNormalTexture.get() / 2u));
}

bool GUI::Button::isSelectable() const{
    return true;
}

void GUI::Button::select(){
    Component::select();
    mSprite.setTexture(mSelectedTexture);
}

void GUI::Button::deselect(){
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void GUI::Button::activate(){
    Component::activate();
    if(mIsToggle)
        mSprite.setTexture(mPressedTexture);
    if(mCallback)
        mCallback();
    if(!mIsToggle)
        deactivate();
}

void GUI::Button::deactivate(){
    Component::deactivate();
    if(mIsToggle){
        if(isSelected())
            mSprite.setTexture(mSelectedTexture);
        else 
            mSprite.setTexture(mNormalTexture);
    }
}

}