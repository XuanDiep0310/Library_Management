#include "user.h"
#include <cstring>
#include <iostream>
#include "Node.h"
using namespace std;



User::User()
{
    this->numborrow = 4;
    this->numrequest = 4;
    for (int i = 4; i >= 0; i--)
    {
        Borrow[i].IDborrow = '0';
        Request[i].IDrequest = '0';
        Request[i].Accept = 0;
    }
}

void User::setID(string ID)
{
    this->ID = ID;
}

void User::setName(string Name)
{
    this->Name = Name;
}

void User::setDob(Date Dob)
{
    this->Dob = Dob;
}

void User::setPhone(string Phone)
{
    this->Phone = Phone;
}

void User::setNumborrow(int numborrow)
{
    this->numborrow = numborrow;
}

void User::setNumRequest(int numrequest)
{
    this->numrequest = numrequest;
}

void User::setBorrow(string IDborrow, Date Dayborrow, Date Dayexpiry, int i)
{
    Borrow[i].IDborrow = IDborrow;
    Borrow[i].Dayborrow = Dayborrow;
    Borrow[i].Dayexpiry = Dayexpiry;
}

void User::setRequest(string IDrequest, int Accept, int i)
{
    Request[i].IDrequest = IDrequest;
    Request[i].Accept = Accept;
}

string User::getID()
{
    return ID;
}

string User::getName()
{
    return Name;
}

Date User::getDob()
{
    return Dob;
}

string User::getPhone()
{
    return Phone;
}

int User::getNumborrow()
{
    return this->numborrow;
}

int User::getNumrequest()
{
    return this->numrequest;
}

borrow User::getBorrow(int i)
{
    return this->Borrow[i];
}

request User::getRequest(int i)
{
    return this->Request[i];
}

