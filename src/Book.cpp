#pragma once    
#include "Person.h"
#include "Date.h"
#include "General.h"
#include <iostream>
#include <vector.h>
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
    string retClass();
    bool updateUserRent(char s[]);
    bool updateUserReturn(char s[]);
    static bool compareById(const User& u1, const User& u2) {
        return u1.retId() < u2.retId();
    };  // Hàm so sánh
protected:
private:
    char username[15];
    char password[50];
    string clas;
    vector<string> rentedBooks;
    int rentedBookCount;
    Date birthDate;
    void format();
};
