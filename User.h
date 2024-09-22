#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

class User {
protected:
    string id;
    string name;
    string password;
    vector<Book> borrowedBooks;
    vector<Book> requestedBooks;
    bool isAdmin;
public:
    bool login(string id, string password);
    void viewBorrowedBooks();
    void requestBook(Book book);
    void cancelRequest(Book book);
    // Other methods...
};