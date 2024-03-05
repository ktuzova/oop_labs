#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

template<typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
};

#endif