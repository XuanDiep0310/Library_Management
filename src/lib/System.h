#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "UserTree.h"
#include "Graphic.h"

using namespace std;

// Function to check if the input string is "exit"
bool isExitCommand(const string& input) {
    return input == "exit";
}

void displayBookMenu() {
    setColor(MAGENTA);
    cout << ".---------------------------------.\n";
    setColor(BRIGHT_MAGENTA);
    cout << "|======== Book Management ========|\n";
    setColor(BLUE);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_BLUE);
    cout << "|   1. Add Book                   |\n";
    setColor(CYAN);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_CYAN);
    cout << "|   2. Update Book Information    |\n";
    setColor(GREEN);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_GREEN);
    cout << "|   3. Display Books              |\n";
    setColor(YELLOW);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    cout << "|   4. Search Book by title       |\n";
    setColor(RED);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_RED);
    cout << "|   5. Delete Book by title       |\n";
    setColor(YELLOW);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    cout << "|   0. Go back                    |\n";
    setColor(GREEN);
    cout << "'---------------------------------'\n";
    setColor(BRIGHT_GREEN);
    cout << "Enter your choice: ";
    setColor(RESET);
}

void displayUserMenu() {
    setColor(BRIGHT_RED);
    cout << ".---------------------------------.\n";
    setColor(RED);
    cout << "|======== User Management ========|\n";
    setColor(YELLOW);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    cout << "|   1. Add User                   |\n";
    setColor(BRIGHT_GREEN);
    cout << "|---------------------------------|\n";
    setColor(GREEN);
    cout << "|   2. Update User Infomation     |\n";
    setColor(CYAN);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_CYAN);
    cout << "|   3. Display Users              |\n";
    setColor(BRIGHT_BLUE);
    cout << "|---------------------------------|\n";
    setColor(BLUE);
    cout << "|   4. Search User by Username    |\n";
    setColor(MAGENTA);
    cout << "|---------------------------------|\n";
    setColor(BRIGHT_MAGENTA);
    cout << "|   5. Delete User by Username    |\n";
    setColor(BRIGHT_BLUE);
    cout << "|---------------------------------|\n";
    setColor(BLUE);
    cout << "|   0. Go back                    |\n";
    setColor(CYAN);
    cout << "'---------------------------------'\n";
    setColor(BRIGHT_CYAN);
    cout << "Enter your choice: ";
    setColor(RESET);
}

void displayMainMenu() {
    clearScreen();
    setColor(GREEN);
    cout << ".-------------------------------------.\n";
    setColor(BRIGHT_GREEN);
    cout << "|===== Library Management System =====|\n";
    setColor(CYAN);
    cout << "|-------------------------------------|\n";
    setColor(BRIGHT_CYAN);
    cout << "|   1. Books Management               |\n";
    setColor(BRIGHT_BLUE);
    cout << "|-------------------------------------|\n";
    setColor(BLUE);
    cout << "|   2. Users Management               |\n";
    setColor(BRIGHT_MAGENTA);
    cout << "|-------------------------------------|\n";
    setColor(MAGENTA);
    cout << "|   0. Logout                         |\n";
    setColor(BRIGHT_RED);
    cout << "'-------------------------------------'\n";
    setColor(RED);
    cout << "Enter your choice: ";
    setColor(RESET);
}

