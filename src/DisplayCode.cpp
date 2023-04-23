#include "../include/DisplayCode.hpp"

DisplayCode::DisplayCode(sf::RenderWindow &window, int n, int size, int x, int y, sf::Font &font):
    mNumberOfLine(n),
    mSizeOfText(size),
    mFont(font),
    mBound(x, y),
    mTextChild(),
    mRecChild(){
        auto winBound = window.getSize();
        for(int i = 0; i < n; ++i){
            sf::RectangleShape rec(mBound);
            rec.setFillColor(sf::Color::Blue);
            rec.setOrigin(mBound / 2.f);
            rec.setPosition(winBound.x - mBound.x / 2, winBound.y - (mNumberOfLine - i) * mBound.y + mBound.y / 2);
            mRecChild.push_back(rec);
        }

}

void DisplayCode::draw(sf::RenderTarget &target){
    for(auto recChild : mRecChild)
        target.draw(recChild);
    for(auto textChild : mTextChild)
        target.draw(textChild);
}

void DisplayCode::addText(sf::Text text, float padding){
    text.setFillColor(sf::Color::White);

    sf::Vector2f pos = mRecChild[mTextChild.size()].getPosition();
    text.setPosition(pos.x - mBound.x / 2 + (mBound.x / 10) * padding, pos.y);

    mTextChild.push_back(text);
}

void DisplayCode::addText(const std::string tmp, float padding){
    sf::Text text(tmp, mFont, mSizeOfText);
    text.setFillColor(sf::Color::White);
    
    sf::Vector2f pos = mRecChild[mTextChild.size()].getPosition();
    text.setPosition(pos.x - mBound.x / 2 + (mBound.x / 10) * padding, pos.y);

    mTextChild.push_back(text);
    
}




