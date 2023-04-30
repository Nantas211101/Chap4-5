#include "Stack.hpp"
#include "FileReader.hpp"


const std::string Name = "Stack";

Stack::Stack(StateStack& stack, Context context)
    : State(stack, context),
      mBackgroundSprite(),
      mGUIContainer(),
      mDisplayer(*context.window, 5, textSize, add_x * 2, add_y,
                 context.fonts->get(Fonts::Main)),
      mSceneGraph(),
      randomHolder(){
    sf::Texture& texture = context.textures->get(Textures::WhiteBackground);
    mBackgroundSprite.setTexture(texture);

    int cnty = -1;
    // set Init button
    ++cnty;
    auto initButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    initButton->setPosition(start_x, start_y + cnty * add_y);
    initButton->setText("Init");
    initButton->setToggle(true);
    initButton->setCallback([this, context, cnty]() {
        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        int cntx = 0;

        auto ManuallyAction = ([this, context, cnty]() {
            resetButton(NumInitButton + 1);

            auto tmp = ([]() {

            });

            // Number of nodes
            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 2 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Number",
                     textSize);

            //

            // Value of a node
            setInputButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 3 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Value",
                     textSize);
        });

        auto FileAction = ([this, context]() {
            auto file_name = FileHolder.select();
            if (file_name.has_value()) {
                try {
                    data.clear();
                    nodeSaver.reset(mSceneGraph);
                    this->data = readIntegerFile(file_name.value());
                    nodeSaver.init(mSceneGraph, data, context);
                } catch (std::exception& e) {
                    // in lo
                    printedError(context, e.what());
                    data.clear();
                }
            }
        });

        auto RandomAction = ([this, context](){
            nodeSaver.reset(mSceneGraph);
            data = randomHolder.randListData();
            nodeSaver.init(mSceneGraph, data, context);
        });

        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Manually", ManuallyAction);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "File", FileAction);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Random", RandomAction);
    });

    // set Insert button
    ++cnty;
    auto insertButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    insertButton->setPosition(start_x, start_y + cnty * add_y);
    insertButton->setText("Insert");
    insertButton->setToggle(true);
    insertButton->setCallback([this, context, cnty]() {
        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        auto MiddleAction = ([this, context, cnty]() {
            resetButton(NumInitButton + 1);

            auto tmp = ([]() {

            });

            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 2 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "At position",
                     textSize);

            setInputButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 3 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "With value",
                     textSize);
        });

        auto ValueAction = ([this, context, cnty]() {
            resetButton(NumInitButton + 1);
            InputPosition.clear();
            data.clear();

            auto tmp = ([]() {});
            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            data.push_back("");
            setLabel(context, start_x + 2 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Value",
                     textSize);

            auto activeAction = ([this, context] { pushNode(context); });

            setStateButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "Go", activeAction);
        });

        auto ErrorAction = ([this, context]() {
            resetButton(NumInitButton + 3);
            printedError(context, errorMessage + Name);
        });

        int cntx = 0;
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Push", ValueAction);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "to Middle", ErrorAction);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "to First", ErrorAction);
    });

    // set Delete button
    ++cnty;
    auto deleteButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    deleteButton->setPosition(start_x, start_y + cnty * add_y);
    deleteButton->setText("Delete");
    deleteButton->setToggle(true);
    deleteButton->setCallback([this, context, cnty]() {
        auto action = ([this, context]() {
            resetButton(NumInitButton + 3);
            if (!nodeSaver.detachNode(mSceneGraph, nodeSaver.takeNumOfNode()))
                printedError(context, Constants::outOfSizeError);
            // nothing here now
        });

        resetButton(NumInitButton);

        auto MiddleAction = ([this, context, cnty]() {
            resetButton(NumInitButton + 1);

            auto tmp = ([]() {

            });

            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 2 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "At position",
                     textSize);

            setInputButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            setLabel(context, start_x + 3 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "With value",
                     textSize);
        });

        auto ErrorAction = ([this, context]() {
            resetButton(NumInitButton + 3);
            printedError(context, errorMessage + Name);
        });

        auto ClearAction = ([this]() { nodeSaver.reset(mSceneGraph); });

        int cntx = 0;
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Pop", action);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "at First", ErrorAction);
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Clear", ClearAction);
    });

    // set Update Button
    ++cnty;
    auto updateButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    updateButton->setPosition(start_x, start_y + cnty * add_y);
    updateButton->setText("Update");
    updateButton->setToggle(true);
    updateButton->setCallback([this, context, cnty]() {
        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        int cntx = 0;

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", action);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "At position", textSize);

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", action);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "With value", textSize);

        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Updating", action);
    });

    // Set Search Button
    ++cnty;
    auto searchButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    searchButton->setPosition(start_x, start_y + cnty * add_y);
    searchButton->setText("Search");
    searchButton->setToggle(true);
    searchButton->setCallback([this, context, cnty]() {
        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        int cntx = 0;

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", action);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "By Position", textSize);

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", action);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "By Value", textSize);

        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Searching", action);
    });

    // Set Speed Button
    auto speedButton =
        std::make_shared<GUI::SpeedButton>(*context.fonts, *context.textures);
    speedButton->setPosition(11 * start_x, start_y);
    speedButton->setText("x1 speed");
    speedButton->setToggle(true);
    speedButton->setCallback([this]() {
        // auto action = ([this](){
        //     // nothing
        // });
    });

    // set Back Button
    ++cnty;
    auto backButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    backButton->setPosition(start_x, start_y + cnty * add_y);
    backButton->setText("Back");
    backButton->setToggle(true);
    backButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(States::Menu);
    });

    nodeSaver.init(mSceneGraph, data, context);

    mGUIContainer.pack(initButton);
    mGUIContainer.pack(insertButton);
    mGUIContainer.pack(deleteButton);
    mGUIContainer.pack(updateButton);
    mGUIContainer.pack(searchButton);
    mGUIContainer.pack(backButton);
    mGUIContainer.pack(speedButton);
}

