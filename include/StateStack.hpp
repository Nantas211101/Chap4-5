#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "State.hpp"
#include <assert.h>

class StateStack : private sf::NonCopyable{
    public:
        enum Action{
            Push,
            Pop,
            Clear,
        };
    
    public:
        explicit StateStack(State::Context context);

        template <typename T>
        void registerState(States::ID stateID);
        
        void update(sf::Time dt);
        void draw();
        void handleEvent(const sf::Event *event);

        // State manipulating with stack
        void pushState(States::ID stateID);
        void popState();
        void clearStates();
        bool isEmpty() const;

    private:
        auto createState(States::ID stateID) -> State::S_Ptr;
        void applyPendingChanges();

    private:
        struct PendingChange{
            Action      action;
            States::ID  stateID;
        };

    private:
        std::vector<State::S_Ptr>       mStack; // Stack using the vector :)))
        std::vector<PendingChange>      mPendingList;
        State::Context                  mContext;
        std::map<States::ID, std::function<State::Ptr()>>    mFactories;
};