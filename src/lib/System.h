#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "UserTree.h"
#include "Graphic.h"

void displayBookMenu() {
    setColor(MAGENTA);
    std::cout << ".---------------------------------.\n";
    setColor(BRIGHT_MAGENTA);
    std::cout << "|======== Book Management ========|\n";
    setColor(BLUE);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_BLUE);
    std::cout << "|   1. Add Book                   |\n";
    setColor(CYAN);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_CYAN);
    std::cout << "|   2. Update Book Information    |\n";
    setColor(GREEN);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_GREEN);
    std::cout << "|   3. Display Books              |\n";
    setColor(YELLOW);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "|   4. Search Book by title       |\n";
    setColor(RED);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_RED);
    std::cout << "|   5. Delete Book by title       |\n";
    setColor(YELLOW);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "|   0. Go back                    |\n";
    setColor(GREEN);
    std::cout << "'---------------------------------'\n";
    setColor(BRIGHT_GREEN);
    std::cout << "Enter your choice: ";
    setColor(RESET);
}

void displayUserMenu() {
    setColor(BRIGHT_RED);
    std::cout << ".---------------------------------.\n";
    setColor(RED);
    std::cout << "|======== User Management ========|\n";
    setColor(YELLOW);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "|   1. Add User                   |\n";
    setColor(BRIGHT_GREEN);
    std::cout << "|---------------------------------|\n";
    setColor(GREEN);
    std::cout << "|   2. Update User Infomation     |\n";
    setColor(CYAN);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_CYAN);
    std::cout << "|   3. Display Users              |\n";
    setColor(BRIGHT_BLUE);
    std::cout << "|---------------------------------|\n";
    setColor(BLUE);
    std::cout << "|   4. Search User by Username    |\n";
    setColor(MAGENTA);
    std::cout << "|---------------------------------|\n";
    setColor(BRIGHT_MAGENTA);
    std::cout << "|   5. Delete User by Username    |\n";
    setColor(BRIGHT_BLUE);
    std::cout << "|---------------------------------|\n";
    setColor(BLUE);
    std::cout << "|   0. Go back                    |\n";
    setColor(CYAN);
    std::cout << "'---------------------------------'\n";
    setColor(BRIGHT_CYAN);
    std::cout << "Enter your choice: ";
    setColor(RESET);
}

void displayMainMenu() {
    clearScreen();
    setColor(GREEN);
    std::cout << ".-------------------------------------.\n";
    setColor(BRIGHT_GREEN);
    std::cout << "|===== Library Management System =====|\n";
    setColor(CYAN);
    std::cout << "|-------------------------------------|\n";
    setColor(BRIGHT_CYAN);
    std::cout << "|   1. Books Management               |\n";
    setColor(BRIGHT_BLUE);
    std::cout << "|-------------------------------------|\n";
    setColor(BLUE);
    std::cout << "|   2. Users Management               |\n";
    setColor(BRIGHT_MAGENTA);
    std::cout << "|-------------------------------------|\n";
    setColor(MAGENTA);
    std::cout << "|   0. Logout                         |\n";
    setColor(BRIGHT_RED);
    std::cout << "'-------------------------------------'\n";
    setColor(RED);
    std::cout << "Enter your choice: ";
    setColor(RESET);
}

void displayOveralMenu() {
    clearScreen();
    setColor(BRIGHT_RED);
    std::cout << "._.    _ ._.\n";
    std::cout << "| |   (_)| |__  _ __ __ _ _ __ __ _ _   \n";
    setColor(RED);
    std::cout << "| |   | || '_ \\| '__/ _` | '__/| | | |\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "| |___| || |_) | | | (_| | |   | |_| |\n";
    setColor(YELLOW);
    std::cout << "|_____|_||.__,/|_|  \\__,_|_|    \\__, |\n";
    setColor(BRIGHT_GREEN);
    std::cout << "                                |___/\n";
    setColor(GREEN);
    std::cout << "    _                _ _           _   _\n";
    setColor(BRIGHT_CYAN);
    std::cout << "   / \\   _ __  _ __ | (_) ___ __ _| |_(_) ___  _ __\n";
    setColor(CYAN);
    std::cout << "  / _ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\\n";
    setColor(BRIGHT_BLUE);
    std::cout << " / ___ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | |\n";
    setColor(BLUE);
    std::cout << "/_/   \\_\\ .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|\n";
    setColor(BRIGHT_MAGENTA);
    std::cout << "        |_|   |_|\n";
    setColor(MAGENTA);
    std::cout << "          .--------------------.\n";
    setColor(BLUE);
    std::cout << "          |   1. Admin login   |\n";
    setColor(BRIGHT_BLUE);
    std::cout << "          |--------------------|\n";
    setColor(CYAN);
    std::cout << "          |   2. User login    |\n";
    setColor(BRIGHT_CYAN);
    std::cout << "          |--------------------|\n";
    setColor(GREEN);
    std::cout << "          |   0. Exit          |\n";
    setColor(BRIGHT_GREEN);
    std::cout << "          '--------------------'\n";
    setColor(YELLOW);
    std::cout << "          Enter your choice: ";
    setColor(RESET);
}

