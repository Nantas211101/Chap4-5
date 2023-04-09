#include "../include/LoadingState.hpp"

LoadingState::LoadingState(StateStack &stack, Context context):
    State(stack, context){
        sf::RenderWindow &window = *getContext().window;
        sf::Font &font = context.fonts->get(Fonts::Main);
        
}