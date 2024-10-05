#pragma once
#include <iostream>
#include "Person.h"
#include "Book.h"
#include "LinkedList.h"
#include "User.h"

class Admin : public Person 
{
    public:
        Admin();
        LinkedList<Book>* fixBook(LinkedList<Book>* lbook, LinkedList<User>* luser);
        LinkedList<Book>* addBook(LinkedList<Book>* lbook);
        LinkedList<Book>* delBook(LinkedList<Book>* lbook);
        void displayUser(LinkedList<User>* luser);
        list delUser(list l);
        void findUser(LinkedList<User>* luser, LinkedList<Book>* lbook);
        void borrowBook(list l, int time);
        void giveBackBook(list l, int money);
        void resetPasswork(LinkedList<User>* luser);
        void updateIF(LinkedList<User>* luser);
        void thongKe(LinkedList<Book>* lbook,LinkedList<User>* luser);
};