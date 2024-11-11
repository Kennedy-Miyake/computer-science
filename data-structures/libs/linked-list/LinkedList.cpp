#include "LinkedList.hpp"

template <typename T>
Node<T>::Node(T data)
    : m_data{data} {}

template <typename T>
void Node<T>::setData(T data) {
    m_data = data;
}