#pragma once
#include "Book.h"
#include "user.h"
#include "inkhung.h"
template <typename T>
class node
{
private:
    T data;
    node<T>* next;
    node<T>* prev;
public:
    node();
    node(node<T>* next, node<T>* prev, T data);
    void setData(T data);
    T getData();
    void setNext(node<T>* next);
    node<T>* getNext();
    void setPrev(node<T>* prev);
    node<T>* getPrev();
    void print(node<User>* tmp, int i, int c);
    void print(node<Book>* tmp, int i, int c);
    int operator != (int N);
    int operator == (int N);
    friend class linkedlist<T>;
};


template <typename T>
class linkedlist
{
private:
    node<T>* head;
    node<T>* tail;
    int count;
public:
    linkedlist();
    void setHead(node<T>* head);
    void setTail(node<T>* tail);
    node<T>* getHead();
    node<T>* getTail();
    node<T>* get(string ID);
    node<T>* getAvailable(string ID);
    void printNext();
    void printNextavailble();
    void addTail(T data);
    int getCount();
    void setCount(int count);
};

template <typename T>
node<T>::node() {

}

template <typename T>
node<T>::node(node<T>* next, node<T>* prev, T data)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <typename T>
void node<T>::setNext(node<T>* next)
{
    this->next = next;
}

template <typename T>
node<T>* node<T>::getNext()
{
    return next;
}

template <typename T>
void node<T>::setPrev(node<T>* prev)
{
    this->prev = prev;
}

template <typename T>
node<T>* node<T>::getPrev()
{
    return prev;
}

template <typename T>
void node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
T node<T>::getData()
{
    return data;
}

template <typename T>
void node<T>::print(node<User>* tmp, int i, int c)
{
    box(1, 7 + i, 20, 2, 11, 1, tmp->data.getID());
    gotoXY(1, 7 + i); cout << char(195);
    box(21, 7 + i, 30, 2, 11, 1, tmp->data.getName());
    box(51, 7 + i, 20, 2, 11, 1, tmp->data.getDob());
    box(71, 7 + i, 20, 2, 11, 1, tmp->data.getPhone());
    box(91, 7 + i, 20, 2, 11, 1, 4 - tmp->data.getNumborrow());
    box(111, 7 + i, 14, 2, 11, 1, 4 - tmp->data.getNumrequest());
    if (c == 1)
    {
        gotoXY(21, 7 + i); cout << char(197);
        gotoXY(21, 9 + i); cout << char(197);
        gotoXY(51, 7 + i); cout << char(197);
        gotoXY(51, 9 + i); cout << char(197);
        gotoXY(71, 7 + i); cout << char(197);
        gotoXY(71, 9 + i); cout << char(197);
        gotoXY(91, 7 + i); cout << char(197);
        gotoXY(91, 9 + i); cout << char(197);
        gotoXY(111, 7 + i); cout << char(197);
        gotoXY(111, 9 + i); cout << char(197);
        gotoXY(125, 7 + i); cout << char(180);
    }
    else if (c == 0)
    {
        gotoXY(21, 7 + i); cout << char(197);
        gotoXY(21, 9 + i); cout << char(193);
        gotoXY(51, 7 + i); cout << char(197);
        gotoXY(51, 9 + i); cout << char(193);
        gotoXY(71, 7 + i); cout << char(197);
        gotoXY(71, 9 + i); cout << char(193);
        gotoXY(91, 7 + i); cout << char(197);
        gotoXY(91, 9 + i); cout << char(193);
        gotoXY(111, 7 + i); cout << char(197);
        gotoXY(111, 9 + i); cout << char(193);
        gotoXY(125, 7 + i); cout << char(180);
    }
}

