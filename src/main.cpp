#include <SFML/Graphics.hpp>
#include "Application.hpp"

int main(){
    try{
        Application game;
        game.run();
    }
    catch (std::exception& e){
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}