// Function to get username with Esc key handling
std::string getUsername() {
    std::string username;
    char ch;

    std::cout << "\nEnter Username: ";
    while (true) {
        ch = _getch();

        if (ch == 27) { // Esc key pressed
            return ""; // Return an empty string to indicate cancellation
        }
        else if (ch == '\r') { // Enter key pressed
            std::cout << std::endl;
            break;
        }
        else if (ch == '\b' && !username.empty()) { // Backspace pressed
            username.pop_back();
            std::cout << "\b \b"; // Erase the last character
        }
        else if (isprint(ch)) { // Printable character
            username += ch;
            std::cout << ch;
        }
    }
    return username;
}

// Function to get password with masking and Tab for toggle visibility
std::string getPassword() {
    std::string password;
    bool showPassword = false;
    char ch;

    while (true) {
        ch = _getch(); // Get a character without displaying it
        
        if (ch == 27) { // Esc key pressed
            return ""; // Return an empty string to indicate cancellation
        }

        if (ch == '\r') { // Enter key pressed
            std::cout << std::endl;
            break;
        }
        else if (ch == '\b' && !password.empty()) { // Backspace pressed
            password.pop_back();
            std::cout << "\b \b"; // Move back, erase character, move back again
        }
        else if (ch == '\t') { // Tab key pressed to toggle visibility
            showPassword = !showPassword;
            // Clear the line and reprint the prompt with updated visibility
            std::cout << "\rEnter Password: ";
            for (size_t i = 0; i < password.size() + 20; ++i) std::cout << ' '; // Clear extra characters
            std::cout << "\rEnter Password: "; // Reset cursor position
            for (char c : password) {
                std::cout << (showPassword ? c : '*');
            }
        }
        else if (isprint(ch)) { // Printable characters
            password += ch;
            std::cout << (showPassword ? ch : '*');
        }
    }
    return password;
}

bool login(UserTree& userTree) {
    std::cout << "Press ";
    setColor(RED);
    std::cout << "[Esc]";
    setColor(RESET); 
    std::cout << " to cancel!\n"; 
    std::string username = getUsername();
    if (username.empty()) { // Check if Esc was pressed during username entry
        setColor(YELLOW);
        std::cout << "\n.------------------------------------------.\n";
        std::cout << "|  Login canceled. Returning to main menu  |.\n";
        std::cout << "'------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false; // Exit immediately without asking for password
    }

    std::cout << "---Press ";
    setColor(BLUE); 
    std::cout << "[tab]";
    setColor(RESET); 
    std::cout << " to show password---\n";
    std::cout << "Enter Password: ";
    std::string password = getPassword();
    if (password.empty()) { // Check if Esc was pressed during password entry
        setColor(YELLOW);
        std::cout << "\nLogin canceled.\n";
        setColor(RESET);
        system("pause");
        return false;
    }

    clearScreen();
    if (userTree.login(username, password)) {
        setColor(GREEN);
        std::cout << ".---------------------.\n";
        std::cout << "|  Login successful!  |\n";
        std::cout << "'---------------------'\n";
        setColor(RESET);
        system("pause");
        return true;
    }
    else {
        setColor(RED);
        std::cout << ".--------------------------------------------------------.\n";
        std::cout << "|    Invalid username or password. Please try again.     |\n";
        std::cout << "'--------------------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false;
    }
}

void displayUserActionMenu() {
    clearScreen();
    setColor(BRIGHT_YELLOW);
    std::cout << ".---------------------------------.\n";
    setColor(YELLOW);
    std::cout << "|========= User's Action =========|\n";
    setColor(BRIGHT_CYAN);
    std::cout << ".---------------------------------.\n";
    setColor(CYAN);
    std::cout << "|   1. Borrow Book                |\n";
    setColor(BRIGHT_BLUE);
    std::cout << "|---------------------------------|\n";
    setColor(BLUE);
    std::cout << "|   2. Return Book                |\n";
    setColor(BRIGHT_MAGENTA);
    std::cout << "|---------------------------------|\n";
    setColor(MAGENTA);
    std::cout << "|   3. Show Book                  |\n";
    setColor(BRIGHT_RED);
    std::cout << "|---------------------------------|\n";
    setColor(RED);
    std::cout << "|   0. Log out                    |\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "'---------------------------------'\n";
    setColor(RESET);
}

bool adminLogin() {
    clearScreen();
    std::string username, password;
    std::cout << "Press ";
    setColor(RED);
    std::cout << "[Esc]";
    setColor(RESET); 
    std::cout << " to cancel!\n"; 
    username = getUsername();
    if (username.empty()) { // Check if Esc was pressed during username entry
        setColor(YELLOW);
        std::cout << "\n.-------------------------------------------.\n";
        std::cout << "|  Login canceled. Returning to main menu.  |\n";
        std::cout << "'-------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false; // Exit immediately without asking for password
    }

    std::cout << "---Press ";
    setColor(BLUE); 
    std::cout << "[tab]";
    setColor(RESET); 
    std::cout << " to show password---\n";
    std::cout << "Enter Password: "; 
    password = getPassword();
    clearScreen();
    if (username == "admin" && password == "admin123") {
        setColor(GREEN);
        std::cout << ".----------------------------.\n";
        std::cout << "|  Admin login successful!   |\n";
        std::cout << "'----------------------------'\n";
        setColor(RESET);
        system("pause");
        return true;
    }
    else {
        setColor(RED);
        std::cout << ".-----------------------------------------------.\n";
        std::cout << "| Invalid admin credentials. Please try again.  |\n";
        std::cout << "'-----------------------------------------------'\n";
        setColor(RESET);
        system("pause");
        return false;
    }
}