template <typename T>
void node<T>::print(node<Book>* tmp, int i, int c)
{
    box(1, 7 + i, 15, 2, 11, 1, tmp->data.getID());
    gotoXY(1, 7 + i); cout << char(195);
    box(12, 7 + i, 25, 2, 11, 1, tmp->data.getName());
    box(37, 7 + i, 15, 2, 11, 1, tmp->data.getCategory());
    box(52, 7 + i, 20, 2, 11, 1, tmp->data.getPublisher());
    box(72, 7 + i, 15, 2, 11, 1, tmp->data.getYear());
    box(87, 7 + i, 20, 2, 11, 1, tmp->data.getAuthor());
    box(107, 7 + i, 9, 2, 11, 1, tmp->data.getlocation());
    box(116, 7 + i, 9, 2, 11, 1, tmp->data.getAmount(), tmp->data.getfixedAmount());
    if (c == 1)
    {
        gotoXY(12, 7 + i); cout << char(197);
        gotoXY(12, 9 + i); cout << char(197);
        gotoXY(37, 7 + i); cout << char(197);
        gotoXY(37, 9 + i); cout << char(197);
        gotoXY(52, 7 + i); cout << char(197);
        gotoXY(52, 9 + i); cout << char(197);
        gotoXY(72, 7 + i); cout << char(197);
        gotoXY(72, 9 + i); cout << char(197);
        gotoXY(87, 7 + i); cout << char(197);
        gotoXY(87, 9 + i); cout << char(197);
        gotoXY(107, 7 + i); cout << char(197);
        gotoXY(107, 9 + i); cout << char(197);
        gotoXY(116, 7 + i); cout << char(197);
        gotoXY(116, 9 + i); cout << char(197);
        gotoXY(125, 7 + i); cout << char(180);
    }
    else if (c == 0)
    {
        gotoXY(12, 7 + i); cout << char(197);
        gotoXY(12, 9 + i); cout << char(193);
        gotoXY(37, 7 + i); cout << char(197);
        gotoXY(37, 9 + i); cout << char(193);
        gotoXY(52, 7 + i); cout << char(197);
        gotoXY(52, 9 + i); cout << char(193);
        gotoXY(72, 7 + i); cout << char(197);
        gotoXY(72, 9 + i); cout << char(193);
        gotoXY(87, 7 + i); cout << char(197);
        gotoXY(87, 9 + i); cout << char(193);
        gotoXY(107, 7 + i); cout << char(197);
        gotoXY(107, 9 + i); cout << char(193);
        gotoXY(116, 7 + i); cout << char(197);
        gotoXY(116, 9 + i); cout << char(193);
        gotoXY(125, 7 + i); cout << char(180);
    }
}

template <typename T>
int node<T>:: operator != (int N)
{
    if (this != NULL) return 1;
    else return 0;
}

template <typename T>
int node<T>:: operator == (int N)
{
    if (this == NULL) return 1;
    else return 0;
}

template <typename T>
linkedlist<T>::linkedlist()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <typename T>
void linkedlist<T>::setTail(node<T>* tmp)
{
    this->tail = tmp;
}

template <typename T>
void linkedlist<T>::setHead(node<T>* tmp)
{
    this->head = tmp;
    this->head->setPrev(NULL);
}

template <typename T>
node<T>* linkedlist<T>::getHead()
{
    return head;
}

template <typename T>
node<T>* linkedlist<T>::getTail()
{
    return tail;
}

template <typename T>
node<T>* linkedlist<T>::get(string ID)
{
    node<T>* P;
    for (P = head; P != NULL; P = P->getNext())
    {
        if (P->getData().getID() == ID)
        {
            return P;
        }
    }
    return P;
}

template <typename T>
node<T>* linkedlist<T>::getAvailable(string ID)
{
    node<T>* P;
    for (P = head; P != NULL; P = P->getNext())
    {
        if (P->getData().getID() == ID && P->getData().getAmount() > 0)
        {
            return P;
        }
    }
    return P;
}

template <typename T>
void linkedlist<T>::printNext()
{
    int i = 2;
    node<T>* tmp = head;
    while (tmp != NULL)
    {
        tmp->print(tmp, i, 1);
        i += 2;
        tmp = tmp->getNext();
    }
}

template <typename T>
void linkedlist<T>::printNextavailble()
{
    int i = 2;
    node<T>* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->getData().getAmount() > 0)
        {
            tmp->print(tmp, i, 1);
            i += 2;
        }
        tmp = tmp->getNext();
    }

}

template <typename T>
void linkedlist<T>::addTail(T data)
{
    node<T>* tmp = new node<T>(NULL, NULL, data);
    count++;
    if (head == NULL)
    {
        head = tail = tmp;
        return;
    }
    tmp->setPrev(tail);
    tail->setNext(tmp);
    setTail(tmp);
}

template <typename T>
int linkedlist<T>::getCount()
{
    return count;
}

template <typename T>
void linkedlist<T>::setCount(int count)
{
    this->count = count;
}
