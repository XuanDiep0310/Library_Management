#pragma once
#include <string>
#include <iostream>
// Mã ANSI để đổi màu
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m"; 
const std::string MAGENTA = "\033[35m";    
const std::string CYAN = "\033[36m";       
const std::string WHITE = "\033[37m";  
const std::string BRIGHT_RED = "\033[91m";
const std::string BRIGHT_GREEN = "\033[92m";
const std::string BRIGHT_YELLOW = "\033[93m";
const std::string BRIGHT_BLUE = "\033[94m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN = "\033[96m";
const std::string BRIGHT_WHITE = "\033[97m";    

void setColor(const std::string& color) {
    std::cout << color;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Lệnh cho Windows
#else
    system("clear");  // Lệnh cho Linux/macOS
#endif
}

void clearLine() {
    std::cout << "\r" << std::string(80, ' ') << "\r"; // Clear the current line
}

// Function to move the cursor up by a specific number of lines
void moveCursorUp(int lines) {
    std::cout << "\33[" << lines << "A";
}

// Function to move the cursor down by a specific number of lines
void moveCursorDown(int lines) {
    std::cout << "\33[" << lines << "B";
}