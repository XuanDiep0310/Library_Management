#include "General.h"
#include <string>
#include <algorithm>

using namespace std;

// Convert string to lowercase
string General::toLowerStr(const string &str) {
    string result = str;
    for (auto& ch : result) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
        }
    }
    return str;
}

// Convert string to uppercase
string General::toUpperStr(const string& str) {
    string result = str;
    for (auto& ch : result) {
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
    }
    return str;
}

// Remove extra spaces from string, capitalize each word's first letter
string General::format(const string& str) {
    string formated = str;
    // Remove leading and trailing spaces
    formated.erase(0, formated.find_first_not_of(' '));
    formated.erase(formated.find_last_not_of(' ') + 1);

    // Remove multiple spaces between words
    string formatted;
    bool isSpace = false;
    for (char ch : str) {
        if (ch == ' ') {
            if (!isSpace) {
                formatted += ch;
            }
            isSpace = true;
        }
        else {
            formatted += ch;
            isSpace = false;
        }
    }

    // Capitalize the first letter of each word
    bool capitalize = true;
    for (auto& ch : formatted) {
        if (capitalize && ch != ' ') {
            ch = toupper(ch);
            capitalize = false;
        }
        else if (ch == ' ') {
            capitalize = true;
        }
        else {
            ch = tolower(ch);
        }
    }

    return formatted;
}

// Clear standard input buffer
void General::clearStdin() {
    cin.clear();
    fflush(stdin);
}
