#pragma once
#include "Person.h"
#include "Book.h"
#include "Date.h"
#include<iomanip>
#include<string>
#include<iostream>
#include <vector>

using namespace std;
template <typename T>
class linkedlist;

struct borrow 
{
    string idBorrow;
    Date dayBorrow;
    Date dayExpiry;
};

struct request 
{
    string idRequest;
    int accept = 0;
};

class User : public Person 
{
private:
    string id;
    string name;
    Date dayOfBirth;
    string phone;
    int numborrow;
    int numrequest;
    vector<borrow> Borrow;
    vector<request> Request;
public:
    User();
    void setId(string id);
    void setName(string name);
    void setDayOfBirth(Date dayOfBirth);
    void setPhone(string phone);
    void setNumborrow(int numborrow);
    void setNumRequest(int numrequest);
    void setBorrow(string idBorrow,Date dayBorrow,Date dayExpiry);
    void setRequest(string idRequest,int accept);
    string getId();
    string getName();
    Date getDayOfBirth();
    string getPhone();
    int getNumborrow();
    int getNumrequest();
    borrow getBorrow(int pos);
    request getRequest(int pos);
};
User::User() 
{
    this->numborrow = 4;
    this->numrequest = 4;
    Borrow.resize(10);
    Request.resize(10);
    for(int i = 0; i <10; i++) 
    {
        Borrow[i].idBorrow = '0';
        Request[i].idRequest = '0';
        Request[i].accept = 0;
    }
}
    
void User::setId(string id) 
{
    this->id = id;
}
    
void User::setName(string name) 
{
    this->name = name;
}

void User::setDayOfBirth(Date dayOfBirth) 
{
    this->dayOfBirth = dayOfBirth;
}
    
void User::setPhone(string phone) 
{
    this->phone = phone;
}

void User::setNumborrow(int numborrow) 
{
    this->numborrow = numborrow;
}

void User::setNumRequest(int numrequest) 
{
    this->numrequest = numrequest;
} 
    
void User::setBorrow(string idBorrow,Date dayBorrow,Date dayExpiry) 
{
    Borrow.push_back({idBorrow, dayBorrow, dayExpiry});
}
    
void User::setRequest(string idRequest,int accept) 
{
    Request.push_back({idRequest, accept});
}

string User::getId() 
{
    return id;
}

string User::getName() 
{
    return name;
}

Date User::getDayOfBirth() 
{
    return dayOfBirth;
}
    
string User::getPhone() 
{
    return phone;
}

int User::getNumborrow() 
{
    return this->numborrow;
}

int User::getNumrequest() 
{
    return this->numrequest;
}

borrow User::getBorrow(int pos) 
{
    return this->Borrow[pos];
}

request User::getRequest(int pos) 
{
    return this->Request[pos];
}