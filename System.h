#pragma once
#define ADMINUSER "admin"
#define ADMINPASSWORD "admin"

#define USER "user"
#define USERPASSWORD "user123"
#include "General.h"
#include "ServiceBook.h"
#include "ManagerEmloyee.h"
#include <iostream>
#include "windows.h"
using namespace std;
class System
{
public:
    System();
    virtual ~System();
    void run();
protected:
private:
    void HideCursor();
    bool login();
    bool login_user();
    void menu_main();
    void menu_admin_manager();
    void menu_user_manager();
    void menu_book_manager();
    void menu_user();
    void menu_employee_manager();
    void format();
};

