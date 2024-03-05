#ifndef CONSTITERATOR_HPP_INCLUDED
#define CONSTITERATOR_HPP_INCLUDED

#include "Node.hpp"
#include "List.hpp"

#include <memory>
#include <stdexcept>

template<typename T>
class ConstIterator {
    const Node<T> *node;
    size_t size = 0;

public:
    ConstIterator() = default;
    ~ConstIterator() = default;

    ConstIterator(const Node<T> *_node, size_t _size);
    ConstIterator(const ConstIterator &other);
    ConstIterator &operator=(const ConstIterator &other);

    ConstIterator &operator++();
    bool operator==(ConstIterator other) const;
    bool operator>=(ConstIterator other) const;
    bool operator>(ConstIterator other) const;
    bool operator!=(ConstIterator other) const;

    const Node<T>* get_node() const;
    size_t get_size() const;

    const T &operator*() const;
    const T &operator->() const;
};

template<typename T>
ConstIterator<T>::ConstIterator(const Node<T> *_node, size_t _size):
        node(_node),
        size(_size) {}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++() {
    if (node != nullptr) {
        node = node->next;
    }
    return *this;
}

template<typename T>
ConstIterator<T>::ConstIterator(const ConstIterator &other) {
    node = other.node;
    size = other.size;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator<T> &other) {
    node = other.node;
    size = other.size;
    return *this;
}

template<typename T>
const Node<T>* ConstIterator<T>::get_node() const {
    return node;
}

template<typename T>
size_t ConstIterator<T>::get_size() const {
    return size;
}

template<typename T>
bool ConstIterator<T>::operator==(ConstIterator<T> other) const {
    return (this->node == other.node) && (this->size == other.size);
}

template<typename T>
bool ConstIterator<T>::operator>=(ConstIterator<T> other) const {
    return (this->node == other.node) && (this->size >= other.size);
}

template<typename T>
bool ConstIterator<T>::operator>(ConstIterator<T> other) const {
    return (this->node == other.node) && (this->size > other.size);
}

template<typename T>
bool ConstIterator<T>::operator!=(ConstIterator<T> other) const {
    return !((this->node == other.node) && (this->size == other.size));
}

template<typename T>
const T &ConstIterator<T>::operator*() const {
    return node->data;
}

template<typename T>
const T &ConstIterator<T>::operator->() const {
    return node->data;
}

#endif