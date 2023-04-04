#include "../include/CommandQueue.hpp"

void CommandQueue::push(const Command &command){
    mQueue.push(command);
}

auto CommandQueue::pop() -> Command{
    Command ans = mQueue.front();
    mQueue.pop();
}

bool CommandQueue::isEmpty() const{
    return mQueue.empty();
}