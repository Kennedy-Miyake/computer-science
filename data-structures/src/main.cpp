#include "../libs/linked-list/LinkedList.hpp"
#include <iostream> 

int main() {

    LinkedList ll{10};
    ll.addNode(20);
    ll.addNode(30);

    ll.test();
    return 0;
}