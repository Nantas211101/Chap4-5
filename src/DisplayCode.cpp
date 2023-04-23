#include "../include/DisplayCode.hpp"

DisplayCode::DisplayCode(const sf::RenderWindow &window, int n, int size, int x, int y):
    mNumberOfLine(n),
    mSizeOfText(size),
    mBound(x, y),
    mTextChild(),
    mRecChild(){
        auto winBound = window.getSize();
        
        sf::RectangleShape rec(mBound);
        rec.setFillColor(sf::Color::Blue);

}