int User::displayborrow(linkedlist<Book>* lbook, int t)
{
    if (t == 0)
    {
        system("cls");
    }
    box(1, 5 + t, 124, 2, 11, 1, "---------------------------------------------------TOAN BO SACH DANG MUON--------------------------------------------------");
    box(1, 7 + t, 11, 2, 11, 1, "MA SO SACH");
    if (t != 0)
    {
        gotoXY(1, 5 + t); cout << char(195);
        gotoXY(21, 5 + t); cout << char(193);
        gotoXY(51, 5 + t); cout << char(193);
        gotoXY(71, 5 + t); cout << char(193);
        gotoXY(91, 5 + t); cout << char(193);
        gotoXY(111, 5 + t); cout << char(193);
        gotoXY(125, 5 + t); cout << char(180);
    }
    gotoXY(1, 7 + t); cout << char(195);
    box(12, 7 + t, 20, 2, 11, 1, "      TEN SACH");
    box(32, 7 + t, 15, 2, 11, 1, "   THE LOAI");
    box(47, 7 + t, 15, 2, 11, 1, " NHA XUAT BAN");
    box(62, 7 + t, 13, 2, 11, 1, "NAM XUAT BAN");
    box(75, 7 + t, 19, 2, 11, 1, "      TAC GIA");
    box(94, 7 + t, 9, 2, 11, 1, "SO LUONG");
    box(103, 7 + t, 11, 2, 11, 1, "NGAY MUON");
    box(114, 7 + t, 11, 2, 11, 1, "  HET HAN");
    gotoXY(12, 7 + t); cout << char(194);
    gotoXY(12, 9 + t); cout << char(193);
    gotoXY(32, 7 + t); cout << char(194);
    gotoXY(32, 9 + t); cout << char(193);
    gotoXY(47, 7 + t); cout << char(194);
    gotoXY(47, 9 + t); cout << char(193);
    gotoXY(62, 7 + t); cout << char(194);
    gotoXY(62, 9 + t); cout << char(193);
    gotoXY(75, 7 + t); cout << char(194);
    gotoXY(75, 9 + t); cout << char(193);
    gotoXY(94, 7 + t); cout << char(194);
    gotoXY(94, 9 + t); cout << char(193);
    gotoXY(103, 7 + t); cout << char(194);
    gotoXY(103, 9 + t); cout << char(193);
    gotoXY(114, 7 + t); cout << char(194);
    gotoXY(114, 9 + t); cout << char(193);
    gotoXY(125, 7 + t); cout << char(180);
    int i = 2;
    for (int s = this->numborrow + 1; s <= 4; s++)
    {
        string ID = this->Borrow[s].IDborrow;
        node<Book>* tmp = lbook->get(ID);
        Book B = tmp->getData();
        box(1, 7 + i + t, 11, 2, 11, 1, B.getID());
        gotoXY(1, 7 + i + t); cout << char(195);
        box(12, 7 + i + t, 20, 2, 11, 1, B.getName());
        box(32, 7 + i + t, 15, 2, 11, 1, B.getCategory());
        box(47, 7 + i + t, 15, 2, 11, 1, B.getPublisher());
        box(62, 7 + i + t, 13, 2, 11, 1, B.getYear());
        box(75, 7 + i + t, 20, 2, 11, 1, B.getAuthor());
        box(94, 7 + i + t, 9, 2, 11, 1, B.getAmount(), B.getfixedAmount());
        box(103, 7 + i + t, 11, 2, 11, 1, this->Borrow[s].Dayborrow);
        box(114, 7 + i + t, 11, 2, 11, 1, this->Borrow[s].Dayexpiry);
        gotoXY(12, 7 + i + t); cout << char(197);
        gotoXY(12, 9 + i + t); cout << char(197);
        gotoXY(32, 7 + i + t); cout << char(197);
        gotoXY(32, 9 + i + t); cout << char(197);
        gotoXY(47, 7 + i + t); cout << char(197);
        gotoXY(47, 9 + i + t); cout << char(197);
        gotoXY(62, 7 + i + t); cout << char(197);
        gotoXY(62, 9 + i + t); cout << char(197);
        gotoXY(75, 7 + i + t); cout << char(197);
        gotoXY(75, 9 + i + t); cout << char(197);
        gotoXY(94, 7 + i + t); cout << char(197);
        gotoXY(94, 9 + i + t); cout << char(197);
        gotoXY(103, 7 + i + t); cout << char(197);
        gotoXY(103, 9 + i + t); cout << char(197);
        gotoXY(114, 7 + i + t); cout << char(197);
        gotoXY(114, 9 + i + t); cout << char(197);
        gotoXY(125, 7 + i + t); cout << char(180);
        i += 2;
    }
    gotoXY(12, 7 + i + t); cout << char(193);
    gotoXY(32, 7 + i + t); cout << char(193);
    gotoXY(47, 7 + i + t); cout << char(193);
    gotoXY(62, 7 + i + t); cout << char(193);
    gotoXY(75, 7 + i + t); cout << char(193);
    gotoXY(94, 7 + i + t); cout << char(193);
    gotoXY(103, 7 + i + t); cout << char(193);
    gotoXY(114, 7 + i + t); cout << char(193);
    if (t == 0)
    {
        cin.get();
    }
    return i;
}

void User::newpassword()
{
    cin.ignore();
    string pw;
    string npw;
    string lpw;
    while (true)
    {
        system("cls");
        box(15, 10, 98, 18, 11, 1);
        box(49, 14, 30, 2, 11, 1, "=========DOI MAT KHAU=========");
        gotoXY(20, 17);
        cout << "Nhap mat khau hien tai : ";
        box(49, 16, 30, 2, 11, 1);
        gotoXY(49, 16); cout << char(195);
        gotoXY(79, 16); cout << char(180);
        gotoXY(20, 19);
        cout << "Nhap mat khau moi : ";
        box(49, 18, 30, 2, 11, 1);
        gotoXY(49, 18); cout << char(195);
        gotoXY(79, 18); cout << char(180);
        gotoXY(20, 21);
        cout << "Nhap lai mat khau moi : ";
        box(49, 20, 30, 2, 11, 1);
        gotoXY(49, 20); cout << char(195);
        gotoXY(79, 20); cout << char(180);
        gotoXY(50, 17);
        pw = gioihan(50, 17, 29);
        if (pw == this->getPw())
        {
            gotoXY(50, 19);
            npw = gioihan(50, 19, 29);
            gotoXY(50, 21);
            lpw = gioihan(50, 21, 29);
            if (npw.length() >= 6 && lpw.length() <= 15)
            {
                if (npw != lpw)
                {
                    gotoXY(49, 24);
                    cout << "Mat khau nhap khong khop !!!" << endl;
                    cin.get();
                }
                else
                {
                    this->setPw(npw);
                    gotoXY(49, 24);
                    cout << "Doi thanh cong !!!" << endl;
                    cin.get();
                    return;
                }
            }
            else
            {
                gotoXY(49, 24);
                cout << "Mat khau toi thieu 6 ki tu, toi da 15 ki tu !!!" << endl;
                cin.get();
            }
        }
        else
        {
            gotoXY(49, 24);
            cout << "Mat khau sai !!!" << endl;
            cin.get();
            return;
        }
    }
}

