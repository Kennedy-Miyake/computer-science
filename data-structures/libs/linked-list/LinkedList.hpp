#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <memory>

template <typename T>
class Node {
private:
    T m_data{};
    std::unique_ptr<Node<T>> m_ptr_to_next_node = nullptr;

public:
    Node(T data);

    void setData(T data);
    T getData() { return m_data; }
};

#endif