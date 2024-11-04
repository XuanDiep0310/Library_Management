#include <iostream>
#include "./lib/Book.h"
#include "./lib/UserTree.h"
#include "./lib/User.h"
#include "./lib/System.h"
#include "./lib/Graphic.h"
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <limits>
#include <conio.h>
#include <regex> // Include for regex validation

using namespace std;

void borrowBook(const string& username, const string& bookTitle, BSTree& bookTree); 
void returnBook(const string& username, const string& bookTitle, BSTree& bookTree);

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
                        case 1: { //Add book
                            clearScreen();
                            int id, year, quantity;
                            string title, author, genre, status;

                            do{
                                setColor(BRIGHT_YELLOW);
                                cout << "Enter Book ID: "; cin >> id;

                                // Check if the Book ID already exists
                                if (library.getBookById(id) != nullptr) {  // Using getBookById to check for duplicates
                                    setColor(RED);
                                    cout << ".---------------------------------------------------------------.\n";
                                    cout << "| Error: Book ID already exists. Please enter a unique Book ID. |\n";
                                    cout << "'---------------------------------------------------------------'\n";
                                    setColor(RESET);

                                    moveCursorUp(4); // Move the cursor up to the ID prompt
                                    clearLine(); // Clear the ID prompt line
                                    clearLine(); // Clear the first error line
                                    clearLine(); // Clear the second error line
                                } else {
                                    break;  // Unique ID found, exit the loop
                                }
                            }while(library.getBookById(id) != nullptr);

                            setColor(YELLOW);
                            cout << "Enter Title: "; cin.ignore(); getline(cin, title);
                            setColor(BRIGHT_GREEN);
                            cout << "Enter Author: "; getline(cin, author);
                            setColor(GREEN);
                            cout << "Enter Genre: "; getline(cin, genre);
                            setColor(BRIGHT_CYAN);
                            cout << "Enter Year: "; cin >> year;
                            do {
                                setColor(CYAN);
                                cout << "Enter Quantity: "; cin >> quantity;
                                if(quantity <= 0) {
                                    setColor(RED);
                                    cout << ".-------------------------------------------------.\n";
                                    cout << "| Quantity must larger than 0! Please try again!  |\n";
                                    cout << "'-------------------------------------------------'\n";
                                    system("pause");
                                    setColor(RESET);

                                    moveCursorUp(5); // Move cursor up to the Quantity prompt
                                    clearLine(); // Clear Quantity prompt
                                    clearLine(); // Clear the error message
                                    clearLine(); // Clear the bottom border line
                                }
                            }while(quantity <= 0);

                            setColor(BRIGHT_BLUE);
                            do{
                                cout << "Enter Status (Available, Rented, Updating): "; cin.ignore(); getline(cin, status);

                                status = library.matchStatus(status);
                                if (status.empty()) {
                                    setColor(RED);
                                    cout << ".----------------------------------------------------------------.\n";
                                    cout << "|  Invalid status. Please enter Available, Rented, or Updating.  |\n";
                                    cout << "'----------------------------------------------------------------'\n";
                                    setColor(BRIGHT_BLUE);

                                    moveCursorUp(4); // Move up to the Quantity prompt
                                    clearLine();
                                    clearLine();
                                    clearLine();
                                }
                            } while(status.empty());
                            setColor(BLUE);
                            library.addBook(id, title, author, genre, year, quantity, status);
                            clearScreen();
                            setColor(GREEN);
                            cout << ".---------------------------.\n";
                            cout << "| Book added successfully!  |\n";
                            cout << "'---------------------------'\n";
                            setColor(RESET);
                            library.saveToFile(filename);
                            system("pause");
                            break;
                        }
                        case 2: { // Update book information
                            string bookTitle;
                            setColor(MAGENTA);
                            cout << "Enter the Title of the Book to Update: ";
                            setColor(RESET);
                            cin.ignore();
                            getline(cin, bookTitle);

                            library.updateBookInformation(bookTitle);
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
                            string bookTitle;
                            setColor(BRIGHT_MAGENTA);
                            cout << "Enter Book Title to Search (suggestions will appear as you type): ";
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
                                bookTitle += ch;

                                // Clear screen and display prompt again with current input
                                clearScreen();
                                setColor(BRIGHT_MAGENTA);
                                cout << "Enter Book Title to Search (suggestions will appear as you type): " << bookTitle << endl;
                                setColor(RESET);

                                // Convert current input to lowercase for case-insensitive comparison
                                string lowerBookTitle = bookTitle;
                                transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);

                                // Retrieve suggestions based on the current title input
                                vector<Book*> suggestions = library.getSuggestionsByTitle(bookTitle);

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
                            Book* foundBook = library.searchBook(bookTitle);
                            if (foundBook != nullptr) {
                                setColor(GREEN);
                                cout << "\nFound Book:\n";

                                // Table header
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
                            system("pause");
                            break;
                        }

                        case 5: { // Delete book
                            clearScreen();
                            string title;
                            setColor(BRIGHT_RED);
                            cout << "Enter Book Title to Delete (suggestions will appear as you type): ";
                            setColor(RESET);
                            
                            char ch;
                            vector<Book*> suggestions;

                            while (true) {
                                ch = _getch();  // Use _getch() to read a single character without pressing Enter

                                if (ch == '\r') {  // Enter key pressed
                                    break;
                                } else if (ch == '\b') {  // Backspace key
                                    if (!title.empty()) {
                                        title.pop_back();  // Remove the last character
                                    }
                                } else {
                                    title += ch;  // Add character to title
                                }

                                // Clear screen for updated suggestions
                                clearScreen();  // Implement clearScreen to refresh the display as needed
                            
                                // Display the prompt and current input
                                setColor(BRIGHT_RED);
                                cout << "Enter Book Title to Delete (suggestions will appear as you type): " << title << endl;
                                setColor(RESET);

                                string lowerTitle = title;
                                transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
                                // Fetch suggestions based on current input
                                suggestions = library.getSuggestionsByTitle(lowerTitle);

                                // Display suggestions
                                cout << "Suggestions: ";
                                if (suggestions.empty()) {
                                    cout << "No suggestions available.";
                                } else {
                                    for (const auto& book : suggestions) {
                                        string bookTitle = book->getTitle();
                                        string lowerBookTitle = bookTitle;
                                        transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);
                                        
                                        if (lowerBookTitle.find(lowerTitle) != string::npos) {
                                            cout << bookTitle << "  ";  // Display the original title with correct casing
                                        }
                                    }
                                }
                                cout << endl;
                            }

                            // Final deletion confirmation
                            if (!title.empty()) {
                                    library.deleteBookByTitle(title);  // Call the delete function (even without a bool return type)
                                    setColor(GREEN);
                                    cout << "Book deleted successfully!" << endl;
                                    setColor(RESET);
                                    library.saveToFile(filename);
                                } else {
                                    setColor(RED);
                                    cout << "Book not found or could not be deleted." << endl;
                                    setColor(RESET);
                                }

                            system("pause");
                            break;
                        }

                        case 0:
                            break; // Go back to the main menu
                        default:
                            cout << ".-----------------------------------.\n";
                            cout << "| Invalid choice. Please try again. |\n";
                            cout << "'-----------------------------------'\n";
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
                            string name, email, username, password;
                            int day, month, year;

                            // Load existing users from file into a temporary vector
                            vector<User*> existingUsers; // Temporarily store users for checking duplicates
                            userTree.loadUsersFromFile(filename); // Load users into UserTree

                            // Assuming UserTree keeps a list of users internally, if needed, you can have a method to get them:
                            existingUsers = userTree.getAllUsers(); // Assuming this method returns a vector of User pointers

                            // Get user name
                            setColor(BLUE);
                            cout << "Enter User Name: "; 
                            cin.ignore(); 
                            getline(cin, name);
                            setColor(RESET);

                            // Get email with duplicate check and format validation
                            bool validEmail = false;
                            do {
                                setColor(BRIGHT_BLUE);
                                cout << "Enter Email: "; 
                                getline(cin, email);
                                setColor(RESET);

                                // Check for existing email
                                auto emailIt = find_if(existingUsers.begin(), existingUsers.end(), [&](User* user) {
                                    return user->getMail() == email; // Ensure your User class has getEmail method
                                });

                                // Email format validation
                                bool emailFormatValid = (email.find("@gmail.com") != string::npos) || (email.find(".edu") != string::npos);

                                if (!emailFormatValid) {
                                    setColor(RED);
                                    cout << "Invalid email format. Please enter a valid '@gmail.com' or '.edu' email." << endl;
                                    setColor(RESET);
                                    system("pause");
                                } else if (emailIt != existingUsers.end()) {
                                    setColor(RED);
                                    cout << "Email already exists. Please use a different email." << endl;
                                    setColor(RESET);
                                    system("pause");
                                } else {
                                    validEmail = true; // Email is valid, exit the loop
                                }
                            } while (!validEmail);

                            // Get username with duplicate check
                            bool validUsername = false;
                            do {
                                cout << "Enter Username: "; 
                                getline(cin, username);

                                // Check for existing username
                                auto usernameIt = find_if(existingUsers.begin(), existingUsers.end(), [&](User* user) {
                                    return user->getUsername() == username;
                                });

                                if (usernameIt != existingUsers.end()) {
                                    setColor(RED);
                                    cout << "Username already exists. Please use a different username." << endl;
                                    setColor(RESET);
                                    system("pause");
                                } else {
                                    validUsername = true; // Username is valid, exit the loop
                                }
                            } while (!validUsername);

                            // Get password
                            setColor(MAGENTA);
                            cout << "Enter Password: "; 
                            getline(cin, password);
                            setColor(RESET);

                            // Get birthday with validation
                            bool validDate = false;
                            do {
                                setColor(YELLOW);
                                cout << "Enter Birthday (Day Month Year): "; 
                                cin >> day >> month >> year;
                                setColor(RESET);

                                if (Date::isValidDate(day, month, year)) {
                                    validDate = true;
                                } else {
                                    setColor(RED);
                                    cout << "Invalid date entered. Please enter a valid date." << endl;
                                    setColor(RESET);
                                    // Clear the error state and ignore invalid input to allow re-entry
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            } while (!validDate);

                            // Add user and save to file
                            userTree.addUser(new User(name, Date(day, month, year), email, username, password));
                            cout << "User added successfully!" << endl;
                            userTree.saveUsersToFile(filename);
                            
                            system("pause");
                            break;
                        }
                        case 2: { // Update User Information
                            clearScreen();
                            string username;
                            cout << "Enter Username to Update: ";
                            cin.ignore();
                            getline(cin, username);

                            userTree.updateUserInformation(username);
                            system("pause");
                            break;
                        }
                        case 3:
                            clearScreen();
                            cout << "\nList of Users in the System:" << endl;
                            userTree.displayUsers();
                            system("pause");
                            break;
                        // Case 4: Search for User with Suggestions
                        case 4: {
                            clearScreen();
                            string username;
                            char ch;
                            cout << "Enter Username to Search: ";
                            cin.ignore();

                            // Dynamically update suggestions based on input
                            while (true) {
                                ch = _getch(); // Read each character input without pressing enter
                                if (ch == '\r') { // Enter key pressed
                                    break;
                                } else if (ch == '\b') { // Backspace
                                    if (!username.empty()) {
                                        username.pop_back();
                                    }
                                } else {
                                    username += ch;
                                }

                                clearScreen(); // Clear screen to refresh suggestions
                                cout << "Enter Username to Search: " << username << endl;

                                // Display search suggestions
                                vector<User*> suggestions = userTree.suggestUsersByUsername(username);
                                if (!suggestions.empty()) {
                                    cout << "Suggestions:" << endl;
                                    for (const auto& user : suggestions) {
                                        cout << " - " << user->getUsername() << " (" << user->getMail() << ")" << endl;
                                    }
                                }
                            }

                            // Perform final search
                            User* foundUser = userTree.searchUser(username);
                            if (foundUser) {
                                cout << "Found User: " << foundUser->getUsername() << " (" << foundUser->getMail() << ")" << endl;
                            } else {
                                cout << "No user found with username " << username << endl;
                            }
                            system("pause");
                            break;
                        }

                        // Case 5: Delete User with Confirmation Prompt
                        case 5: {
                            clearScreen();
                            string username;
                            char confirmation;

                            setColor(RED);
                            cout << "Enter Username to Delete: ";
                            cin.ignore();
                            getline(cin, username);
                            setColor(RESET);

                            User* foundUser = userTree.searchUser(username);
                            if (!foundUser) {
                                setColor(RED);
                                cout << "No user found with username " << username << endl;
                                setColor(RESET);
                            } else {
                                setColor(BLUE);
                                cout << "Are you sure you want to delete user '" << username << "'? (Y/N): ";
                                confirmation = _getch();
                                if (confirmation == 'Y' || confirmation == 'y') {
                                    userTree.deleteUser(username);
                                    setColor(GREEN);
                                    cout << ".------------------------------.\n";
                                    cout << "|  User deleted successfully!  |\n";
                                    cout << "'------------------------------'\n";
                                    setColor(RESET);
                                    userTree.saveUsersToFile(filename);
                                } else {
                                    setColor(BRIGHT_YELLOW);
                                    cout << ".---------------------------.\n";
                                    cout << "|    Deletion cancelled.    |\n";
                                    cout << "'---------------------------'\n";
                                    setColor(RESET);
                                }
                                setColor(RESET);
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
                    cout << ".------------------------------------.\n";
                    cout << "| Invalid choice. Please try again.  |\n";
                    cout << "'------------------------------------'\n";
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
                            cout << "Enter the title of the book you want to borrow: " << bookTitle << endl;

                            // Kiểm tra xem có người dùng nào đang đăng nhập không
                            if (userTree.getCurrentUserName().empty()) {
                                setColor(RED);
                                cout << ".---------------------------------.\n";
                                cout << "| No user is currently logged in. |\n";
                                cout << "'---------------------------------'\n";
                                setColor(RESET);
                                break; // Thoát khỏi vòng lặp
                            } else {
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
                        if (!userTree.getCurrentUserName().empty()) {
                            userTree.borrowBook(userTree.getCurrentUserName(), bookTitle, library); // Gọi hàm borrowBook với tên sách
                        }
                        
                        library.saveToFile(filename);
                        system("pause");
                        break;
                    }
                    case 2: { // Return Book
                        clearScreen();
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
                            cout << "Enter the title of the book you want to return: " << bookTitle << endl;

                            // Check for logged-in user
                            string currentUser = userTree.getCurrentUserName();
                            if (currentUser.empty()) {
                                cout << "No user is currently logged in." << endl;
                                break; // Exit loop if no user is logged in
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
                                cout << "Error: Unable to open borrows.txt" << endl;
                                break; // Exit if file cannot be opened
                            }

                            // Show suggestions
                            if (!suggestions.empty()) {
                                cout << "Suggestions:\n";
                                for (const auto& suggestion : suggestions) {
                                    cout << " - " << suggestion << endl; // Display each suggestion
                                }
                            } else {
                                cout << "No suggestions available." << endl;
                            }
                        }
                        setColor(RESET);

                        // Return book if user is logged in
                        if (!userTree.getCurrentUserName().empty()) {
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
                    case 4: { // Log out
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
            } while (mainChoice != 4); // Repeat until user chooses to log out
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