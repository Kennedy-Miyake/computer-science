#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include <memory>
#include <stdexcept>
#include <iostream>

enum PosNode {
    Next,
    Previous,
    All
};

template <typename T>
class Node {
private:
    T m_data;
    std::shared_ptr<Node<T>> m_ptr_to_next_node;
    std::shared_ptr<Node<T>> m_ptr_to_prev_node;

public:
    Node(T data);

    void setData(T data);
    T getData() const { return m_data; }
    void setNode(std::shared_ptr<Node<T>> node, PosNode pos);
    std::shared_ptr<Node<T>> getNextNode() const { return m_ptr_to_next_node; }
    std::shared_ptr<Node<T>> getPrevNode() const { return m_ptr_to_prev_node; }
};

template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> m_head_node;
    std::shared_ptr<Node<T>> m_tail_node;
    int m_size{1};

public:
    LinkedList(T data);
    
    void info_data();
    void addNode(T data);
    void addNode(int index, T data);
    void removeNode();
    void test();
};

// Implementações da classe Node
template <typename T>
Node<T>::Node(T data) : m_data{data}, m_ptr_to_next_node{nullptr} {}

template <typename T>
void Node<T>::setData(T data) { m_data = data; }
template <typename T>
void Node<T>::setNode(std::shared_ptr<Node<T>> node, PosNode pos) {
    if(pos == PosNode::Next) { m_ptr_to_next_node = node; }
    else if(pos == PosNode::Previous) { m_ptr_to_prev_node = node; }
    else if(pos == PosNode::All) {
        m_ptr_to_next_node = node->getNextNode();
        m_ptr_to_prev_node = node;
    }
}

// Implementações da classe LinkedList
template <typename T>
LinkedList<T>::LinkedList(T data)
    : m_head_node{std::make_shared<Node<T>>(data)} { m_tail_node = m_head_node; }

template <typename T>
void LinkedList<T>::info_data() {
    auto aux_node = m_head_node;
    do {
        std::cout << aux_node->getData() << '\n';
        aux_node = aux_node->getNextNode();
    } while(aux_node != nullptr);
    return;
}
template <typename T>
void LinkedList<T>::addNode(T data) {
    std::shared_ptr<Node<T>> new_node{std::make_shared<Node<T>>(data)};
    std::shared_ptr<Node<T>> aux_node = m_head_node;
    while(aux_node->getNextNode() != nullptr) {
        aux_node = aux_node->getNextNode();
    }
    new_node->setNode(aux_node, PosNode::Previous);
    aux_node->setNode(new_node, PosNode::Next);
    m_tail_node = new_node;
    m_size++;
}
template <typename T>
void LinkedList<T>::addNode(int index, T data) {
    std::shared_ptr<Node<T>> new_node{std::make_shared<Node<T>>(data)};
    std::shared_ptr<Node<T>> aux_node = m_head_node;
    if(index > m_size || index == 0) {
        std::cout << "Erro de índice." << '\n';
        return;
    }
    else if(index == 1) {
        m_head_node = new_node;
        aux_node->setNode(m_head_node, PosNode::Previous);
        m_head_node->setNode(aux_node, PosNode::Next);
        m_size++;
        return;
    }
    for(int i{1}; i < (index-1); i++) {
        aux_node = aux_node->getNextNode();
    }
    new_node->setNode(aux_node->getNextNode(), PosNode::Next);
    new_node->setNode(aux_node, PosNode::Previous);
    (aux_node->getNextNode())->setNode(new_node, PosNode::Previous);
    aux_node->setNode(new_node, PosNode::Next);
    m_size++;
}
template <typename T>
void LinkedList<T>::removeNode() {
    auto aux_node = m_tail_node;
    m_tail_node = aux_node->getPrevNode();
    m_tail_node->setNode(nullptr, PosNode::Next);
    aux_node.reset();
    m_size--;
}
template <typename T>
void LinkedList<T>::test() {
    auto aux_head_node = m_head_node;
    while(aux_head_node != nullptr) {
        std::cout << aux_head_node->getData() << '\n';
        aux_head_node = aux_head_node->getNextNode();
    }
}

#endif