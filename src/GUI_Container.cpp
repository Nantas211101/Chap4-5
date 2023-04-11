#include "../include/GUI_Container.hpp"

GUI::Container::Container():
    mChildren(),
    mSeletedChild(-1){

}

void GUI::Container::pack(Component::Ptr component){
    mChildren.push_back(component);
    if(!hasSelection() && component->isSelectable())
        select(mChildren.size() - 1);
}

void GUI::Container::handleEvent(const sf::Event &event){
    if(hasSelection() && mChildren[mSeletedChild] -> isActive()){
        mChildren[mSeletedChild]->handleEvent(event);
    }
    else if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up
        || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
            selectPrev();
        }
        else if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down
            ||  event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
            selectNext();
        }
        else if(event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space){
            if(hasSelection())
                mChildren[mSeletedChild]->activate();
        }
    }
}

// Container is not a selectable object
auto GUI::Container::isSelectable() -> bool const{
    return false;
}

auto GUI::Container::hasSelection() -> bool const{
    return mSeletedChild >= 0;
}

void GUI::Container::select(std::size_t index){
    if(mChildren[index]->isSelectable()){
        if(hasSelection())
            mChildren[mSeletedChild]->deselect();
        mChildren[index]->select();
        mSeletedChild = index;
    }
}

void GUI::Container::selectNext(){
    if(!hasSelection())
        return;
    // searching for the next component that may be selectable
    int next = mSeletedChild;
    // a little slow but code will be ez to read
    do{
        next = (next + 1);
        next %= mChildren.size(); // circular index
    }while(!mChildren[next]->isSelectable());
    // And finally select it
    select(next);
}

// quite the same selectNext();
void GUI::Container::selectPrev(){
    if(!hasSelection())
        return;
    int prev = mSeletedChild;
    do{
        prev = (prev - 1);
        prev = (prev + mChildren.size()) % mChildren.size();
    }while(!mChildren[prev]->isSelectable());
    select(prev);
}