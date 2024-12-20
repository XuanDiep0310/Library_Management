#pragma once
#include "UserNode.h"
#include "BookTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Graphic.h"

using namespace std;

class UserTree {
private:
    UserNode* root;
    User* currentUser;
    string currentUserName; 

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

    User* search(UserNode* node, const string& email) const {
        ifstream file("users.txt");
        if (!file.is_open()) {
            cerr << "Error: Could not open users.txt" << endl;
            return nullptr;
        }

        string lowerEmail = email;
        transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);
        lowerEmail = trim(lowerEmail);

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> fields;
            string field;

            // Split line by commas to populate the fields
            while (getline(iss, field, ',')) {
                fields.push_back(field);
            }

            // Verify the file has enough fields (assuming email is the 4th field, zero-indexed)
            if (fields.size() >= 7) {  // Ensure we have all 7 fields from the file
                string fileEmail = fields[3]; // The email should be at index 3
                transform(fileEmail.begin(), fileEmail.end(), fileEmail.begin(), ::tolower);
                fileEmail = trim(fileEmail);

                if (fileEmail == lowerEmail) {
                    // Debugging output to verify data
                    cout << "Found matching email: " << fileEmail << endl;
                    cout << "User data from file: " << endl;
                    cout << "Username: " << fields[0] << endl;
                    cout << "Password: " << fields[1] << endl;
                    cout << "Name: " << fields[2] << endl;
                    cout << "Email: " << fields[3] << endl;
                    cout << "Birthdate: " << fields[4] << "/" << fields[5] << "/" << fields[6] << endl;

                    // Create and return a new User object with the parsed data
                    string username = fields[0];        // Username
                    string password = fields[1];        // Password
                    string name = fields[2];            // Name
                    string email = fields[3];           // Email
                    int birthDay = stoi(fields[4]);     // Birth date day
                    int birthMonth = stoi(fields[5]);   // Birth date month
                    int birthYear = stoi(fields[6]);    // Birth date year
                    Date birthday(birthDay, birthMonth, birthYear);

                    // Close the file and return the user found
                    file.close();
                    return new User(name, birthday, email, username, password);
                }
            }
        }

        // If no user found, close the file and return nullptr
        file.close();
        return nullptr;
    }

    User* searchByUsername(UserNode* node, const string& username) const {
        ifstream file("users.txt");
        if (!file.is_open()) {
            cerr << "Error: Could not open users.txt" << endl;
            return nullptr;
        }

        string lowerUsername = username;
        transform(lowerUsername.begin(), lowerUsername.end(), lowerUsername.begin(), ::tolower);
        lowerUsername = trim(lowerUsername);

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> fields;
            string field;

            // Split line by commas to populate the fields
            while (getline(iss, field, ',')) {
                fields.push_back(field);
            }

            // Verify the file has enough fields (assuming username is the 1st field, zero-indexed)
            if (fields.size() >= 7) {  // Ensure we have all 7 fields from the file
                string fileUsername = fields[0]; // Username should be at index 0
                transform(fileUsername.begin(), fileUsername.end(), fileUsername.begin(), ::tolower);
                fileUsername = trim(fileUsername);

                if (fileUsername == lowerUsername) {
                    // Create and return a new User object with the parsed data
                    string username = fields[0];        // Username
                    string password = fields[1];        // Password
                    string name = fields[2];            // Name
                    string email = fields[3];           // Email
                    int birthDay = stoi(fields[4]);     // Birth date day
                    int birthMonth = stoi(fields[5]);   // Birth date month
                    int birthYear = stoi(fields[6]);    // Birth date year
                    Date birthday(birthDay, birthMonth, birthYear);

                    // Close the file and return the user found
                    file.close();
                    return new User(name, birthday, email, username, password);
                }
            }
        }

        // If no user found, close the file and return nullptr
        file.close();
        return nullptr;
    }

    void printHeader() const {
        // Print table header
        cout << left << setw(20) << "Username" 
                  << setw(20) << "Password" 
                  << setw(30) << "Email" 
                  << setw(15) << "Birthday" << endl;
        cout << string(85, '-') << endl; // Print a separator line
    }

    // Helper function for in-order traversal to display users
    void displayInOrder(UserNode* node) const {
        if (node != nullptr) {
            displayInOrder(node->left); // Traverse left

            // Print header only once before the first user is printed
            static bool headerPrinted = false;
            if (!headerPrinted) {
                headerPrinted = true; // Ensure header is printed only once
            }

            // Print user information in a formatted manner
            cout << left << setw(20) << node->user->getUsername() 
                      << setw(20) << node->user->getPassword() 
                      << setw(30) << node->user->getMail() 
                      << setw(15) << node->user->getBirthday().toString() << endl;

            displayInOrder(node->right); // Traverse right
        }
    }

    // Helper function to delete a user
    UserNode* deleteUser(UserNode* node, const string& email) {
        if (node == nullptr) return node;

        string lowerEmail = email;
        transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);
        string nodeEmail = node->user->getMail();
        transform(nodeEmail.begin(), nodeEmail.end(), nodeEmail.begin(), ::tolower);

        if (lowerEmail < nodeEmail) {
            node->left = deleteUser(node->left, email);
        } else if (lowerEmail > nodeEmail) {
            node->right = deleteUser(node->right, email);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                UserNode* temp = node->right;
                delete node->user;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                UserNode* temp = node->left;
                delete node->user;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor
            UserNode* temp = findMin(node->right);
            node->user = temp->user;
            node->right = deleteUser(node->right, temp->user->getMail());
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

    // Helper method to collect all users
    void collectUsers(UserNode* node, vector<User*>& users) {
        if (node != nullptr) {
            collectUsers(node->left, users);
            users.push_back(node->user);
            collectUsers(node->right, users);
        }
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

    // Function to perform a case-insensitive substring search
    bool caseInsensitiveContains(const string& str, const string& substr) {
        string strLower = str;
        string substrLower = substr;
        transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
        transform(substrLower.begin(), substrLower.end(), substrLower.begin(), ::tolower);
        return strLower.find(substrLower) != string::npos;
    }

    void suggestUsersByEmail(UserNode* node, const string& partialEmail, vector<User*>& suggestions) {
        if (node == nullptr) {
            return;
        }

        // Perform in-order traversal to maintain sorted order of suggestions
        suggestUsersByEmail(node->left, partialEmail, suggestions);

        // Check if the email contains the partial input (case-insensitive)
        if (caseInsensitiveContains(node->user->getMail(), partialEmail)) {
            suggestions.push_back(node->user);
        }

        suggestUsersByEmail(node->right, partialEmail, suggestions);
    }

    // Public method to get user suggestions by partial username
    vector<string> suggestUsersByEmail(const string& filename, const string& partialEmail) {
        vector<string> suggestions;
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Unable to open " << filename << endl;
            return suggestions;
        }

        string line;
        string lowerPartialEmail = partialEmail;
        transform(lowerPartialEmail.begin(), lowerPartialEmail.end(), lowerPartialEmail.begin(), ::tolower);

        while (getline(file, line)) {
            // Split line by commas to get email (assuming email is the 4th field)
            istringstream iss(line);
            vector<string> fields;
            string field;

            while (getline(iss, field, ',')) {
                fields.push_back(field);
            }

            if (fields.size() >= 4) { // Ensure there are at least 4 fields
                string email = fields[3];
                string lowerEmail = email;
                transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);

                if (lowerEmail.find(lowerPartialEmail) == 0) { // Check if email starts with input
                    suggestions.push_back(email);
                }
            }
        }

        file.close();
        return suggestions;
    }

    // Method to get all users
    vector<User*> getAllUsers() {
        vector<User*> users;
        collectUsers(root, users);
        return users;
    }

    // Function to search for a user by username
    User* searchUser(const string& email) const {
        return search(root, email);
    }

    User* searchUserByUsername(const string& username) const {
        return searchByUsername(root, username);
    }

    // Function to display all users
    void displayUsers() const {
        printHeader();
        displayInOrder(root);
    }

    // Function to delete a user by username
    void deleteUser(const string& email) {
        root = deleteUser(root, email);
    }

    // Function to handle user login
    bool login(const string& username, const string& password) {
        User* user = searchUserByUsername(username); // Corrected to use searchUser
        if (user) {
            if (user->getPassword() == password) {
                currentUserName = username; // Set current user
                return true; // Login successful
            } else {
                setColor(RED);
                cout << ".---------------------.\n";
                cout << "| Incorrect password. |\n";
                cout << "'---------------------'\n";
                setColor(RESET);
            }
        } else {
            setColor(RED);
            cout << ".------------------.\n";
            cout << "| User not found.  |\n";
            cout << "'------------------'\n";
            setColor(RESET);
        }
        return false; // Login failed
    }

    void createAccount() {
        User* newUser = User::createAccount(getAllUsers());
        if (newUser) {
            addUser(newUser);
            setColor(GREEN);
            cout << ".------------------------------------.\n";
            cout << "| User account created successfully! |\n";
            cout << "'------------------------------------'\n";
            setColor(RESET);
        } else {
            setColor(RED);
            cout << ".----------------------------------------------.\n";
            cout << "| Account creation canceled or duplicate email |\n";
            cout << "'----------------------------------------------'\n";
            setColor(RESET);
        }
    }

    void updateUserInformation(const string& email) {
        // Convert the email to lowercase for case-insensitive search
        string lowerEmail = email;
        transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);

        // Search for the user to update by email
        User* user = searchUser(lowerEmail);
        if (!user) {
            setColor(RED);
            cout << ".------------------.\n"; 
            cout << "| User not found.  |\n";
            cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        setColor(YELLOW);
        cout << "Updating information for user: " << email << endl;
        setColor(BRIGHT_YELLOW);

        bool continueUpdating = true;
        bool hasChanges = false;
        while (continueUpdating) {
            // Display Menu to Update User Information
            setColor(RED);
            cout << "\n.------------------------------------.\n";
            setColor(BRIGHT_BLUE);
            cout << "|  Select the information to update  |\n";
            setColor(CYAN);
            cout << "|------------------------------------|\n";
            setColor(MAGENTA);
            cout << "|  1. Name                           |\n";
            setColor(RESET);
            cout << "|------------------------------------|\n";
            setColor(RED);
            cout << "|  2. Email                          |\n";
            setColor(BRIGHT_CYAN);
            cout << "|------------------------------------|\n";
            setColor(BRIGHT_YELLOW);
            cout << "|  3. Password                       |\n";
            setColor(BRIGHT_RED);
            cout << "|------------------------------------|\n";
            setColor(BRIGHT_BLUE);
            cout << "|  4. Birthday                       |\n";
            setColor(BRIGHT_MAGENTA);
            cout << "|------------------------------------|\n";
            setColor(YELLOW);
            cout << "|  5. Cancel                         |\n";
            setColor(CYAN);
            cout << "'------------------------------------'\n";
            setColor(RESET);
            
            // Get User's Choice
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

            switch (choice) {
                case 1: {
                    // Get new name
                    setColor(BRIGHT_BLUE);
                    cout << "Current Name: " << user->getName() << endl;
                    cout << "Enter new name (or leave empty to keep current): ";
                    string newName;
                    getline(cin, newName);
                    if (isExitCommand(newName)) {
                        continueUpdating = false; // Exit to menu
                        break;
                    }
                    if (!newName.empty()) {
                        user->setName(newName);
                        hasChanges = true; 
                    }
                    setColor(RESET);
                    break;
                }
                case 2: {
                    // Get new email with duplicate check
                    string newEmail;
                    bool validEmail = false;
                    vector<User*> existingUsers = getAllUsers(); // Get existing users for duplicate check
                    do {
                        setColor(BRIGHT_MAGENTA);
                        cout << "Enter new Email (or leave empty to keep current): ";
                        getline(cin, newEmail);
                        if (isExitCommand(newEmail)) {
                            continueUpdating = false; // Exit to menu
                            break;
                        }
                        setColor(RESET);

                        // Check for existing email only if the user is changing the email
                        if (!newEmail.empty()) {
                            auto emailIt = find_if(existingUsers.begin(), existingUsers.end(), [&](User* u) {
                                return u->getMail() == newEmail;
                            });

                            if (!User::isEmailFormatValid(newEmail)) {
                                setColor(RED);
                                cout << ".------------------------------------------------------------.\n";
                                cout << "| Invalid email format. Please enter a valid email format.  |\n";
                                cout << "'------------------------------------------------------------'\n";
                                setColor(RESET);
                                system("pause");
                            } else if (emailIt != existingUsers.end()) {
                                setColor(RED);
                                cout << ".-----------------------------------------------------.\n";
                                cout << "| Email already exists. Please use a different email. |\n";
                                cout << "'-----------------------------------------------------'\n";
                                setColor(RESET);
                                system("pause");
                            } else {
                                validEmail = true; // Email is valid, exit the loop
                                user->setMail(newEmail);
                                hasChanges = true;
                            }
                        } else {
                            validEmail = true; // No new email provided, keep the current one
                        }
                    } while (!validEmail);
                    break;
                }
                case 3: {
                    // Get new password
                    setColor(BLUE);
                    cout << "Enter new password (or leave empty to keep current): ";
                    string newPassword;
                    getline(cin, newPassword);
                    if (isExitCommand(newPassword)) {
                        continueUpdating = false; // Exit to menu
                        break;
                    }
                    if (!newPassword.empty()) {
                        user->setPassword(newPassword);
                        hasChanges = true;
                    }
                    setColor(RESET);
                    break;
                }
                case 4: {
                    // Get new birthday
                    setColor(CYAN);
                    cout << "Current Birthday: " << user->getBirthday().toString() << endl;
                    bool validDate = false;
                    int newDay, newMonth, newYear;

                    do {
                        cout << "Enter new birthday (dd mm yyyy, or leave empty to keep current): ";
                        string dateInput;
                        getline(cin, dateInput);

                        if (isExitCommand(dateInput)) {
                            continueUpdating = false; // Exit to menu
                            break;
                        }

                        if (!dateInput.empty()) {
                            istringstream dateStream(dateInput);
                            dateStream >> newDay >> newMonth >> newYear;

                            if (!dateStream.fail() && Date::isValidDate(newDay, newMonth, newYear)) {
                                Date newBirthday(newDay, newMonth, newYear);
                                Date currentDate = Date::currentDate();

                                if (newBirthday < currentDate) { // Ensure the date is not in the future
                                    user->setBirthday(newBirthday);
                                    hasChanges = true;
                                    validDate = true; // Exit loop
                                } else {
                                    setColor(RED);
                                    cout << ".--------------------------------------------------.\n";
                                    cout << "| Birthday cannot be today or in the future.       |\n";
                                    cout << "'--------------------------------------------------'\n";
                                    setColor(RESET);
                                    system("pause");
                                }
                            } else {
                                setColor(RED);
                                cout << ".--------------------------------------------------.\n";
                                cout << "| Invalid date entered. Please enter a valid date. |\n";
                                cout << "'--------------------------------------------------'\n";
                                setColor(RESET);
                                system("pause");
                            }
                        } else {
                            validDate = true; // No new date provided, keep the current one
                        }
                    } while (!validDate);

                    setColor(RESET);
                    break;
                }
                case 5: {
                    // Exit to menu
                    continueUpdating = false;
                    break;
                }
                default:
                    setColor(RED);
                    cout << ".-----------------------------------------------.\n";
                    cout << "| Invalid choice! Please select a valid option. |\n";
                    cout << "'-----------------------------------------------'\n";
                    setColor(RESET);
                    break;
            }

            // Save updated user information to file after all changes
            if (hasChanges) {
                saveUsersToFile("users.txt");
                setColor(GREEN);
                cout << ".----------------------------------------.\n";
                cout << "| User information updated successfully! |\n";
                cout << "'----------------------------------------'\n";
                setColor(RESET);
            }
        }
    }

    void showRentedBooks() {
        string currentUser = getCurrentUserName();  // Get the current username
        if (currentUser.empty()) {
            setColor(RED);
            cout << ".---------------------------------.\n";
            cout << "| No user is currently logged in. |\n";
            cout << "'---------------------------------'\n";
            setColor(RESET);
            return;
        }

        ifstream borrowedFile("borrows.txt");
        bool hasRentedBooks = false;

        if (!borrowedFile.is_open()) {
            setColor(RED);
            cout << ".-------------------------------.\n";
            cout << "| Failed to open borrows.txt.   |\n";
            cout << "'-------------------------------'\n";
            setColor(RESET);
            return;
        }

        // Table headers
        setColor(BRIGHT_MAGENTA);
        cout << "Rented Books for user "; 
        setColor(BLUE); 
        cout << currentUser; 
        setColor(RESET); 
        setColor(BRIGHT_MAGENTA); 
        cout << ":\n\n"; 
        setColor(RESET);

        setColor(CYAN);
        cout << string(83, '-') << "\n";  // Table border
        cout << setfill(' ') << left << setw(30) << "| Book Title" 
                << setw(30) << "Borrow Date" 
                << setw(25) << "Predicted Return Date |" << "\n";
        cout << string(83, '-') << "\n";  // Table border
        setColor(RESET);

        // Read file and populate table rows
        string line;
        while (getline(borrowedFile, line)) {
            stringstream ss(line);
            string username, id, bookTitle, author, category, year, quantityStr, borrowDate, returnDate;

            // Parse fields from line
            getline(ss, username, ','); // Read username
            getline(ss, id, ',');
            getline(ss, bookTitle, ',');
            getline(ss, author, ',');
            getline(ss, category, ',');
            getline(ss, year, ',');
            getline(ss, quantityStr, ',');
            getline(ss, borrowDate, ',');
            getline(ss, returnDate);

            // Remove the "User: " prefix if it exists in the username
            size_t pos = username.find("User: ");
            if (pos != string::npos) {
                username = username.substr(pos + 6);  // Remove the "User: " part
            }

            // Check if this borrow record belongs to the current user
            if (username == currentUser) {
                hasRentedBooks = true;

                // Print each row with formatted columns
                cout << setfill(' ') << left << setw(30) << bookTitle
                        << setw(30) << borrowDate
                        << setw(25) << returnDate << "\n";
            }
        }

        if (!hasRentedBooks) {
            setColor(RED);
            cout << ".------------------.\n";
            cout << "| No books rented. |\n";
            cout << "'------------------'\n";
            setColor(RESET);
        }

        borrowedFile.close();
    }

    void borrowBook(const string& username, const string& bookTitle, BSTree& bookTree) {
        string filename = "books.txt";
        User* user = searchUserByUsername(username);
        if (!user) {
            setColor(RED);
            cout << ".------------------.\n";
            cout << "| User not found.  |\n";
            cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        Book* book = bookTree.searchBookByTitle(bookTitle); // Retrieve book by title
        if (!book) {
            setColor(RED);
            cout << ".------------------.\n";
            cout << "| Book not found.  |\n";
            cout << "'------------------'\n";
            setColor(RESET);
            return;
        }

        // If the book is available, put it in "pending approval" state
        if (book->isAvailable()) {
            // Save request to borrow_request.txt for admin approval
            ofstream borrowRequestFile("borrow_request.txt", ios::app);
            if (borrowRequestFile.is_open()) {
                borrowRequestFile << "User: " << username << ", Book Title: " << bookTitle << ", Status: Pending" << endl;
                borrowRequestFile.close();
            }

            setColor(YELLOW);
            cout << ".----------------------------.\n";
            cout << "| Book request is pending... |\n";
            cout << "'----------------------------'\n";
            setColor(RESET);
        } else {
            // If the book is not available, register the request for future approval
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
        cout << ".-------------------------------------------------------------------------------------.\n";
        cout << "| Book is currently unavailable. You have registered to borrow it when it's returned. |\n";
        cout << "'-------------------------------------------------------------------------------------'\n";
        setColor(RESET);
    }

    Date getPredictedReturnDate(int bookId) {
        // Find the current user
        User* user = search(root, currentUserName); // Assuming currentUserName is set correctly
        if (!user) {
            setColor(RED);
            cout << ".-------------------.\n";
            cout << "|  User not found.  |\n";
            cout << "'-------------------'\n";
            setColor(RESET);
            return Date(); // Return a default date or handle error appropriately
        }

        // Retrieve the borrowed books of the current user
        const vector<int>& rentedBooks = user->getRentedBooks(); // Assuming this method exists
        if (find(rentedBooks.begin(), rentedBooks.end(), bookId) == rentedBooks.end()) {
            setColor(RED);
            cout << ".--------------------------------------------.\n";
            cout << "|  Book ID not found in user's rented books. |\n";
            cout << "'--------------------------------------------'\n";
            setColor(RESET);
            return Date(); // Return a default date or handle error appropriately
        }

        Date borrowDate = getBorrowDateForBook(user, bookId); // This method needs to be implemented

        // Predict return date as borrow date + 7 days
        return borrowDate.addDays(7);
    }

    // Function to get borrowed books for the currently logged-in user
    vector<Book*> getBorrowedBooks(const string& username) {
        User* user = searchUser(username); // Find the user by username
        BSTree* bookTree;
        vector<Book*> borrowedBooks; // Vector to store pointers to borrowed books

        if (user) {
            const vector<int>& rentedBooks = user->getRentedBooks(); // Assuming this method returns a vector of book IDs

            if (rentedBooks.empty()) {
                setColor(YELLOW);
                cout << ".------------------.\n";
                cout << "| No books rented. |\n";
                cout << "'------------------'\n";
                setColor(RESET);
                return borrowedBooks; // Return empty vector if no books are rented
            } else {
                setColor(GREEN);
                cout << "Borrowed Books for user " << username << ":\n";
                setColor(RESET);
                
                for (int bookId : rentedBooks) {
                    Book* book = bookTree->getBookById(bookId); // Assuming bookTree can search by book ID
                    if (book) {
                        borrowedBooks.push_back(book); // Store pointer to the book in the vector
                        cout << book->getTitle() << endl; // Display each borrowed book
                    } else {
                        // Handle the case where the book ID is invalid
                        setColor(RED);
                        cout << "Book with ID " << bookId << " not found.\n";
                        setColor(RESET);
                    }
                }
            }
        } else {
            setColor(RED);
            cout << ".-----------------.\n";
            cout << "| User not found. |\n";
            cout << "'-----------------'\n";
            setColor(RESET);
        }
        
        return borrowedBooks; // Return the list of borrowed books
    }

    void returnBook(const string& username, const string& bookTitle, BSTree& bookTree) {
        User* user = searchUserByUsername(username);
        if (!user) {
            setColor(RED);
            cout << ".-------------------.\n";
            cout << "|  User not found.  |\n";
            cout << "'-------------------'\n";
            setColor(RESET);
            return;
        }

        Book* book = bookTree.searchBookByTitle(bookTitle);
        if (!book) {
            setColor(RED);
            cout << ".-----------------.\n";
            cout << "| Book not found. |\n";
            cout << "'-----------------'\n";
            setColor(RESET);
            return;
        }

        // Open files to read and write data
        ifstream borrowFile("borrows.txt");
        ofstream tempFile("temp.txt");
        ofstream returnFile("returns.txt", ios::app);

        string line;
        bool bookFound = false;

        while (getline(borrowFile, line)) {
            istringstream record(line);
            string recordUsername, id, fileBookTitle, authorName, fileCategory, year, quantityStr, borrowDate, predictedReturnDate;
            
            // Parse fields from the record
            getline(record, recordUsername, ',');   // User: username
            getline(record, id, ',');
            getline(record, fileBookTitle, ',');
            getline(record, authorName, ',');
            getline(record, fileCategory, ',');
            getline(record, year, ',');
            getline(record, quantityStr, ',');
            getline(record, borrowDate, ',');
            getline(record, predictedReturnDate);

            // Remove "User: " prefix from recordUsername
            if (recordUsername.find("User: ") == 0) {
                recordUsername = recordUsername.substr(6);  // Strips "User: " prefix
            }

            // Trim and ensure parsed fields are clean (extra spaces, newlines)
            recordUsername.erase(recordUsername.find_last_not_of(" \n\r\t") + 1);
            fileBookTitle.erase(fileBookTitle.find_last_not_of(" \n\r\t") + 1); 

            // Convert both the input title and fileBookTitle to lowercase for case-insensitive comparison
            string lowerBookTitle = bookTitle;
            transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

            string lowerFileBookTitle = fileBookTitle;
            transform(lowerFileBookTitle.begin(), lowerFileBookTitle.end(), lowerFileBookTitle.begin(), ::tolower);

            // Match user and title
            if (recordUsername == username && lowerFileBookTitle == lowerBookTitle) {
                bookFound = true;
                book->markAsReturned();  // Mark book as returned

                // Calculate late fee if the return is delayed
                Date predictedReturn = Date::fromString(predictedReturnDate);
                Date currentDate = Date::currentDate();
                int lateFee = 0;
                int daysLate = 0;

                if (currentDate > predictedReturn) { // Check if the return date is after the predicted return date
                    daysLate = currentDate.daysBetween(predictedReturn);
                    lateFee = daysLate * 10000;
                }

                // Return confirmation
                cout << "Book returned successfully!" << endl;
                cout << "User: " << username << ", Book: " << bookTitle << endl;
                cout << "Borrowed on: " << borrowDate << endl;
                setColor(CYAN);
                cout << "Returned on: " << currentDate << endl;
                setColor(YELLOW);
                cout << "Expected return: " << predictedReturnDate << endl;
                setColor(RESET);

                if (lateFee > 0) {
                    setColor(RED);
                    cout << "Late return fee: " << lateFee << " VND (for " << daysLate << " days late)" << endl;
                    setColor(RESET);
                } else {
                    setColor(GREEN);
                    cout << "No penalty fee!" << endl;
                    setColor(RESET);
                }

                // Log the return in returns.txt
                returnFile << id << "," << fileBookTitle << "," << username << "," << borrowDate << ","
                       << currentDate.toString() << "," << lateFee << endl;

                continue;  // Skip this record to delete from borrows.txt
            }

            // Write unmatched records to the temporary file
            tempFile << line << endl;
        }

        borrowFile.close();
        tempFile.close();

        // Update book availability in books.txt
        ifstream booksFile("books.txt");
        ofstream tempBooksFile("temp_books.txt");
        bool updated = false;

        if (!booksFile.is_open()) {
            setColor(RED);
            cout << ".----------------------.\n";
            cout << "| Failed to open books.txt |\n";
            cout << "'----------------------'\n";
            setColor(RESET);
            return;
        }

        while (getline(booksFile, line)) {
            Book currentBook = Book::fromString(line);
            string currentBookTitle = currentBook.getTitle();
            // Trim whitespace from both titles
            currentBookTitle.erase(currentBookTitle.find_last_not_of(" \n\r\t") + 1); 
            string lowerBookTitle = bookTitle;
            transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);
            transform(currentBookTitle.begin(), currentBookTitle.end(), currentBookTitle.begin(), ::tolower);

            if (currentBookTitle == lowerBookTitle) {
                currentBook.setQuantity(currentBook.getQuantity() + 1);
                tempBooksFile << currentBook.toString() << endl;
                updated = true;
            } else {
                tempBooksFile << line << endl;
            }
        }

        booksFile.close();
        tempBooksFile.close();

        if (!updated) {
            setColor(RED);
            cout << ".---------------------------.\n";
            cout << "| No matching book found to update |\n";
            cout << "'---------------------------'\n";
            setColor(RESET);
            return;
        }

        // Rename temp file to replace the original books.txt
        if (remove("books.txt") != 0) {
            setColor(RED);
            cout << ".-------------------------.\n";
            cout << "| Failed to remove books.txt |\n";
            cout << "'-------------------------'\n";
            setColor(RESET);
            return;
        }

        if (rename("temp_books.txt", "books.txt") != 0) {
            setColor(RED);
            cout << ".-----------------------------.\n";
            cout << "| Failed to rename temp file to books.txt |\n";
            cout << "'-----------------------------'\n";
            setColor(RESET);
            return;
        }

        // remove("books.txt");
        // rename("temp_books.txt", "books.txt");

        remove("borrows.txt");
        rename("temp.txt", "borrows.txt");

        if (!bookFound) {
            setColor(RED);
            cout << ".-------------------------.\n";
            cout << "| No record found for the |\n";
            cout << "| specified book return.  |\n";
            cout << "'-------------------------'\n";
            setColor(RESET);
        } else if (!updated) {
            cout << "Failed to update book information in books.txt" << endl;
        }
    }

    void loadBorrowedBooks(const string& filename) {
        ifstream borrowFile(filename);
        if (!borrowFile.is_open()) {
            setColor(RED);
            cerr << "Failed to open " << filename << endl;
            setColor(RESET);
            return;
        }

        string line;
        while (getline(borrowFile, line)) {
            // Assuming file format: "User: username, Book Title: bookTitle, Borrow Date: date, Predicted Return Date: date"
            string username, bookTitle, borrowDateStr, returnDateStr;
            // Parse each field from the line (you may need to adjust parsing based on file format)
            
            // Store the borrowed book in the user data (e.g., map of users and borrowed books)
        }

        borrowFile.close();
    }

    void loadReturnedBooks(const string& filename) {
        ifstream returnFile(filename);
        if (!returnFile.is_open()) {
            setColor(RED);
            cerr << "Failed to open " << filename << endl;
            setColor(RESET);
            return;
        }

        string line;
        while (getline(returnFile, line)) {
            // Assuming file format: "User: username, Book ID: id, Return Date: date, Fine: fineAmount"
            string username, bookId, returnDateStr, fineStr;
            // Parse each field from the line
            
            // Store the return history for the user
        }

        returnFile.close();
    }

    void loadAdvanceBorrows(const string& filename) {
        ifstream advanceFile(filename);
        if (!advanceFile.is_open()) {
            setColor(RED);
            cerr << "Failed to open " << filename << endl;
            setColor(RESET);
            return;
        }

        string line;
        while (getline(advanceFile, line)) {
            // Assuming file format: "User: username, Book ID: bookId"
            string username, bookId;
            // Parse each field
            
            // Store advance reservation details for the user
        }

        advanceFile.close();
    }


    // Function to save users to a file
    void saveUsersToFile(const string& filename, bool isNewUserOnly = false) const {
        ofstream outFile(filename, ios::app); // Sử dụng ios::app để chỉ thêm dữ liệu mới
        if (outFile.is_open()) {
            if (isNewUserOnly) {
                saveUsersToFile(root, outFile); // Chỉ lưu người dùng mới nhất
            } else {
                outFile.close(); // Đóng file tạm để mở lại ở chế độ ghi đè
                ofstream outFile(filename); // Mở lại file ở chế độ ghi đè cho toàn bộ cây
                saveUsersToFile(root, outFile); // Lưu toàn bộ cây người dùng
            }
            outFile.close();
        } else {
            setColor(RED);
            cerr << ".---------------------------------.\n";
            cerr << "| Error opening file for writing. |\n";
            cerr << "'---------------------------------'\n";
            setColor(RESET);
        }
    }

    // Hàm đệ quy để lưu thông tin từ một node cụ thể
    void saveUsersToFile(UserNode* node, ofstream& outFile) const {
        if (node != nullptr) {
            // Lưu thông tin người dùng ở định dạng cấu trúc
            outFile << node->user->getUsername() << ","
                    << node->user->getPassword() << ","
                    << node->user->getName() << ","
                    << node->user->getMail() << ","
                    << node->user->getBirthday().getDay() << ","
                    << node->user->getBirthday().getMonth() << ","
                    << node->user->getBirthday().getYear() << endl;
            saveUsersToFile(node->left, outFile);
            saveUsersToFile(node->right, outFile);
        }
    }


    // Function to load users from a file
    void loadUsersFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                string username, password, name, email;
                int day, month, year;

                // Đọc các trường từ dòng
                if (getline(iss, username, ',') &&
                    getline(iss, password, ',') &&
                    getline(iss, name, ',') &&
                    getline(iss, email, ',') && // Đọc email thật
                    (iss >> day) && (iss.ignore()) &&
                    (iss >> month) && (iss.ignore()) &&
                    (iss >> year)) {

                    // Tạo đối tượng Date và User
                    Date birthday(day, month, year);
                    User* user = new User(name, birthday, email, username, password);
                    addUser(user); // Thêm người dùng vào hệ thống
                }
            }
            inFile.close();
        }
        else {
            setColor(RED);
            cerr << ".-----------------------------------.\n";
            cerr << "|  Error opening file for reading.  |\n";
            cerr << "'-----------------------------------'\n";
            setColor(RESET);
        }
    }
};