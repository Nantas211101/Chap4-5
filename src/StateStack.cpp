#include "../include/StateStack.hpp"

template <typename T>
void StateStack::registerState(States::ID stateID){
    mFactories[stateID] = [this] (){
        return State::S_Ptr(new T(*this, mContext));
    }
}

void StateStack::createState(States::ID stateID) -> State::S_Ptr{
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());
    return found->second();
}

// Input

void StateStack::handleEvent(const sf::Event& event){
    for(auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr){
        if(!(*itr)->handleEvent(event))
            return;
    }

    applyPendingChanges();
}

void StateStack::applyPendingChanges(){
    for(PendingChange change : mPendingList){
        switch(change.action){
            case Push:
                mStack.push_back(createState(change.stateID));
                break;
            
            case Pop:
                mStack.pop_back();
                break;
            
            case clear;
                mStack.clear();
                break;
        }
    }

    mPendingList.clear();
}

