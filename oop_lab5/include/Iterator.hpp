#ifndef ITERATOR_HPP_INCLUDED
#define ITERATOR_HPP_INCLUDED

#include "Node.hpp"
#include "List.hpp"

#include <memory>
#include <stdexcept>

template<typename T>
class Iterator {
    Node<T> *node;
    size_t size = 0;

public:
    Iterator() = default;
    ~Iterator() = default;

    Iterator(Node<T> *_node, size_t _size);
    Iterator(const Iterator &other);

    Iterator &operator=(const Iterator &other);
    Iterator &operator++();

    bool operator==(Iterator other) const;
    bool operator>=(Iterator other) const;
    bool operator>(Iterator other) const;
    bool operator!=(Iterator other) const;

    Node<T>* get_node() const;
    size_t get_size() const;

    T &operator*();
    T &operator->();
};

template<typename T>
Iterator<T>::Iterator(Node<T> *_node, size_t _size):
        node(_node),
        size(_size) {}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    if (node != nullptr) {
        node = node->next;
    }
    return *this;
}

template<typename T>
Iterator<T>::Iterator(const Iterator &other) {
    node = other.node;
    size = other.size;
}

template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &other) {
    node = other.node;
    size = other.size;
    return *this;
}

template<typename T>
Node<T>* Iterator<T>::get_node() const {
    return node;
}

template<typename T>
size_t Iterator<T>::get_size() const {
    return size;
}

template<typename T>
bool Iterator<T>::operator==(Iterator<T> other) const {
    return (this->node == other.node) && (this->size == other.size);
}

template<typename T>
bool Iterator<T>::operator>=(Iterator<T> other) const {
    return (this->node == other.node) && (this->size >= other.size);
}

template<typename T>
bool Iterator<T>::operator>(Iterator<T> other) const {
    return (this->node == other.node) && (this->size > other.size);
}

template<typename T>
bool Iterator<T>::operator!=(Iterator<T> other) const {
    return !((this->node == other.node) && (this->size == other.size));
}

template<typename T>
T &Iterator<T>::operator*() {
    return node->data;
}

template<typename T>
T &Iterator<T>::operator->() {
    return node->data;
}

#endif