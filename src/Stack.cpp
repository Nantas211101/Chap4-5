#include "../include/Stack.hpp"

Stack::Stack(StateStack &stack, Context context):
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
        insertButton->setCallback([this, context] (){
            auto action = ([this] (){
                //nohing here now
            });
            setStateButton(context, 300, 50, "to First", action);
            setStateButton(context, 300, 100, "to Last", action);
            setStateButton(context, 300, 150, "to Middle", action);
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

void Stack::draw(){
    sf::RenderWindow &window = *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool Stack::update(sf::Time dt){
    //right now there is nothing in here
    return true;
}

bool Stack::handleEvent(const sf::Event &event){
    // mGUIContainer.handleEvent(event);
    handleRealTimeInput();
    return false;
}

bool Stack::handleRealTimeInput(){
    sf::RenderWindow &window = *getContext().window;
    mGUIContainer.handleRealTimeInput(window);
    return false;
}

void Stack::setStateButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action){
    auto stateButton = std::make_shared<GUI::Button>(
        *context.fonts, *context.textures);
    stateButton->setPosition(posx, posy);
    stateButton->setText(text);
    auto tmp = action;
    stateButton->setCallback(tmp);
    mGUIContainer.pack(stateButton);
}