void User::newusername(linkedlist<User>* luser)
{
    string pw;
    string nun;
    cin.ignore();
    while (true)
    {
        system("cls");
        box(15, 10, 98, 18, 11, 1);
        box(49, 14, 30, 2, 11, 1, "=======DOI TEN DANG NHAP======");
        gotoXY(20, 17);
        cout << "Nhap mat khau hien tai : ";
        box(49, 16, 30, 2, 11, 1);
        gotoXY(49, 16); cout << char(195);
        gotoXY(79, 16); cout << char(180);
        gotoXY(20, 19);
        cout << "Nhap ten dap nhap: ";
        box(49, 18, 30, 2, 11, 1);
        gotoXY(49, 18); cout << char(195);
        gotoXY(79, 18); cout << char(180);
        gotoXY(50, 17);
        pw = gioihan(50, 17, 29);
        if (pw == this->getPw())
        {
            gotoXY(50, 19);
            nun = gioihan(50, 19, 29);
            for (node<User>* P = luser->getHead(); P != NULL; P = P->getNext())
            {
                if (nun.length() < 6 || nun.length() > 15)
                {
                    gotoXY(49, 24);
                    cout << "Ten dang nhap tu phai tu 6 - 15 ki tu !!!" << endl;
                    cin.get();
                    break;
                }
                if (nun == P->getData().getUn())
                {
                    gotoXY(49, 24);
                    cout << "Ten dap nhap da ton tai !!!" << endl;
                    cin.get();
                    break;
                }
                else
                {
                    this->setUn(nun);
                    gotoXY(49, 24);
                    cout << "Doi thanh cong !!!" << endl;
                    cin.get();
                    return;
                }
            }
            cin.get();
        }
        else
        {
            gotoXY(49, 24);
            cout << "Mat khau sai !!!" << endl;
            cin.get();
            return;
        }
    }
}

void User::request(linkedlist<Book>* lbook, int i)
{
    cin.ignore();
    if (this->numrequest >= 0)
    {
        string ID;
        box(32, 9 + i, 92, 2, 11, 1, "Nhap ma so sach yeu cau muon : ");
        box(32, 11 + i, 92, 2, 11, 1);
        gotoXY(32, 11 + i); cout << char(195);
        gotoXY(124, 11 + i); cout << char(180);
        gotoXY(65, 10 + i);
        ID = gioihan(65, 10 + i, 58);
        if (lbook->get(ID) != NULL)
        {
            this->Request[this->numrequest].IDrequest = ID;
            this->numrequest -= 1;
            gotoXY(75, 12 + i);
            cout << "Ban da yeu cau muon ma so sach " << ID;
            cin.get();
        }
        else
        {
            gotoXY(75, 12 + i);
            cout << "Ma so khong ton tai !!!" << endl;
            cin.get();
        }

    }
    else
    {
        box(32, 10 + i, 92, 2, 11, 1, "               Ban da yeu cau toi da 5 cuon sach, khong the yeu cau them !!!");
        cin.get();
    }
}

void User::cancelrequest(linkedlist<Book>* lbook, int i)
{
    cin.ignore();
    if (this->numrequest < 4)
    {
        string ID;
        int ms;
        bool check = false;
        box(32, 9 + i, 92, 2, 11, 1, "Nhap ma so sach can huy:");
        box(32, 11 + i, 92, 2, 11, 1);
        gotoXY(32, 11 + i); cout << char(195);
        gotoXY(124, 11 + i); cout << char(180);
        gotoXY(80, 10 + i);
        cout << "Nhap ma so yeu cau:";
        gotoXY(60, 10 + i);
        ID = gioihan(60, 10 + i, 19);
        gotoXY(101, 10 + i);
        cin >> ms;
        for (int t = 4; t >= this->numrequest + 1; t--)
        {
            if (Request[t].IDrequest == ID && t == ms)
            {
                check = true;
                for (int k = t; k >= this->numrequest + 2; k--)
                {
                    this->Request[k].IDrequest = this->Request[k - 1].IDrequest;
                    this->Request[k].Accept = this->Request[k - 1].Accept;
                }
                this->Request[this->numrequest + 1].IDrequest = "0";
                this->Request[this->numrequest + 1].Accept = 0;
                this->numrequest += 1;
                gotoXY(75, 12 + i);
                cout << "Ban da huy yeu cau muon ma so sach " << ID;
                _getch();
                break;
            }
        }
        if (check == false)
        {
            gotoXY(80, 12 + i);
            cout << "Du lieu sai !!!";
            _getch();
        }
    }
    else
    {
        box(32, 10 + i, 92, 2, 11, 1, "                       Ban khong yeu cau sach nao, khong the huy !!!");
        _getch();
    }
}


