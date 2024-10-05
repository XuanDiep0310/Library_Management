#include "Access.h"
#include <iostream>
#include <cstring>
#include <conio.h>
#include "ReadFile.h"
#include "WriteFile.h"
#include "Menu.h"
#include "Date.h"
using namespace std;
bool leapYeart(int year)
{
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int nummontht[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nummonthplust[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
List signUp(List l)
{
        ShowCur(1);
        string userName;
        string password;
        string lPassword;
        string IdUser;
        string nameUser;
        Date DateOfBirth;
        string phone;
        Date D;
        int year;
        int month;
        int day;
        bool check = true;
        cin.ignore();
        while (true)
        {
                system("cls");
                box(49, 8, 30, 2, 11, 1, "    DANG KY TAI KHOAN");
                gotoXY(25, 12);
                cout << "Nhap ma so sinh vien:";
                box(49, 11, 30, 2, 11, 1);
                gotoXY(49, 11);
                cout << char(218);
                gotoXY(79, 11);
                cout << char(191);
                gotoXY(25, 14);
                cout << "Nhap ho ten: ";
                box(49, 13, 30, 2, 11, 1);
                gotoXY(49, 13);
                cout << char(195);
                gotoXY(79, 13);
                cout << char(180);
                gotoXY(25, 16);
                cout << "Nhap nam sinh: " << endl;
                box(49, 15, 30, 2, 11, 1);
                gotoXY(49, 15);
                cout << char(195);
                gotoXY(79, 15);
                cout << char(180);
                gotoXY(25, 18);
                cout << "Nhap thang sinh: " << endl;
                box(49, 17, 30, 2, 11, 1);
                gotoXY(49, 17);
                cout << char(195);
                gotoXY(79, 17);
                cout << char(180);
                gotoXY(25, 20);
                cout << "Nhap ngay sinh: " << endl;
                box(49, 19, 30, 2, 11, 1);
                gotoXY(49, 19);
                cout << char(195);
                gotoXY(79, 19);
                cout << char(180);
                gotoXY(25, 22);
                cout << "Nhap so dien thoai: ";
                box(49, 21, 30, 2, 11, 1);
                gotoXY(49, 21);
                cout << char(195);
                gotoXY(79, 21);
                cout << char(180);
                gotoXY(25, 24);
                cout << "Ten dang nhap : ";
                box(49, 23, 30, 2, 11, 1);
                gotoXY(49, 23);
                cout << char(195);
                gotoXY(79, 23);
                cout << char(180);
                gotoXY(25, 26);
                cout << "Mat khau : ";
                box(49, 25, 30, 2, 11, 1);
                gotoXY(49, 25);
                cout << char(195);
                gotoXY(79, 25);
                cout << char(180);
                gotoXY(51, 12);
                IdUser = limit(51, 12, 28);          //
                userName = password = IdUser;          // 
                gotoXY(51, 14);
                nameUser = limit(51, 14, 28);        //
                gotoXY(51, 16);
                cin >> year;
                DateOfBirth.setYear(year);
                gotoXY(51, 18);
                cin >> month;
                DateOfBirth.setMonth(month);
                gotoXY(51, 20);
                cin >> day;
                DateOfBirth.setDay(day);
                gotoXY(51, 22);
                cin.ignore();
                phone = limit(51, 22, 28);
                if (IdUser.length() != 9 && IdUser != "Admin")
                {
                        check = false;
                        gotoXY(82, 12);
                        cout << "Ma so sinh vien khong dung !!!" << endl;
                }
                if (l.luser()->get(IdUser) != NULL)
                {
                        check = false;
                        gotoXY(82, 12);
                        cout << "Ma so sinh vien nay da dang ky !!!" << endl;
                }
                if (nameUser.empty())
                {
                        check = false;
                        gotoXY(82, 14);
                        cout << "Hay nhap ho ten !!!" << endl;
                }
                if (DateOfBirth.getYear() > D.now().getYear() || DateOfBirth.getYear() < 1900)
                {
                        check = false;
                        gotoXY(82, 16);
                        cout << "Sai du lieu !!!" << endl;
                        gotoXY(82, 18);
                        cout << "Sai du lieu !!!" << endl;
                        gotoXY(82, 20);
                        cout << "Sai du lieu !!!" << endl;
                }
                else if (DateOfBirth.getMonth() < 1 || DateOfBirth.getMonth() > 12)
                {
                        check = false;
                        gotoXY(82, 18);
                        cout << "Sai du lieu !!!" << endl;
                        gotoXY(82, 20);
                        cout << "Sai du lieu !!!" << endl;
                }
                else if (leapYeart(DateOfBirth.getYear()) == true && (DateOfBirth.getDay() < 1 || DateOfBirth.getDay() > nummonthplust[DateOfBirth.getMonth()]))
                {
                        check = false;
                        gotoXY(82, 20);
                        cout << "Sai du lieu !!!" << endl;
                }
                else if (leapYeart(DateOfBirth.getYear()) == false && (DateOfBirth.getDay() < 1 || DateOfBirth.getDay() > nummontht[DateOfBirth.getMonth()]))
                {
                        check = false;
                        gotoXY(82, 20);
                        cout << "Sai du lieu !!!" << endl;
                }
                cin.get();
                if (check == true)
                {
                        gotoXY(51, 24);
                        cout << userName;
                        gotoXY(51, 26);
                        cout << password;
                        gotoXY(51, 30);
                        cout << "Dang ky thanh cong." << endl;
                        User P;
                        P.setId(IdUser);
                        P.setName(nameUser);
                        P.setDateOfBirth(DateOfBirth);
                        P.setPhone(phone);
                        P.setUsername(userName);
                        P.setPassword(password);
                        l.luser()->addTail(P);
                        writeFileUser(l.luser());
                        _getch();
                }
                gotoXY(45, 30);
                cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc....!!!" << endl;
                char c = _getch();
                if (c == 27)
                {
                        return l;
                }
        }
}

List dangnhap(List l)
{
        bool check = false;
        system("cls");
        box(29, 10, 70, 17, 11, 1);
        box(49, 14, 30, 2, 11, 1, "    DANG NHAP TAI KHOAN");
        gotoXY(35, 18);
        cout << "Ten dap nhap:";
        box(49, 17, 30, 2, 11, 1);
        gotoXY(49, 17);
        cout << char(218);
        gotoXY(79, 17);
        cout << char(191);
        gotoXY(35, 20);
        cout << "Mat khau:";
        box(49, 19, 30, 2, 11, 1);
        gotoXY(49, 19);
        cout << char(195);
        gotoXY(79, 19);
        cout << char(180);
        gotoXY(35, 22);
        cout << "Tab de xem mat khau.";
        gotoXY(50, 18);
        char str1[1000];
        int n1, index1 = 0;
        do
        {
                n1 = getch();
                if (((n1 >= '0' && n1 <= '9') || (n1 >= 'A' && n1 <= 'Z') || (n1 >= 'a' && n1 <= 'z') || n1 == ' ' || n1 == '.' || n1 == '@') && index1 < 28)
                {
                        gotoXY(51 + index1, 18);
                        cout << char(n1);
                        str1[index1++] = n1;
                }
                else if (n1 == '\b' && index1 > 0)
                {
                        cout << "\b \b";
                        str1[--index1] = 0;
                }
        } while (n1 != 13);
        str1[index1] = 0;
        string un(str1);
        gotoXY(50, 20);
        char str[1000];
        int n, index = 0;
        bool tab = false;
        do
        {
                n = getch();
                if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z') || n == ' ' || n == '.' || n == '@') && index < 28)
                {
                        gotoXY(51 + index, 20);
                        cout << "*";
                        str[index++] = n;
                }
                else if (n == '\b' && index > 0)
                {
                        cout << "\b \b";
                        str[--index] = 0;
                }
                else if (n == '\t' && tab == false)
                {
                        tab = true;
                        for (int i = 0; i <= index - 1; i++)
                        {
                                gotoXY(51 + i, 20);
                                cout << str[i];
                        }
                }
                else if (n == '\t' && tab == true)
                {
                        tab = false;
                        for (int i = 0; i <= index - 1; i++)
                        {
                                gotoXY(51 + i, 20);
                                cout << "*";
                        }
                }
        } while (n != 13);
        str[index] = 0;
        string pw(str);
        if (un == "Admin" && pw == "admin@")
        {
                l = menuAdmin(l);
                check = true;
        }
        else
        {
                for (Node<User> *P = l.luser()->getHead(); P != NULL; P = P->getNext())
                {
                        if (un == P->getData().getUsername() && pw == P->getData().getPassword())
                        {
                                l = menuUser(l, P);
                                check = true;
                                break;
                        }
                }
        }
        if (check == false)
        {
                gotoXY(49, 23);
                cout << "Ten dang nhap hoac mat khau bi sai !!!" << endl;
                un.clear();
                pw.clear();
        }
        cin.get();
        return l;
}

void List::setLBook(LinkedList<Book> *plbook)
{
        this->plbook = plbook;
}
LinkedList<Book> *List::lbook()
{
        return plbook;
}
void List::setLUser(LinkedList<User> *pluser)
{
        this->pluser = pluser;
}
LinkedList<User> *List::luser()
{
        return pluser;
}

void List::setTime(int time)
{
        this->time = time;
}

void List::setMoney(int money)
{
        this->money = money;
}

int List::getTime()
{
        return time;
}

int List::getMoney()
{
        return money;
}