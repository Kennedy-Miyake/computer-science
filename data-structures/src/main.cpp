#include "../libs/linked-list/LinkedList.hpp"
#include <iostream> 

int main() {

    LinkedList ll{10};

    std::cout << ll.info_data();
        
    return 0;
}