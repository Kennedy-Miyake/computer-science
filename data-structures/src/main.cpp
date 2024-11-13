#include "../libs/linked-list/LinkedList.hpp"
#include <iostream> 

int main() {

    LinkedList ll{10};

    ll.addNode(20);
    std::cout << ll.info_data() << '\n';

    return 0;
}