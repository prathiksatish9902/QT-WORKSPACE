#include "linkedlist.h"
template<typename T>
LinkedList<T>::LinkedList() {
    m_head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
clear();
}

template<typename T>
void LinkedList<T>::append(const T &value)
{
    Node *newnode = new Node(value);
    if(!m_head){
        m_head = newnode;
    }
    else{
        Node *temp = m_head;
        while(temp->m_next)
            temp = temp->m_next;
        temp->m_next = newnode;

    }
}

template<typename T>
void LinkedList<T>::display()
{
    Node *temp = m_head;
    while(temp){
        std::cout<<temp->m_data<<"->";
        temp = temp->m_next;
    }
    std::cout<<"NUll"<<std::endl;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node *temp = m_head;
    while(temp){
        Node *nextNode = temp->m_next;
        delete temp;
        temp = nextNode;
    }
    m_head = nullptr;
}
template class LinkedList <int >;
template class LinkedList <float>;
template class LinkedList <char>;
template class LinkedList <std::string>;
template class LinkedList <double>;
