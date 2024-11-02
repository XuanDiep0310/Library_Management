#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class Date {
public:
    Date(int day = 1, int month = 1, int year = 1900, int hour = 0, int minute = 0, int second = 0);
    virtual ~Date();

    int currentDaysInYear();
    static bool isLeap(int year);
    static int daysInMonth(int month, int year);
    static int daysInYear(int year);
    static bool isValidDate(int day, int month, int year);
    static bool isValidHour(int hour);
    static bool isValidMinute(int minute);
    static bool isValidSecond(int second);
    static Date defaultDate;


    // Define the addDays function
    Date addDays(int days);

    // Define a toString function
    std::string toString() const;

    int daysBetween(const Date &other) const;
    int toDays() const;
    
    bool operator<(const Date& dt) const;
    bool operator>(const Date& dt) const;
    bool operator==(const Date& dt) const;
    bool operator!=(const Date& dt) const;
    int operator-(const Date& dt) const;
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator>>(istream& is, Date& dt);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // Method to get the current date
    static Date currentDate() {
        // Get current time as time_t
        std::time_t t = std::time(nullptr);
        std::tm* currentTime = std::localtime(&t);

        if (currentTime == nullptr) {
            // Handle error, e.g., throw an exception or return a default Date
            throw std::runtime_error("Failed to get current time");
        }

        return Date(currentTime->tm_mday, 
                     currentTime->tm_mon + 1, 
                     currentTime->tm_year + 1900, 
                     currentTime->tm_hour, 
                     currentTime->tm_min, 
                     currentTime->tm_sec);
    }

    bool isValid() const {
        return isValidDate(day, month, year) &&
            isValidHour(hour) &&
            isValidMinute(minute) &&
            isValidSecond(second);
    }

private:
    int day, month, year;
    int hour, minute, second;
};

// Constructor and Destructor
Date::Date(int day, int month, int year, int second, int minute, int hour) : day(day), month(month), year(year), hour(hour), minute(minute), second(second) {}
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

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << year << " "
        << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second;
    return oss.str();
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

// Hour and Minute Validation
bool Date::isValidHour(int hour) {
    return hour >= 0 && hour < 24;
}

bool Date::isValidMinute(int minute) {
    return minute >= 0 && minute < 60;
}

bool Date::isValidSecond(int second) {
    return second >= 0 && second < 60;
}

// Comparison Operators
bool Date::operator<(const Date& dt) const {
    return (year < dt.year) || (year == dt.year && (month < dt.month || (month == dt.month && day < dt.day))) ||
           (year == dt.year && month == dt.month && hour < dt.hour) ||
           (year == dt.year && month == dt.month && hour == dt.hour && minute < dt.minute) ||
           (year == dt.year && month == dt.month && hour == dt.hour && minute == dt.minute && second < dt.second);
}

bool Date::operator>(const Date& dt) const {
    return (year > dt.year) || (year == dt.year && (month > dt.month || (month == dt.month && day > dt.day))) ||
           (year == dt.year && month == dt.month && hour > dt.hour) ||
           (year == dt.year && month == dt.month && hour == dt.hour && minute > dt.minute) ||
           (year == dt.year && month == dt.month && hour == dt.hour && minute == dt.minute && second > dt.second);
}

bool Date::operator==(const Date& dt) const {
    return year == dt.year && month == dt.month && day == dt.day && 
           hour == dt.hour && minute == dt.minute && second == dt.second;
}

bool Date::operator!=(const Date& dt) const {
    return !(*this == dt);
}

int Date::operator-(const Date& dt) const {
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
    os << std::setw(2) << std::setfill('0') << dt.day << "-"
       << std::setw(2) << std::setfill('0') << dt.month << "-"
       << dt.year << " "
       << std::setw(2) << std::setfill('0') << dt.hour << ":"
       << std::setw(2) << std::setfill('0') << dt.minute << ":"
       << std::setw(2) << std::setfill('0') << dt.second;
    return os;
}

istream& operator>>(istream& is, Date& dt) {
    is >> dt.day >> dt.month >> dt.year >> dt.hour >> dt.minute >> dt.second;
    return is;
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
