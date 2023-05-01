#pragma once
#include "ArrowData.hpp"
#include "Constants.hpp"
#include "DisplayCode.hpp"
#include "GUI_Button.hpp"
#include "GUI_Container.hpp"
#include "GUI_FileSelector.hpp"
#include "GUI_InputButton.hpp"
#include "GUI_Label.hpp"
#include "GUI_SpeedButton.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "StackNode.hpp"
#include "State.hpp"
#include "NodeManipulate.hpp"
#include "Randomize.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class Stack : public State, Constants{
  public:
    Stack(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
    virtual bool handleRealTimeInput();

  private:
    void setStateButton(Context context, int posx, int posy,
                        const std::string& text, std::function<void()> action);
    void setLabel(Context context, int posx, int posy, const std::string& text,
                  int sizeoftext);
    void setInputButton(Context context, int posx, int posy,
                        const std::string& text, std::function<void()> action);
    void resetButton(int size, bool isResetInputButton = true);
    void printedError(Context context, const std::string& text, int padding = 0);
    
    void pushNode(Context context);
    void searchingNode(sf::Time dt);
    void accessingNode(sf::Time dt);

  private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
    GUI::FileSelector FileHolder;
    DisplayCode mDisplayer;
    std::vector<int> InputPosition;
    SceneNode mSceneGraph;
    std::vector<std::string> data;
    NodeManipulate<StackNode> nodeSaver;
    Randomize randomHolder;
    bool isSearching;
    std::string usingData;
};