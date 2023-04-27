#include "SettingsState.hpp"

SettingsState::SettingsState(StateStack &stack, Context context):
    State(stack, context),
    mGUIContainer(){
        mBackgroundSprite.setTexture(context.textures->get(Textures::Menu));

        // Build key binding buttons and labels
        addButtonLabel(Player::MoveLeft, 150.f, "Move Left", context);
        addButtonLabel(Player::MoveRight, 200.f, "Move Right", context);
        addButtonLabel(Player::MoveUp, 250.f, "Move up", context);
        addButtonLabel(Player::MoveDown, 300.f, "Move Down", context);

        updateLabels();

        // set the backButton
        // we set it in the setting state because only setting state have it
        auto backButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
        backButton->setPosition(80.f, 375.f);
        backButton->setText("Back");
        backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));

        mGUIContainer.pack(backButton);
}

void SettingsState::draw(){
    sf::RenderWindow &window = *getContext().window;
    
    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time elapsedTime){
    return false;
}

bool SettingsState::handleEvent(const sf::Event &event){
    bool isKeyBingding = false;
    for(std::size_t action = 0; action < Player::CountMove; ++action){

        if(mBindingButtons[action]->isActive()){
            isKeyBingding = true;

            if(event.type == sf::Event::KeyReleased){
                getContext().player->assignKey(
                    static_cast<Player::Action>(action), event.key.code);
                mBindingButtons[action]->deactivate();
            }
            break;
        }
    }

    if(isKeyBingding)
        updateLabels();
    else {
        // mGUIContainer.handleEvent(event);
        sf::RenderWindow &window = *getContext().window;
        mGUIContainer.handleRealTimeInput(window);
    }
    return false; // Settingsstate quite the same as pause state
}

void SettingsState::updateLabels(){ // make sure the labels are writing out the correct name for the key
    Player &player = *getContext().player;

    for(std::size_t i = 0; i < Player::CountMove; ++i){
        sf::Keyboard::Key key = player.getAssignedKey(static_cast<Player::Action>(i)); // take the Keyboard ith;
        mBindingLabels[i]->setText(toString(key));
    }
}

// Additional function

void SettingsState::addButtonLabel(Player::Action action, float y, const std::string &text, Context context){
    mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    mBindingButtons[action]->setPosition(80.f, y);
    mBindingButtons[action]->setText(text);
    mBindingButtons[action]->setToggle(true);

    mBindingLabels[action] = std::make_shared<GUI::Label>("", *context.fonts, textSize);
    mBindingLabels[action]->setPosition(300.f, y + 15.f);

    mGUIContainer.pack(mBindingButtons[action]);
    mGUIContainer.pack(mBindingLabels[action]);
}