#pragma once
#include "Book.h"
#include <string>
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Person
{
private:
    string username;
    string password;

public:
    Person();
    Person(string username, string password);
    void setUsername(string username);
    void setPassword(string password);
    string getUsername();
    string getPassword();
    void displayAvailable(LinkedList<Book> *lbook);
    void findCategory(LinkedList<Book> *lbook);
    void findBookName(LinkedList<Book> *lbook);
    void findAuthor(LinkedList<Book> *lbook);
    void displayBook(LinkedList<Book> *lbook);
};

