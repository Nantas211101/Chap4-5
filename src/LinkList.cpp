#include "LinkList.hpp"

// Node

//

LinkList::LinkList() {}

void LinkList::init(std::vector<std::string> tmp) {
    reset();
    Node* cur = pHead;
    for(std::string v : tmp){
        Node* tmp = new Node;
        tmp->data = v;
        tmp->pNext = nullptr;
        if(!cur){
            cur = tmp;
            pHead = tmp;
        }
        else {
            cur->pNext = tmp;
            cur = cur->pNext;
        }
    }
    n = tmp.size();
}

void LinkList::reset(){
    while(pHead != nullptr){
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }
    n = 0;
}

bool LinkList::push(std::string x, int k){
    if(k > n + 1)
        return false;
    ++n;
    if(k == 1){
        Node* tmp = new Node;
        tmp->data = x;
        tmp->pNext = pHead;
        pHead = tmp;
        return true;   
    }
    Node* cur = pHead;
    for(int i = 1; i < k - 1; ++i)
        cur = cur->pNext;
    
    Node* tmp = new Node;
    tmp->data = x;
    tmp->pNext = cur->pNext;
    cur->pNext = tmp;
    return true;
}

bool LinkList::pop(int k){
    if(k > n)
        return false;
    --n;
    if(k == 1){
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
        return true;
    }
    Node* cur = pHead;
    for(int i = 1; i < k - 1; ++i)
        cur = cur->pNext;
    
    Node* tmp = cur->pNext;
    cur->pNext = cur->pNext->pNext;
    delete tmp;
    return true;
}