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
    string gettPassword();
    void displayAvailable(LinkedList<Book> *lbook);
    void findCategory(LinkedList<Book> *lbook);
    void findbookname(LinkedList<Book> *lbook);
    void findAuthor(LinkedList<Book> *lbook);
    void displaybook(LinkedList<Book> *lbook);
};

Person::Person() {

}

Person::Person(string username, string password) {
    this->username = username;
    this->password = password;
}

void Person::setUsername(string username) {
    this->username = username;
}

void Person::setPassword(string password) {
    this->password = password;
}

string Person::getUsername() {
    return username;
}

string Person::gettPassword() {
    return password;
}

string chuhoa(string s) 
{
    for(int i = 0; i < s.length(); i++) 
    {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    return s;
}