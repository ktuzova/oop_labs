#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "Node.hpp"
#include "Iterator.hpp"
#include "ConstIterator.hpp"

#include <memory>

template<typename T, class Alloc = std::allocator<T>>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t sz = 0;
    Alloc alloc;

public:
    List() = default;
    List(const List<T, Alloc>& other);
    List(std::initializer_list<T> init);
    ~List();

    void push_front(const T& data);
    void push_back(const T& data);

    Node<T> *pop_front();
    Node<T> *pop_back();
    void clear();

    const T& front();
    Iterator<T> begin();
    ConstIterator<T> cbegin() const;
    Iterator<T> end();
    ConstIterator<T> cend() const;

    bool empty();
    size_t size();
    void swap(List<T, Alloc> other);

    Iterator<T> erase(Iterator<T> it);
    Iterator<T> insert(Iterator<T> it, const T& val);
    void insert(Iterator<T> it, size_t num, const T& val);
    void insert(Iterator<T> it, Iterator<T> start, Iterator<T> finish);

    bool operator==(List<T, Alloc>& other);

};

template<typename T, class Alloc>
const T &List<T, Alloc>::front() {
    if (sz == 0) {
        return T{};
    }
    return head->data;
}

template<typename T, class Alloc>
void List<T, Alloc>::clear() {
    while (sz != 0) {
        pop_front();
    }
}

template<typename T, class Alloc>
List<T, Alloc>::List(std::initializer_list<T> init) {
    for (auto elem : init) {
        push_back(elem);
    }
}

template<typename T, class Alloc>
List<T, Alloc>::List(const List<T, Alloc> &other) {
    for (auto it = other.cbegin(); it != other.cend(); ++it) {
        push_back(it.get_node()->data);
    }
}

template<typename T, class Alloc>
Iterator<T> List<T, Alloc>::begin() {
    Iterator<T> temp(head, sz);
    return temp;
}

template<typename T, class Alloc>
Iterator<T> List<T, Alloc>::end() {
    Iterator<T> temp(nullptr, sz);
    return temp;
}

template<typename T, class Alloc>
ConstIterator<T> List<T, Alloc>::cbegin() const {
    return ConstIterator<T>(head, sz);
}

template<typename T, class Alloc>
ConstIterator<T> List<T, Alloc>::cend() const {
    return ConstIterator<T>(nullptr, sz);
}

template<typename T, class Alloc>
bool List<T, Alloc>::empty() {
    return sz == 0;
}

template<typename T, class Alloc>
List<T, Alloc>::~List() {
    for (auto it = begin(); it != end(); ++it) {
        it.get_node()->~Node();
    }
}

template<typename T, class Alloc>
void List<T, Alloc>::push_front(const T& data) {
    if (head == nullptr) {
        head = alloc.allocate(1);
        head->data = data;
        tail = head;
        ++sz;
        return;
    }
    Node<T>* new_node = alloc.allocate(1);

    new_node->data = data;
    new_node->next = head;

    head = new_node;
    ++sz;
}

template<typename T, class Alloc>
void List<T, Alloc>::push_back(const T& data) {
    if (tail == nullptr) {
        tail = alloc.allocate(1);
        tail->data = data;
        head = tail;
        ++sz;
        return;
    }
    Node<T>* new_node = alloc.allocate(1);
    new_node->data = data;

    tail->next = new_node;
    tail = new_node;

    ++sz;
}

template<typename T, class Alloc>
size_t List<T, Alloc>::size() {
    return sz;
}

template<typename T, class Alloc>
void List<T, Alloc>::swap(List<T, Alloc> other) {
    std::swap(head, other.head);
    if (head != tail) {
        std::swap(tail, other.tail);
    }
    std::swap(sz, other.sz);
    std::swap(alloc, other.alloc);
}

template<typename T, class Alloc>
Iterator<T> List<T, Alloc>::insert(Iterator<T> it, const T &val) {
    if (it.get_node() == head) {
        Node<T>* new_node = alloc.allocate(1);
        new_node->data = val;
        head = new_node;
        head->next = it.get_node();
        ++sz;
        if (sz == 1) {
            tail = head;
        }
        return begin();
    }

    Node<T>* prev = head;
    while (prev != nullptr && prev->next != it.get_node()) {
        prev = prev->next;
    }

    Node<T>* new_node = alloc.allocate(1);
    new_node->data = val;
    new_node->next = it.get_node();

    if (prev != nullptr) {
        prev->next = new_node;
    }
    ++sz;

    return Iterator<T>(new_node, sz);
}

template<typename T, class Alloc>
void List<T, Alloc>::insert(Iterator<T> pos, Iterator<T> start, Iterator<T> finish) {
    for (auto it = start; it != finish; ++it) {
        insert(pos, it.get_node()->data);
    }
}

template<typename T, class Alloc>
void List<T, Alloc>::insert(Iterator<T> it, size_t num, const T &val) {
    for (size_t i = 0; i < num; ++i) {
        insert(it, val);
    }
}

template<typename T, class Alloc>
Iterator<T> List<T, Alloc>::erase(Iterator<T> it) {
    if (it.get_node() == nullptr) {
        return end();
    }

    if (sz == 1) {
        alloc.deallocate(it.get_node(), 1);
        --sz;
        head = nullptr;
        return end();
    }

    if (it == begin()) {
        head = head->next;
        alloc.deallocate(it.get_node(), 1);
        --sz;
        return begin();
    }

    Node<T>* next = it.get_node()->next;
    Node<T>* prev = head;
    while (prev != nullptr && prev->next != it.get_node()) {
        prev = prev->next;
    }
    if (prev != nullptr) {
        prev->next = next;
    }

    alloc.deallocate(it.get_node(), 1);
    --sz;

    if (it.get_node() == tail) {
        tail = prev;
        return end();
    }

    Iterator<T> tmp(next, sz);
    return tmp;
}

template<typename T, class Alloc>
Node<T> *List<T, Alloc>::pop_back() {
    if (head == nullptr)
        return nullptr;

    return erase(Iterator(tail, sz)).get_node();
}

template<typename T, class Alloc>
Node<T> *List<T, Alloc>::pop_front() {
    if (head == nullptr)
        return nullptr;

    return erase(begin()).get_node();
}

template<typename T, class Alloc>
bool List<T, Alloc>::operator==(List<T, Alloc> &other) {
    if (sz != other.sz)
        return false;

    bool flag = true;
    auto it1 = begin();
    auto it2 = other.begin();
    for (; it1 != end();) {
        if (it1.get_node()->data != it2.get_node()->data) {
            flag = false;
            break;
        }
        ++it1;
        ++it2;
    }
    return flag;
}

#endif