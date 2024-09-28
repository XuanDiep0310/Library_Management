#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
private:
    string id;        // mã sách
    string name;      // tên sách
    string category;  // thể loại sách
    string publisher; // nhà xuất bản
    int year;         // năm xuất bản
    string author;    // tác giả
    int amount;       // số lượng sách
    int fixedAmount;  // số lượng cố định
    string location;  // vị trí sách

public:
    Book();
    Book(string id, string name, string category, string publisher, int year, string author, int amount, string location);

    void setID(string id);
    void setName(string name);
    void setCategory(string category);
    void setPublisher(string publisher);
    void setYear(int year);
    void setAuthor(string author);
    void setAmount(int amount);
    void setFixedAmount(int fixedAmount);
    void setLocation(string location);

    string getID();
    string getName();
    string getCategory();
    string getPublisher();
    int getYear();
    string getAuthor();
    int getAmount();
    int getFixedAmount();
    string getLocation();
};
#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {

}

Book::Book(string id, string name, string category, string publisher, int year, string author, int amount, string location) {
    this->id = id;
    this->name = name;
    this->category = category;
    this->publisher = publisher;
    this->year = year;
    this->author = author;
    this->amount = amount;
    this->location = location;
}

void Book::setID(string id) {
    this->id = id;
}

void Book::setName(string name) {
    this->name = name;
}

void Book::setCategory(string category) {
    this->category = category;
}

void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

void Book::setYear(int year) {
    this->year = year;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setAmount(int amount) {
    this->amount = amount;
}

void Book::setFixedAmount(int fixedAmount) {
    this->fixedAmount = fixedAmount;
}

void Book::setLocation(string location) {
    this->location = location;
}

string Book::getID() {
    return id;
}

string Book::getName() {
    return name;
}

string Book::getCategory() {
    return category;
}

string Book::getPublisher() {
    return publisher;
}

int Book::getYear() {
    return year;
}

string Book::getAuthor() {
    return author;
}

int Book::getAmount() {
    return amount;
}

int Book::getFixedAmount() {
    return fixedAmount;
}

string Book::getLocation() {
    return location;
}
