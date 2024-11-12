#pragma once
#include "Book.h"
#include <iostream>
using namespace std;

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

        // Convert both the title and node's book title to lowercase for case-insensitive comparison
        string bookTitleLower = node->book->getTitle();
        string titleLower = title;
        transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);

        // Compare the lowercase versions of the titles
        if (bookTitleLower == titleLower) {
            return node->book; // Found the exact match
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

    // Helper function to delete a book by title, case-insensitive
    TreeNode* deleteBookByTitle(TreeNode* node, const string& title, bool& deleted) {
        if (!node) return nullptr;

        // Convert both the node title and the search title to lowercase for case-insensitive comparison
        string bookTitleLower = node->book->getTitle();
        string titleLower = title;
        transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);

        // Compare the lowercase titles
        if (titleLower < bookTitleLower) {
            node->left = deleteBookByTitle(node->left, title, deleted);
        }
        else if (titleLower > bookTitleLower) {
            node->right = deleteBookByTitle(node->right, title, deleted);
        }
        else {
            // Found the node to delete
            deleted = true;
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

            // Node with two children: Get the inorder successor
            TreeNode* minRight = findMin(node->right);
            node->book = minRight->book;
            node->right = deleteBookByTitle(node->right, minRight->book->getTitle(), deleted);
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
        regex updatingPattern(R"(^\s*(updat|upd|up|u|updating)\s*$)");

        // Match against each status pattern
        if (regex_search(loweredInput, availablePattern)) return "Available";
        if (regex_match(loweredInput, updatingPattern)) return "Updating";

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
            cout << ".----------------------------------------.\n";
            cout << "| Book found. Choose information to edit |\n";
            cout << "'----------------------------------------'\n";
            setColor(RESET);

            int choice = -1;
            do {
                setColor(BRIGHT_CYAN);
                cout << "\n.------------------------------.\n";
                setColor(CYAN);
                cout << "|  Select an option to update  |\n";
                setColor(BRIGHT_BLUE);
                cout << "|------------------------------|\n";
                setColor(BLUE);
                cout << "|  1. Title                    |\n";
                setColor(BRIGHT_MAGENTA);
                cout << "|------------------------------|\n";
                setColor(MAGENTA);
                cout << "|  2. Author                   |\n";
                setColor(BRIGHT_RED);
                cout << "|------------------------------|\n";
                setColor(RED);
                cout << "|  3. Genre                    |\n";
                setColor(BRIGHT_YELLOW);
                cout << "|------------------------------|\n";
                setColor(YELLOW);
                cout << "|  4. Publication Year         |\n";
                setColor(BRIGHT_GREEN);
                cout << "|------------------------------|\n";
                setColor(GREEN);
                cout << "|  5. Quantity                 |\n";
                setColor(BRIGHT_CYAN);
                cout << "|------------------------------|\n";
                setColor(CYAN);
                cout << "|  6. Status                   |\n";
                setColor(BRIGHT_BLUE);
                cout << "|------------------------------|\n";
                setColor(BLUE);
                cout << "|  0. Done                     |\n";
                setColor(BRIGHT_MAGENTA);
                cout << "'------------------------------'\n";
                setColor(RESET);
                cout << "Enter your choice: ";

                cin >> choice;
                cin.ignore(); // To ignore the newline after the choice

                switch (choice) {
                    case 1: {
                        string newTitle;
                        setColor(CYAN);
                        cout << "Enter new Title (current: " << bookToUpdate->getTitle() << "): ";
                        setColor(RESET);
                        getline(cin, newTitle);
                        if (!newTitle.empty()) bookToUpdate->setTitle(newTitle);
                        break;
                    }
                    case 2: {
                        string newAuthor;
                        setColor(CYAN);
                        cout << "Enter new Author (current: " << bookToUpdate->getAuthor() << "): ";
                        setColor(RESET);
                        getline(cin, newAuthor);
                        if (!newAuthor.empty()) bookToUpdate->setAuthor(newAuthor);
                        break;
                    }
                    case 3: {
                        string newGenre;
                        setColor(CYAN);
                        cout << "Enter new Genre (current: " << bookToUpdate->getGenre() << "): ";
                        setColor(RESET);
                        getline(cin, newGenre);
                        if (!newGenre.empty()) bookToUpdate->setGenre(newGenre);
                        break;
                    }
                    case 4: {
                        int newPubYear;
                        setColor(CYAN);
                        cout << "Enter new Publication Year (current: " << bookToUpdate->getPublicationYear() << "): ";
                        setColor(RESET);
                        if (cin >> newPubYear && newPubYear > 0) {
                            bookToUpdate->setPublicationYear(newPubYear);
                        } else {
                            setColor(RED);
                            cout << ".--------------------------------------------------.\n";
                            cout << "| Invalid Publication Year. Keeping current value. |\n";
                            cout << "'--------------------------------------------------'\n";
                            setColor(RESET);
                            cin.clear();
                        }
                        cin.ignore();
                        break;
                    }
                    case 5: {
                        int newQuantity;
                        setColor(CYAN);
                        cout << "Enter new Quantity (current: " << bookToUpdate->getQuantity() << "): ";
                        setColor(RESET);
                        if (cin >> newQuantity && newQuantity >= 0) {
                            bookToUpdate->setQuantity(newQuantity);
                        } else {
                            setColor(RED);
                            cout << ".------------------------------------------.\n";
                            cout << "| Invalid Quantity. Keeping current value. |\n";
                            cout << "'------------------------------------------'\n";
                            setColor(RESET);
                            cin.clear();
                        }
                        cin.ignore();
                        break;
                    }
                    case 6: {
                        string newStatus;
                        do {
                            setColor(CYAN);
                            cout << "Enter new Status (current: " << bookToUpdate->getStatus() << "): ";
                            setColor(RESET);
                            getline(cin, newStatus);
                            newStatus = matchStatus(newStatus);
                            if (!newStatus.empty()) {
                                bookToUpdate->setStatus(newStatus);
                            } else {
                                setColor(RED);
                                cout << ".----------------------------------------.\n";
                                cout << "| Invalid Status. Keeping current value. |\n";
                                cout << "'----------------------------------------'\n";
                                setColor(RESET);
                            }
                        } while (newStatus.empty());
                        break;
                    }
                    case 0:
                        setColor(GREEN);
                        cout << "\n.----------------------------------------.\n";
                        cout << "| Book information update completed.     |\n";
                        cout << "'----------------------------------------'\n";
                        setColor(RESET);
                        break;
                    default:
                        setColor(RED);
                        cout << ".-----------------------------------.\n";
                        cout << "| Invalid choice. Please try again. |\n";
                        cout << "'-----------------------------------'\n";
                        setColor(RESET);
                        break;
                }
            } while (choice != 0);
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

    bool deleteBookByTitle(const string& title) {
        bool deleted = false;
        root = deleteBookByTitle(root, title, deleted);
        return deleted;
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