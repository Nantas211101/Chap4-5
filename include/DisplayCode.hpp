// #pragma once
// #include <SFML/Graphics.hpp>

// #include <iostream>
// #include <vector>
// #include <string>

// class DisplayCode{
//     public:
//         DisplayCode(sf::RenderWindow &window, int n, int size, int x, int y, sf::Font &font);

//         void draw(sf::RenderTarget &target);
//         void addText(sf::Text text, float padding = 1);
//         void addText(const std::string text, float padding = 1);

//     private:
//         int mNumberOfLine;
//         int mSizeOfText;
//         sf::Font mFont;
//         sf::Vector2f mBound;
//         std::vector<sf::Text> mTextChild;
//         std::vector<sf::RectangleShape> mRecChild;
// };