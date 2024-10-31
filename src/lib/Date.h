#pragma once

#include <iostream>
using namespace std;

class Date {
public:
    Date(int day = 1, int month = 1, int year = 1900);
    virtual ~Date();

    int currentDaysInYear();
    static bool isLeap(int year);
    static int daysInMonth(int month, int year);
    static int daysInYear(int year);
    static bool isValidDate(int day, int month, int year);
    static Date defaultDate;


    // Define the addDays function
    Date addDays(int days);

    // Define a toString function
    std::string toString() const;

    int daysBetween(const Date &other) const;
    int toDays() const;
    
    bool operator<(const Date& dt);
    bool operator>(const Date& dt);
    bool operator==(const Date& dt);
    bool operator!=(const Date& dt);
    int operator-(const Date& dt);
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator>>(istream& is, Date& dt);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

private:
    int day, month, year;
};

// Constructor and Destructor
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date::~Date() {}

// Utility functions
int Date::currentDaysInYear() {
    int days = day;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    return days;
}

Date Date::addDays(int days) {
    Date newDate = *this; // Create a copy of the current date to modify
    while (days > 0) {
        int daysInCurrentMonth = daysInMonth(newDate.month, newDate.year);
        // Check if adding `days` will overflow the current month
        if (newDate.day + days <= daysInCurrentMonth) {
            newDate.day += days;
            days = 0; // All days added
        } else {
            // Move to the first day of the next month and subtract the days remaining in the current month
            days -= (daysInCurrentMonth - newDate.day + 1);
            newDate.day = 1;
            newDate.month++;
            // Check if we've exceeded December and need to roll over to January of the next year
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
    }
    return newDate; // Return the modified Date
}

bool Date::isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 2:
        return isLeap(year) ? 29 : 28;
    default:
        return 30;
    }
}

int Date::daysInYear(int year) {
    return isLeap(year) ? 366 : 365;
}

bool Date::isValidDate(int day, int month, int year) {
    return year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(month, year);
}

// Comparison Operators
bool Date::operator<(const Date& dt) {
    return (year < dt.year) || (year == dt.year && (month < dt.month || (month == dt.month && day < dt.day)));
}

bool Date::operator>(const Date& dt) {
    return (year > dt.year) || (year == dt.year && (month > dt.month || (month == dt.month && day > dt.day)));
}

bool Date::operator==(const Date& dt) {
    return year == dt.year && month == dt.month && day == dt.day;
}

bool Date::operator!=(const Date& dt) {
    return !(*this == dt);
}

int Date::operator-(const Date& dt) {
    Date dt1 = *this;
    Date dt2 = dt;
    bool isNegative = false;
    if (dt1 < dt2) {
        std::swap(dt1, dt2);
        isNegative = true;
    }

    int days = 0;
    for (int i = dt2.year; i < dt1.year; i++) {
        days += daysInYear(i);
    }
    days = days - dt1.currentDaysInYear() + dt2.currentDaysInYear();
    return isNegative ? -days : days;
}

// Stream Operators
ostream& operator<<(ostream& os, const Date& dt) {
    os << dt.day << "-" << dt.month << "-" << dt.year;
    return os;
}

istream& operator>>(istream& is, Date& dt) {
    is >> dt.day >> dt.month >> dt.year;
    return is;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << year << "-" 
        << (month < 10 ? "0" : "") << month << "-"
        << (day < 10 ? "0" : "") << day;
    return oss.str();
}

int Date::daysBetween(const Date& other) const {
    return abs(toDays() - other.toDays());
}

// Convert the current date to a total number of days from a baseline (e.g., 1/1/0000)
int Date::toDays() const {
    int days = day;

    // Count days in months of the current year
    for (int m = 1; m < month; m++) {
        days += Date(year, m, 1).daysInMonth(m, year);
    }

    // Count days in previous years
    for (int y = 1; y < year; y++) {
        days += (Date(y, 1, 1).isLeap(year) ? 366 : 365);
    }
    return days;
}

// Static Member
Date Date::defaultDate;
