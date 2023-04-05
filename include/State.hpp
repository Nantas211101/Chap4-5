#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "StateStack.hpp"

class State{
    public:
        typedef std::unique_ptr<State> S_Ptr;
        struct Context {};
    
    public:
                        State(StateStack& stack, Context context);
        virtual         ~State();

        virtual void    draw() = 0;
        virtual bool    update(sf::Time dt) = 0;
        virtual bool    handleEvent(const sf::Event &event) = 0;

    protected:
        void requestStackPush(States::ID stateID);
        void requestStackPop();
        void requestStateClear();

        Context getContext() const;

    private:
        StateStack* mStack;
        Context mContext;
};