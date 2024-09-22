#pragma once
#include <iostream>
#include "Book.h"
#include "User.h"

class Library {
private:
    LinkedList<Book> books;
    LinkedList<User> users;
public:
    void loadBooks();
    void loadUsers();
    void searchBook(string criteria, string value);
    void displayBooks();
    void displayAvailableBooks();
    // Other methods...
};
