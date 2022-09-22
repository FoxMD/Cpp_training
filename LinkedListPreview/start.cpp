#include <iostream>
#include "ll.h"

int main()
{
    LinkedList::Node *pHead;
    LinkedList::Node *pTail;

    LinkedList::Node *pNode = new LinkedList::Node();
    pNode->value = 4;
    pNode->next = nullptr;
    pNode->previous = nullptr;

    pHead = pNode;
    pTail = pNode;
    
    pNode = new LinkedList::Node();
    pNode->value = 5;
    pNode->next = nullptr;
    pNode->previous = pTail;
    pTail->next = pNode;
    pTail = pNode;

    LinkedList::printForward(pHead);
    return 0;
}