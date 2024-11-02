#pragma once
#include "UserNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graphic.h"

class UserTree {
private:
    UserNode* root;
    User* currentUser;
    std::string currentUserName; 

    UserNode* insert(UserNode* node, User* user) {
        if (node == nullptr) {
            return new UserNode(user);
        }
        if (user->getUsername() < node->user->getUsername()) {
            node->left = insert(node->left, user);
        }
        else if (user->getUsername() > node->user->getUsername()) {
            node->right = insert(node->right, user);
        }
        return node;
    }

    User* search(UserNode* node, const string& username) const {
        if (node == nullptr || node->user->getUsername() == username) {
            return node ? node->user : nullptr;
        }
        if (username < node->user->getUsername()) {
            return search(node->left, username);
        }
        return search(node->right, username);
    }

    // Helper function for in-order traversal to display users
    void displayInOrder(UserNode* node) const {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << "Username: " << node->user->getUsername() << std::endl;
            displayInOrder(node->right);
        }
    }

    // Helper function to delete a user
    UserNode* deleteUser(UserNode* node, const string& username) {
        if (node == nullptr) return node;

        if (username < node->user->getUsername()) {
            node->left = deleteUser(node->left, username);
        }
        else if (username > node->user->getUsername()) {
            node->right = deleteUser(node->right, username);
        }
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                UserNode* temp = node->right;
                delete node->user;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                UserNode* temp = node->left;
                delete node->user;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor
            UserNode* temp = findMin(node->right);
            node->user = temp->user;
            node->right = deleteUser(node->right, temp->user->getUsername());
        }
        return node;
    }

    UserNode* findMin(UserNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void destroyTree(UserNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node->user;
            delete node;
        }
    }

    Date getBorrowDateForBook(User* user, int bookId) {
        return Date::currentDate(); 
    }

    

