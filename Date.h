#pragma once
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    // Kiểm tra xem năm có phải năm nhuận không
    bool isLeapYear(int year) const;

    // Kiểm tra xem ngày có hợp lệ với tháng và năm không
    bool isValidDate(int day, int month, int year) const;
 
public:
    Date();  // Constructor mặc định
    Date(int d, int m, int y);  // Constructor với tham số

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Phương thức nhập ngày
    void input();

    // Phương thức xuất ngày
    void display() const;

    // Kiểm tra ngày hợp lệ
    bool isValid() const;

    // Cộng ngày, trừ ngày
    Date addDays(int days);
    Date subtractDays(int days);

    // So sánh hai đối tượng Date
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    // Tính khoảng cách ngày giữa hai Date
    int daysBetween(const Date& other) const;

    // Cộng tháng và năm (tùy chọn)
    Date addMonths(int months);
    Date addYears(int years);
};

// Constructor mặc định
Date::Date() {
    day = 1;
    month = 1;
    year = 1;
}

// Constructor với tham số
Date::Date(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    } else {
        day = 1;
        month = 1;
        year = 1;
    }
}

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Setters
void Date::setDay(int d) {
    if (isValidDate(d, month, year)) {
        day = d;
    } else {
        cout << "Ngày không hợp lệ!" << endl;
    }
}

void Date::setMonth(int m) {
    if (isValidDate(day, m, year)) {
        month = m;
    } else {
        cout << "Tháng không hợp lệ!" << endl;
    }
}

void Date::setYear(int y) {
    if (isValidDate(day, month, y)) {
        year = y;
    } else {
        cout << "Năm không hợp lệ!" << endl;
    }
}

// Kiểm tra năm nhuận
bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Kiểm tra ngày hợp lệ
bool Date::isValidDate(int d, int m, int y) const {
    if (m < 1 || m > 12 || d < 1) return false;

    int daysInMonth[] = {31, isLeapYear(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return d <= daysInMonth[m - 1];
}

// Phương thức nhập ngày
void Date::input() {
    int d, m, y;
    cout << "Nhập ngày: ";
    cin >> d;
    cout << "Nhập tháng: ";
    cin >> m;
    cout << "Nhập năm: ";
    cin >> y;

    if (isValidDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    } else {
        cout << "Ngày tháng không hợp lệ!" << endl;
    }
}

// Phương thức xuất ngày
void Date::display() const {
    cout << day << "/" << month << "/" << year << endl;
}

// Kiểm tra ngày có hợp lệ hay không
bool Date::isValid() const {
    return isValidDate(day, month, year);
}

// So sánh hai ngày
bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year < other.year) return true;
    if (year == other.year && month < other.month) return true;
    if (year == other.year && month == other.month && day < other.day) return true;
    return false;
}

bool Date::operator>(const Date& other) const {
    return !(*this < other) && *this != other;
}

// Cộng số ngày vào Date
Date Date::addDays(int days) {
    Date newDate = *this;
    newDate.day += days;

    // Kiểm tra và điều chỉnh tháng nếu số ngày vượt quá ngày trong tháng
    while (!isValidDate(newDate.day, newDate.month, newDate.year)) {
        newDate.day -= 31;  // giả định tháng có nhiều nhất 31 ngày
        newDate.month++;
        if (newDate.month > 12) {
            newDate.month = 1;
            newDate.year++;
        }
    }
    return newDate;
}

// Trừ số ngày từ Date
Date Date::subtractDays(int days) {
    Date newDate = *this;
    newDate.day -= days;

    // Kiểm tra và điều chỉnh tháng nếu số ngày nhỏ hơn 1
    while (newDate.day < 1) {
        newDate.month--;
        if (newDate.month < 1) {
            newDate.month = 12;
            newDate.year--;
        }
        newDate.day += 31;  // giả định tháng có nhiều nhất 31 ngày
    }
    return newDate;
}

// Tính số ngày giữa hai Date
int Date::daysBetween(const Date& other) const {
    int daysCount = 0;
    Date temp = *this;

    // Nếu temp nhỏ hơn other, tính số ngày từ temp đến other
    while (temp < other) {
        temp = temp.addDays(1);
        daysCount++;
    }

    // Nếu temp lớn hơn other, tính số ngày từ other đến temp
    while (temp > other) {
        temp = temp.subtractDays(1);
        daysCount--;
    }

    return daysCount;
}

// Cộng tháng
Date Date::addMonths(int months) {
    Date newDate = *this;
    newDate.month += months;
    while (newDate.month > 12) {
        newDate.month -= 12;
        newDate.year++;
    }
    return newDate;
}

// Cộng năm
Date Date::addYears(int years) {
    Date newDate = *this;
    newDate.year += years;
    return newDate;
}
