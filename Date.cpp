#include "Date.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#define leapYear(year) ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? true : false
using namespace std;

int nummonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int nummonthplus[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

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
            cout << "Sai du lieu !!!" << endl;
        }
    }
    else
    {
        cout << "Sai du lieu !!!" << endl;
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
    fullday.erase(0, pos + delimiter.length());
    pos = fullday.find(delimiter);
    Month = fullday.substr(0, pos);
    delimiter = "\n";
    fullday.erase(0, pos + delimiter.length());
    pos = fullday.find(delimiter);
    Year = fullday.substr(0, pos);
    fullday.erase(0, pos + delimiter.length());

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

Date::Date(const Date& D)
{
    this->day = D.day;
    this->month = D.month;
    this->year = D.year;
}

istream& operator >> (istream& in, Date& D)
{
    cout << "Nhap nam : "; in >> D.year;
    do
    {
        cout << "Nhap thang :"; in >> D.month;
        if (D.month >= 1 && D.month <= 12)
        {
            bool check = false;
            do
            {

                cout << "Nhap ngay :"; in >> D.day;
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

ostream& operator << (ostream& out, const Date& D)
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

bool Date::operator > (const Date& D)
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
            else return false;
        }
        else return false;
    }
    else return false;
}

bool Date::operator == (const Date& D)
{
    if (this->year == D.year)
    {
        if (this->month == D.month)
        {
            if (this->day == D.day)
            {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

bool Date::operator < (const Date& D)
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
            else return false;
        }
        else return false;
    }
    else return false;
}

Date Date::now()
{
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    this->year = 1900 + ltm.tm_year;
    this->month = 1 + ltm.tm_mon;
    this->day = ltm.tm_mday;
    return *this;
}


Date Date::expiry(int time)
{
    Date D;
    this->day = D.now().day;
    this->month = D.now().month;
    this->year = D.now().year;
    this->year = year;
    int tg = time - (nummonthplus[month] - day);
    this->month += 1;
    bool check = true;
    while (check == true)
    {
        if (leapYear(year) == true)
        {
            if (month >= 1 && month <= 12 && tg > nummonthplus[month])
            {
                tg = tg - nummonthplus[month];
                month = month + 1;
            }
            else if (tg > nummonthplus[month])
            {
                month = 1;
                year += 1;
            }
            else check = false;
        }
        else
        {
            if (month >= 1 && month <= 12 && tg > nummonth[month])
            {
                tg = tg - nummonth[month];
                month = month + 1;
            }
            else if (tg > nummonth[1])
            {
                month = 1;
                year += 1;
            }
            else check = false;
        }
    }
    this->day = tg;
    return *this;
}

int Date::overdue(Date Dayexpiry)
{
    Date D;
    this->day = D.now().day;
    this->month = D.now().month;
    this->year = D.now().year;
    int tg;
    if (this->month == Dayexpiry.month && this->year == Dayexpiry.year)
    {
        tg = this->day - Dayexpiry.day;
        return tg;
    }
    else
    {
        tg = this->day;
        month = month - 1;
    }
    bool check = true;
    while (check == true)
    {
        if (this->year = Dayexpiry.year)
        {
            if (leapYear(year) == true)
            {
                if (this->month > Dayexpiry.month)
                {
                    tg = tg + nummonthplus[month];
                    month = month - 1;
                }
                else if (this->month == Dayexpiry.month)
                {
                    tg = tg + (nummonthplus[month] - Dayexpiry.day);
                    month = month - 1;
                }
                else check = false;
            }
            else
            {
                if (this->month > Dayexpiry.month)
                {
                    tg = tg + nummonth[month];
                    month = month - 1;
                }
                else if (this->month == Dayexpiry.month)
                {
                    tg = tg + (nummonth[month] - Dayexpiry.day);
                    month = month - 1;
                }
                else check = false;
            }
        }
        else
        {
            if (leapYear(year) == true)
            {
                if (this->year > Dayexpiry.year && month >= 1 && month <= 12)
                {
                    tg = tg + nummonthplus[month];
                    month = month - 1;
                }
                else if (this->year > Dayexpiry.year)
                {
                    month = 12;
                    year -= 1;
                }
                else check = false;
            }
            else
            {
                if (this->year > Dayexpiry.year && month >= 1 && month <= 12)
                {
                    tg = tg + nummonth[month];
                    month = month - 1;
                }
                else if (this->year > Dayexpiry.year)
                {
                    month = 12;
                    year -= 1;
                }
                else check = false;
            }
        }
    }
    return tg;
}