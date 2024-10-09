#pragma once
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Person.h"
#include "Book.h"
#include "truycap.h"
using namespace std;

class Admin : public Person
{
public:
    Admin();
    linkedlist<Book>* fixbook(linkedlist<Book>* lbook, linkedlist<User>* luser);
    linkedlist<Book>* addbook(linkedlist<Book>* lbook);
    linkedlist<Book>* delbook(linkedlist<Book>* lbook);
    void displayuser(linkedlist<User>* luser);
    list deluser(list l);
    void finduser(linkedlist<User>* luser, linkedlist<Book>* lbook);
    void borrowbook(list l, int time);
    void givebackbook(list l, int money);
    void resetpw(linkedlist<User>* luser);
    void updateIF(linkedlist<User>* luser);
    void thongke(linkedlist<Book>* lbook, linkedlist<User>* luser);
};
