#include "../include/GUI_InputButton.hpp"

namespace GUI{
    
InputButton::InputButton(const FontHolder &fonts, const TextureHolder &textures):
    mCallback(),
    mNormalTexture(textures.get(Textures::ButtonNormal)),
    mSelectedTexture(textures.get(Textures::ButtonSelected)),
    mPressedTexture(textures.get(Textures::ButtonPressed)),
    mSprite(),
    mText("", fonts.get(Fonts::Main), 16),
    mIsToggle(true){
        mSprite.setTexture(mNormalTexture);
        sf::FloatRect bounds = mSprite.getLocalBounds();
        mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void InputButton::setCallback(Callback callback){
    mCallback = std::move(callback);
}

void InputButton::setText(const std::string &text){
    mText.setString(text);
    setCenterOrigin(mText);
}

void InputButton::setToggle(bool flag){
    mIsToggle = flag;
}

auto InputButton::takeSaveText() -> std::string{
    return saveText;
}

bool InputButton::isSelectable() const{
    return true;
}

void InputButton::select(){
    Component::select();
    mSprite.setTexture(mSelectedTexture);
}

void InputButton::deselect(){
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void InputButton::activate(){
    Component::activate();
    
    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if(mIsToggle)
        mSprite.setTexture(mPressedTexture);

    if(mCallback)
        mCallback();
    
    // If we are not a toggle then deactivate the button since we are just momentarily activated.
    if(!mIsToggle)
        deactivate();
}

void InputButton::deactivate(){
    Component::deactivate();
    mText.setString("");
    if(mIsToggle){
        // reset the textures of the msprite after deactivate to make sure it at the right Texture
        if(isSelected())
            mSprite.setTexture(mSelectedTexture);
        else 
            mSprite.setTexture(mNormalTexture);
    }
}

void InputButton::handleEvent(const sf::Event &event){
    std::string tmpText = mText.getString(); 
    if(event.key.code == sf::Keyboard::BackSpace && !tmpText.empty()){
        tmpText.pop_back();
    }
    else if(event.type == sf::Event::TextEntered){
            tmpText.push_back(event.text.unicode);
    } 

    if(event.type == sf::Event::KeyPressed)
        if(event.key.code == sf::Keyboard::Return){
            saveText = tmpText;
            std::cout << saveText << "\n";
        }   
    mText.setString(tmpText);
    setCenterOrigin(mText);
}

bool InputButton::handleRealTimeInput(const sf::RenderWindow &window){
    sf::FloatRect bounds = takeLocalBounds();
    auto pos = sf::Mouse::getPosition(window);
    return contain(pos, bounds);
}

bool InputButton::isSpeedButton(){
    return false;
}

bool InputButton::isSpeedUp(){
    return false;
}

void InputButton::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}

auto InputButton::takeLocalBounds() -> sf::FloatRect{
    return mSprite.getLocalBounds();
}

bool InputButton::contain(sf::Vector2i mouse_pos, sf::FloatRect bounds){
    sf::Vector2f cur_pos = getPosition();
    bounds.left = cur_pos.x;
    bounds.top = cur_pos.y;
    return bounds.contains(sf::Vector2f(mouse_pos));
}

}