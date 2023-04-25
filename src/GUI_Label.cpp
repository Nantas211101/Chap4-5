#include "../include/GUI_Label.hpp"

namespace GUI{

Label::Label(const std::string &text, const FontHolder &fonts, int sizeoftext):
    mText(text, fonts.get(Fonts::Main), sizeoftext){
}

// Label also cannot select
bool Label::isSelectable() const{
    return false;
}

void Label::handleEvent(const sf::Event &event){
    
}

bool Label::handleRealTimeInput(const sf::RenderWindow &window){
    return false;
}

bool Label::isSpeedButton(){
    return false;
}

bool Label::isSpeedUp(){
    return false;
}

std::string Label::takeSaveText(){
    return "";
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(mText, states);
}

void Label::setText(const std::string &text){
    mText.setString(text);
    mText.setFillColor(sf::Color::Blue);
    setCenterOrigin(mText);
}

}