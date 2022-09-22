#include "ll.h"
using namespace Cache;

LinkedList::LinkedList()
{
    Node *pNode = new Node();
    pNode->value = 4;
    pNode->next = nullptr;
    pNode->previous = nullptr;

    pHead = pNode;
    pTail = pNode;
}

void LinkedList::destructNodes()
{
    Node *pTravers = pTail;
    Node *pTemp = pTail;
    while(pTravers != nullptr)
    {
        pTravers->next = nullptr;
        pTemp = pTravers->previous;
        delete pTravers;
        pTravers = pTemp;
    }
    delete pTemp;
    std::cout << "Destructed temporary" << std::endl;
}

void LinkedList::removeLastNode()
{
    Node *pTravers = pTail->previous;
    std::cout << "Removed: " << pTail->value << std::endl;
    delete pTail;
    pTravers->next = nullptr;
    pTail = pTravers;
}

LinkedList::~LinkedList()
{
    destructNodes();
    std::cout << "Destructed List" << std::endl;
}

void LinkedList::prepareNext(Node *pNode)
{
    pNode->next = nullptr;
    pNode->previous = pTail;
    pTail->next = pNode;
    pTail = pNode;
}

Node *LinkedList::start()
{
    return pHead;
}

Node::Node(/* args */)
{

}

Node::~Node()
{
    std::cout << "Destructed Node" << std::endl;
}


void LinkedList::setValue(int value)
{
    pTail->value = value;
}

void LinkedList::addNode(int input)
{
    Node *pNode = new Node();
    pNode->value = input;
    prepareNext(pNode);
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
