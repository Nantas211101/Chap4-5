#include "../include/GUI_SpeedButton.hpp"

namespace GUI{

SpeedButton::SpeedButton(const FontHolder &fonts, const TextureHolder &textures):
    mCallback(),
    mNormalTexture(textures.get(Textures::ButtonNormal)),
    mSelectedTexture(textures.get(Textures::ButtonSelected)),
    mPressedTexture(textures.get(Textures::ButtonPressed)),
    mSprite(),
    mText("", fonts.get(Fonts::Main), 16),
    mIsToggle(false),
    cntActive(0){
        mSprite.setTexture(mNormalTexture);
        sf::FloatRect bounds = mSprite.getLocalBounds();
        mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void SpeedButton::setCallback(Callback callback){
    mCallback = std::move(callback);
}

void SpeedButton::setText(const std::string &text){
    mText.setString(text);
    setCenterOrigin(mText);
}

void SpeedButton::setToggle(bool flag){
    mIsToggle = flag;
}

bool SpeedButton::isSelectable() const{
    return true;
}

void SpeedButton::select(){
    Component::select();
    mSprite.setTexture(mSelectedTexture);
}

void SpeedButton::deselect(){
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void SpeedButton::activate(){
    Component::activate();

    ++cntActive;
    cntActive %= 3;

    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if(mIsToggle){
        if(cntActive)
            mSprite.setTexture(mPressedTexture);
        switch (cntActive)
        {
            case cntActive == 0:
                mSpeedSprite.setTexture(hinh1); // hinh x1 speed
                break;
            
            case cntActive == 1:
                mSpeedSprite.setTexture(hinh2); // hinh x2 speed
                break;

            case cntActive == 2:
                mSpeedSprite.setTexture(hinh3); // hinh x3 speed;
                break;

            default:
                break;
        }
    }
    if(mCallback)
        mCallback();
    
    // If we are not a toggle then deactivate the button since we are just momentarily activated.
    if(!mIsToggle)
        deactivate();
}

void SpeedButton::deactivate(){
    Component::deactivate();

    if(mIsToggle && !cntActive){
        // reset the textures of the msprite after deactivate to make sure it at the right Texture
        if(isSelected())
            mSprite.setTexture(mSelectedTexture);
        else 
            mSprite.setTexture(mNormalTexture);
    }
}

void SpeedButton::handleEvent(const sf::Event &event){
}

bool SpeedButton::handleRealTimeInput(const sf::RenderWindow &window){
    sf::FloatRect bounds = takeLocalBounds();
    auto pos = sf::Mouse::getPosition(window);
    return contain(pos, bounds);
}

void SpeedButton::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mSpeedSprite, states);
    target.draw(mText, states);
}

auto SpeedButton::takeLocalBounds() -> sf::FloatRect{
    return mSprite.getLocalBounds();
}

bool SpeedButton::contain(sf::Vector2i mouse_pos, sf::FloatRect bounds){
    sf::Vector2f cur_pos = getPosition();
    bounds.left = cur_pos.x;
    bounds.top = cur_pos.y;
    return bounds.contains(sf::Vector2f(mouse_pos));
}

}