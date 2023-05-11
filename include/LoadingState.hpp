// #pragma once
// #include "State.hpp"
// #include "ParallelTask.hpp"
// #include "TextureManipulate.hpp"

// const std::string Loading_text = "Loading Resource...";
// const float yShiftText = 50.f;
// const float yShiftBar = 40.f;

// class LoadingState : public State {
//     public:
//         LoadingState(StateStack &stack, Context context);

//         virtual void draw();
//         virtual bool update(sf::Time elapsedTime);
//         virtual bool handleEvent(const sf::Event &event);

//         void setComplete(float percent); // change the fill of the Bar 
//     private:
//         sf::Text				mLoadingText;
//         sf::RectangleShape		mProgressBarBackground;
//         sf::RectangleShape		mProgressBar;
//         ParallelTask			mLoadingTask;
// };