#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    // Constructor
    Date();
    Date(int day, int month, int year);
    Date(string fullday);
    Date(const Date &D);
    // Get
    int getday();
    int getmonth();
    int getyear();
    // Set
    void setday(int day);
    void setmonth(int month);
    void setyear(int year);
    // friend >>, <<
    friend istream &operator>>(istream &in, Date &D);
    friend ostream &operator<<(ostream &out, const Date &D);
    bool operator>(const Date &D);
    bool operator==(const Date &D);
    bool operator<(const Date &D);
    // Trả về ngày hiện tại
    Date now();
    // Tính thời gian quá hạn dựa vào số ngày mượn cụ thể
    Date expiry(int time);
    // Tính số ngày quá hạn (với 1 ngày quá hạn được cung cấp)
    int overdue(Date dayExpiry);
};

// Ngày trong các của năm Nhuận và năm Không Nhuận
vector<int> nummonth({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
vector<int> nummonthplus({0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});

bool leapYear(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}

Date::Date(int day, int month, int year)
{
    this->year = year;
    if (month >= 1 && month <= 12)
    {
        this->month = month;
        if (leapYear(year) == true && day >= 1 && day <= nummonthplus[month])
        {
            this->day = day;
        }
        else if (leapYear(year) == false && day >= 1 && day <= nummonth[month])
        {
            this->day = day;
        }
        else
        {
            cout << "Du lieu khong hop le !!!" << endl;
        }
    }
    else
    {
        cout << "Du lieu khong hop le !!!" << endl;
    }
}

int Date::getday()
{
    return day;
}

int Date::getmonth()
{
    return month;
}

int Date::getyear()
{
    return year;
}

void Date::setday(int day)
{
    this->day = day;
}

void Date::setmonth(int month)
{
    this->month = month;
}

void Date::setyear(int year)
{
    this->year = year;
}

Date::Date(string fullday)
{
    string Day;
    string Month;
    string Year;
    size_t pos = 0;
    string delimiter = "/";
    pos = fullday.find(delimiter);
    Day = fullday.substr(0, pos);
    fullday.erase(0, pos + 1);
    pos = fullday.find(delimiter);
    Month = fullday.substr(0, pos);
    delimiter = "\n";
    fullday.erase(0, pos + 1);
    pos = fullday.find(delimiter);
    Year = fullday.substr(0, pos);
    fullday.erase(0, pos + 1);

    int day = stoi(Day);
    int month = stoi(Month);
    int year = stoi(Year);
    this->year = year;
    if (month >= 1 && month <= 12)
    {
        this->month = month;
        if (leapYear(year) == true && day >= 1 && day <= nummonthplus[month])
        {
            this->day = day;
        }
        else if (leapYear(year) == false && day >= 1 && day <= nummonth[month])
        {
            this->day = day;
        }
        else
        {
            cout << "Sai du lieu !!!" << endl;
        }
    }
    else
    {
        cout << "Sai du lieu !!!" << endl;
    }
}

Date::Date(const Date &D)
{
    this->day = D.day;
    this->month = D.month;
    this->year = D.year;
}

istream &operator>>(istream &in, Date &D)
{
    cout << "Nhap nam : ";
    in >> D.year;
    do
    {
        cout << "Nhap thang :";
        in >> D.month;
        if (D.month >= 1 && D.month <= 12)
        {
            bool check = false;
            do
            {

                cout << "Nhap ngay :";
                in >> D.day;
                if (leapYear(D.year) == true && D.day >= 1 && D.day <= nummonthplus[D.month])
                {
                    check = true;
                }
                else if (leapYear(D.year) == false && D.day >= 1 && D.day <= nummonth[D.month])
                {
                    check = true;
                }
                else
                {

                    cout << "Sai du lieu !!!" << endl;
                }
            } while (check == false);
        }
        else
        {
            cout << "Sai du lieu !!!" << endl;
        }
    } while (D.month < 1 || D.month > 12);
    return in;
}

ostream &operator<<(ostream &out, const Date &D)
{
    if (D.year == 0)
    {
        out << D.day << "/" << D.month << "/" << "0000";
    }
    else
    {
        out << D.day << "/" << D.month << "/" << D.year;
    }
    return out;
}

bool Date::operator>(const Date &D)
{
    if (this->year > D.year)
    {
        return true;
    }
    else if (this->year == D.year)
    {
        if (this->month > D.month)
        {
            return true;
        }
        else if (this->month == D.month)
        {
            if (this->day > D.day)
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Date::operator==(const Date &D)
{
    if (this->year == D.year)
    {
        if (this->month == D.month)
        {
            if (this->day == D.day)
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Date::operator<(const Date &D)
{
    if (this->year < D.year)
    {
        return true;
    }
    else if (this->year == D.year)
    {
        if (this->month < D.month)
        {
            return true;
        }
        else if (this->month == D.month)
        {
            if (this->day < D.day)
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

Date Date::now()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->year = 1900 + ltm->tm_year;
    this->month = 1 + ltm->tm_mon;
    this->day = ltm->tm_mday;
    return *this;
}
// Tính thời gian quá hạn dựa vào số ngày mượn cụ thể (time la so ngay)
Date Date::expiry(int time)
{
    Date D = this->now();
    int tg = time + D.day;

    while (tg > (leapYear(D.year) ? nummonthplus[D.month] : nummonth[D.month]))
    {
        tg -= (leapYear(D.year) ? nummonthplus[D.month] : nummonth[D.month]);
        D.month++;
        if (D.month > 12)
        {
            D.month = 1;
            D.year++;
        }
    }
    D.day = tg;

    return D;
}
// Tính số ngày quá hạn (với 1 ngày quá hạn được cung cấp)
int Date::overdue(Date dayExpiry)
{
    Date D = D.now();
    int tg = 0;

    int curDay = D.day;
    int curMonth = D.month;
    int curYear = D.year;

    if (curYear == dayExpiry.year && curMonth == dayExpiry.month)
    {
        return curDay - dayExpiry.day;
    }
    tg = curDay;
    curMonth--;
    if (curMonth == 0)
    {
        curMonth = 12;
        curYear--;
    }

    vector<int> monthDay = leapYear(curYear) ? nummonthplus : nummonth;
    while (curYear > dayExpiry.year || (curYear == dayExpiry.year && curMonth >= dayExpiry.month))
    {
        if (curYear == dayExpiry.year && curMonth == dayExpiry.month)
        {
            tg += monthDay[curMonth] - dayExpiry.day;
            break;
        }
        tg += monthDay[curMonth];
        curMonth--;
         if (curMonth == 0) 
        {
            curMonth = 12;
            curYear--; 
        }

        monthDay = leapYear(curYear) ? nummonthplus : nummonth;
    }
    return tg;
}
