#include "ll.h"

LinkedList::Node::Node(/* args */)
{

}

LinkedList::Node::~Node()
{

}

void LinkedList::printForward(Node *head)
{
    Node *pTravers = head;
    while(pTravers != nullptr)
    {
        std::cout << pTravers->value << std::endl;
        pTravers = pTravers->next;
    }
}

void LinkedList::printBackwards(Node *tail)
{
    Node *pTravers = tail;
    while(pTravers != nullptr)
    {
        std::cout << pTravers->value << std::endl;
        pTravers = pTravers->previous;
    }
}
