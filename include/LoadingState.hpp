#pragma once
#include "State.hpp"
#include "ParallelTask.hpp"
class LoadingState : public State {
    public:
        LoadingState(StateStack &stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time elapsedTime);
        virtual bool handleEvent(const sf::Event &event);

    private:
        sf::Text				mLoadingText;
        sf::RectangleShape		mProgressBarBackground;
        sf::RectangleShape		mProgressBar;
        ParallelTask			mLoadingTask;
};