int menudongrequest(int xp, int yp, int xcu, int ycu, int i, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 9 + i) thanhsang(xcu, ycu, 30, 2, 1, "      YEU CAU MUON SACH");
            if (ycu == 11 + i) thanhsang(xcu, ycu, 30, 2, 1, "      HUY YEU CAU MUON");
            if (ycu == 13 + i) thanhsang(xcu, ycu, 30, 2, 1, "          QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 9 + i) thanhsang(xp, yp, 30, 2, 75, "      YEU CAU MUON SACH");
            if (yp == 11 + i) thanhsang(xp, yp, 30, 2, 75, "      HUY YEU CAU MUON");
            if (yp == 13 + i) thanhsang(xp, yp, 30, 2, 75, "          QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 9 + i)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 9 + i)
                {
                    kt = true;
                    yp = 13 + i;
                }
                else if (c == 80 && yp != 13 + i)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 13 + i)
                {
                    kt = true;
                    yp = 9 + i;
                }
            }
            else if (c == 13)
            {
                kt = false;
                return yp;
            }
        }
    }
}

void User::menurequest(linkedlist<Book>* lbook)
{
    int option;
    bool check = true;
    while (check)
    {
        int i = displayrequest(lbook, 0);
        box(1, 7 + i, 30, 2, 11, 1, "=============MENU=============");
        gotoXY(1, 7 + i); cout << char(195);
        box(1, 9 + i, 30, 2, 11, 1, "      YEU CAU MUON SACH");
        gotoXY(1, 9 + i); cout << char(195);
        gotoXY(31, 9 + i); cout << char(180);
        box(1, 11 + i, 30, 2, 11, 1, "      HUY YEU CAU MUON");
        gotoXY(1, 11 + i); cout << char(195);
        gotoXY(31, 11 + i); cout << char(180);
        box(1, 13 + i, 30, 2, 11, 1, "          QUAY LAI");
        gotoXY(1, 13 + i); cout << char(195);
        gotoXY(31, 13 + i); cout << char(180);
        box(31, 7 + i, 94, 8, 11, 1);
        gotoXY(12, 7 + i); cout << char(193);
        gotoXY(37, 7 + i); cout << char(193);
        gotoXY(52, 7 + i); cout << char(193);
        gotoXY(72, 7 + i); cout << char(193);
        gotoXY(85, 7 + i); cout << char(193);
        gotoXY(104, 7 + i); cout << char(193);
        gotoXY(113, 7 + i); cout << char(193);
        gotoXY(125, 7 + i); cout << char(180);
        gotoXY(31, 7 + i); cout << char(194);
        gotoXY(31, 9 + i); cout << char(180);
        gotoXY(31, 11 + i); cout << char(180);
        gotoXY(31, 13 + i); cout << char(180);
        gotoXY(31, 15 + i); cout << char(193);
        option = menudongrequest(1, 9 + i, 1, 9 + i, i, true);
        if (option == 9 + i)
        {
            request(lbook, i);
        }
        else if (option == 11 + i)
        {
            cancelrequest(lbook, i);
        }
        else if (option == 13 + i)
        {
            check = false;
        }
    }
}

