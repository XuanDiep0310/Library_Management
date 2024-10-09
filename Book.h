#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
private:
    string ID;
    string Name;
    string Category;
    string Publisher;
    int Year;
    string Author;
    int Amount;
    int fixedAmount;
    string location;
public:
    Book();
    Book(string, string, string, string, int, string, int, string);
    void setID(string);
    void setName(string);
    void setCategory(string);
    void setPublisher(string);
    void setYear(int);
    void setAuthor(string);
    void setAmount(int);
    void setfixedAmount(int);
    void setlocation(string);
    string getID();
    string getName();
    string getCategory();
    string getPublisher();
    int getYear();
    string getAuthor();
    int getAmount();
    int getfixedAmount();
    string getlocation();
};
