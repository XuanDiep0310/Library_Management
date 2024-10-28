#include <iostream>
#include "./lib/Book.h"
#include "./lib/UserTree.h"
#include "./lib/System.h"

using namespace std;

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

                            vector<Book*> foundBooks = library.searchBook(bookTitle);
                            if (!foundBooks.empty()) {
                                cout << "Found Books:" << endl;
                                for (const auto& book : foundBooks) {
                                    cout << "ID: " << book->getBookId() << ", Title: " << book->getTitle()
                                        << ", Author: " << book->getAuthor() << endl;
                                }
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