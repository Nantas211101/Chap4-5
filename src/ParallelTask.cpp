#include "../include/ParallelTask.hpp"

ParallelTask::ParallelTask():
    mThread(),
    mFinished(),
    mElapsedTime(),
    mMutex(){

}

auto ParallelTask::isFinished() -> bool{
    sf::Lock lock(mMutex);
    return mFinished;
}

void ParallelTask::runTask(){
    // Dummy Task wait for 5 second
    bool ended = false;
    while(!ended){
        sf::Lock lock(mMutex); // Protect the clock;
        if(mElapsedTime.getElapsedTime().asSeconds() >= waitTime)
            ended = true;
    }

    {
        // protect the mFinished
        sf::Lock lock(mMutex);
        mFinished = true;
        // the bracket here is the scope of the sf::Lock so that if it go out the scope
        // it will release the mMutex
    }

}