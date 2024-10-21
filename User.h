#pragma once    
#include "Person.h"
#include "Date.h"
#include "General.h"
#include <iostream>
#include <windows.h>
using namespace std;

class User :public Person
{
public:
    User();
    virtual ~User();
    void add_user();
    void update_user();
    void delete_user();
    void search_user();
    void show_user();
    void write_user();
    void display();
    void report();
    int retId() const;
    char* retUsername();
    char* retPassword();
    char* retClass();
    bool updateUserRent(char s[]);
    bool updateUserReturn(char s[]);
    static bool compareById(const User& u1, const User& u2) {
        return u1.retId() < u2.retId();
    };  // Hàm so sánh
protected:
private:
    char username[15];
    char password[20];
    char clas[15];
    char rentBook[20];
    int status;
    Date birthDate;
    void format();
};
