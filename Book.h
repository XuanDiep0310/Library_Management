#pragma once
#include <iostream>

class Book {
private:
    string bookId;
    string title;
    string author;
    string genre;
    int totalCopies;
    int availableCopies;
public:
    string getDetails();
    bool isAvailable();
    // Other methods...
};