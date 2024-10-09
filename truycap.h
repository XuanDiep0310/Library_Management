#pragma once
#include "LinkedList.h"
#include <iostream>
#include <cstring>
#include <conio.h>
#include "ReadFile.h"
#include "WriteFile.h"
#include "Menu.h"
#include "Date.h"
#include "PrintFrame.h"
class List
{
private:
        LinkedList<Book> *plbook;
        LinkedList<User> *pluser;
        int time;
        int money;

public:
        void setLBook(LinkedList<Book> *pLBook);
        LinkedList<Book> *lbook();
        void setLUser(LinkedList<User> *pLUser);
        LinkedList<User> *luser();
        void setTime(int time);
        void setMoney(int money);
        int getTime();
        int getMoney();
};
List signUp(List l);
List dangnhap(List l);
