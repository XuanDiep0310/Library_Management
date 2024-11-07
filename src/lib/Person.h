#pragma once
#include <string>
using namespace std;

class Person {
protected:
	string name;
	string mail;
public:
	//Constructor
	Person(const string &name, const string &mail) 
		: name(name), mail(mail) {}

	//Getters
	string getName() const { return name; }
	string getMail() const { return mail; }

	// Setters
	void setName(const string& name) { this->name = name; }
	void setMail(const string& mail) { this->mail = mail; }
};