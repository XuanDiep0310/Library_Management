#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"

class Admin : public User {
public:
    void addBook(Book book);
    void removeBook(string bookId);
    void updateBook(string bookId, Book newInfo);
    void viewUsers();
    void approveRequest(User user, Book book);
    void returnBook(User user, string bookId);
    void viewStatistics();
    // Other methods...
};