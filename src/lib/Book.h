#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include "Graphic.h"
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <iomanip>

using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    string genre;
    int publicationYear;
    int quantity;
    string status; //Available, Rented, Damaged, Lost
public:
    Book(int id, const string& t, const string& a, const string& g, int pubYear, int q, const string& stt)
        : bookId(id), title(t), author(a), genre(g), publicationYear(pubYear), quantity(q), status(stt) {}

    //Getters
    int getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getPublicationYear() const { return publicationYear; }
    int getQuantity() const { return quantity; }
    string getStatus() const { return status; }

    //Setters
    void setBookId(int id) { bookId = id; }
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setGenre(const string& g) { genre = g; }
    void setPublicationYear(int pubYear) { publicationYear = pubYear; }
    void setQuantity(int q) { quantity = q; }
    void setStatus(const string& stt) { status = stt; }

    bool isAvailable() const { return quantity > 0; }
    
    void addAdvanceRequest(const std::string& username) {
        // Add username to a list of advance requests
    }

    void updateStatus(const std::string& newStatus) { status = newStatus; }

    void markAsBorrowed() {
        if (quantity > 0) {
            --quantity;
        }
        if (quantity == 0) {
            status = "Rented";
        }
    }

    void markAsReturned() {
        quantity++;
        if (status == "Rented" && quantity > 0) {
            status = "Available";
        }
    }

    //save book details to a file
    void saveToFile(ofstream& outfile) const {
        outfile << bookId << "," << title << "," << author << "," << genre << ","
            << publicationYear << "," << quantity << "," << status << endl;
    }

    //load book details from a line of text
    static Book* loadFromFile(const string& line) {
        stringstream ss(line);
        string id, title, author, genre, pubYear, qty, status;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, genre, ',');
        getline(ss, pubYear, ',');
        getline(ss, qty, ',');
        getline(ss, status, ',');

        // Check for empty strings and handle them
        if (id.empty() || pubYear.empty() || qty.empty()) {
            cerr << "Error: Missing data in line: " << line << endl;
            return nullptr; // Return nullptr if data is missing
        }

        try {
            int bookId = stoi(id);
            int publicationYear = stoi(pubYear);
            int quantity = stoi(qty);
            return new Book(bookId, title, author, genre, publicationYear, quantity, status);
        } catch (const std::invalid_argument& e) {
            cerr << "Error: Invalid number format in line: " << line << endl;
            return nullptr; // Return nullptr if stoi fails
        } catch (const std::out_of_range& e) {
            cerr << "Error: Number out of range in line: " << line << endl;
            return nullptr; // Handle out of range errors
        }
    }

};