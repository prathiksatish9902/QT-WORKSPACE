#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
template<typename T>
class LinkedList
{
private:
    struct Node{
        T m_data;
        Node *m_next;

        Node(const T &value){
            m_data = value;
            m_next = nullptr;
        }
    };

    Node *m_head;

public:
    LinkedList();
    ~LinkedList();

    void append(const T &value);
    void display();
    void clear();
};

#endif // LINKEDLIST_H
