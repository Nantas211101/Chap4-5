#include "../include/DynamicArray.hpp"

DynamicArray::DynamicArray(StateStack &stack, Context context):
    State(stack, context),
    mBackgroundSprite(),
    mGUIContainer(){
        sf::Texture &texture = context.textures->get(Textures::WhiteBackground);
        mBackgroundSprite.setTexture(texture);

        int cnty = -1;

        // set Init button
        ++cnty;
        auto initButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        initButton->setPosition(start_x, start_y + cnty * add_y);
        initButton->setText("Init");
        initButton->setToggle(true);
        initButton->setCallback([this, context, cnty] (){
            auto action = ([this](){
                // nothing here now
            });

            while(mGUIContainer.isOutOfSize(6))
                mGUIContainer.depackend();

            int cntx = 0;
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "Manually", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "File", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "Random", action);

        });

        // set Insert button
        ++cnty;
        auto insertButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        insertButton->setPosition(start_x, start_y + cnty * add_y);
        insertButton->setText("Insert");
        insertButton->setToggle(true);
        insertButton->setCallback([this, context, cnty] (){
            auto action = ([this](){
                // nothing here now
            });

            while(mGUIContainer.isOutOfSize(6))
                mGUIContainer.depackend();

            int cntx = 0;
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "to First", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "to Last", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "to Middle", action);

        });

        // set Delete button
        ++cnty;
        auto deleteButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        deleteButton->setPosition(start_x, start_y + cnty * add_y);
        deleteButton->setText("Delete");
        deleteButton->setToggle(true);
        deleteButton->setCallback([this, context, cnty] (){
            auto action = ([this](){
                // nothing here now
            });

            while(mGUIContainer.isOutOfSize(6))
                mGUIContainer.depackend();

            int cntx = 0;
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "at First", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "at Last", action);
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "at Middle", action);

        });

        // set Update Button
        ++cnty;
        auto updateButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        updateButton->setPosition(start_x, start_y + cnty * add_y);
        updateButton->setText("Update");
        updateButton->setToggle(true);
        updateButton->setCallback([this, context, cnty] (){
            auto action = ([this](){
                // nothing here now
            });

            while(mGUIContainer.isOutOfSize(6))
                mGUIContainer.depackend();

            int cntx = 0;

            setInputButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "", action);
            setLabel(context, start_x + (cntx) * add_x + add_x / 2, start_y + cnty * add_y - add_y / 2, "At position");

            setInputButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "", action);
            setLabel(context, start_x + (cntx) * add_x + add_x / 2, start_y + cnty * add_y - add_y / 2, "With value");

            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "Updating", action);

        });

        // Set Search Button
        ++cnty;
        auto searchButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        searchButton->setPosition(start_x, start_y + cnty * add_y);
        searchButton->setText("Search");
        searchButton->setToggle(true);
        searchButton->setCallback([this, context, cnty] (){
            auto action = ([this](){
                // nothing here now
            });

            while(mGUIContainer.isOutOfSize(6))
                mGUIContainer.depackend();

            int cntx = 0;
            
            setInputButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "", action);
            setLabel(context, start_x + (cntx) * add_x + add_x / 2, start_y + cnty * add_y - add_y / 2, "By Position");
            
            setInputButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "", action);
            setLabel(context, start_x + (cntx) * add_x + add_x / 2, start_y + cnty * add_y - add_y / 2, "By Value");
            
            setStateButton(context, start_x + (++cntx) * add_x, start_y + cnty * add_y, "Searching", action);

        });

        // set Back Button
        ++cnty;
        auto backButton = std::make_shared<GUI::Button>(
            *context.fonts, *context.textures);
        backButton->setPosition(start_x, start_y + cnty * add_y);
        backButton->setText("Back");
        backButton->setToggle(true);
        backButton->setCallback([this] (){
            requestStackPop();
            requestStackPush(States::Menu);
        });
        
        mGUIContainer.pack(initButton);
        mGUIContainer.pack(insertButton);
        mGUIContainer.pack(deleteButton);
        mGUIContainer.pack(updateButton);
        mGUIContainer.pack(searchButton);
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
    mGUIContainer.handleEvent(event);
    handleRealTimeInput();
    return false;
}

bool DynamicArray::handleRealTimeInput(){
    sf::RenderWindow &window = *getContext().window;
    mGUIContainer.handleRealTimeInput(window);
    return false;
}

void DynamicArray::setStateButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action){
    auto stateButton = std::make_shared<GUI::Button>(
        *context.fonts, *context.textures);
    stateButton->setPosition(posx, posy);
    stateButton->setText(text);
    stateButton->setToggle(true);
    auto tmp = action;
    stateButton->setCallback(tmp);
    mGUIContainer.pack(stateButton);
}

void DynamicArray::setLabel(Context context, int posx, int posy, const std::string &text){
    auto Label = std::make_shared<GUI::Label>(
        "", *context.fonts);
    Label->setPosition(posx, posy);
    Label->setText(text);
    mGUIContainer.pack(Label); 
}

void DynamicArray::setInputButton(Context context, int posx, int posy, const std::string &text, std::function<void()> action){
    auto stateButton = std::make_shared<GUI::InputButton>(
        *context.fonts, *context.textures);
    stateButton->setPosition(posx, posy);
    stateButton->setText(text);
    stateButton->setToggle(true);
    auto tmp = action;
    stateButton->setCallback(tmp);
    mGUIContainer.pack(stateButton);
}