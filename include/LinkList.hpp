#pragma once

#include <memory>
#include <string>
#include <vector>

struct Node{
    std::string data;
    Node* pNext;
};

class LinkList{
    public:
        LinkList();

        void init(std::vector<std::string> tmp);

        void reset();

        bool push(std::string x, int k);
        bool pop(int k);
    private:
        Node* pHead;      
        int n;
};