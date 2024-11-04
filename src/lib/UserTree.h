#pragma once
#include "UserNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
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

    void printHeader() const {
        // Print table header
        std::cout << std::left << std::setw(20) << "Username" 
                  << std::setw(20) << "Password" 
                  << std::setw(30) << "Email" 
                  << std::setw(15) << "Birthday" << std::endl;
        std::cout << std::string(85, '-') << std::endl; // Print a separator line
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
            std::cout << std::left << std::setw(20) << node->user->getUsername() 
                      << std::setw(20) << node->user->getPassword() 
                      << std::setw(30) << node->user->getMail() 
                      << std::setw(15) << node->user->getBirthday().toString() << std::endl;

            displayInOrder(node->right); // Traverse right
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

    // Helper method to collect all users
    void collectUsers(UserNode* node, std::vector<User*>& users) {
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
    bool caseInsensitiveContains(const std::string& str, const std::string& substr) {
        std::string strLower = str;
        std::string substrLower = substr;
        std::transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
        std::transform(substrLower.begin(), substrLower.end(), substrLower.begin(), ::tolower);
        return strLower.find(substrLower) != std::string::npos;
    }

    void suggestUsersByUsername(UserNode* node, const std::string& partialUsername, std::vector<User*>& suggestions) {
        if (node == nullptr) {
            return;
        }

        // Perform in-order traversal to maintain sorted order of suggestions
        suggestUsersByUsername(node->left, partialUsername, suggestions);

        // Check if the username contains the partial input (case-insensitive)
        if (caseInsensitiveContains(node->user->getUsername(), partialUsername)) {
            suggestions.push_back(node->user);
        }

        suggestUsersByUsername(node->right, partialUsername, suggestions);
    }

    // Public method to get user suggestions by partial username
    std::vector<User*> suggestUsersByUsername(const std::string& partialUsername) {
        std::vector<User*> suggestions;
        suggestUsersByUsername(root, partialUsername, suggestions);
        return suggestions;
    }

    // Method to get all users
    std::vector<User*> getAllUsers() {
        std::vector<User*> users;
        collectUsers(root, users);
        return users;
    }

    // Function to search for a user by username
    User* searchUser(const string& username) const {
        return search(root, username);
    }

    // Function to display all users
    void displayUsers() const {
        printHeader();
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

        setColor(YELLOW);
        std::cout << "Updating information for user: " << username << std::endl;
        setColor(BRIGHT_YELLOW);

        // Get new name
        setColor(BRIGHT_BLUE);
        std::cout << "Current Name: " << user->getName() << std::endl;
        std::cout << "Enter new name (or leave empty to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) {
            user->setName(newName);
        }
        setColor(RESET);

        // Get new email with duplicate check
        string newEmail;
        bool validEmail = false;
        vector<User*> existingUsers = getAllUsers(); // Get existing users for duplicate check
        do {
            setColor(BRIGHT_MAGENTA);
            std::cout << "Enter new Email (or leave empty to keep current): ";
            getline(cin, newEmail);
            setColor(RESET);

            // Check for existing email only if the user is changing the email
            if (!newEmail.empty()) {
                auto emailIt = find_if(existingUsers.begin(), existingUsers.end(), [&](User* u) {
                    return u->getMail() == newEmail;
                });

                // Email format validation
                bool emailFormatValid = (newEmail.find("@gmail.com") != string::npos) || (newEmail.find(".st.utc2.edu.vn") != string::npos);

                if (!emailFormatValid) {
                    setColor(RED);
                    std::cout << ".---------------------------------------------------------------------------.\n";
                    std::cout << "| Invalid email format. Please enter a valid '@gmail.com' or '.edu' email.  |\n";
                    std::cout << "'---------------------------------------------------------------------------'\n";
                    setColor(RESET);
                    system("pause");
                } else if (emailIt != existingUsers.end()) {
                    setColor(RED);
                    std::cout << ".-----------------------------------------------------.\n";
                    std::cout << "| Email already exists. Please use a different email. |\n";
                    std::cout << "'-----------------------------------------------------'\n";
                    setColor(RESET);
                    system("pause");
                } else {
                    validEmail = true; // Email is valid, exit the loop
                }
            } else {
                validEmail = true; // No new email provided, keep the current one
            }
        } while (!validEmail);

        if (!newEmail.empty()) {
            user->setMail(newEmail);
        }
        
        setColor(BLUE);
        // Get new password
        std::cout << "Enter new password (or leave empty to keep current): ";
        string newPassword;
        getline(cin, newPassword);
        if (!newPassword.empty()) {
            user->setPassword(newPassword);
        }
        setColor(RESET);

        // Get new birthday
        setColor(CYAN);
        std::cout << "Current Birthday: " << user->getBirthday().toString() << std::endl;
        bool validDate = false;
        int newDay, newMonth, newYear;
        do {
            std::cout << "Enter new birthday (dd mm yyyy, or leave empty to keep current): ";
            string dateInput;
            getline(cin, dateInput);

            if (!dateInput.empty()) {
                std::istringstream dateStream(dateInput);
                dateStream >> newDay >> newMonth >> newYear;

                if (!dateStream.fail() && Date::isValidDate(newDay, newMonth, newYear)) {
                    user->setBirthday(Date(newDay, newMonth, newYear));
                    validDate = true; // Date is valid, exit the loop
                } else {
                    setColor(RED);
                    std::cout << ".--------------------------------------------------.\n";
                    std::cout << "| Invalid date entered. Please enter a valid date. |\n";
                    std::cout << "'--------------------------------------------------'\n";
                    setColor(RESET);
                    system("pause");
                }
            } else {
                validDate = true; // No new date provided, keep the current one
            }
        } while (!validDate);
        setColor(RESET);
        cin.clear(); // Clear the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line to avoid issues

        // Save updated user information to file
        saveUsersToFile("users.txt");
        setColor(GREEN);
        std::cout << ".----------------------------------------.\n";
        std::cout << "| User information updated successfully! |\n";
        std::cout << "'----------------------------------------'\n";
        setColor(RESET);
    }

    void showRentedBooks() {
        std::string currentUser = getCurrentUserName();
        std::ifstream borrowedFile("borrows.txt");
        bool hasRentedBooks = false;

        if (!borrowedFile.is_open()) {
            setColor(RED);
            std::cout << ".-------------------------------.\n";
            std::cout << "| Failed to open borrows.txt.   |\n";
            std::cout << "'-------------------------------'\n";
            setColor(RESET);
            return;
        }

        // Table headers
        setColor(BRIGHT_MAGENTA);
        std::cout << "Rented Books for user "; 
        setColor(BLUE); 
        std::cout << currentUser; 
        setColor(RESET); 
        setColor(BRIGHT_MAGENTA); 
        cout << ":\n\n"; 
        setColor(RESET);

        setColor(CYAN);
        std::cout << std::string(83, '-') << "\n";  // Table border
        std::cout << std::left << std::setw(30) << "| Book Title" 
                << std::setw(30) << "Borrow Date" 
                << std::setw(25) << "Predicted Return Date |" << "\n";
        std::cout << std::string(83, '-') << "\n";  // Table border
        setColor(RESET);

        // Read file and populate table rows
        std::string line;
        while (getline(borrowedFile, line)) {
            size_t userPos = line.find("User: ");
            size_t titlePos = line.find(", Book Title: ");
            size_t borrowDatePos = line.find(", Borrow Date: ");
            size_t returnDatePos = line.find(", Predicted Return Date: ");

            if (userPos != std::string::npos && titlePos != std::string::npos &&
                borrowDatePos != std::string::npos && returnDatePos != std::string::npos) {
                std::string username = line.substr(userPos + 6, titlePos - (userPos + 6));
                if (username == currentUser) {
                    std::string bookTitle = line.substr(titlePos + 13, borrowDatePos - (titlePos + 13));
                    std::string borrowDate = line.substr(borrowDatePos + 14, returnDatePos - (borrowDatePos + 14));
                    std::string returnDate = line.substr(returnDatePos + 23);

                    hasRentedBooks = true;

                    // Print each row with formatted columns
                    std::cout << std::left << std::setw(30) << bookTitle
                            << std::setw(30) << borrowDate
                            << std::setw(25) << returnDate << "\n";
                }
            }
        }

        if (!hasRentedBooks) {
            setColor(RED);
            std::cout << ".------------------.\n";
            std::cout << "| No books rented. |\n";
            std::cout << "'------------------'\n";
            setColor(RESET);
        }

        borrowedFile.close();
    }


    void borrowBook(const string& username, const string& bookTitle, BSTree& bookTree) {
        string filename = "books.txt";
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
            ofstream borrowFile("borrows.txt", std::ios::app);
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

    // Function to get borrowed books for the currently logged-in user
    std::vector<Book*> getBorrowedBooks(const std::string& username) {
        User* user = searchUser(username); // Find the user by username
        BSTree* bookTree;
        std::vector<Book*> borrowedBooks; // Vector to store pointers to borrowed books

        if (user) {
            const std::vector<int>& rentedBooks = user->getRentedBooks(); // Assuming this method returns a vector of book IDs

            if (rentedBooks.empty()) {
                setColor(YELLOW);
                std::cout << ".------------------.\n";
                std::cout << "| No books rented. |\n";
                std::cout << "'------------------'\n";
                setColor(RESET);
                return borrowedBooks; // Return empty vector if no books are rented
            } else {
                setColor(GREEN);
                std::cout << "Borrowed Books for user " << username << ":\n";
                setColor(RESET);
                
                for (int bookId : rentedBooks) {
                    Book* book = bookTree->getBookById(bookId); // Assuming bookTree can search by book ID
                    if (book) {
                        borrowedBooks.push_back(book); // Store pointer to the book in the vector
                        std::cout << book->getTitle() << std::endl; // Display each borrowed book
                    } else {
                        // Handle the case where the book ID is invalid
                        setColor(RED);
                        std::cout << "Book with ID " << bookId << " not found.\n";
                        setColor(RESET);
                    }
                }
            }
        } else {
            setColor(RED);
            std::cout << ".-----------------.\n";
            std::cout << "| User not found. |\n";
            std::cout << "'-----------------'\n";
            setColor(RESET);
        }
        
        return borrowedBooks; // Return the list of borrowed books
    }

    void returnBook(const std::string& username, const std::string& bookTitle, BSTree& bookTree) {
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

        std::ifstream borrowFile("borrows.txt");
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool bookFound = false;

        while (getline(borrowFile, line)) {
            std::istringstream record(line);
            std::string userToken, bookTitleToken, borrowDateToken, predictedReturnToken;

            if (getline(record, userToken, ',') && getline(record, bookTitleToken, ',') &&
                getline(record, borrowDateToken, ',') && getline(record, predictedReturnToken)) {
                
                // Extract the information by tokenizing strings
                std::string fileUser = userToken.substr(userToken.find(":") + 2);
                std::string fileBookTitle = bookTitleToken.substr(bookTitleToken.find(":") + 2);
                std::string fileBorrowDate = borrowDateToken.substr(borrowDateToken.find(":") + 2);
                std::string filePredictedReturnDate = predictedReturnToken.substr(predictedReturnToken.find(":") + 2);

                if (fileUser == username && fileBookTitle == bookTitle) {
                    bookFound = true;

                    // Here you can implement any logic for returning the book
                    // For example, updating the book's quantity
                    book->markAsReturned();  // Assuming you have this method

                    // Log the return details
                    std::cout << "Book returned successfully!" << std::endl;
                    std::cout << "User: " << fileUser << ", Book: " << fileBookTitle << std::endl;
                    std::cout << "Borrowed on: " << fileBorrowDate << ", Expected return: " << filePredictedReturnDate << std::endl;

                    continue; // Skip this line as we are returning this book
                }
            }

            // Write back to the temporary file if it's not the returned book
            tempFile << line << std::endl;
        }

        borrowFile.close();
        tempFile.close();

        // Replace the original file with the temporary file
        std::remove("borrows.txt");
        std::rename("temp.txt", "borrows.txt");

        if (!bookFound) {
            setColor(RED);
            std::cout << ".-------------------------.\n";
            std::cout << "|  No record found for the |\n";
            std::cout << "|  specified book return.   |\n";
            std::cout << "'-------------------------'\n";
            setColor(RESET);
        }
    }

    void loadBorrowedBooks(const string& filename) {
        ifstream borrowFile(filename);
        if (!borrowFile.is_open()) {
            std::cerr << "Failed to open " << filename << std::endl;
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
            std::cerr << "Failed to open " << filename << std::endl;
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
            std::cerr << "Failed to open " << filename << std::endl;
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