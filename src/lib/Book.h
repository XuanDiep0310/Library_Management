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

    Book* searchBookByTitle(TreeNode* node, const string& title) const {
        if (node == nullptr) {
            return nullptr; // Không tìm thấy
        }

        // So sánh tiêu đề của sách với tiêu đề tìm kiếm
        if (node->book->getTitle() == title) {
            return node->book; // Trả về con trỏ đến sách nếu tìm thấy
        }

        // Tìm kiếm trong cây bên trái
        Book* leftResult = searchBookByTitle(node->left, title);
        if (leftResult != nullptr) {
            return leftResult;
        }

        // Tìm kiếm trong cây bên phải
        return searchBookByTitle(node->right, title);
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

    void printHeader() const {
        cout << string(97, '-') << endl;
        cout << left 
            << setw(12) << "Book ID"
            << setw(35) << "Title"
            << setw(25) << "Author"
            << setw(10) << "Quantity"
            << setw(15) << "Status" 
            << endl;
        cout << string(97, '-') << endl;  // Adjust separator to match column width
    }

    void inorder(TreeNode* node) const {
        if (node) {
            inorder(node->left);

            setColor(GREEN);
            cout << left 
                << setw(12) << node->book->getBookId()
                << setw(35) << node->book->getTitle()
                << setw(25) << node->book->getAuthor()
                << setw(10) << node->book->getQuantity()
                << setw(15) << node->book->getStatus() 
                << endl;
            setColor(RESET);

            inorder(node->right);
        }
    }

public:
    BSTree() : root(nullptr) {}

    string matchStatus(const string& input) {
        // Convert the input to lowercase for case-insensitive matching
        string loweredInput = input;
        transform(loweredInput.begin(), loweredInput.end(), loweredInput.begin(), ::tolower);

        // Define regular expressions for each status
        regex availablePattern(R"(.*\b(avail|avai|av|a|available)\b.*)");
        regex rentedPattern(R"(.*\b(rent|rented|r)\b.*)");

        // Match against each status pattern
        if (regex_search(loweredInput, availablePattern)) return "Available";
        if (regex_search(loweredInput, rentedPattern)) return "Rented";

        return ""; // No valid status found
    }

    void addBook(int id, const string& title, const string& author, const string& genre,
        int publicationYear, int quantity, const string& status) {
        Book* newBook = new Book(id, title, author, genre, publicationYear, quantity, status);
        root = addBook(root, newBook);
    }

    Book* getBookById(int bookId) const {
        return getBookById(root, bookId);
    }

    Book* getBookById(TreeNode* node, int bookId) const {
        if (!node) return nullptr; // Book not found

        if (node->book->getBookId() == bookId)
            return node->book;
        else if (bookId < node->book->getBookId())
            return getBookById(node->left, bookId);
        else
            return getBookById(node->right, bookId);
    }

    Book* searchBookByTitle(const string& title) const {
        return searchBookByTitle(root, title);
    }

    void updateBookInformation(const string& title) {
        Book* bookToUpdate = searchBookByTitle(title);
        if (bookToUpdate != nullptr) {
            setColor(GREEN);
            cout << ".----------------------------------------------------------------------------.\n";
            cout << "|  Book found. Enter new information (leave blank to keep current values):   |\n";
            cout << "'----------------------------------------------------------------------------'\n";
            setColor(RESET);

            string newTitle, newAuthor, newGenre, newStatus;
            int newPubYear = -1, newQuantity = -1;

            setColor(CYAN);
            cout << "Enter new Title (current: " << bookToUpdate->getTitle() << "): ";
            getline(cin, newTitle);
            if (!newTitle.empty()) bookToUpdate->setTitle(newTitle);

            cout << "Enter new Author (current: " << bookToUpdate->getAuthor() << "): ";
            getline(cin, newAuthor);
            if (!newAuthor.empty()) bookToUpdate->setAuthor(newAuthor);

            cout << "Enter new Genre (current: " << bookToUpdate->getGenre() << "): ";
            getline(cin, newGenre);
            if (!newGenre.empty()) bookToUpdate->setGenre(newGenre);

            cout << "Enter new Publication Year (current: " << bookToUpdate->getPublicationYear() << "): ";
            if (cin >> newPubYear && newPubYear > 0) {
                bookToUpdate->setPublicationYear(newPubYear);
            } else {
                setColor(RED);
                cout << "Invalid Publication Year. Keeping current value.\n";
                setColor(RESET);
                cin.clear(); // Clear error flag
            }
            cin.ignore(); // Clear newline character

            cout << "Enter new Quantity (current: " << bookToUpdate->getQuantity() << "): ";
            if (cin >> newQuantity && newQuantity >= 0) {
                bookToUpdate->setQuantity(newQuantity);
            } else {
                setColor(RED);
                cout << "Invalid Quantity. Keeping current value.\n";
                setColor(RESET);
                cin.clear();
            }
            cin.ignore(); // Clear newline character

            do {
                cout << "Enter new Status (current: " << bookToUpdate->getStatus() << "): ";
                getline(cin, newStatus);
                newStatus = matchStatus(newStatus);
                if (!newStatus.empty()) {
                    bookToUpdate->setStatus(newStatus);
                } else if (!newStatus.empty()) {
                    setColor(RED);
                    cout << "Invalid Status. Keeping current value.\n";
                    setColor(RESET);
                }
            } while (!newStatus.empty() && newStatus.empty()); // Repeat until valid

            clearScreen();
            setColor(GREEN);
            cout << ".----------------------------------------.\n";
            cout << "| Book information updated successfully! |\n";
            cout << "'----------------------------------------'\n";
            setColor(RESET);
        } else {
            setColor(RED);
            cout << "<- No book found with title \"" << title << "\". ->" << endl;
            setColor(RESET);
        }
    }

    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            saveBooksToFile(root, outFile);
            outFile.close();
            setColor(GREEN);
            cout << "Library data saved successfully to " << filename << endl;
            setColor(RESET);
        }
        else {
            setColor(RED);
            cout << "Error: Could not open file " << filename << " for writing." << endl;
            setColor(RESET);
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
            setColor(GREEN);
            cout << "Library data loaded successfully from " << filename << endl;
            setColor(RESET);
        }
        else {
            setColor(RED);
            cout << "Error: Could not open file " << filename << " for reading." << endl;
            setColor(RESET);
        }
    }

    Book* searchBook(const string& title) const {
        return searchBookByTitle(root, title);
    }

    void deleteBookByTitle(const string& title) {
        root = deleteBookByTitle(root, title);
    }

    void displayBooks() const {
        BSTree::printHeader();
        inorder(root);
    }

    vector<Book*> getSuggestionsByTitle(const string& partialTitle) const {
        vector<Book*> matches;
        getSuggestionsByTitle(root, partialTitle, matches);
        return matches;
    }

    void getSuggestionsByTitle(TreeNode* node, const string& partialTitle, vector<Book*>& matches) const {
        if (!node) return;

        // Convert both strings to lowercase for case-insensitive comparison
        string bookTitleLower = node->book->getTitle();
        string partialTitleLower = partialTitle;
        transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        transform(partialTitleLower.begin(), partialTitleLower.end(), partialTitleLower.begin(), ::tolower);

        // If the title contains the partial title, add to suggestions
        if (bookTitleLower.find(partialTitleLower) != string::npos) {
            matches.push_back(node->book);
        }

        getSuggestionsByTitle(node->left, partialTitle, matches);
        getSuggestionsByTitle(node->right, partialTitle, matches);
    }

};