void displayOveralMenu() {
    clearScreen();
    setColor(BRIGHT_RED);
    cout << "._.    _ ._.\n";
    cout << "| |   (_)| |__  _ __ __ _ _ __ __ _ _   \n";
    setColor(RED);
    cout << "| |   | || '_ \\| '__/ _` | '__/| | | |\n";
    setColor(BRIGHT_YELLOW);
    cout << "| |___| || |_) | | | (_| | |   | |_| |\n";
    setColor(YELLOW);
    cout << "|_____|_||.__,/|_|  \\__,_|_|    \\__, |\n";
    setColor(BRIGHT_GREEN);
    cout << "                                |___/\n";
    setColor(GREEN);
    cout << "    _                _ _           _   _\n";
    setColor(BRIGHT_CYAN);
    cout << "   / \\   _ __  _ __ | (_) ___ __ _| |_(_) ___  _ __\n";
    setColor(CYAN);
    cout << "  / _ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\\n";
    setColor(BRIGHT_BLUE);
    cout << " / ___ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | |\n";
    setColor(BLUE);
    cout << "/_/   \\_\\ .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|\n";
    setColor(BRIGHT_MAGENTA);
    cout << "        |_|   |_|\n";
    setColor(MAGENTA);
    cout << "          .--------------------.\n";
    setColor(BLUE);
    cout << "          |   1. Admin login   |\n";
    setColor(BRIGHT_BLUE);
    cout << "          |--------------------|\n";
    setColor(CYAN);
    cout << "          |   2. User login    |\n";
    setColor(BRIGHT_CYAN);
    cout << "          |--------------------|\n";
    setColor(GREEN);
    cout << "          |   0. Exit          |\n";
    setColor(BRIGHT_GREEN);
    cout << "          '--------------------'\n";
    setColor(YELLOW);
    cout << "          Enter your choice: ";
    setColor(RESET);
}

// Function to get username with Esc key handling
string getUsername() {
    string username;
    char ch;

    setColor(BLUE);
    cout << "Enter Username: ";
    setColor(RESET);
    while (true) {
        ch = _getch();

        if (ch == 27) { // Esc key pressed
            return ""; // Return an empty string to indicate cancellation
        }
        else if (ch == '\r') { // Enter key pressed
            cout << endl;
            break;
        }
        else if (ch == '\b' && !username.empty()) { // Backspace pressed
            username.pop_back();
            cout << "\b \b"; // Erase the last character
        }
        else if (isprint(ch)) { // Printable character
            username += ch;
            cout << ch;
        }
    }
    return username;
}

// Function to get password with masking and Tab for toggle visibility
string getPassword() {
    string password;
    bool showPassword = false;
    char ch;

    while (true) {
        ch = _getch(); // Get a character without displaying it
        
        if (ch == 27) { // Esc key pressed
            return ""; // Return an empty string to indicate cancellation
        }

        if (ch == '\r') { // Enter key pressed
            cout << endl;
            break;
        }
        else if (ch == '\b' && !password.empty()) { // Backspace pressed
            password.pop_back();
            cout << "\b \b"; // Move back, erase character, move back again
        }
        else if (ch == '\t') { // Tab key pressed to toggle visibility
            showPassword = !showPassword;
            // Clear the line and reprint the prompt with updated visibility
            cout << "\rEnter Password: ";
            for (size_t i = 0; i < password.size() + 20; ++i) cout << ' '; // Clear extra characters
            cout << "\rEnter Password: "; // Reset cursor position
            for (char c : password) {
                cout << (showPassword ? c : '*');
            }
        }
        else if (isprint(ch)) { // Printable characters
            password += ch;
            cout << (showPassword ? ch : '*');
        }
    }
    return password;
}

