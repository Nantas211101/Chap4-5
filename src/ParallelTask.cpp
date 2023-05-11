// #include "ParallelTask.hpp"

// ParallelTask::ParallelTask():
//     mThread(&ParallelTask::runTask, this),
//     mFinished(false),
//     mElapsedTime(),
//     mMutex(){

// }

// void ParallelTask::execute(){
//     mFinished = false;
//     mElapsedTime.restart();
// }

// auto ParallelTask::isFinished() -> bool{
//     sf::Lock lock(mMutex);
//     return mFinished;
// }

// auto ParallelTask::getPercentComplete() -> float{
//     sf::Lock lock(mMutex);
//     return mElapsedTime.getElapsedTime().asSeconds() / waitTime;
// }

// void ParallelTask::runTask(){
//     // Dummy Task wait for 5 second
//     bool ended = false;
//     while(!ended){
//         sf::Lock lock(mMutex); // Protect the clock;
//         if(mElapsedTime.getElapsedTime().asSeconds() >= waitTime)
//             ended = true;
//     }

//     {
//         // protect the mFinished
//         sf::Lock lock(mMutex);
//         mFinished = true;
//         // the bracket here is the scope of the sf::Lock so that if it go out the scope
//         // it will release the mMutex
//     }

// }