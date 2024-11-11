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
    T getData() const { return m_data; }
};

template <typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> m_head_node{};
    int m_size{0};

public:
    LinkedList(T data);
    
    T info_data() const;
};

// Implementações da classe Node
template <typename T>
Node<T>::Node(T data) : m_data{data} {}

template <typename T>
void Node<T>::setData(T data) { m_data = data; }

// Implementações da classe LinkedList
template <typename T>
LinkedList<T>::LinkedList(T data)
    : m_head_node{std::make_unique<Node<T>>(data)} {}

template <typename T>
T LinkedList<T>::info_data() const {
    return m_head_node->getData();    
}

#endif