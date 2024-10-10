#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {

}

Book::Book(string ID, string Name, string Category, string Publisher, int Year, string Author, int Amount, string location) {
    this->ID = ID;
    this->Name = Name;
    this->Category = Category;
    this->Publisher = Publisher;
    this->Year = Year;
    this->Author = Author;
    this->Amount = Amount;
    this->location = location;
}

void Book::setID(string ID) {
    this->ID = ID;
}

void Book::setName(string Name) {
    this->Name = Name;
}

void Book::setCategory(string Category) {
    this->Category = Category;
}

void Book::setPublisher(string Publisher) {
    this->Publisher = Publisher;
}

void Book::setYear(int Year) {
    this->Year = Year;
}

void Book::setAuthor(string Author) {
    this->Author = Author;
}

void Book::setAmount(int Amount) {
    this->Amount = Amount;
}

void Book::setfixedAmount(int fixedAmount)
{
    this->fixedAmount = fixedAmount;
}

void Book::setlocation(string location)
{
    this->location = location;
}

string Book::getID() {
    return ID;
}

string Book::getName() {
    return Name;
}

string Book::getCategory() {
    return Category;
}

string Book::getPublisher() {
    return Publisher;
}

int Book::getYear() {
    return Year;
}

string Book::getAuthor() {
    return Author;
}

int Book::getAmount() {
    return Amount;
}

int Book::getfixedAmount()
{
    return fixedAmount;
}

string Book::getlocation()
{
    return location;
}