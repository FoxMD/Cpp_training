#include <iostream>
#include "ll.h"

int main()
{
    Cache::LinkedList ll;
    ll.setValue(2); 
    ll.addNode(5);
    ll.addNode(6);
    ll.addNode(7);
    ll.addNode(8);
    ll.printForward(ll.start());
    ll.removeLastNode();
    ll.printForward(ll.start());
    return 0;
}
