#pragma once
#include <iostream>
#include "User.h"
#include "Book.h";
using namespace std;


class ServiceBook :public User, public Book
{
public:
    ServiceBook();
    virtual ~ServiceBook();
    void rentBook();
    void returnBook();

protected:

private:
};