int User::displayrequest(linkedlist<Book>* lbook, int k)
{
    if (k == 0)
    {
        system("cls");
    }
    box(1, 5 + k, 124, 2, 11, 1, "-------------------------------------------------TOAN BO SACH DANG YEU CAU-------------------------------------------------");
    if (k != 0)
    {
        gotoXY(1, 5 + k); cout << char(195);
        gotoXY(12, 5 + k); cout << char(193);
        gotoXY(32, 5 + k); cout << char(193);
        gotoXY(47, 5 + k); cout << char(193);
        gotoXY(62, 5 + k); cout << char(193);
        gotoXY(75, 5 + k); cout << char(193);
        gotoXY(94, 5 + k); cout << char(193);
        gotoXY(103, 5 + k); cout << char(193);
        gotoXY(114, 5 + k); cout << char(193);
        gotoXY(125, 5 + k); cout << char(180);
    }
    box(1, 7 + k, 11, 2, 11, 1, "MA SO SACH");
    gotoXY(1, 7 + k); cout << char(195);
    box(12, 7 + k, 25, 2, 11, 1, "        TEN SACH");
    box(37, 7 + k, 15, 2, 11, 1, "   THE LOAI");
    box(52, 7 + k, 20, 2, 11, 1, "    NHA XUAT BAN");
    box(72, 7 + k, 13, 2, 11, 1, "NAM XUAT BAN");
    box(85, 7 + k, 19, 2, 11, 1, "      TAC GIA");
    box(104, 7 + k, 9, 2, 11, 1, "MA SO YC");
    box(113, 7 + k, 12, 2, 11, 1, "TRANG THAI");
    gotoXY(12, 7 + k); cout << char(194);
    gotoXY(12, 9 + k); cout << char(193);
    gotoXY(37, 7 + k); cout << char(194);
    gotoXY(37, 9 + k); cout << char(193);
    gotoXY(52, 7 + k); cout << char(194);
    gotoXY(52, 9 + k); cout << char(193);
    gotoXY(72, 7 + k); cout << char(194);
    gotoXY(72, 9 + k); cout << char(193);
    gotoXY(85, 7 + k); cout << char(194);
    gotoXY(85, 9 + k); cout << char(193);
    gotoXY(104, 7 + k); cout << char(194);
    gotoXY(104, 9 + k); cout << char(193);
    gotoXY(113, 7 + k); cout << char(194);
    gotoXY(113, 9 + k); cout << char(193);
    gotoXY(125, 7 + k); cout << char(180);
    int i = 2;
    for (int t = this->numrequest + 1; t <= 4; t++)
    {
        string ID = this->Request[t].IDrequest;
        node<Book>* tmp = lbook->get(ID);
        Book B = tmp->getData();
        box(1, 7 + i + k, 11, 2, 11, 1, B.getID());
        gotoXY(1, 7 + i + k); cout << char(195);
        box(12, 7 + i + k, 25, 2, 11, 1, B.getName());
        box(37, 7 + i + k, 15, 2, 11, 1, B.getCategory());
        box(52, 7 + i + k, 20, 2, 11, 1, B.getPublisher());
        box(72, 7 + i + k, 13, 2, 11, 1, B.getYear());
        box(85, 7 + i + k, 20, 2, 11, 1, B.getAuthor());
        box(104, 7 + i + k, 9, 2, 11, 1, t);
        if (this->Request[t].Accept == 0)
        {
            box(113, 7 + i + k, 12, 2, 11, 1, "Dang xet");
        }
        else if (this->Request[t].Accept == 1)
        {
            box(113, 7 + i + k, 12, 2, 11, 1, "Chap nhan");
        }
        else if (this->Request[t].Accept == 2)
        {
            box(113, 7 + i + k, 12, 2, 11, 1, "Tu choi");
        }
        gotoXY(12, 7 + i + k); cout << char(197);
        gotoXY(12, 9 + i + k); cout << char(197);
        gotoXY(37, 7 + i + k); cout << char(197);
        gotoXY(37, 9 + i + k); cout << char(197);
        gotoXY(52, 7 + i + k); cout << char(197);
        gotoXY(52, 9 + i + k); cout << char(197);
        gotoXY(72, 7 + i + k); cout << char(197);
        gotoXY(72, 9 + i + k); cout << char(197);
        gotoXY(85, 7 + i + k); cout << char(197);
        gotoXY(85, 9 + i + k); cout << char(197);
        gotoXY(104, 7 + i + k); cout << char(197);
        gotoXY(104, 9 + i + k); cout << char(197);
        gotoXY(113, 7 + i + k); cout << char(197);
        gotoXY(113, 9 + i + k); cout << char(197);
        gotoXY(125, 7 + i + k); cout << char(180);
        i += 2;
    }
    return i;
}