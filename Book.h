#pragma once

#include <iostream>
#include <string.h>
#include "General.h"
#include "Dohoa.h"
#include "User.h"
#include "windows.h"
using namespace std;

class Book
{
public:
    Book();
    virtual ~Book();
    void addBook();
    void updateBook();
    void deleteBook();
    void searchBook();
    void showBook();
    void wirteBook();
    void display();
    void report();
    int retId();
    char* retName();
    char* retBrand();
    char* retAuthor();
    char* retRentUser();
    int retStatus();
    void format();
    bool updateRentBook(char s[]);
    bool updateBookReturn(char s[]);
    void HideCursor();
protected:

private:
    int id;
    char name[50];
    char brand[50];
    char author[50];
    int status;
    char rentUser[50];
};

