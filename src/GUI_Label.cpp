#include "../include/GUI_Label.hpp"

namespace GUI{

Label::Label(const std::string &text, const FontHolder &fonts):
    mText(text, fonts.get(Fonts::Main), 16){

}

// Label also cannot select
auto GUI::Label::isSelectable() -> bool const{
    return false;
}

void GUI::Label::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(mText, states);
}

void GUI::Label::setText(const std::string &text){
    mText.setString(text);
}

}