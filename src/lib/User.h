#pragma once
#include "Person.h"
#include "Date.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class User : public Person {
private:
	string username;
	string password;
	string email;
	vector<int> rentedBooks;
	Date birthday;
	unordered_map<int, Date> bookReturnDates;

public:
	//Constructor
	User(const string &name, const Date &birthday, const string &mail,
		 const string &username, const string &password)
		: Person(name, mail), username(username), password(password), birthday(birthday) {}

	//Getters
	string getUsername() const { return username; }
	string getPassword() const { return password; }
	const vector<int>& getRentedBooks() const { return rentedBooks; }
	Date getBirthday() const { return birthday; }

	//Setters
	void setUsername(const string &username) { this->username = username; }
	void setPassword(const string& password) { this->password = password; }
	void setBirthday(const Date& birthday) {
		this->birthday = birthday;
	}

	//Methods
	void rentBook(int bookId) {
		rentedBooks.push_back(bookId);
	}

	void returnBook(int bookId) {
		auto it = find(rentedBooks.begin(), rentedBooks.end(), bookId);
		if (it != rentedBooks.end()) {
			rentedBooks.erase(it);
		}
	}

	// Method to check if the user has borrowed a specific book
    bool hasBorrowed(int bookId) const {
        return std::find(rentedBooks.begin(), rentedBooks.end(), bookId) != rentedBooks.end();
    }

	// Method to set the predicted return date for a specific book
    void setPredictedReturnDate(int bookId, const Date& date) {
        bookReturnDates[bookId] = date;
    }

    // Method to get the predicted return date for a specific book
    Date getPredictedReturnDate(int bookId) const {
        auto it = bookReturnDates.find(bookId);
        if (it != bookReturnDates.end()) {
            return it->second;
        }
        return Date(); // Return a default Date if book ID not found
    }

	static bool isEmailFormatValid(const string& email) {
        // Regular expression to match common email domains
        regex emailPattern(R"((^[\w.-]+@[a-zA-Z0-9.-]+\.(com|net|org|edu|gov|mil|co\.\w+|vn)$)|"
                        R"(^[\w.-]+@(gmail|yahoo|outlook|icloud|zoho|aol|gmx|yandex|mail|lycos)\.(com|edu|net|org|ru|de|vn|co\.\w+)$))");

        // Check if the email matches the regular expression pattern
        return regex_match(email, emailPattern);
    }

	// Static method for creating a new account
	static User* createAccount(const std::vector<User*>& existingUsers) {
		string name, email, username, password;
		int day, month, year;

		setColor(CYAN);
		cout << ".-----------------------------.\n";
		cout << "| Creating a new account...   |\n";
		cout << "'-----------------------------'\n";

		// Prompt for name with exit check
		cout << "Enter User Name: ";
		getline(cin >> ws, name);
		if (name == "exit") return nullptr;

		// Prompt for email with exit check
		bool validEmail = false;
		do {
			cout << "Enter Email: ";
			getline(cin, email);
			if (email == "exit") return nullptr;

			if (!isEmailFormatValid(email)) {
				setColor(RED);
				cout << "\n.---------------------------------------------------------.\n";
				cout << "| Invalid email format. Please use true form of an email. |\n";
				cout << "'---------------------------------------------------------'\n";
				setColor(RESET);
				continue;
			}

			auto emailIt = find_if(existingUsers.begin(), existingUsers.end(), [&](const User* user) {
				return user->getMail() == email;
			});

			if (emailIt != existingUsers.end()) {
				setColor(RED);
				cout << "\n.----------------------------------------------.\n";
				cout << "| Email already exists. Use a different email. |\n";
				cout << "'----------------------------------------------'\n";
				setColor(RESET);
			} else validEmail = true;
		} while (!validEmail);

		// Prompt for username with exit check
		bool validUsername = false;
		do {
			cout << "Enter Username: ";
			getline(cin, username);
			if (username == "exit") return nullptr;

			auto usernameIt = find_if(existingUsers.begin(), existingUsers.end(), [&](const User* user) {
				return user->getUsername() == username;
			});

			if (usernameIt != existingUsers.end()) {
				setColor(RED);
				cout << "\n.----------------------------------------------------.\n";
				cout << "| Username already exists. Use a different username. |\n";
				cout << "'----------------------------------------------------'\n";
				setColor(RESET);
			} else validUsername = true;
		} while (!validUsername);

		// Prompt for password with exit check
		do {
			setColor(CYAN);
			cout << "Enter Password: ";
			setColor(RESET);
			getline(cin, password);
			if (password == "exit") return nullptr;
			if (password.length() < 6) {
				setColor(RED);
				cout << ".----------------------------------------.\n";
				cout << "| Password must at least at 6 character! |\n";
				cout << "'----------------------------------------'\n";
				setColor(RESET);
			}
		} while(password.length() < 6);

		// Prompt for birthday with exit check
		bool validDate = false;
		do {
			cout << "Enter Birthday (Day Month Year): ";
			cin >> day >> month >> year;

			if (cin.fail()) {
				cin.clear(); // Clear error flags
				std::string exitCheck;
				cin >> exitCheck;
				if (exitCheck == "exit") return nullptr;

				setColor(RED);
				cout << "\n.--------------------------------------------------.\n";
				cout << "| Invalid input. Please enter numeric values only. |\n";
				cout << "'--------------------------------------------------'\n";
				setColor(RESET);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			} 

			if (Date::isValidDate(day, month, year)) {
				validDate = true;
			} else {
				setColor(RED);
				cout << "\n.-----------------------------------.\n";
				cout << "| Invalid date. Enter a valid date. |\n";
				cout << "'-----------------------------------'\n";
				setColor(RESET);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!validDate);

		Date birthday(day, month, year, 0, 0, 0);
		return new User(name, birthday, email, username, password);
	}
	
private:
	// Function to calculate age from date of birth
	static int calculateAge(const Date& birthday) {
		Date currentDate;  // Assume default constructor gets the current date
		int age = currentDate.getYear() - birthday.getYear();

		// Check if birthday hasn't occurred yet this year
		if ((currentDate.getMonth() < birthday.getMonth()) ||
			(currentDate.getMonth() == birthday.getMonth() && currentDate.getDay() < birthday.getDay())) {
			age--;
		}
		return age;
	}
};