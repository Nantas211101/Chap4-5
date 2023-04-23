#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

class DisplayCode{
    public:
        DisplayCode(const sf::RenderWindow &window, int n, int size, int x, int y);
    

    private:
        int mNumberOfLine;
        int mSizeOfText;
        sf::Vector2f mBound;
        std::vector<sf::Text> mTextChild;
        std::vector<sf::RectangleShape> mRecChild;
};