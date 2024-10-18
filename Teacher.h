#pragma once
#include <iostream>
#include <string>
#include "People.h"
using namespace std;

class Teacher : public People
{
public:
    Teacher();
    virtual ~Teacher();
    virtual void showInfo();
    virtual string getDeptName();
    Teacher(int option, int id, string name, int age, string mail, float basic_salary, float cft_salary);
protected:

private:
    float overtime_pay;
};
