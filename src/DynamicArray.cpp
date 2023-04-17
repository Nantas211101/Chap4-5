#include "../include/DynamicArray.hpp"

DynamicArray::DynamicArray(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mGUIContainer(){
        sf::Texture &texture = context.textures->get(Textures::WhiteBackground);
        mBackgroundSprite.setTexture(texture);

        // set Insert button
        auto insertButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        insertButton->setPosition(100, 100);
        insertButton->setText("Insert");
        insertButton->setCallback([this] (){
            //nothing here now
        });

        // set Delete button
        auto deleteButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        deleteButton->setPosition(100, 150);
        deleteButton->setText("delete");
        deleteButton->setCallback([this] (){
            //nothing here now
        });

        // set Back Button
        auto backButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        backButton->setPosition(100, 200);
        backButton->setText("Back");
        backButton->setCallback([this] (){
            requestStackPop();
            requestStackPush(States::Menu);
        });
        
        mGUIContainer.pack(insertButton);
        mGUIContainer.pack(deleteButton);
        mGUIContainer.pack(backButton);
}

void DynamicArray::draw(){
    sf::RenderWindow &window = *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool DynamicArray::update(sf::Time){
    //right now there is nothing in here
    return true;
}

bool DynamicArray::handleEvent(const sf::Event &event){
    // mGUIContainer.handleEvent(event);
    handleRealTimeInput();
    return false;
}

bool DynamicArray::handleRealTimeInput(){
    sf::RenderWindow &window = *getContext().window;
    mGUIContainer.handleRealTimeInput(window);
    return false;
}