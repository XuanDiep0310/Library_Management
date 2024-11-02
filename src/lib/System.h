#pragma once
#include <iostream>
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

bool login(UserTree& userTree) {
    std::string username, password;
    std::cout << "Enter Username: "; std::cin >> username;
    std::cout << "Enter Password: "; std::cin >> password;
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
    std::cout << "|   4. Log out                    |\n";
    setColor(BRIGHT_YELLOW);
    std::cout << "'---------------------------------'\n";
    setColor(RESET);
}

bool adminLogin() {
    clearScreen();
    std::string username, password;
    std::cout << "Enter Admin Username: "; std::cin >> username;
    std::cout << "Enter Admin Password: "; std::cin >> password;
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