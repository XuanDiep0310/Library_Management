#pragma once
#include <iostream>
#include "UserTree.h"

void clearScreen() {
#ifdef _WIN32
    system("CLS");  // Windows command to clear the screen
#else
    system("clear");  // Unix-based command to clear the screen
#endif
}

void displayBookMenu() {
    std::cout << "\n===== Book Management =====" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Display Books" << std::endl;
    std::cout << "3. Search Book by title" << std::endl;
    std::cout << "4. Delete Book by title" << std::endl;
    std::cout << "0. Go back" << std::endl;
}

void displayUserMenu() {
    std::cout << "\n===== User Management =====" << std::endl;
    std::cout << "1. Add User" << std::endl;
    std::cout << "2. Display Users" << std::endl;
    std::cout << "3. Search User by Username" << std::endl;
    std::cout << "4. Delete User by Username" << std::endl;
    std::cout << "0. Go back" << std::endl;
}

void displayMainMenu() {
    clearScreen();
    std::cout << "\n===== Library Management System =====" << std::endl;
    std::cout << "1. Books Management" << std::endl;
    std::cout << "2. Users Management" << std::endl;
    std::cout << "0. Logout" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter your choice: ";
}

void displayOveralMenu() {
    clearScreen();
    std::cout << "1. Admin login" << std::endl;
    std::cout << "2. User login" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

bool login(UserTree& userTree) {
    std::string username, password;
    std::cout << "Enter Username: "; std::cin >> username;
    std::cout << "Enter Password: "; std::cin >> password;
    if (userTree.login(username, password)) {
        std::cout << "Login successful!" << std::endl;
        return true;
    }
    else {
        std::cout << "Invalid username or password. Please try again." << std::endl;
        return false;
    }
}

void displayUserActionMenu() {
    clearScreen();
    std::cout << "1. Borrow Book" << std::endl;
    std::cout << "2. Return Book" << std::endl;
    std::cout << "3. Show Book" << std::endl;
    std::cout << "4. Log out" << std::endl;
}

bool adminLogin() {
    clearScreen();
    std::string username, password;
    std::cout << "Enter Admin Username: "; std::cin >> username;
    std::cout << "Enter Admin Password: "; std::cin >> password;
    if (username == "admin" && password == "admin123") {
        std::cout << "Admin login successful!" << std::endl;
        return true;
    }
    else {
        std::cout << "Invalid admin credentials. Please try again." << std::endl;
        return false;
    }
}