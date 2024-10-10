#pragma once
#include "Node.h"
#include "inkhung.h"
class list
{
private:
    linkedlist<Book>* plbook;
    linkedlist<User>* pluser;
    int time;
    int money;
public:
    void setlbook(linkedlist<Book>* plbook);
    linkedlist<Book>* lbook();
    void setluser(linkedlist<User>* pluser);
    linkedlist<User>* luser();
    void settime(int time);
    void setmoney(int money);
    int gettime();
    int getmoney();
};
list dangky(list l);
list dangnhap(list l);