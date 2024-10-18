#pragma once

#include <iostream>
#include <string>
#include "People.h"
using namespace std;
class Accountant : public People
{
public:
    Accountant();
    virtual ~Accountant();
    void showInfo();
    string getDeptName();
    Accountant(int option, int id, string name, int age, string mail, float basic_salary, float cft_salary);
protected:

private:
    float bonus;
};

