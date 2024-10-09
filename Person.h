#pragma once
#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

using namespace std;
template <typename T>
class linkedlist;

class Person
{
private:
    string un;
    string pw;
public:
    Person();
    Person(string, string);
    void setUn(string);
    void setPw(string);
    string getUn();
    string getPw();
    void displayAvailable(linkedlist<Book>* lbook);
    void findCategory(linkedlist<Book>* lbook);
    void findbookname(linkedlist<Book>* lbook);
    void findAuthor(linkedlist<Book>* lbook);
    void displaybook(linkedlist<Book>* lbook);
};

