#include <iostream>
#include <memory>

std::shared_ptr<int> testPointer(int data) {
    std::shared_ptr<int> ptr_to_int = std::make_shared<int>(data);
    std::shared_ptr<int> test_ptr = std::make_shared<int>(20);
    std::cout << "Dado do ponteiro: " << data << '\n';
    std::cout << "Contador de ponteiros compartilhados: " << ptr_to_int.use_count()
        << '\n'; 
    return ptr_to_int;
}

int main() {

    std::shared_ptr<int> ptr_int = testPointer(10);
    std::cout << ptr_int.use_count();

    return 0;
}