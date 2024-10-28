#pragma once
#include <string>
using namespace std;

class Person {
protected:
	string name;
	int age;
	string mail;
public:
	//Constructor
	Person(const string &name, int age, const string &mail) 
		: name(name), age(age), mail(mail) {}

	//Getters
	string getName() const { return name; }
	int getAge() const { return age; }
	string getMail() const { return mail; }

	// Setters
	void setName(const string& name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setMail(const string& mail) { this->mail = mail; }
};