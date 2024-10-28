#pragma once

#include <iostream>
#include <fstream>
using namespace std;
class Date
{
public:
    Date(int day = 1, int month = 1, int year = 1900);
    virtual ~Date();

    int currentDaysInYear();
    static bool isLeap(int year);
    static int daysInMonth(int month, int year);
    static int daysInYear(int year);
    static bool isValidDate(Date dt);
    static bool isValidDate(int day, int month, int year);
    static Date defaultDate;

    bool operator<(const Date& dt);
    bool operator>(const Date& dt);
    bool operator==(const Date& dt);
    bool operator!=(const Date& dt);
    int operator-(const Date& dt);
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator>>(istream& is, Date& dt);
    friend ofstream& operator<<(ofstream& fo, const Date& dt);
    friend ifstream& operator>>(ifstream& fi, Date& dt);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

private:
    int day, month, year;

};

// Date constructor and destructor
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::~Date() {}

// Existing utility functions for Date
int Date::currentDaysInYear()
{
    int days = day;
    for (int i = 1; i < month; i++)
    {
        days += daysInMonth(i, year);
    }
    return days;
}

bool Date::isLeap(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

int Date::daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 2:
        return isLeap(year) ? 29 : 28;
    default:
        return 30;
    }
}

// Comparison operators for Date
bool Date::operator<(const Date& dt)
{
    if (this->year < dt.year) return true;
    if (this->year == dt.year && this->month < dt.month) return true;
    if (this->year == dt.year && this->month == dt.month && this->day < dt.day) return true;
    return false;
}

bool Date::operator>(const Date& dt)
{
    if (this->year > dt.year) return true;
    if (this->year == dt.year && this->month > dt.month) return true;
    if (this->year == dt.year && this->month == dt.month && this->day > dt.day) return true;
    return false;
}

bool Date::operator==(const Date& dt)
{
    return this->year == dt.year && this->month == dt.month && this->day == dt.day;
}

bool Date::operator!=(const Date& dt)
{
    return !(*this == dt);
}

// Subtraction operator to find the number of days between two dates
int Date::operator-(const Date& dt)
{
    Date dt1 = *this;
    Date dt2 = dt;
    bool isNegative = false;
    if (dt1 < dt2)
    {
        std::swap(dt1, dt2);
        isNegative = true;
    }

    int days = 0;
    for (int i = dt2.year; i < dt1.year; i++)
    {
        days += daysInYear(i);
    }
    days = days - dt1.currentDaysInYear() + dt2.currentDaysInYear();
    return isNegative ? -days : days;
}

// Days in a year for a given year
int Date::daysInYear(int year)
{
    return isLeap(year) ? 366 : 365;
}

// Date validation
bool Date::isValidDate(Date dt)
{
    return isValidDate(dt.day, dt.month, dt.year);
}

bool Date::isValidDate(int day, int month, int year)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
        return false;
    return true;
}

// Combined stream operator for Date class
ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.day << "-" << dt.month << "-" << dt.year;
    return os;
}

istream& operator>>(istream& is, Date& dt)
{
    is >> dt.day >> dt.month >> dt.year;
    return is;
}

Date Date::defaultDate;