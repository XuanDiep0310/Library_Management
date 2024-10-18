#include "Teacher.h"

Teacher::Teacher()
{
    //ctor
}

Teacher::~Teacher()
{
    //dtor
}

Teacher::Teacher(int option, int id, string name, int age, string mail, float basic_salary, float cft_salary)
{
    this->option = option;
    this->id = id;
    this->name = name;
    this->age = age;
    this->mail = mail;
    this->basic_salary = basic_salary;
    this->cft_salary = cft_salary;
}
void Teacher::showInfo()
{
    cout << "              ._____________________.\n";
    cout << "||--------------| INFORMATION TEACHER |---------------||" << endl;
    cout << "              '---------------------'\n";
    cout << " - Teacher ID: " << this->id << endl;
    cout << " - Teacher Name: " << this->name << endl;
    cout << " - Teacher Age: " << this->age << endl;
    cout << " - Teacher Mail: " << this->mail << endl;
    cout << " - Post: " << this->getDeptName() << endl;
    cout << " - Basic Salary: " << (size_t)(this->basic_salary) << endl;
    cout << " - Coefficients salary: " << (size_t)(this->cft_salary) << endl;
    cout << " - Total Salary: " << (size_t)(this->basic_salary * this->cft_salary) << endl;
}

string Teacher::getDeptName()
{
    return string("Teacher");
}
