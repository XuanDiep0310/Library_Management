#pragma once
#include "Person.h"
#include "Book.h"
#include "Date.h"
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;
template <typename T>
class linkedlist;

struct borrow
{
    string IDborrow;
    Date Dayborrow;
    Date Dayexpiry;
};

struct request
{
    string IDrequest;
    int Accept;
};

class User : public Person
{
private:
    string ID;
    string Name;
    Date Dob;
    string Phone;
    int numborrow;
    int numrequest;
    borrow Borrow[5];
    request Request[5];
public:
    User();
    void setID(string);
    void setName(string);
    void setDob(Date);
    void setPhone(string);
    void setNumborrow(int);
    void setNumRequest(int);
    void setBorrow(string, Date, Date, int);
    void setRequest(string, int, int);
    string getID();
    string getName();
    Date getDob();
    string getPhone();
    int getNumborrow();
    int getNumrequest();
    borrow getBorrow(int);
    request getRequest(int);
    int displayborrow(linkedlist<Book>* lbook, int t);
    int displayrequest(linkedlist<Book>* lbook, int k);
    void newusername(linkedlist<User>* luser);
    void newpassword();
    void request(linkedlist<Book>* lbook, int i);
    void cancelrequest(linkedlist<Book>* lbook, int i);
    void menurequest(linkedlist<Book>* lbook);

};
