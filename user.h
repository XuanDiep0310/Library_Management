#pragma once
#include "Person.h"
#include "LinkedList.h"
#include "Book.h"
#include "Date.h"
#include<iomanip>
#include<string>
#include<iostream>
#include <vector>

using namespace std;
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
    Date dateOfBirth;
    string phone;
    int numborrow;
    int numrequest;
    borrow Borrow[5];
    request Request[5];
public:
    User();
    void setId(string id);
    void setName(string name);
    void setDateOfBirth(Date dateOfBirth);
    void setPhone(string phone);
    void setNumBorrow(int numborrow);
    void setNumRequest(int numrequest);
    void setBorrow(string idBorrow,Date dayBorrow,Date dayExpiry, int pos);
    void setRequest(string idRequest,int accept, int pos);
    string getId();
    string getName();
    Date getDateOfBirth();
    string getPhone();
    int getNumBorrow();
    int getNumRequest();
    borrow getBorrow(int pos);
    request getRequest(int pos);

    int displayBorrow(LinkedList<Book>* lbook,int t); 
    int displayRequest(LinkedList<Book>* lbook,int k);
    void newUsername(LinkedList<User>* luser);
    void newPassword();
    void request(LinkedList<Book>* lbook,int i);
    void cancelRequest(LinkedList<Book>* lbook,int i);
    void menuRequest(LinkedList<Book>* lbook);
};
