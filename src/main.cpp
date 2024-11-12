#include <iostream>
#include "./lib/Book.h"
#include "./lib/BookTree.h"
#include "./lib/UserTree.h"
#include "./lib/User.h"
#include "./lib/System.h"
#include "./lib/Graphic.h"
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <limits>
#include <conio.h>
#include <regex>
#include <chrono>  

using namespace std;

int main() {
    BSTree library;
    UserTree userTree;
    int overalChoice, mainChoice, subChoice;
    const string filename = "books.txt";
    const string borrowsFilename = "borrows.txt";
    const string returnsFilename = "returns.txt";
    const string advanceBorrowsFilename = "advance_borrows.txt";

    userTree.loadBorrowedBooks(borrowsFilename);
    userTree.loadReturnedBooks(returnsFilename);
    userTree.loadAdvanceBorrows(advanceBorrowsFilename);

    // Load books from file at the start
    library.loadFromFile(filename);

    // Display the overall menu first
    do {
        displayOveralMenu();
        cin >> overalChoice;

        if (overalChoice == 1) {  // Admin login
            // Try admin login
            if (!adminLogin()) {
                continue;  // Back to overall menu if login fails
            }

            // Admin login successful, proceed to main menu
            do {
                displayMainMenu();
                cin >> mainChoice;

                if (mainChoice == 1) {  // Book Management
                    do {
                        clearScreen();
                        displayBookMenu();
                        cin >> subChoice;

                        switch (subChoice) {
                        case 1: { // Add book
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            int id, year, quantity;
                            string title, author, genre, status;
                            bool cancelOperation = false;

                            // Enter Book ID
                            while (true) {
                                setColor(BRIGHT_YELLOW);
                                cout << "Enter Book ID: ";
                                string inputId;
                                cin >> inputId;

                                if (isExitCommand(inputId)) {
                                    cancelOperation = true;
                                    break;
                                }

                                try {
                                    id = stoi(inputId);
                                    if (library.getBookById(id) != nullptr) {
                                        setColor(RED);
                                        cout << ".---------------------------------------------------------------.\n";
                                        cout << "| Error: Book ID already exists. Please enter a unique Book ID. |\n";
                                        cout << "'---------------------------------------------------------------'\n";
                                        setColor(RESET);
                                    } else {
                                        break;
                                    }
                                } catch (invalid_argument&) {
                                    setColor(RED);
                                    cout << ".----------------------------------------------.\n";
                                    cout << "| Invalid input. Please enter a valid Book ID. |\n";
                                    cout << "'----------------------------------------------'\n";
                                    setColor(RESET);
                                    cin.clear(); // Clear error flag
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                }
                            }
                            if (cancelOperation) break;

                            // Enter Title
                            setColor(YELLOW);
                            while (true) {
                                cout << "Enter Title: ";
                                cin.ignore(); // Clear the newline left in the buffer
                                getline(cin, title);

                                if (isExitCommand(title)) {
                                    cancelOperation = true;  // Set cancel flag
                                    break;  // Exit to book menu
                                }

                                if (title.empty()) {
                                    setColor(RED);
                                    cout << ".-----------------------------------------------.\n";
                                    cout << "| Title cannot be empty. Please enter a title. |\n";
                                    cout << "'-----------------------------------------------'\n";
                                    setColor(YELLOW);
                                } else {
                                    break;  // Valid title entered
                                }
                            }
                            if (cancelOperation) break;  // Cancel and go back to book menu

                            // Enter Author
                            setColor(BRIGHT_GREEN);
                            cout << "Enter Author: ";
                            getline(cin, author);
                            if (isExitCommand(author)) {
                                cancelOperation = true;
                                break;
                            }

                            // Enter Genre
                            setColor(GREEN);
                            cout << "Enter Genre: ";
                            getline(cin, genre);
                            if (isExitCommand(genre)) {
                                cancelOperation = true;
                                break;
                            }

                            // Enter Year
                            setColor(BRIGHT_CYAN);
                            while (true) {
                                cout << "Enter Year: ";
                                string inputYear;
                                cin >> inputYear;

                                if (isExitCommand(inputYear)) {
                                    cancelOperation = true;
                                    break;
                                }

                                try {
                                    year = stoi(inputYear);

                                    // Lấy năm hiện tại từ hệ thống
                                    time_t t = time(0);
                                    tm* now = localtime(&t);
                                    int currentYear = now->tm_year + 1900;

                                    // Kiểm tra nếu năm âm hoặc lớn hơn năm hiện tại
                                    if (year < 0) {
                                        setColor(RED);
                                        cout << ".------------------------------------------------------.\n";
                                        cout << "| Error: Year cannot be negative. Please try again.    |\n";
                                        cout << "'------------------------------------------------------'\n";
                                        setColor(RESET);
                                    } else if (year > currentYear) {
                                        setColor(RED);
                                        cout << ".------------------------------------------------------.\n";
                                        cout << "| Error: Year cannot be in the future. Try again.      |\n";
                                        cout << "'------------------------------------------------------'\n";
                                        setColor(RESET);
                                    } else {
                                        break;  // Valid year entered
                                    }

                                } catch (invalid_argument&) {
                                    setColor(RED);
                                    cout << ".-------------------------------------------.\n";
                                    cout << "| Invalid input. Please enter a valid Year. |\n";
                                    cout << "'-------------------------------------------'\n";
                                    setColor(RESET);
                                }
                                
                                cin.clear();  // Clear error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                            }
                            if (cancelOperation) break;  // Cancel and go back to book menu

                            // Enter Quantity
                            while (true) {
                                setColor(CYAN);
                                cout << "Enter Quantity: ";
                                string inputQuantity;
                                cin >> inputQuantity;

                                if (isExitCommand(inputQuantity)) {
                                    cancelOperation = true;
                                    break;
                                }

                                try {
                                    quantity = stoi(inputQuantity);
                                    if (quantity <= 0) {
                                        setColor(RED);
                                        cout << ".----------------------------------------------------.\n";
                                        cout << "| Quantity must be greater than 0! Please try again. |\n";
                                        cout << "'----------------------------------------------------'\n";
                                        setColor(RESET);
                                    } else {
                                        break;
                                    }
                                } catch (invalid_argument&) {
                                    setColor(RED);
                                    cout << ".-----------------------------------------------.\n";
                                    cout << "| Invalid input. Please enter a valid Quantity. |\n";
                                    cout << "'-----------------------------------------------'\n";
                                    setColor(RESET);
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            if (cancelOperation) break;

                            // Enter Status
                            setColor(BRIGHT_BLUE);
                            while (true) {
                                setColor(CYAN);
                                cout << "Enter Status (Available, Updating): ";
                                setColor(RESET);
                                cin.ignore(); // Clear buffer
                                getline(cin, status);

                                if (isExitCommand(status)) {
                                    cancelOperation = true;
                                    break;
                                }

                                status = library.matchStatus(status);
                                if (status.empty()) {
                                    setColor(RED);
                                    cout << ".-----------------------------------------------------.\n";
                                    cout << "| Invalid status. Please enter Available or Updating. |\n";
                                    cout << "'-----------------------------------------------------'\n";
                                    setColor(BRIGHT_BLUE);
                                } else {
                                    break;
                                }
                            }
                            if (cancelOperation) break;

                            // If we reach this point, the book can be added
                            setColor(BLUE);
                            library.addBook(id, title, author, genre, year, quantity, status);
                            clearScreen();
                            setColor(GREEN);
                            cout << ".--------------------------.\n";
                            cout << "| Book added successfully! |\n";
                            cout << "'--------------------------'\n";
                            setColor(RESET);
                            library.saveToFile(filename);
                            system("pause");
                            break;
                        }

                        case 2: { // Update book information
                            clearScreen();
                            string bookTitle;
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);
                            setColor(MAGENTA);
                            cout << "Enter the Title of the Book to Update: ";
                            setColor(RESET);
                            
                            char ch;

                            // Display initial empty suggestions
                            setColor(CYAN);
                            cout << "\nSuggestions: ";
                            setColor(RESET);

                            while (true) {
                                // Read a single character
                                ch = _getch();  // Use _getch() for immediate character capture without Enter key
                                if (ch == '\r') break;  // Stop on Enter key ('\r' is the Enter key in Windows)

                                // Add character to the search term
                                if (ch == 8) { // Handle backspace
                                    if (!bookTitle.empty()) {
                                        bookTitle.pop_back(); // Remove the last character
                                    }
                                } else {
                                    bookTitle += ch; // Add character to the search term
                                }

                                // Clear screen and display prompt again with current input
                                clearScreen();
                                setColor(BRIGHT_MAGENTA);
                                cout << "Enter the Title of the Book to Update: " << bookTitle << endl;
                                setColor(RESET);

                                // Check for exit command
                                if (bookTitle == "exit") {
                                    clearScreen();
                                    break;  // Exit to book menu
                                }
                                
                                // Convert current input to lowercase for case-insensitive comparison
                                string lowerBookTitle = bookTitle;
                                transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

                                // Retrieve suggestions based on the current title input
                                vector<Book*> suggestions = library.getSuggestionsByTitle(lowerBookTitle);

                                // Display updated suggestions
                                setColor(CYAN);
                                cout << "\nSuggestions: ";
                                if (!suggestions.empty()) {
                                    for (auto* book : suggestions) {
                                        cout << book->getTitle() << "  ";
                                    }
                                } else {
                                    cout << "No matches found.\n";
                                }
                                cout << endl;
                                setColor(RESET);
                            }

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            if (isExitCommand(bookTitle)) {
                                // User chose to cancel the operation
                                clearScreen();
                                break; // Go back to the book menu
                            }

                            // Proceed with updating the book information
                            library.updateBookInformation(bookTitle);
                            library.saveToFile(filename);
                            system("pause");
                            break;
                        }

                        case 3: {//List book
                            clearScreen();
                            setColor(BRIGHT_MAGENTA);
                            cout << "               .----------------------------------------------------.\n";
                            setColor(MAGENTA);
                            cout << "               |=========== List of Books in the Library ===========|\n";
                            setColor(BRIGHT_RED);
                            cout << "               '----------------------------------------------------'\n";
                            setColor(RESET);
                            library.displayBooks();
                            system("pause");
                            break;
                        }
                        case 4: {  // Search Book by Title
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            string bookTitle;
                            setColor(BRIGHT_MAGENTA);
                            cout << "Enter Book Title to Search: ";
                            setColor(RESET);
                            
                            char ch;

                            // Display initial empty suggestions
                            setColor(CYAN);
                            cout << "\nSuggestions: ";
                            setColor(RESET);

                            while (true) {
                                // Read a single character
                                ch = _getch();  // Use _getch() for immediate character capture without Enter key
                                if (ch == '\r') break;  // Stop on Enter key ('\r' is the Enter key in Windows)

                                // Add character to the search term
                                if (ch == 8) { // Handle backspace
                                    if (!bookTitle.empty()) {
                                        bookTitle.pop_back(); // Remove the last character
                                    }
                                } else {
                                    bookTitle += ch; // Add character to the search term
                                }

                                // Clear screen and display prompt again with current input
                                clearScreen();
                                setColor(BRIGHT_MAGENTA);
                                cout << "Enter Book Title to Search: " << bookTitle << endl;
                                setColor(RESET);

                                // Check for exit command
                                if (bookTitle == "exit") {
                                    clearScreen();
                                    break;  // Exit to book menu
                                }
                                
                                // Convert current input to lowercase for case-insensitive comparison
                                string lowerBookTitle = bookTitle;
                                transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

                                // Retrieve suggestions based on the current title input
                                vector<Book*> suggestions = library.getSuggestionsByTitle(lowerBookTitle);

                                // Display updated suggestions
                                setColor(CYAN);
                                cout << "\nSuggestions: ";
                                if (!suggestions.empty()) {
                                    for (auto* book : suggestions) {
                                        cout << book->getTitle() << "  ";
                                    }
                                } else {
                                    cout << " ";
                                }
                                cout << endl;
                                setColor(RESET);
                            }

                            // After Enter is pressed, search for the exact title entered
                            if (bookTitle != "exit") { // Only search if exit wasn't typed
                                // Convert search term to lowercase for case-insensitive search
                                string lowerBookTitle = bookTitle;
                                transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

                                Book* foundBook = library.searchBook(lowerBookTitle);
                                if (foundBook != nullptr) {
                                    setColor(GREEN);
                                    cout << "\nFound Book:\n";

                                    // Table header
                                    cout << "------------------------------------------------------------------------------------" << endl;
                                    cout << left << setw(10) << "ID" 
                                        << setw(30) << "Title" 
                                        << setw(20) << "Author"
                                        << setw(15) << "Quantity"
                                        << setw(10) << "Status" 
                                        << endl;
                                    cout << "------------------------------------------------------------------------------------" << endl;

                                    // Book information
                                    cout << left << setw(10) << foundBook->getBookId()
                                        << setw(30) << foundBook->getTitle()
                                        << setw(20) << foundBook->getAuthor()
                                        << setw(15) << foundBook->getQuantity()
                                        << setw(10) << foundBook->getStatus()
                                        << endl;

                                    setColor(RESET);
                                } else {
                                    setColor(RED);
                                    cout << "\nNo book found with title \"" << bookTitle << "\"" << endl;
                                    setColor(RESET);
                                }
                            }
                            system("pause");
                            break;
                        }
                        case 5: { // Delete book by title
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            string title;
                            char ch;

                            // Display prompt and allow typing with suggestions
                            setColor(BRIGHT_RED);
                            cout << "Enter Book Title to Delete: ";
                            setColor(RESET);

                            while (true) {
                                ch = _getch(); // Capture input character by character

                                if (ch == '\r') { // Enter key
                                    break;
                                } else if (ch == '\b') { // Backspace
                                    if (!title.empty()) {
                                        title.pop_back();
                                    }
                                } else if (ch == 27) { // ESC key to exit
                                    clearScreen();
                                    setColor(BRIGHT_YELLOW);
                                    cout << ".---------------------.\n";
                                    cout << "| Deletion cancelled. |\n";
                                    cout << "'---------------------'\n";
                                    setColor(RESET);
                                    system("pause");
                                    break;
                                } else {
                                    title += ch;
                                }

                                // Exit if user types "exit"
                                if (title == "exit") {
                                    clearScreen();
                                    setColor(BRIGHT_YELLOW);
                                    cout << ".---------------------.\n";
                                    cout << "| Deletion cancelled. |\n";
                                    cout << "'---------------------'\n";
                                    setColor(RESET);
                                    system("pause");
                                    break;
                                }

                                // Refresh screen to display the current input and suggestions
                                system("cls");
                                setColor(BRIGHT_RED);
                                cout << "Enter Book Title to Delete: " << title << endl;
                                setColor(RESET);

                                // Convert input title to lowercase for case-insensitive comparison
                                string lowerTitle = title;
                                transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

                                // Display suggestions (assuming library.getSuggestionsByTitle provides book title suggestions)
                                vector<Book*> suggestions = library.getSuggestionsByTitle(lowerTitle);
                                setColor(GREEN);
                                cout << "\nSuggestions: ";
                                if (!suggestions.empty()) {
                                    for (const auto& book : suggestions) {
                                        cout << book->getTitle() << "  ";
                                    }
                                } else {
                                    setColor(RED);
                                    cout << "\n.---------------------------.\n";
                                    cout << "| No suggestions available. |\n";
                                    cout << "'---------------------------'\n";
                                }
                                cout << endl;
                                setColor(RESET);
                            }

                            // Attempt to delete the book if the title is not empty or "exit"
                            if (!title.empty() && title != "exit") {
                                string lowerTitle = title;
                                transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

                                bool deleted = library.deleteBookByTitle(lowerTitle); // Use the modified delete function
                                if (deleted) {
                                    setColor(GREEN);
                                    cout << "\n.------------------------------.\n";
                                    cout << "|  Book deleted successfully!  |\n";
                                    cout << "'------------------------------'\n";
                                    setColor(RESET);

                                    // Save updated library to file
                                    library.saveToFile("books.txt");
                                } else {
                                    setColor(RED);
                                    cout << "\n.-------------------------------------------.\n";
                                    cout << "|  Book not found or could not be deleted.  |\n";
                                    cout << "'-------------------------------------------'\n";
                                    setColor(RESET);
                                }
                            }

                            system("pause");
                            break;
                        }
                        case 0:
                            break; // Go back to the main menu
                        default:
                            setColor(RED);
                            cout << ".-----------------------------------.\n";
                            cout << "| Invalid choice. Please try again. |\n";
                            cout << "'-----------------------------------'\n";
                            setColor(RESET);
                            system("pause");
                        }
                    } while (subChoice != 0);
                }
                else if (mainChoice == 2) {  // User Management
                    string filename = "users.txt";
                    userTree.loadUsersFromFile(filename);
                    do {
                        clearScreen();  
                        displayUserMenu();
                        cin >> subChoice;

                        switch (subChoice) {
                        case 1: { // Add user
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            userTree.loadUsersFromFile(filename); // Load users before creating a new account
                            userTree.createAccount(); // This will call User::createAccount() internally
                            userTree.saveUsersToFile(filename); // Save the updated user li

                            system("pause");
                            break;
                        }
                        case 2: { // Update User Information by Email
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            setColor(BLUE);
                            cout << "Enter Email to Update: ";
                            setColor(RESET);

                            string email;
                            vector<string> emails;
                            ifstream file("users.txt");

                            // Load emails from the file into the vector
                            if (file.is_open()) {
                                string line;
                                while (getline(file, line)) {
                                    // Split the line by comma and extract the 4th element (email)
                                    size_t pos = 0;
                                    int fieldIndex = 0;
                                    string token;
                                    while ((pos = line.find(',')) != string::npos) {
                                        token = line.substr(0, pos);
                                        line.erase(0, pos + 1);
                                        fieldIndex++;

                                        // When we reach the 4th field (email)
                                        if (fieldIndex == 3) {
                                            emails.push_back(line); // The remaining part is the email
                                            break;
                                        }
                                    }
                                }
                                file.close();
                            } else {
                                setColor(RED);
                                cout << ".----------------------------------.\n";
                                cout << "| Error: Could not open users.txt  |\n";
                                cout << "'----------------------------------'\n";
                                setColor(RESET);
                                system("pause");
                                break;
                            }

                            char ch;
                            while ((ch = _getch()) != '\r') { // Loop until Enter key is pressed
                                if (ch == '\b') { // Handle Backspace
                                    if (!email.empty()) {
                                        email.pop_back(); // Remove last character from email
                                    }
                                } else if (isprint(ch)) { // Append printable characters
                                    email += ch;
                                }

                                // Convert the input email to lowercase for case-insensitive comparison
                                string lowerEmail = email;
                                transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);

                                // Clear the screen and re-display the prompt and current input
                                clearScreen();
                                setColor(BRIGHT_YELLOW);
                                cout << ".-------------------------.\n";
                                cout << "|  Type 'exit' to cancel  |\n";
                                cout << "'-------------------------'\n";
                                setColor(RESET);

                                setColor(BLUE);
                                cout << "Enter Email to Update: ";
                                setColor(RESET);
                                cout << email << endl;

                                // Show suggestions based on the current input
                                cout << "\nSuggestions:\n";
                                for (const auto& userEmail : emails) {
                                    // Convert stored emails to lowercase and check if they match the input
                                    string lowerUserEmail = userEmail;
                                    transform(lowerUserEmail.begin(), lowerUserEmail.end(), lowerUserEmail.begin(), ::tolower);
                                    
                                    if (lowerUserEmail.find(lowerEmail) == 0) { // Check if email starts with input
                                        cout << " - " << userEmail << endl;
                                    }
                                }
                            }

                            cout << endl; // Move to the next line after Enter key

                            // Check for exit command
                            if (email == "exit") {
                                clearScreen();
                                break; // Exit to the previous menu
                            }

                            // Attempt to update user information based on email
                            userTree.updateUserInformation(email);
                            system("pause");
                            break;
                        }
                        case 3: {
                            clearScreen();
                            cout << "\nList of Users in the System:" << endl;
                            userTree.displayUsers();
                            system("pause");
                            break;
                        }
                        case 4: { // Search for User with Suggestions by Email
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            string email;
                            char ch;
                            setColor(BLUE);
                            cout << "Enter Email to Search: ";
                            setColor(RESET);
                            cin.ignore();

                            // Dynamically update suggestions based on input
                            while (true) {
                                ch = _getch(); // Read each character input without pressing enter
                                if (ch == '\r') { // Enter key pressed
                                    break;
                                } else if (ch == '\b') { // Backspace
                                    if (!email.empty()) {
                                        email.pop_back();
                                    }
                                } else {
                                    email += ch;
                                }

                                // Check for exit command
                                if (email == "exit") {
                                    clearScreen();
                                    break; // Exit to the previous menu
                                }

                                clearScreen(); // Clear screen to refresh suggestions
                                setColor(BLUE);
                                cout << "Enter Email to Search: " << email << endl;
                                setColor(RESET);
                                
                                // Display search suggestions with inline lowercase transformation
                                string searchKey = email;
                                transform(searchKey.begin(), searchKey.end(), searchKey.begin(), ::tolower);

                                // Display search suggestions based on email
                                vector<string> suggestions = userTree.suggestUsersByEmail("users.txt",email);
                                if (!suggestions.empty()) {
                                    setColor(GREEN);
                                    cout << "Suggestions:" << endl;
                                    for (const auto& suggestion : suggestions) {
                                        cout << " - " << suggestion << endl;
                                    }
                                    setColor(RESET);
                                }
                            }

                            if (!email.empty() && email != "exit") {
                                // Perform final search by email
                                User* foundUser = userTree.searchUser(email);
                            }

                            system("pause");
                            break;
                        }
                        case 5: { //Delete User with Confirmation Prompt
                            clearScreen();
                            setColor(BRIGHT_YELLOW);
                            cout << ".-------------------------.\n";
                            cout << "|  Type 'exit' to cancel  |\n";
                            cout << "'-------------------------'\n";
                            setColor(RESET);

                            vector<string> emails;
                            ifstream file("users.txt");

                            // Load emails from file into the vector
                            if (file.is_open()) {
                                string line;
                                while (getline(file, line)) {
                                    istringstream iss(line);
                                    string username, password, name, email;
                                    int day, month, year;
                                    
                                    // Đọc các trường từ dòng
                                    if (getline(iss, username, ',') &&
                                        getline(iss, password, ',') &&
                                        getline(iss, name, ',') &&
                                        getline(iss, email, ',')) {
                                        emails.push_back(email); // Lưu email vào vector
                                    }
                                }
                                file.close();
                            } else {
                                setColor(RED);
                                cout << ".---------------------------------.\n";
                                cout << "| Error: Could not open users.txt |\n";
                                cout << "'---------------------------------'\n";
                                setColor(RESET);
                                break;
                            }

                            string email;
                            setColor(RED);
                            cout << "Enter Email to Delete: ";
                            setColor(RESET);

                            char ch;
                            while ((ch = _getch()) != '\r') { // Loop until Enter key is pressed
                                if (ch == '\b') { // Handle Backspace
                                    if (!email.empty()) {
                                        email.pop_back(); // Remove the last character
                                    }
                                } else if (isprint(ch)) { // Append printable characters
                                    email += ch;
                                }

                                // Clear the screen and re-display the prompt and current input
                                clearScreen();
                                setColor(BRIGHT_YELLOW);
                                cout << ".-------------------------.\n";
                                cout << "|  Type 'exit' to cancel  |\n";
                                cout << "'-------------------------'\n";
                                setColor(RESET);

                                setColor(RED);
                                cout << "Enter Email to Delete: ";
                                setColor(RESET);
                                cout << email << endl;

                                // Convert entered username to lowercase for case-insensitive matching
                                string lowerEmail = email;
                                transform(lowerEmail.begin(), lowerEmail.end(), lowerEmail.begin(), ::tolower);

                                // Display suggestions based on lowercase input
                                cout << "\nSuggestions:\n";
                                for (const auto& user : emails) {
                                    string lowerUser = user;
                                    transform(lowerUser.begin(), lowerUser.end(), lowerUser.begin(), ::tolower);
                                    if (lowerUser.find(lowerEmail) == 0) { // Display emails that start with the lowercase input
                                        cout << " - " << user << endl;
                                    }
                                }
                            }

                            cout << endl; // Move to the next line after Enter key

                            // Check for cancellation
                            if (email == "exit") {
                                clearScreen();
                                setColor(BRIGHT_YELLOW);
                                cout << ".---------------------.\n";
                                cout << "| Deletion cancelled. |\n";
                                cout << "'---------------------'\n";
                                setColor(RESET);
                            } else {
                                User* foundUser = userTree.searchUser(email);
                                if (!foundUser) {
                                    setColor(RED);
                                    cout << "No user found with email " << email << endl;
                                    setColor(RESET);
                                } else {
                                    setColor(BLUE);
                                    cout << "Are you sure you want to delete user '";
                                    setColor(GREEN);
                                    cout << email;
                                    setColor(RESET); 
                                    cout << "'? (Y/N): ";
                                    char confirmation = _getch();
                                    if (confirmation == 'Y' || confirmation == 'y') {
                                        userTree.deleteUser(email);
                                        setColor(GREEN);
                                        cout << "\n.------------------------------.\n";
                                        cout << "|  User deleted successfully!  |\n";
                                        cout << "'------------------------------'\n";
                                        setColor(RESET);
                                        userTree.saveUsersToFile("users.txt");
                                    } else {
                                        setColor(BRIGHT_YELLOW);
                                        cout << ".---------------------------.\n";
                                        cout << "|    Deletion cancelled.    |\n";
                                        cout << "'---------------------------'\n";
                                        setColor(RESET);
                                    }
                                    setColor(RESET);
                                }
                            }

                            system("pause");
                            break;
                        }
                        case 0:
                            break; // Go back to the main menu
                        default:
                            setColor(RED);
                            cout << ".------------------------------------.\n";
                            cout << "| Invalid choice. Please try again.  |\n";
                            cout << "'------------------------------------'\n";
                            setColor(RESET);
                            system("pause");
                        }
                    } while (subChoice != 0);
                }
                else if (mainChoice == 0) {
                    setColor(BRIGHT_YELLOW);
                    cout << ".------------------.\n";
                    cout << "|  Logging out...  |\n";
                    cout << "'------------------'\n";
                    setColor(RESET);
                    system("pause");
                    break;  // Log out to overall menu
                } else {
                    setColor(RED);
                    cout << ".------------------------------------.\n";
                    cout << "| Invalid choice. Please try again.  |\n";
                    cout << "'------------------------------------'\n";
                    setColor(RESET);
                    system("pause");
                }
            } while (mainChoice != 0);
        }
        else if (overalChoice == 2) {
            clearScreen();
            // User login
            if (!login(userTree)) {
                setColor(RED);
                cout << ".---------------------------------.\n";
                cout << "| Login failed. Please try again. |\n";
                cout << "'---------------------------------'\n";
                setColor(RESET);
                continue;
            } // Attempt to login, if failed, continue to overall menu

            do {
                displayUserActionMenu();
                cin >> mainChoice; // Changed to mainChoice to match the menu structure

                switch (mainChoice) {
                    case 1: { // Borrow Book
                        clearScreen();
                        setColor(BRIGHT_YELLOW);
                        cout << ".-------------------------.\n";
                        cout << "|  Type 'exit' to cancel  |\n";
                        cout << "'-------------------------'\n";
                        setColor(RESET);

                        string bookTitle;
                        char ch;

                        setColor(BLUE);
                        cout << "Enter the title of the book you want to borrow: ";
                        
                        // Duyệt từng ký tự nhập vào
                        setColor(GREEN);
                        while (true) {
                            ch = _getch();  // Lấy ký tự nhập từ bàn phím

                            // Thoát khi nhấn phím Enter
                            if (ch == '\r') {
                                break; // Kết thúc nhập
                            }
                            // Xóa ký tự nếu nhấn phím Backspace
                            else if (ch == '\b') { // Sửa điều kiện để không kiểm tra bookTitle.empty()
                                if (!bookTitle.empty()) {
                                    bookTitle.pop_back();
                                    cout << "\b \b"; // Xóa ký tự trên console
                                }
                            }
                            // Bổ sung ký tự vào tiêu đề sách
                            else if (isprint(ch)) {
                                bookTitle += ch;
                                cout << ch; // Hiển thị ký tự đã nhập
                            }

                            // Xóa màn hình để làm mới phần gợi ý
                            clearScreen();
                            setColor(BLUE);
                            cout << "Enter the title of the book you want to borrow: " << bookTitle << endl;

                            // Kiểm tra xem có người dùng nào đang đăng nhập không
                            if (userTree.getCurrentUserName().empty()) {
                                setColor(RED);
                                cout << ".---------------------------------.\n";
                                cout << "| No user is currently logged in. |\n";
                                cout << "'---------------------------------'\n";
                                setColor(RESET);
                                break; // Thoát khỏi vòng lặp
                            } 
                            // Check for cancellation
                            else if (bookTitle == "exit") {
                                setColor(BRIGHT_YELLOW);
                                cout << ".----------------------.\n";
                                cout << "| Borrowing cancelled. |\n";
                                cout << "'----------------------'\n";
                                setColor(RESET);
                                break; // Exit the loop
                            }
                            else {
                                // Hiển thị gợi ý sách
                                vector<Book*> suggestions = library.getSuggestionsByTitle(bookTitle); // Gọi hàm gợi ý
                                if (!suggestions.empty()) {
                                    setColor(GREEN);
                                    cout << "Suggestions:\n";
                                    for (const auto& suggestion : suggestions) {
                                        cout << " - " << suggestion->getTitle() << endl; // Gọi phương thức getTitle() nếu cần
                                    }
                                    setColor(RESET);
                                } else {
                                    setColor(RED);
                                    cout << ".----------------------------.\n";
                                    cout << "| No suggestions available.  |\n";
                                    cout << "'----------------------------'\n";
                                    setColor(RESET);
                                }
                            }
                        }
                        setColor(RESET);

                        // Mượn sách khi đã nhập xong tiêu đề
                        if (!userTree.getCurrentUserName().empty() && bookTitle != "exit") {
                            userTree.borrowBook(userTree.getCurrentUserName(), bookTitle, library); // Gọi hàm borrowBook với tên sách
                        }
                        
                        library.saveToFile(filename);
                        system("pause");
                        break;
                    }
                    case 2: { // Return Book
                        clearScreen();
                        setColor(BRIGHT_YELLOW);
                        cout << ".-------------------------.\n";
                        cout << "|  Type 'exit' to cancel  |\n";
                        cout << "'-------------------------'\n";
                        setColor(RESET);

                        string bookTitle;
                        char ch;

                        setColor(BLUE);
                        cout << "Enter the title of the book you want to return: ";

                        // Input loop
                        while (true) {
                            ch = _getch();  // Get character input from keyboard
                            
                            // Exit on Enter key (ASCII 13)
                            if (ch == 13) {  // Change '\r' to 13 for clarity
                                break; // End input
                            }
                            // Handle Backspace
                            else if (ch == '\b') {
                                if (!bookTitle.empty()) {
                                    bookTitle.pop_back();
                                    cout << "\b \b"; // Remove character from console
                                }
                            }
                            // Add character to book title
                            else if (isprint(ch)) {
                                bookTitle += ch;
                                cout << ch; // Display character
                            }

                            // Clear screen for suggestions
                            clearScreen();
                            setColor(BLUE);
                            cout << "Enter the title of the book you want to return: " << bookTitle << endl;
                            setColor(RESET);

                            // Check for logged-in user
                            string currentUser = userTree.getCurrentUserName();
                            if (currentUser.empty()) {
                                setColor(RED);
                                cout << ".---------------------------------.\n";
                                cout << "| No user is currently logged in. |\n";
                                cout << "'---------------------------------'\n";
                                setColor(RESET);
                                break; // Exit loop if no user is logged in
                            } else if (bookTitle == "exit") {
                                setColor(BRIGHT_YELLOW);
                                cout << ".----------------------.\n";
                                cout << "| Returning cancelled. |\n";
                                cout << "'----------------------'\n";
                                setColor(RESET);
                                break; // Exit the loop
                            }

                            // Read from borrows.txt and search for suggestions
                            vector<string> suggestions;
                            ifstream borrowsFile("borrows.txt");
                            if (borrowsFile.is_open()) {
                                string line;
                                while (getline(borrowsFile, line)) {
                                    // Assuming the format in borrows.txt is: username, bookTitle, borrowDate, returnDate
                                    // Split the line by commas and get the book title
                                    stringstream ss(line);
                                    string username, bookTitleFromFile, borrowDate, returnDate;

                                    // Read the first four fields
                                    getline(ss, username, ',');
                                    getline(ss, bookTitleFromFile, ',');
                                    getline(ss, borrowDate, ',');
                                    getline(ss, returnDate);

                                    // Check if the book title contains the user input
                                    if (bookTitleFromFile.find(bookTitle) != string::npos) {
                                        suggestions.push_back(bookTitleFromFile); // Add matching title to suggestions
                                    }
                                }
                                borrowsFile.close();
                            } else {
                                setColor(RED);
                                cout << ".------------------------------------.\n";
                                cout << "| Error: Unable to open borrows.txt  |\n";
                                cout << "'------------------------------------'\n";
                                setColor(RESET);
                                break; // Exit if file cannot be opened
                            }

                            // Show suggestions
                            if (!suggestions.empty()) {
                                setColor(GREEN);
                                cout << "Suggestions:\n";
                                for (const auto& suggestion : suggestions) {
                                    cout << " - " << suggestion << endl; // Display each suggestion
                                }
                                setColor(RESET);
                            } else {
                                setColor(RED);
                                cout << ".---------------------------.\n"; 
                                cout << "| No suggestions available. |\n";
                                cout << "'---------------------------'\n";
                                setColor(RESET);
                            }
                        }
                        setColor(RESET);

                        // Return book if user is logged in
                        if (!userTree.getCurrentUserName().empty() && bookTitle != "exit") {
                            userTree.returnBook(userTree.getCurrentUserName(), bookTitle, library); // Call returnBook with book title
                        }
                        library.saveToFile(filename);
                        system("pause");
                        break;
                    }
                    case 3: { // Show Borrowed Books
                        clearScreen();
                        if (userTree.getCurrentUserName().empty()) {
                            setColor(RED);
                            cout << ".---------------------------------.\n";
                            cout << "| No user is currently logged in. |\n";
                            cout << "'---------------------------------'\n";
                            setColor(RESET);
                        } else {
                            setColor(BRIGHT_GREEN);
                            cout << "Books currently borrowed by you:" << endl;
                            setColor(RESET);
                            userTree.showRentedBooks(); // This method should list borrowed books for the current user
                        }
                        system("pause");
                        break;
                    }
                    case 4: {
                        clearScreen();
                        setColor(BRIGHT_MAGENTA);
                        cout << "               .----------------------------------------------------.\n";
                        setColor(MAGENTA);
                        cout << "               |=========== List of Books in the Library ===========|\n";
                        setColor(BRIGHT_RED);
                        cout << "               '----------------------------------------------------'\n";
                        setColor(RESET);
                        library.displayBooks();
                        system("pause");
                        break;
                    }
                    case 0: { // Log out
                        setColor(YELLOW);
                        cout << ".------------------.\n";
                        cout << "|  Logging out...  |\n";
                        cout << "'------------------'\n";
                        setColor(RESET);
                        system("pause");
                        break; // Exit to overall menu
                    }
                    default:
                        setColor(RED);
                        cout << ".-----------------------------------.\n";
                        cout << "| Invalid choice. Please try again. |\n";
                        cout << "'-----------------------------------'\n";
                        setColor(RESET);
                        system("pause");
                }
            } while (mainChoice != 0); // Repeat until user chooses to log out
        }
        else if (overalChoice == 0) {
            // Save books to file before exiting
            library.saveToFile(filename);
            setColor(YELLOW);
            cout << ".-------------------------.\n";
            cout << "| Exiting the program...  |\n";
            cout << "'-------------------------'\n";
            setColor(RESET);
            break;
        }
        else {
            setColor(RED);
            cout << ".-----------------------------------.\n";
            cout << "| Invalid choice. Please try again. |\n";
            cout << "'-----------------------------------'\n";
            setColor(RESET);
            system("pause");
        }
    } while (overalChoice != 0);

    return 0;
}