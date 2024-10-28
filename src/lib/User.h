#pragma once
#include "Person.h"
#include "Date.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class User : public Person {
private:
	string username;
	string password;
	vector<int> rentedBooks;
	Date birthday;

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

	// Static method for creating a new account
	static User* createAccount() {
		string name, email, username, password;
		int day, month, year;

		cout << "Creating a new account..." << endl;
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