#pragma once
#include <iostream>
#include <string>

namespace Cache
{
    class Node
    {
        friend class LinkedList;
        private:
            int value;
            Node *next;
            Node *previous; 
            Node();
            ~Node();
    };
    class LinkedList
    {
        private:
            Node *pHead;
            Node *pTail;
            void prepareNext(Node *pNode);
            void destructNodes();
        public:
            LinkedList();
            ~LinkedList();
            void setValue(int value);
            void addNode(int input);
            void printForward(Node *head);
            void printBackwards(Node *tail);
            void removeLastNode();
            Node* start();
    }; 
};
