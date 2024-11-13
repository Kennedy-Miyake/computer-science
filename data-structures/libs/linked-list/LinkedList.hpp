#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <memory>

template <typename T>
class Node {
private:
    T m_data;
    std::shared_ptr<Node<T>> m_ptr_to_next_node;

public:
    Node(T data);

    void setData(T data);
    T getData() const { return m_data; }
    void setNextNode(std::shared_ptr<Node<T>> node);
    std::shared_ptr<Node<T>> getNextNode() const { return m_ptr_to_next_node; }
};

template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> m_head_node;
    int m_size{1};

public:
    LinkedList(T data);
    
    T info_data() const;
    void addNode(T data);
};

// Implementações da classe Node
template <typename T>
Node<T>::Node(T data) : m_data{data}, m_ptr_to_next_node{nullptr} {}

template <typename T>
void Node<T>::setData(T data) { m_data = data; }
template <typename T>
void Node<T>::setNextNode(std::shared_ptr<Node<T>> node) { m_ptr_to_next_node = node; }

// Implementações da classe LinkedList
template <typename T>
LinkedList<T>::LinkedList(T data)
    : m_head_node{std::make_shared<Node<T>>(data)} {}

template <typename T>
T LinkedList<T>::info_data() const {
    return m_head_node->getData();
}
template <typename T>
void LinkedList<T>::addNode(T data) {
    std::shared_ptr<Node<T>> new_node{std::make_shared<Node<T>>(data)};
    std::shared_ptr<Node<T>> temp_node = m_head_node;
    while(temp_node->getNextNode() != nullptr) {
        temp_node = temp_node->getNextNode();
    }
    temp_node->setNextNode(new_node);
}

#endif