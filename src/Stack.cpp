#include "Stack.hpp"
#include "FileReader.hpp"
#include "NodesSaverIdentifiers.hpp"
#include "StringConvert.hpp"

const std::string Name = "Stack";

Stack::Stack(StateStack& stack, Context context)
    : State(stack, context),
      mBackgroundSprite(),
      mGUIContainer(),
      mDisplayer(*context.window, 5, textSize, add_x * 2, add_y,
                 context.fonts->get(Fonts::Main)),
      mSceneGraph(),
      randomHolder(),
      isSearching(false),
      usingData1("") {
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
        if (nodeSaver.takeCurrentState() != NodesState::nothing)
            return;

        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        int cntx = 0;

        auto ManuallyAction = ([this, context, cnty]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
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
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;

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

        auto RandomAction = ([this, context]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;

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
        if (nodeSaver.takeCurrentState() != NodesState::nothing)
            return;

        auto action = ([this]() {
            // nothing here now
        });

        resetButton(NumInitButton);

        auto MiddleAction = ([this, context, cnty]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
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
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            resetButton(NumInitButton + 1);
            data.clear();

            auto tmp = ([]() {});
            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            data.push_back("");
            setLabel(context, start_x + 2 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Value",
                     textSize);

            auto activeAction = ([this, context] {
                resetButton(NumInitButton + 4, false);
                if (checkError(inputID::Val, 0))
                    pushNode(context);
            });

            setStateButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "Go", activeAction);
        });

        auto ErrorAction = ([this, context]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
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
        if (nodeSaver.takeCurrentState() != NodesState::nothing)
            return;

        auto action = ([this, context]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            resetButton(NumInitButton + 3);
            if (!nodeSaver.detachNode(mSceneGraph, nodeSaver.takeNumOfNode()))
                printedError(context, Constants::outOfSizeError);
            // nothing here now
        });

        resetButton(NumInitButton);

        auto MiddleAction = ([this, context, cnty]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
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
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            resetButton(NumInitButton + 3);

            printedError(context, errorMessage + Name);
        });

        auto ClearAction = ([this]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            nodeSaver.reset(mSceneGraph);
        });

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
        if (nodeSaver.takeCurrentState() != NodesState::nothing)
            return;
        resetButton(NumInitButton);
        data.clear();

        auto tmp = ([this]() {
            // nothing here now
        });

        int cntx = 0;

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", tmp);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        data.push_back("");
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "At position", textSize);

        setInputButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "", tmp);
        InputPosition.push_back(mGUIContainer.takeSize() - 1);
        data.push_back("");
        setLabel(context, start_x + (cntx)*add_x + add_x / 2,
                 start_y + cnty * add_y - add_y / 2, "With value", textSize);

        auto activeAction([this, context]() {
            resetButton(NumInitButton + 5, false);
            if (checkError(inputID::Pos, 0) && checkError(inputID::Val, 1)) {
                nodeSaver.setIsUpdating();
                usingData1 = "";
                usingData2 = "";
            }
        });
        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Go", activeAction);
    });

    // Set Search Button
    ++cnty;
    auto searchButton =
        std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    searchButton->setPosition(start_x, start_y + cnty * add_y);
    searchButton->setText("Search");
    searchButton->setToggle(true);
    searchButton->setCallback([this, context, cnty]() {
        if (nodeSaver.takeCurrentState() != NodesState::nothing)
            return;

        auto action = ([this]() {

        });

        resetButton(NumInitButton);

        int cntx = 0;

        // Accessing

        auto accessAction = ([this, context, cnty]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            resetButton(NumInitButton + 2);
            data.clear();

            auto tmp = ([]() {});
            setInputButton(context, start_x + 1 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            data.push_back("");
            setLabel(context, start_x + 3 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Position",
                     textSize);

            auto activeAction = ([this, context] {
                resetButton(NumInitButton + 5, false);
                if (checkError(inputID::Pos, 0)) {
                    nodeSaver.setIsAccessing();
                    usingData1 = "";
                }
            });

            setStateButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "Go", activeAction);
        });

        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Accessing", accessAction);

        // Searching

        auto searchAction([this, context, cnty]() {
            if (nodeSaver.takeCurrentState() != NodesState::nothing)
                return;
            resetButton(NumInitButton + 2);
            data.clear();

            auto tmp = ([]() {});
            setInputButton(context, start_x + 2 * add_x,
                           start_y + (cnty + 1) * add_y, "", tmp);
            InputPosition.push_back(mGUIContainer.takeSize() - 1);
            data.push_back("");
            setLabel(context, start_x + 3 * add_x + add_x / 2,
                     start_y + (cnty + 1) * add_y - add_y / 2, "Value",
                     textSize);

            auto activeAction = ([this, context]() {
                resetButton(NumInitButton + 5, false);
                if(checkError(inputID::Val, 0)){
                    nodeSaver.setIsSearching();
                    usingData1 = "";
                }
            });

            setStateButton(context, start_x + 3 * add_x,
                           start_y + (cnty + 1) * add_y, "Go", activeAction);
        });

        setStateButton(context, start_x + (++cntx) * add_x,
                       start_y + cnty * add_y, "Searching", searchAction);
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
    NodesState::ID curState = nodeSaver.takeCurrentState();
    // -1: isAccess
    // 1: isSearching
    if (curState != NodesState::nothing) {

        if (curState == NodesState::isSearching) {
            searchingNode(dt);
        }

        if (curState == NodesState::isAccesing) {
            accessingNode(dt);
        }

        if (curState == NodesState::isUpdating) {
            updatingNode(dt);
        }
    }
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

void Stack::resetButton(int size, bool isResetInputButton) {
    while (mGUIContainer.isOutOfSize(size))
        mGUIContainer.depackend();
    nodeSaver.resetColor(mSceneGraph);
    if (isResetInputButton)
        InputPosition.clear();
}

void Stack::printedError(Context context, const std::string& text,
                         int padding) {
    sf::Vector2f pos = context.window->getView().getCenter();
    setLabel(context, pos.x, pos.y + (padding)*add_y, text, textSize * 2);
}

bool Stack::checkError(inputID::ID kind, int p) {
    if (kind == inputID::Pos) {

        if (data[p] == "") {
            printedError(getContext(), "You did not input the position");
            return false;
        }

        if (!isContain(data[p], Constants::MINI::numOfNode,
                       Constants::MAXI::numOfNode)) {
            printedError(getContext(),
                         "The position (number) should in [" +
                             std::to_string(Constants::MINI::numOfNode) + ", " +
                             std::to_string(Constants::MAXI::numOfNode) + "]");
            return false;
        }
    }

    if (kind == inputID::Val) {

        if (data[p] == "") {
            printedError(getContext(), "You did not input the value");
            return false;
        }

        if (!isContain(data[p], Constants::MINI::valueOfNode,
                       Constants::MAXI::valueOfNode)) {
            printedError(
                getContext(),
                "The value should in [" +
                    std::to_string(Constants::MINI::valueOfNode) + ", " +
                    std::to_string(Constants::MAXI::valueOfNode) + "]");
            return false;
        }
    }

    return true;
}

void Stack::pushNode(Context context) {
    if (!nodeSaver.pushBackNode(mSceneGraph, data[0], context))
        printedError(context, Constants::outOfSizeError);
}

void Stack::searchingNode(sf::Time dt) {
    if (usingData1 == "")
        usingData1 = data[0];
    std::string value = usingData1;

    ActionState::ID state = nodeSaver.searchingNode(mSceneGraph, dt, value);

    if (state == ActionState::DoneFalse) {
        printedError(getContext(), "Can not find");
    }

    if (state == ActionState::DoneTrue) {
        printedError(getContext(), "We find it");
    }
}

void Stack::accessingNode(sf::Time dt) {
    if (usingData1 == "")
        usingData1 = data[0];
    int id = toNum(usingData1);

    ActionState::ID state = nodeSaver.accessingNode(mSceneGraph, dt, id);

    if (state == ActionState::DoneFalse) {
        printedError(getContext(), "Position out of data");
    }

    if (state == ActionState::DoneTrue) {
        std::string number = nodeSaver.takeValueOfNode(id);
        printedError(getContext(), "We find it with value is: " + number);
    }
}

void Stack::updatingNode(sf::Time dt) {
    if (usingData1 == "") {
        usingData1 = data[0];
        usingData2 = data[1];
    }
    int id = toNum(usingData1);
    std::string value = usingData2;

    ActionState::ID state = nodeSaver.updatingNode(mSceneGraph, dt, id, value);

    if (state == ActionState::DoneFalse) {
        printedError(getContext(), "Position out of data");
    }

    if (state == ActionState::DoneTrue) {
        printedError(getContext(), "Update successfully");
    }
}