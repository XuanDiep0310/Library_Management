#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
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

    //save book details to a file
    void saveToFile(ofstream& outfile) const {
        outfile << bookId << " ," << title << ", " << author << ", " << genre << ", "
            << publicationYear << ", " << quantity << ", " << status << endl;
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

        return new Book(stoi(id), title, author, genre, stoi(pubYear), stoi(qty), status);
    }
};

struct TreeNode {
    Book* book;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Book* b) : book(b), left(nullptr), right(nullptr) {}
};

class BSTree {
private:
    TreeNode* root;

    TreeNode* addBook(TreeNode* node, Book* book) {
        if (!node) return new TreeNode(book);

        if (book->getBookId() < node->book->getBookId())
            node->left = addBook(node->left, book);
        else if (book->getBookId() > node->book->getBookId())
            node->right = addBook(node->right, book);

        return node;
    }

    void saveBooksToFile(TreeNode* node, ofstream& outFile) const {
        if (node) {
            node->book->saveToFile(outFile);
            saveBooksToFile(node->left, outFile);
            saveBooksToFile(node->right, outFile);
        }
    }

    vector<Book*> searchBookByTitle(TreeNode* node, const string& title) const {
        vector<Book*> foundBooks;
        if (!node) return foundBooks;

        // Check current node's title
        if (node->book->getTitle() == title) {
            foundBooks.push_back(node->book);
        }

        // Search left and right subtrees
        vector<Book*> leftResults = searchBookByTitle(node->left, title);
        vector<Book*> rightResults = searchBookByTitle(node->right, title);

        // Combine results
        foundBooks.insert(foundBooks.end(), leftResults.begin(), leftResults.end());
        foundBooks.insert(foundBooks.end(), rightResults.begin(), rightResults.end());

        return foundBooks;
    }

    TreeNode* findMin(TreeNode* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    // Delete a book by title
    TreeNode* deleteBookByTitle(TreeNode* node, const string& title) {
        if (!node) return nullptr;

        // Traverse the tree to find the book with the specified title
        if (title < node->book->getTitle()) {
            node->left = deleteBookByTitle(node->left, title);
        }
        else if (title > node->book->getTitle()) {
            node->right = deleteBookByTitle(node->right, title);
        }
        else {
            // Title matches
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* minRight = findMin(node->right);
            node->book = minRight->book;
            node->right = deleteBookByTitle(node->right, minRight->book->getTitle());
        }
        return node;
    }

    void inorder(TreeNode* node) const {
        if (node) {
            inorder(node->left);
            cout << "Book ID: " << node->book->getBookId() << ", Title: " << node->book->getTitle()
                << ", Author: " << node->book->getAuthor() << ", Quantity: " << node->book->getQuantity() << endl;
            inorder(node->right);
        }
    }

public:
    BSTree() : root(nullptr) {}

    void addBook(int id, const string& title, const string& author, const string& genre,
        int publicationYear, int quantity, const string& status) {
        Book* newBook = new Book(id, title, author, genre, publicationYear, quantity, status);
        root = addBook(root, newBook);
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            saveBooksToFile(root, outFile);
            outFile.close();
            cout << "Library data saved successfully to " << filename << endl;
        }
        else {
            cout << "Error: Could not open file " << filename << " for writing." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        string line;

        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                Book* book = Book::loadFromFile(line);
                if (book) addBook(book->getBookId(), book->getTitle(), book->getAuthor(),
                    book->getGenre(), book->getPublicationYear(),
                    book->getQuantity(), book->getStatus());
            }
            inFile.close();
            cout << "Library data loaded successfully from " << filename << endl;
        }
        else {
            cout << "Error: Could not open file " << filename << " for reading." << endl;
        }
    }

    vector<Book*> searchBook(const string& title) const {
        return searchBookByTitle(root, title);
    }

    void deleteBookByTitle(const string& title) {
        root = deleteBookByTitle(root, title);
    }

    void displayBooks() const {
        inorder(root);
    }
};