void Stack::draw() {
    sf::RenderWindow& window =
        *getContext().window; // return dereference of context.window
    window.setView(window.getDefaultView());

    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
    window.draw(mSceneGraph);
    mDisplayer.draw(window);
}

bool Stack::update(sf::Time dt) {
    nodeSaver.updatePos(mSceneGraph, dt);
    // right now there is nothing in here
    return true;
}

bool Stack::handleEvent(const sf::Event& event) {
    mGUIContainer.handleEvent(event);
    // take the data from input button
    for (int i = 0; i < std::min(data.size(), InputPosition.size()); ++i)
        data[i] = mGUIContainer.takeOutString(InputPosition[i]);
    handleRealTimeInput();
    return false;
}

bool Stack::handleRealTimeInput() {
    sf::RenderWindow& window = *getContext().window;
    mGUIContainer.handleRealTimeInput(window);
    return false;
}

void Stack::setStateButton(Context context, int posx, int posy,
                           const std::string& text,
                           std::function<void()> action) {
    auto stateButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    stateButton->setPosition(posx, posy);
    stateButton->setText(text);
    stateButton->setToggle(true);
    auto tmp = action;
    stateButton->setCallback(tmp);
    mGUIContainer.pack(stateButton);
}

void Stack::setLabel(Context context, int posx, int posy,
                     const std::string& text, int sizeoftext) {
    auto Label = std::make_shared<GUI::Label>("", *context.fonts, sizeoftext);
    Label->setPosition(posx, posy);
    Label->setText(text);
    mGUIContainer.pack(Label);
}

void Stack::setInputButton(Context context, int posx, int posy,
                           const std::string& text,
                           std::function<void()> action) {
    auto stateButton =
        std::make_shared<GUI::InputButton>(*context.fonts, *context.textures);
    stateButton->setPosition(posx, posy);
    stateButton->setText(text);
    stateButton->setToggle(true);
    auto tmp = action;
    stateButton->setCallback(tmp);
    mGUIContainer.pack(stateButton);
}

void Stack::resetButton(int size) {
    while (mGUIContainer.isOutOfSize(size))
        mGUIContainer.depackend();
    InputPosition.clear();
}

void Stack::printedError(Context context, const std::string& text,
                         int padding) {
    sf::Vector2f pos = context.window->getView().getCenter();
    setLabel(context, pos.x, pos.y + (padding)*add_y, text, textSize * 2);
}

void Stack::pushNode(Context context) {
    if (!nodeSaver.pushBackNode(mSceneGraph, data[0], context))
        printedError(context, Constants::outOfSizeError);
}