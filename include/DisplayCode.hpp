#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class DisplayCode{
    public:
        DisplayCode(int n, int size, int x, int y);

        // void draw(sf::RenderTarget &target);

    private:
        int mNumberOfLine;
        int mSizeOfText;
    //     sf::Vector2f mBound;
    //     std::vector<sf::Text> mTextChild;
    //     std::vector<sf::RectangleShape> mRecChild;
};