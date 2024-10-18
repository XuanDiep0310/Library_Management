#pragma once

#include <iostream>
#include <fstream>
#include "General.h"
using namespace std;
#include <string>

class People
{
public:
    People();
    virtual ~People();
    int option;
    int id;
    string name;
    int age;
    string mail;
    float basic_salary;
    float cft_salary;
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    void format();
protected:

private:
};