public:
    UserTree() : root(nullptr) {
        loadUsersFromFile("users.txt"); // Load users from file on initialization

        // Create the admin user and add it to the UserTree
        Date adminBirthday(1, 1, 2000);  // Example date for the admin
        User* adminUser = new User("Admin Name", adminBirthday, "admin@example.com", "admin", "admin123");
        addUser(adminUser);
    }

    ~UserTree() {
        destroyTree(root);
    }

    string getCurrentUserName() {
        return currentUserName; // Return the current user's username
    }

    // Function to insert a user
    void addUser(User* user) {
        root = insert(root, user);
    }

    // Function to search for a user by username
    User* searchUser(const string& username) const {
        return search(root, username);
    }

    // Function to display all users
    void displayUsers() const {
        displayInOrder(root);
    }

    // Function to delete a user by username
    void deleteUser(const string& username) {
        root = deleteUser(root, username);
    }

    // Function to handle user login
    bool login(const string& username, const string& password) {
        User* user = searchUser(username); // Corrected to use searchUser
        if (user) {
            if (user->getPassword() == password) {
                currentUserName = username; // This will now work
                return true; // Login successful
            }
            else {
                setColor(RED);
                std::cout << ".---------------------.\n";
                std::cout << "| Incorrect password. |\n";
                std::cout << "'---------------------'\n";
                setColor(RESET);
            }
        }
        else {
            setColor(RED);
            std::cout << ".------------------.\n";
            std::cout << "| User not found.  |\n";
            std::cout << "'------------------'\n";
            setColor(RESET);
        }
        return false; // Login failed
    }

    void createAccount() {
        User* newUser = User::createAccount();
        if (newUser) {
            addUser(newUser);
            setColor(GREEN);
            std::cout << ".------------------------------------.\n";
            std::cout << "| User account created successfully! |\n";
            std::cout << "'------------------------------------'\n";
            setColor(RESET);
        }
    }

    void updateUserInformation(const string& username) {
        // Search for the user to update
        User* user = searchUser(username);
        if (!user) {
            setColor(RED);
            std::cout << ".------------------.\n"; 
            std::cout << "| User not found.  |\n";
            std::cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        std::cout << "Updating information for user: " << username << std::endl;
        std::cout << "Current Name: " << user->getName() << std::endl;
        std::cout << "Enter new name (or leave empty to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            user->setName(newName);
        }

        std::cout << "Enter new password (or leave empty to keep current): ";
        string newPassword;
        getline(cin, newPassword);
        if (!newPassword.empty()) {
            user->setPassword(newPassword);
        }

        std::cout << "Current Birthday: " << user->getBirthday().toString() << std::endl;
        std::cout << "Enter new birthday (dd mm yyyy, or leave empty to keep current): ";
        int newDay, newMonth, newYear;
        if (cin >> newDay >> newMonth >> newYear) {
            Date newBirthday(newDay, newMonth, newYear);
            if (newBirthday.isValid()) {
                user->setBirthday(newBirthday);
            } else {
                setColor(RED);
                std::cout << ".-------------------------------------------------.\n";
                std::cout << "| Invalid date entered. Keeping current birthday. |\n";
                std::cout << "'-------------------------------------------------'\n";
                setColor(RESET);
            }
        }
        cin.clear(); // Clear the input stream

        // Save updated user information to file
        saveUsersToFile("users.txt");
        setColor(RED);
        std::cout << ".----------------------------------------.\n";
        std::cout << "| User information updated successfully! |\n";
        std::cout << "'----------------------------------------'\n";
        setColor(RESET);
    }

    // Function to show rented books for the currently logged-in user
    void showRentedBooks() {
        std::string currentUser = getCurrentUserName();
        User* user = searchUser(currentUser);
        if (user) {
            const vector<int>& rentedBooks = user->getRentedBooks(); // Assuming this method exists
            if (rentedBooks.empty()) {
                setColor(YELLOW);
                std::cout << ".------------------.\n";
                std::cout << "| No books rented. |\n";
                std::cout << "'------------------'\n";
                setColor(RESET);
            } else {
                std::cout << "Rented Books for user " << currentUser << ":" << endl;
                for (int bookId : rentedBooks) {
                    std::cout << "Book ID: " << bookId << endl; // Modify to display book details if needed
                }
            }
        } else {
            setColor(RED);
            std::cout << ".-----------------.\n";
            std::cout << "| User not found. |\n";
            std::cout << "'-----------------'\n";
            setColor(RESET);
        }
    }

    void borrowBook(const string& username, const string& bookTitle, BSTree& bookTree) {
        User* user = searchUser(username);
        if (!user) {
            setColor(RED);
            std::cout << ".------------------.\n";
            std::cout << "| User not found.  |\n";
            std::cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        Book* book = bookTree.searchBookByTitle(bookTitle); // Assuming this retrieves a Book by ID
        if (!book) {
            setColor(RED);
            std::cout << ".------------------.\n";
            std::cout << "| Book not found.  |\n";
            std::cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        // Check if the book is available
        if (book->isAvailable()) {
            book->markAsBorrowed();  // Updates the book status and quantity
            user->rentBook(book->getBookId());  // Records the book in the user's borrowed books list

            Date borrowDate = Date::currentDate(); // Assume this defaults to the current date
            Date predictReturnDate = borrowDate.addDays(7);  // Predict return date = borrow date + 7 days

            // Save to file
            ofstream borrowFile("borrows.txt", ios::app);
            if (borrowFile.is_open()) {
                borrowFile << "User: " << username << ", Book Title: " << bookTitle 
                          << ", Borrow Date: " << borrowDate.toString() 
                          << ", Predicted Return Date: " << predictReturnDate.toString() 
                          << endl;
                borrowFile.close();
            }

            setColor(GREEN);
            std::cout << ".--------------------------------.\n";
            std::cout << "|  Book borrowed successfully!   |\n";
            std::cout << "'--------------------------------'\n";
            setColor(RESET);
        } else {
            registerBorrowInAdvance(username, book->getBookId(), bookTree);
        }
    }

    void registerBorrowInAdvance(const string& username, int bookId, BSTree& bookTree) {
        ofstream advanceFile("advance_borrows.txt", ios::app);
        if (advanceFile.is_open()) {
            advanceFile << "User: " << username << ", Book ID: " << bookId << endl;
            advanceFile.close();
        }
        setColor(BRIGHT_YELLOW);
        std::cout << ".-------------------------------------------------------------------------------------.\n";
        std::cout << "| Book is currently unavailable. You have registered to borrow it when it's returned. |\n";
        std::cout << "'-------------------------------------------------------------------------------------'\n";
        setColor(RESET);
    }

    Date getPredictedReturnDate(int bookId) {
        // Find the current user
        User* user = search(root, currentUserName); // Assuming currentUserName is set correctly
        if (!user) {
            setColor(RED);
            std::cout << ".-------------------.\n";
            std::cout << "|  User not found.  |\n";
            std::cout << "'-------------------'\n";
            setColor(RESET);
            return Date(); // Return a default date or handle error appropriately
        }

        // Retrieve the borrowed books of the current user
        const vector<int>& rentedBooks = user->getRentedBooks(); // Assuming this method exists
        if (std::find(rentedBooks.begin(), rentedBooks.end(), bookId) == rentedBooks.end()) {
            setColor(RED);
            std::cout << ".--------------------------------------------.\n";
            std::cout << "|  Book ID not found in user's rented books. |\n";
            std::cout << "'--------------------------------------------'\n";
            setColor(RESET);
            return Date(); // Return a default date or handle error appropriately
        }

        // Assuming you have a way to track the borrow date; if it's not available,
        // you might want to modify your User or Book classes to store it.
        Date borrowDate = getBorrowDateForBook(user, bookId); // This method needs to be implemented

        // Predict return date as borrow date + 7 days
        return borrowDate.addDays(7);
    }

    void returnBook(const string& username, const string& bookTitle, BSTree& bookTree) {
        User* user = searchUser(username);
        if (!user) {
            setColor(RED);
            std::cout << ".-------------------.\n";
            std::cout << "|  User not found.  |\n";
            std::cout << "'-------------------'\n";
            setColor(RESET);
            return;
        }

        Book* book = bookTree.searchBookByTitle(bookTitle);
        if (!book) {
            setColor(RED);
            std::cout << ".-----------------.\n";
            std::cout << "| Book not found. |\n";
            std::cout << "'-----------------'\n";
            setColor(RESET);
            return;
        }

        Date returnDate = Date::currentDate();  // Assume this defaults to the current date
        Date predictedReturnDate = getPredictedReturnDate(book->getBookId()); // Retrieve from borrow record

        int fine = 0;
        if (returnDate > predictedReturnDate) {
            fine = (returnDate.daysBetween(predictedReturnDate)) * 10000; // Calculate fine
        }

        book->markAsReturned();
        user->returnBook(book->getBookId());

        // Save return info to file
        ofstream returnFile("returns.txt", ios::app);
        if (returnFile.is_open()) {
            returnFile << "User: " << username << ", Book ID: " << book->getBookId() 
                    << ", Return Date: " << returnDate.toString() 
                    << ", Fine: " << fine << " VND" << endl;
            returnFile.close();
        }

        setColor(GREEN);
        std::cout << "Book returned successfully! Fine: " << fine << " VND" << std::endl;
        setColor(RESET);
    }

    // Function to save users to a file
    void saveUsersToFile(const string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            saveUsersToFile(root, outFile);
            outFile.close();
        }
        else {
            setColor(RED);
            std::cerr << ".---------------------------------.\n";
            std::cerr << "| Error opening file for writing. |\n";
            std::cerr << "'---------------------------------'\n";
            setColor(RESET);
        }
    }

    void saveUsersToFile(UserNode* node, std::ofstream& outFile) const {
        if (node != nullptr) {
            // Save user details in a structured format
            outFile << node->user->getUsername() << ","
                << node->user->getPassword() << ","
                << node->user->getName() << ","
                << node->user->getBirthday().getDay() << ","
                << node->user->getBirthday().getMonth() << ","
                << node->user->getBirthday().getYear() << std::endl;
            saveUsersToFile(node->left, outFile);
            saveUsersToFile(node->right, outFile);
        }
    }

    // Function to load users from a file
    void loadUsersFromFile(const string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                std::istringstream iss(line);
                string username, password, name;
                int day, month, year;
                if (std::getline(iss, username, ',') &&
                    std::getline(iss, password, ',') &&
                    std::getline(iss, name, ',') &&
                    (iss >> day) && (iss.ignore()) &&
                    (iss >> month) && (iss.ignore()) &&
                    (iss >> year)) {

                    Date birthday(day, month, year); // Assume Date has a suitable constructor
                    User* user = new User(name, birthday, "dummy@mail.com", username, password); // Use dummy email for now
                    addUser(user);
                }
            }
            inFile.close();
        }
        else {
            setColor(RED);
            std::cerr << ".-----------------------------------.\n";
            std::cerr << "|  Error opening file for reading.  |\n";
            std::cerr << "'-----------------------------------'\n";
            setColor(RESET);
        }
    }
};