bool login(UserTree& userTree) {
    setColor(BRIGHT_YELLOW);
    cout << ".-------------------------------------.\n";
    cout << "|    Press ";
    setColor(RED);
    cout << "[Esc]";
    setColor(RESET);
    cout << " to cancel!           |\n";
    cout << "'-------------------------------------'\n";
    setColor(YELLOW);
    string username = getUsername();
    if (username.empty()) { // Check if Esc was pressed during username entry
        setColor(YELLOW);
        cout << "\n.------------------------------------------.\n";
        cout << "|  Login canceled. Returning to main menu  |.\n";
        cout << "'------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false; // Exit immediately without asking for password
    }

    setColor(BRIGHT_YELLOW);
    cout << ".---------------------------------------.\n";
    cout << "|     Press ";
    setColor(BLUE);
    cout << "[Tab]";
    setColor(RESET);
    cout << " to show password      |\n";
    cout << "'---------------------------------------'\n";
    setColor(RESET);
    setColor(BLUE);
    cout << "Enter Password: ";
    setColor(RESET);
    string password = getPassword();
    if (password.empty()) { // Check if Esc was pressed during password entry
        setColor(YELLOW);
        cout << "\nLogin canceled.\n";
        setColor(RESET);
        system("pause");
        return false;
    }

    clearScreen();
    if (userTree.login(username, password)) {
        setColor(GREEN);
        cout << ".---------------------.\n";
        cout << "|  Login successful!  |\n";
        cout << "'---------------------'\n";
        setColor(RESET);
        system("pause");
        return true;
    }
    else {
        setColor(RED);
        cout << ".--------------------------------------------------------.\n";
        cout << "|    Invalid username or password. Please try again.     |\n";
        cout << "'--------------------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false;
    }
}

void displayUserActionMenu() {
    clearScreen();
    setColor(BRIGHT_YELLOW);
    cout << ".---------------------------------.\n";
    setColor(YELLOW);
    cout << "|========= User's Action =========|\n";
    setColor(BRIGHT_CYAN);
    cout << ".---------------------------------.\n";
    setColor(CYAN);
    cout << "|   1. Borrow Book                |\n";
    setColor(BRIGHT_BLUE);
    cout << "|---------------------------------|\n";
    setColor(BLUE);
    cout << "|   2. Return Book                |\n";
    setColor(BRIGHT_MAGENTA);
    cout << "|---------------------------------|\n";
    setColor(MAGENTA);
    cout << "|   3. Show Rented Book           |\n";
    setColor(BRIGHT_RED);
    cout << "|---------------------------------|\n";
    setColor(RED);
    cout << "|   4. Show Book                  |\n";
    setColor(BRIGHT_YELLOW);
    cout << "'---------------------------------'\n";
    setColor(GREEN);
    cout << "|   0. Log Out                    |\n";
    setColor(BRIGHT_GREEN);
    cout << "'---------------------------------'\n";
    setColor(CYAN);
    cout << "Enter your choice: ";
    setColor(RESET);
}

bool adminLogin() {
    clearScreen();
    string username, password;
    setColor(BRIGHT_YELLOW);
    cout << ".-------------------------------------.\n";
    cout << "|    Press ";
    setColor(RED);
    cout << "[Esc]";
    setColor(RESET);
    cout << " to cancel!           |\n";
    cout << "'-------------------------------------'\n";
    setColor(YELLOW);
 
    username = getUsername();
    if (username.empty()) { // Check if Esc was pressed during username entry
        setColor(YELLOW);
        cout << "\n.-------------------------------------------.\n";
        cout << "|  Login canceled. Returning to main menu.  |\n";
        cout << "'-------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false; // Exit immediately without asking for password
    }

    setColor(BRIGHT_YELLOW);
    cout << ".---------------------------------------.\n";
    cout << "|     Press ";
    setColor(BLUE);
    cout << "[Tab]";
    setColor(RESET);
    cout << " to show password      |\n";
    cout << "'---------------------------------------'\n";
    setColor(RESET);
    setColor(BLUE);
    cout << "Enter Password: ";
    setColor(RESET);

    password = getPassword();
    clearScreen();
    if (username == "admin" && password == "admin123") {
        setColor(GREEN);
        cout << ".----------------------------.\n";
        cout << "|  Admin login successful!   |\n";
        cout << "'----------------------------'\n";
        setColor(RESET);
        system("pause");
        return true;
    }
    else {
        setColor(RED);
        cout << ".-----------------------------------------------.\n";
        cout << "| Invalid admin credentials. Please try again.  |\n";
        cout << "'-----------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false;
    }
}