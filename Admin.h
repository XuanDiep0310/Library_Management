#pragma once
#include<iostream>
#include<iomanip>
#include "LinkedList.h"
#include "Person.h"
#include "Book.h"
#include "Access.h"
using namespace std;

class Admin : public Person
{
public:
    Admin();
    LinkedList<Book>* fixBook(LinkedList<Book>* lbook, LinkedList<User>* luser);
    LinkedList<Book>* addBook(LinkedList<Book>* lbook);
    LinkedList<Book>* delBook(LinkedList<Book>* lbook);
    void displayUser(LinkedList<User>* luser);
    List delUser(List l);
    void findUser(LinkedList<User>* luser, LinkedList<Book>* lbook);
    void borrowBook(List l, int time);
    void giveBackBook(List l, int money);
    void resetPasswork(LinkedList<User>* luser);
    void updateInfor(LinkedList<User>* luser);
    void statistic(LinkedList<Book>* lbook, LinkedList<User>* luser);
};
