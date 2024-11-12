#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <locale>


using namespace std;

// Function to check if the input string is "exit"
bool isExitCommand(const string& input) {
    return input == "exit";
}

// Mã ANSI để đổi màu
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m"; 
const string MAGENTA = "\033[35m";    
const string CYAN = "\033[36m";       
const string WHITE = "\033[37m";  
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_BLUE = "\033[94m";
const string BRIGHT_MAGENTA = "\033[95m";
const string BRIGHT_CYAN = "\033[96m";
const string BRIGHT_WHITE = "\033[97m";    

void setColor(const string& color) {
    cout << color;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Lệnh cho Windows
#else
    system("clear");  // Lệnh cho Linux/macOS
#endif
}

void clearLine() {
    cout << "\r" << string(80, ' ') << "\r"; // Clear the current line
}

// Function to move the cursor up by a specific number of lines
void moveCursor(int x, int y) {
    cout << "\033[" << y << ";" << x << "H"; // ANSI escape code for cursor movement
}

// Function to move the cursor down by a specific number of lines
void moveCursorDown(int lines) {
    cout << "\33[" << lines << "B";
}

// Trim from the start (left)
inline std::string& ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

// Trim from the end (right)
inline std::string& rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

// Trim from both ends
inline std::string& trim(std::string& s) {
    return ltrim(rtrim(s));
}
