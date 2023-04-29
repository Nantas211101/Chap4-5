#include "Pos_ID.hpp"
#include "State.hpp"

Pos_ID::Pos_ID():
    size_n(){

}

bool Pos_ID::init(int n){
    if(n > Constants::MAXI::numOfNode)
        return false;
    for(int i = 0; i < Constants::MAXI::numOfNode; ++i)
        ID[i] = 0;
    for(int i = 0; i < n; ++i)
        ID[i] = i + 1;
    size_n = n;
    return true;
}

bool Pos_ID::attachID(int id){
    // Checking whether size_n is max or id is out of reach
    if(size_n == Constants::MAXI::numOfNode || id > size_n + 1 || id < 1) 
        return false;
    
    // Increase the right ID +1
    for(int i = 0; i < size_n; ++i)
        if(ID[i] >= id)
            ++ID[i];

    // attach new 
    ID[size_n++] = id;
    return true;
}

auto Pos_ID::detachID(int id) -> int{ // detach will return the position where ID = id
    // Checking whether empty or id is out of reach
    if(size_n == 0 || id > size_n || id < 1)
        return -1;

    // Finding the id;
    int tmp = -1;
    for(int i = 0; i < size_n; ++i)
        if(ID[i] == id)
            tmp = i;
    
    //  Delete id (by overwrite)
    for(int i = tmp; i < size_n - 1; ++i)
        ID[i] = ID[i + 1];

    ID[size_n--] = 0;

    // Decrease the right ID -1
    for(int i = 0; i < size_n; ++i)
        if(ID[i] > id)
            --ID[i];
        
    return tmp;
}

int Pos_ID::takeID(int pos){
    if(pos < 0 || pos >= size_n)
        return -1;
    return ID[pos];
}

int Pos_ID::findID(int id){
    if(id < 1 || id > size_n)
        return -1;
    for(int i = 0; i < size_n; ++i)
        if(ID[i] == id)
            return i;
    return -1;
}