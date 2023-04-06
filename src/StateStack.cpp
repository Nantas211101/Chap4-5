#include "../include/StateStack.hpp"

template <typename T>
void StateStack::registerState(States::ID stateID){
    mFactories[stateID] = [this] (){
        return State::S_Ptr(new T(*this, mContext));
    }
}