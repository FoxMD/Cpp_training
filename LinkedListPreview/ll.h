#pragma once
#include <iostream>

namespace LinkedList
{
    class Cache
    {
        private:
        public:
    }; 

    class Node
    {
    private:
        /* data */
    public:
        int value;
        Node *next;
        Node *previous; 
        Node(/* args */);
        ~Node();
    };
    void printForward(Node *head);
    void printBackwards(Node *tail);
};
