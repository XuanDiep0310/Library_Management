#include <iostream>
#include "./lib/Book.h"
#include "./lib/UserTree.h"
#include "./lib/User.h"
#include "./lib/System.h"

using namespace std;

void borrowBook(const string& username, const string& bookTitle, BSTree& bookTree); 
void returnBook(const string& username, const string& bookTitle, BSTree& bookTree);

int main() {
    BSTree library;
    UserTree userTree;
    int overalChoice, mainChoice, subChoice;
    const string filename = "books.txt";

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
                            int id, year, quantity;
                            string title, author, genre, status;
                            cout << "Enter Book ID: "; cin >> id;
                            cout << "Enter Title: "; cin.ignore(); getline(cin, title);
                            cout << "Enter Author: "; getline(cin, author);
                            cout << "Enter Genre: "; getline(cin, genre);
                            cout << "Enter Year: "; cin >> year;
                            cout << "Enter Quantity: "; cin >> quantity;
                            cout << "Enter Status: "; cin.ignore(); getline(cin, status);
                            library.addBook(id, title, author, genre, year, quantity, status);
                            cout << "Book added successfully!" << endl;
                            library.saveToFile(filename);
                            system("pause");
                            break;
                        }
                        case 2: {//List book
                            cout << "\nList of Books in the Library:" << endl;
                            library.displayBooks();
                            system("pause");
                            break;
                        }
                        case 3: {  // Search Book by Title
                            string bookTitle;
                            cout << "Enter Book Title to Search: ";
                            cin.ignore();  // Clear input buffer before getting string
                            getline(cin, bookTitle);

                            Book* foundBook = library.searchBook(bookTitle);
                            if (foundBook != nullptr) {
                                cout << "Found Books:" << endl;
                                cout << "ID: " << foundBook->getBookId() << ", Title: " << foundBook->getTitle()
                                     << ", Author: " << foundBook->getAuthor() << endl;
                            }
                            else {
                                cout << "No book found with title \"" << bookTitle << "\"" << endl;
                            }
                            system("pause");
                            break;
                        }

                        case 4: { // Delete book
                            string title;
                            cout << "Enter Book Title to Delete: ";
                            cin.ignore(); // To ignore any leftover newline character in the input buffer
                            getline(cin, title); // Read the entire line to get the title
                            library.deleteBookByTitle(title); // Call the deleteBookByTitle method
                            cout << "Book deleted successfully!" << endl;
                            library.saveToFile(filename);
                            system("pause");
                            break;
                        }

                        case 0:
                            break; // Go back to the main menu
                        default:
                            cout << "Invalid choice. Please try again." << endl;
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
                        case 1: { //Add user
                            string name, email, username, password;
                            int day, month, year;
                            cout << "Enter User Name: "; cin.ignore(); getline(cin, name);
                            cout << "Enter Email: "; getline(cin, email);
                            cout << "Enter Username: "; getline(cin, username);
                            cout << "Enter Password: "; getline(cin, password);
                            cout << "Enter Birthday (Day Month Year): "; cin >> day >> month >> year;

                            //Add user and save to file
                            userTree.addUser(new User(name, Date(day, month, year), email, username, password));
                            cout << "User added successfully!" << endl;
                            userTree.saveUsersToFile(filename);
                            system("pause");
                            break;
                        }
                        case 2:
                            cout << "\nList of Users in the System:" << endl;
                            userTree.displayUsers();
                            system("pause");
                            break;
                        case 3: {
                            string username;
                            cout << "Enter Username to Search: ";
                            cin.ignore();
                            getline(cin, username);
                            User* foundUser = userTree.searchUser(username);
                            if (foundUser) {
                                cout << "Found User: " << foundUser->getUsername() << " (" << foundUser->getMail() << ")" << endl;
                            }
                            else {
                                cout << "No user found with username " << username << endl;
                            }
                            system("pause");
                            break;
                        }
                        case 4: {
                            string username;
                            cout << "Enter Username to Delete: ";
                            cin.ignore();
                            getline(cin, username);
                            userTree.deleteUser(username);
                            cout << "User deleted successfully!" << endl;
                            userTree.saveUsersToFile(filename);
                            system("pause");
                            break;
                        }
                        case 0:
                            break; // Go back to the main menu
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            system("pause");
                        }
                    } while (subChoice != 0);
                }
                else if (mainChoice == 0) {
                    cout << "Logging out..." << endl;
                    system("pause");
                    break;  // Log out to overall menu
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                    system("pause");
                }
            } while (mainChoice != 0);
        }
        else if (overalChoice == 2) {
            // User login
            if (!login(userTree)) {
                cout << "Login failed. Please try again." << endl;
                continue;
            } // Attempt to login, if failed, continue to overall menu

            do {
                displayUserActionMenu();
                cin >> mainChoice; // Changed to mainChoice to match the menu structure

                switch (mainChoice) {
                    case 1: { // Borrow Book
                        string bookTitle;
                        cout << "Enter the title of the book you want to borrow: ";
                        cin.ignore(); // Clear input buffer
                        getline(cin, bookTitle);

                        // Kiểm tra xem có người dùng nào đang đăng nhập không
                        if (userTree.getCurrentUserName().empty()) {
                            cout << "No user is currently logged in." << endl;
                        } else {
                            userTree.borrowBook(userTree.getCurrentUserName(), bookTitle, library); // Gọi hàm borrowBook với tên sách
                        }
                        system("pause");
                        break;
                    }
                    case 2: { // Return Book
                        string bookTitle;
                        cout << "Enter the title of the book you want to return: ";
                        cin.ignore();
                        getline(cin, bookTitle);

                        // Kiểm tra xem có người dùng nào đang đăng nhập không
                        if (userTree.getCurrentUserName().empty()) {
                            cout << "No user is currently logged in." << endl;
                        } else {
                            userTree.returnBook(userTree.getCurrentUserName(), bookTitle, library); // Gọi hàm returnBook với tên sách
                        }
                        system("pause");
                        break;
                    }
                    case 3: { // Show Borrowed Books
                        if (userTree.getCurrentUserName().empty()) {
                            cout << "No user is currently logged in." << endl;
                        } else {
                            cout << "Books currently borrowed by you:" << endl;
                            userTree.showRentedBooks(); // This method should list borrowed books for the current user
                        }
                        system("pause");
                        break;
                    }
                    case 4: { // Log out
                        cout << "Logging out..." << endl;
                        system("pause");
                        break; // Exit to overall menu
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        system("pause");
                }
            } while (mainChoice != 4); // Repeat until user chooses to log out
        }
        else if (overalChoice == 0) {
            // Save books to file before exiting
            library.saveToFile(filename);
            cout << "Exiting the program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
        }
    } while (overalChoice != 0);

    return 0;
}