#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    Date(string fullday);
    Date(const Date& D);
    int getday();
    int getmonth();
    int getyear();
    void setday(int day);
    void setmonth(int month);
    void setyear(int year);
    friend istream& operator >> (istream& in, Date& D);
    friend ostream& operator << (ostream& out, const Date& D);
    bool operator > (const Date& D);
    bool operator == (const Date& D);
    bool operator < (const Date& D);
    Date now();
    Date expiry(int time);
    int overdue(Date Dayexpiry);
};