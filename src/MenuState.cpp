#include "../include/MenuState.hpp"

MenuState::MenuState(StateStack &stack, Context context):
    State(stack, context),
    mGUIContainer(){
        sf::Texture &texture = context.textures->get(Textures::Menu);
        mBackgroundSprite.setTexture(texture);
        
        // set Button play
        auto playButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        playButton->setPosition(OFFSET_X, OFFSET_Y);
        playButton->setText("Play");
        playButton->setCallback([this] (){
            requestStackPop();
            requestStackPush(States::Game);
        });

        // set Button Stack
        // auto stackButton = std::make_shared<GUI::Button>(
        //     *context.fonts, *context.textures);
        // stackButton->setPosition(100, 300);
        // stackButton->setText("Stack");
        // stackButton->setCallback([this] (){
        //     requestStackPop();
        //     requestStackPush(States::Stack);
        // });
        int cnt = 0;
        setStateButton(context, 0, ++cnt, "Stack", States::Stack);
        setStateButton(context, 0, ++cnt, "Queue", States::Queue);
        setStateButton(context, 0, ++cnt, "StaticArray", States::StaticArray);
        setStateButton(context, 0, ++cnt, "DynamicArray", States::DynamicArray);
        setStateButton(context, 0, ++cnt, "SinglyLL", States::SLL);
        setStateButton(context, 0, ++cnt, "DoublyLL", States::DLL);
        setStateButton(context, 0, ++cnt, "CircularLL", States::CLL);


        // Set Button setting
        auto settingsButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        settingsButton->setPosition(OFFSET_X, OFFSET_Y + y_add * (++cnt));
        settingsButton->setText("Setting");
        settingsButton->setCallback([this] (){
            requestStackPush(States::Settings);
        });

        // set Button exit
        auto exitButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        exitButton->setPosition(OFFSET_X, OFFSET_Y + y_add * (++cnt));
        exitButton->setText("Exit");
        exitButton->setCallback([this] (){
            requestStackPop();
        });

        mGUIContainer.pack(playButton);
        mGUIContainer.pack(settingsButton);
        mGUIContainer.pack(exitButton);  
        // mGUIContainer.pack(stackButton);
}

// Additional function
void MenuState::setStateButton(Context context, int x_times, int y_times, const std::string &text, States::ID id){
    auto stateButton = std::make_shared<GUI::Button>(
        *context.fonts, *context.textures);
    stateButton->setPosition(OFFSET_X + x_add * x_times, OFFSET_Y + y_add * y_times);
    stateButton->setText(text);
    stateButton->setCallback([this] (){
        requestStackPop();
        requestStackPush(id);
    })

    mGUIContainer.pack(stateButton);
}

void MenuState::draw(){
    sf::RenderWindow &window = *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);

}

bool MenuState::update(sf::Time){
    //right now there is nothing in here
    return true;
}

bool MenuState::handleEvent(const sf::Event &event){
    // mGUIContainer.handleEvent(event);
    handleRealTimeInput();
    return false;
}

bool MenuState::handleRealTimeInput(){
    sf::RenderWindow &window = *getContext().window;
    mGUIContainer.handleRealTimeInput(window);
    return false;
}
