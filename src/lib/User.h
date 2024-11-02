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
	User(const string &name, const Date & birthday, const string &mail,
		 const string &username, const string &password)
		: Person(name, calculateAge(birthday), mail), username(username), password(password) {}

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
		age = calculateAge(birthday);
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

	// Show borrowed books
    void showRentedBooks() const {
        if (rentedBooks.empty()) {
            cout << "No books rented." << endl;
            return;
        }
        cout << "Rented Books IDs: ";
        for (const auto& id : rentedBooks) {
            cout << id << " ";
        }
        cout << endl;
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

	// Static method for creating a new account
	static User* createAccount() {
		string name, email, username, password;
		int day, month, year;

		setColor(CYAN);
		cout << ".-----------------------------.\n";
		cout << "| Creating a new account...   |\n";
		cout << "'-----------------------------'\n";
		cout << "Enter User Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Email: ";
		getline(cin, email);
		cout << "Enter Username: ";
		getline(cin, username);
		cout << "Enter Password: ";
		getline(cin, password);
		cout << "Enter Birthday (Day Month Year): ";
		cin >> day >> month >> year;
		setColor(RESET);

		Date birthday(day, month, year); // Assume Date has a suitable constructor
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