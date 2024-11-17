#include "../libs/linked-list/LinkedList.hpp"
#include <iostream> 

int main() {

    LinkedList ll{10};
    ll.addNode(20);
    ll.addNode(30);
    ll.addNode(2, 15);
    ll.addNode(3, 17);

    ll.test();

    ll.removeNode();

    std::cout << "\n";
    ll.test();
    return 0;
}