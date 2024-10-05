#include "Menu.h"
#include "Admin.h"
#include "Access.h"
#include "WriteFile.h"
#include <iostream>
#include <cstring>
using namespace std;
#define TRUE 1

int dynamicBookMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 12) lightBar(xcu, ycu, 45, 2, 1, "      XEM TOAN BO SACH TRONG THU VIEN");
            if (ycu == 14) lightBar(xcu, ycu, 45, 2, 1, "    XEM TOAN BO SACH CON TRONG THU VIEN");
            if (ycu == 16) lightBar(xcu, ycu, 45, 2, 1, "           TIM KIEM SACH THEO TEN");
            if (ycu == 18) lightBar(xcu, ycu, 45, 2, 1, "        TIM KIEM SACH THEO THE LOAI");
            if (ycu == 20) lightBar(xcu, ycu, 45, 2, 1, "        TIM KIEM SACH THEO TAC GIA");
            if (ycu == 22) lightBar(xcu, ycu, 45, 2, 1, "           THEM SACH VAO THU VIEN");
            if (ycu == 24) lightBar(xcu, ycu, 45, 2, 1, "          CHINH SUA THONG TIN SACH");
            if (ycu == 26) lightBar(xcu, ycu, 45, 2, 1, "           XOA SACH KHOI THU VIEN");
            if (ycu == 28) lightBar(xcu, ycu, 45, 2, 1, "                  QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 12) lightBar(xp, yp, 45, 2, 75, "      XEM TOAN BO SACH TRONG THU VIEN");
            if (yp == 14) lightBar(xp, yp, 45, 2, 75, "    XEM TOAN BO SACH CON TRONG THU VIEN");
            if (yp == 16) lightBar(xp, yp, 45, 2, 75, "           TIM KIEM SACH THEO TEN");
            if (yp == 18) lightBar(xp, yp, 45, 2, 75, "        TIM KIEM SACH THEO THE LOAI");
            if (yp == 20) lightBar(xp, yp, 45, 2, 75, "        TIM KIEM SACH THEO TAC GIA");
            if (yp == 22) lightBar(xp, yp, 45, 2, 75, "           THEM SACH VAO THU VIEN");
            if (yp == 24) lightBar(xp, yp, 45, 2, 75, "          CHINH SUA THONG TIN SACH");
            if (yp == 26) lightBar(xp, yp, 45, 2, 75, "           XOA SACH KHOI THU VIEN");
            if (yp == 28) lightBar(xp, yp, 45, 2, 75, "                  QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 12)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 12)
                {
                    kt = true;
                    yp = 28;
                }
                else if (c == 80 && yp != 28)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 28)
                {
                    kt = true;
                    yp = 12;
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

List menuBook(List l)
{
    int option;
    Admin Ad;
    while (TRUE)
    {
        system("cls");
        box(45, 5, 45, 2, 11, 1, "        QUAN LY SACH TRONG THU VIEN");
        box(45, 10, 45, 2, 11, 1, "====================MENU====================");
        box(45, 12, 45, 2, 11, 1, "      XEM TOAN BO SACH TRONG THU VIEN");
        gotoXY(45, 12); cout << char(195);
        gotoXY(90, 12); cout << char(180);
        box(45, 14, 45, 2, 11, 1, "    XEM TOAN BO SACH CON TRONG THU VIEN");
        gotoXY(45, 14); cout << char(195);
        gotoXY(90, 14); cout << char(180);
        box(45, 16, 45, 2, 11, 1, "           TIM KIEM SACH THEO TEN");
        gotoXY(45, 16); cout << char(195);
        gotoXY(90, 16); cout << char(180);
        box(45, 18, 45, 2, 11, 1, "        TIM KIEM SACH THEO THE LOAI");
        gotoXY(45, 18); cout << char(195);
        gotoXY(90, 18); cout << char(180);
        box(45, 20, 45, 2, 11, 1, "        TIM KIEM SACH THEO TAC GIA");
        gotoXY(45, 20); cout << char(195);
        gotoXY(90, 20); cout << char(180);
        box(45, 22, 45, 2, 11, 1, "           THEM SACH VAO THU VIEN");
        gotoXY(45, 22); cout << char(195);
        gotoXY(90, 22); cout << char(180);
        box(45, 24, 45, 2, 11, 1, "          CHINH SUA THONG TIN SACH");
        gotoXY(45, 24); cout << char(195);
        gotoXY(90, 24); cout << char(180);
        box(45, 26, 45, 2, 11, 1, "           XOA SACH KHOI THU VIEN");
        gotoXY(45, 26); cout << char(195);
        gotoXY(90, 26); cout << char(180);
        box(45, 28, 45, 2, 11, 1, "                  QUAY LAI");
        gotoXY(45, 28); cout << char(195);
        gotoXY(90, 28); cout << char(180);
        option = dynamicBookMenu(45, 12, 45, 12, true);
        switch (option)
        {
        case 12:
            Ad.displayBook(l.lbook());
            break;
        case 14:
            Ad.displayAvailable(l.lbook());
            break;
        case 16:
            Ad.findBookName(l.lbook());
            break;
        case 18:
            Ad.findCategory(l.lbook());
            break;
        case 20:
            Ad.findAuthor(l.lbook());
            break;
        case 22:
            l.setListBook(Ad.addBook(l.lbook()));
            break;
        case 24:
            l.setListBook(Ad.fixBook(l.lbook(), l.luser()));
            break;
        case 26:
            l.setListBook(Ad.delBook(l.lbook()));
            break;
        case 28:
            writeFileBook(l.lbook());
            writeFileUser(l.luser());
            return l;
        default:
            break;
        }
    }
}

int dynamicUserManagermentMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 12) lightBar(xcu, ycu, 45, 2, 1, "           XEM TOAN BO NGUOI DUNG");
            if (ycu == 14) lightBar(xcu, ycu, 45, 2, 1, "          XEM THONG TIN NGUOI DUNG");
            if (ycu == 16) lightBar(xcu, ycu, 45, 2, 1, "        DANG KY TAI KHOAN NGUOI DUNG");
            if (ycu == 18) lightBar(xcu, ycu, 45, 2, 1, "        SUA DOI THONG TIN NGUOI DUNG");
            if (ycu == 20) lightBar(xcu, ycu, 45, 2, 1, "               XOA NGUOI DUNG");
            if (ycu == 22) lightBar(xcu, ycu, 45, 2, 1, "                 MUON SACH");
            if (ycu == 24) lightBar(xcu, ycu, 45, 2, 1, "                  TRA SACH");
            if (ycu == 26) lightBar(xcu, ycu, 45, 2, 1, "        CAP LAI TAI KHOAN NGUOI DUNG");
            if (ycu == 28) lightBar(xcu, ycu, 45, 2, 1, "                  QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 12) lightBar(xp, yp, 45, 2, 75, "           XEM TOAN BO NGUOI DUNG");
            if (yp == 14) lightBar(xp, yp, 45, 2, 75, "          XEM THONG TIN NGUOI DUNG");
            if (yp == 16) lightBar(xp, yp, 45, 2, 75, "        DANG KY TAI KHOAN NGUOI DUNG");
            if (yp == 18) lightBar(xp, yp, 45, 2, 75, "        SUA DOI THONG TIN NGUOI DUNG");
            if (yp == 20) lightBar(xp, yp, 45, 2, 75, "               XOA NGUOI DUNG");
            if (yp == 22) lightBar(xp, yp, 45, 2, 75, "                 MUON SACH");
            if (yp == 24) lightBar(xp, yp, 45, 2, 75, "                  TRA SACH");
            if (yp == 26) lightBar(xp, yp, 45, 2, 75, "        CAP LAI TAI KHOAN NGUOI DUNG");
            if (yp == 28) lightBar(xp, yp, 45, 2, 75, "                  QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 12)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 12)
                {
                    kt = true;
                    yp = 28;
                }
                else if (c == 80 && yp != 28)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 28)
                {
                    kt = true;
                    yp = 12;
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

List menuUserManagement(List l)
{
    int option;
    Admin Ad;
    while (TRUE)
    {
        system("cls");
        box(45, 5, 45, 2, 11, 1, "     QUAN LY NGUOI DUNG TRONG THU VIEN");
        box(45, 10, 45, 2, 11, 1, "====================MENU====================");
        box(45, 12, 45, 2, 11, 1, "           XEM TOAN BO NGUOI DUNG");
        gotoXY(45, 12); cout << char(195);
        gotoXY(90, 12); cout << char(180);
        box(45, 14, 45, 2, 11, 1, "          XEM THONG TIN NGUOI DUNG");
        gotoXY(45, 14); cout << char(195);
        gotoXY(90, 14); cout << char(180);
        box(45, 16, 45, 2, 11, 1, "        DANG KY TAI KHOAN NGUOI DUNG");
        gotoXY(45, 16); cout << char(195);
        gotoXY(90, 16); cout << char(180);
        box(45, 18, 45, 2, 11, 1, "        SUA DOI THONG TIN NGUOI DUNG");
        gotoXY(45, 18); cout << char(195);
        gotoXY(90, 18); cout << char(180);
        box(45, 20, 45, 2, 11, 1, "               XOA NGUOI DUNG");
        gotoXY(45, 20); cout << char(195);
        gotoXY(90, 20); cout << char(180);
        box(45, 22, 45, 2, 11, 1, "                 MUON SACH");
        gotoXY(45, 22); cout << char(195);
        gotoXY(90, 22); cout << char(180);
        box(45, 24, 45, 2, 11, 1, "                  TRA SACH");
        gotoXY(45, 24); cout << char(195);
        gotoXY(90, 24); cout << char(180);
        box(45, 26, 45, 2, 11, 1, "        CAP LAI TAI KHOAN NGUOI DUNG");
        gotoXY(45, 26); cout << char(195);
        gotoXY(90, 26); cout << char(180);
        box(45, 28, 45, 2, 11, 1, "                  QUAY LAI");
        gotoXY(45, 28); cout << char(195);
        gotoXY(90, 28); cout << char(180);
        option = dynamicUserManagermentMenu(45, 12, 45, 12, true);
        switch (option)
        {
        case 12:
            Ad.displayUser(l.luser());
            break;
        case 14:
            Ad.findUser(l.luser(), l.lbook());
            break;
        case 16:
            l = signUp(l);
            break;
        case 18:
            Ad.updateInfor(l.luser());
            break;
        case 20:
            l = Ad.delUser(l);
            break;
        case 22:
            Ad.borrowBook(l, l.getTime());
            break;
        case 24:
            Ad.giveBackBook(l, l.getMoney());
            break;
        case 26:
            Ad.resetPasswork(l.luser());
            break;
        case 28:
            writeFileUser(l.luser());
            return l;
        default:
            break;
        }
    }
}

List menuAccount(List l)
{
    int option;
    Admin Ad;
    system("cls");
    Ad.statistic(l.lbook(), l.luser());
    cin.get();
    return l;
}

int dynamicSystemMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 12) lightBar(xcu, ycu, 45, 2, 1, "            THONG TIN TIEN PHAT");
            if (ycu == 14) lightBar(xcu, ycu, 45, 2, 1, "        THONG TIN THOI GIAN CHO MUON");
            if (ycu == 16) lightBar(xcu, ycu, 45, 2, 1, "                  QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 12) lightBar(xp, yp, 45, 2, 75, "            THONG TIN TIEN PHAT");
            if (yp == 14) lightBar(xp, yp, 45, 2, 75, "        THONG TIN THOI GIAN CHO MUON");
            if (yp == 16) lightBar(xp, yp, 45, 2, 75, "                  QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 12)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 12)
                {
                    kt = true;
                    yp = 16;
                }
                else if (c == 80 && yp != 16)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 16)
                {
                    kt = true;
                    yp = 12;
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

List menuSystem(List l)
{
    int option;
    Admin Ad;
    while (TRUE)
    {
        system("cls");
        box(45, 5, 45, 2, 11, 1, "         QUAN LY THONG TIN THU VIEN");
        box(20, 10, 45, 2, 11, 1, "====================MENU====================");
        box(20, 12, 45, 2, 11, 1, "            THONG TIN TIEN PHAT");
        gotoXY(20, 12); cout << char(195);
        gotoXY(65, 12); cout << char(180);
        box(20, 14, 45, 2, 11, 1, "        THONG TIN THOI GIAN CHO MUON");
        gotoXY(20, 14); cout << char(195);
        gotoXY(65, 14); cout << char(180);
        box(20, 16, 45, 2, 11, 1, "                  QUAY LAI");
        gotoXY(20, 16); cout << char(195);
        gotoXY(65, 16); cout << char(180);
        box(65, 10, 45, 8, 11, 1);
        gotoXY(65, 10); cout << char(194);
        gotoXY(65, 12); cout << char(180);
        gotoXY(65, 14); cout << char(180);
        gotoXY(65, 16); cout << char(180);
        gotoXY(65, 18); cout << char(193);
        option = dynamicSystemMenu(20, 12, 20, 12, true);
        switch (option)
        {
        case 12:
        {
            int money;
            int key;
            gotoXY(67, 11);
            cout << "So tien phat hien tai :      " << l.getMoney();
            gotoXY(67, 13);
            cout << "Ban co muon thay doi thong tin ? (1/0) : ";
            cin >> key;
            if (key == 1)
            {
                gotoXY(67, 15);
                cout << "Nhap so tien phat moi : ";
                gotoXY(97, 15);
                cin >> money;
                l.setMoney(money);
                gotoXY(80, 17);
                cout << "Thay doi thanh cong !!!";
                cin.get();
            }
            else if (key == 0)
            {
                gotoXY(85, 17);
                cout << "Quay lai !!!";
                cin.get();
            }
            else
            {
                gotoXY(85, 17);
                cout << "Du lieu sai !!!";
                cin.get();
            }
            cin.get();
            break;
        }
        case 14:
        {
            int time;
            int key;
            gotoXY(67, 11);
            cout << "Thoi gian cho muon hien tai :     " << l.getTime();
            gotoXY(67, 13);
            cout << "Ban co muon thay doi thong tin ? (1/0) : ";
            cin >> key;
            if (key == 1)
            {
                gotoXY(67, 15);
                cout << "Nhap thoi gian cho muon moi : ";
                gotoXY(102, 15);
                cin >> time;
                l.setTime(time);
                gotoXY(80, 17);
                cout << "Thay doi thanh cong !!!";
                cin.get();
            }
            else if (key == 0)
            {
                gotoXY(85, 17);
                cout << "Quay lai !!!";
                cin.get();
            }
            else
            {
                gotoXY(85, 17);
                cout << "Du lieu sai !!!";
                cin.get();
            }
            cin.get();
            break;
        }
        case 16:
            writeFileData(l.getMoney(), l.getTime());
            return l;
        default:
            break;
        }
    }
}

int dynamicAdminMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 12) lightBar(xcu, ycu, 30, 2, 1, "         QUAN LY SACH");
            if (ycu == 14) lightBar(xcu, ycu, 30, 2, 1, "      QUAN LY NGUOI DUNG");
            if (ycu == 16) lightBar(xcu, ycu, 30, 2, 1, "  THONG KE SO LIEU THU VIEN");
            if (ycu == 18) lightBar(xcu, ycu, 30, 2, 1, " THAY DOI THONG TIN THU VIEN");
            if (ycu == 20) lightBar(xcu, ycu, 30, 2, 1, "           QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 12) lightBar(xp, yp, 30, 2, 75, "         QUAN LY SACH");
            if (yp == 14) lightBar(xp, yp, 30, 2, 75, "      QUAN LY NGUOI DUNG");
            if (yp == 16) lightBar(xp, yp, 30, 2, 75, "  THONG KE SO LIEU THU VIEN");
            if (yp == 18) lightBar(xp, yp, 30, 2, 75, " THAY DOI THONG TIN THU VIEN");
            if (yp == 20) lightBar(xp, yp, 30, 2, 75, "           QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 12)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 12)
                {
                    kt = true;
                    yp = 20;
                }
                else if (c == 80 && yp != 20)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 20)
                {
                    kt = true;
                    yp = 12;
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

List menuAdmin(List l)
{
    int option;
    Admin Ad;
    while (TRUE)
    {
        system("cls");
        box(49, 5, 30, 2, 11, 1, "    THU VIEN DHBK DA NANG    ");
        box(49, 10, 30, 2, 11, 1, "=============MENU=============");
        box(49, 12, 30, 2, 11, 1, "         QUAN LY SACH");
        gotoXY(49, 12); cout << char(195);
        gotoXY(79, 12); cout << char(180);
        box(49, 14, 30, 2, 11, 1, "      QUAN LY NGUOI DUNG");
        gotoXY(49, 14); cout << char(195);
        gotoXY(79, 14); cout << char(180);
        box(49, 16, 30, 2, 11, 1, "  THONG KE SO LIEU THU VIEN");
        gotoXY(49, 16); cout << char(195);
        gotoXY(79, 16); cout << char(180);
        box(49, 18, 30, 2, 11, 1, " THAY DOI THONG TIN THU VIEN");
        gotoXY(49, 18); cout << char(195);
        gotoXY(79, 18); cout << char(180);
        box(49, 20, 30, 2, 11, 1, "           QUAY LAI");
        gotoXY(49, 20); cout << char(195);
        gotoXY(79, 20); cout << char(180);
        option = dynamicAdminMenu(49, 12, 49, 12, true);
        switch (option)
        {
        case 12:
            l = menuBook(l);
            break;
        case 14:
            l = menuUserManagement(l);
            break;
        case 16:
            l = menuAccount(l);
            break;
        case 18:
            l = menuSystem(l);
            break;
        case 20:
            return l;
        default:
            break;
        }
    }
}

int dynamicUserMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 12) lightBar(xcu, ycu, 30, 2, 1, "       XEM TOAN BO SACH");
            if (ycu == 14) lightBar(xcu, ycu, 30, 2, 1, "     XEM SACH CO THE MUON");
            if (ycu == 16) lightBar(xcu, ycu, 30, 2, 1, "    TIM KIEM THEO TEN SACH");
            if (ycu == 18) lightBar(xcu, ycu, 30, 2, 1, "    TIM KIEM THEO THE LOAI");
            if (ycu == 20) lightBar(xcu, ycu, 30, 2, 1, "    TIM KIEM THEO TAC GIA");
            if (ycu == 22) lightBar(xcu, ycu, 30, 2, 1, "      YEU CAU MUON SACH");
            if (ycu == 24) lightBar(xcu, ycu, 30, 2, 1, "   XEM TOAN BO SACH DANG MUON");
            if (ycu == 26) lightBar(xcu, ycu, 30, 2, 1, "      DOI TEN DANG NHAP");
            if (ycu == 28) lightBar(xcu, ycu, 30, 2, 1, "         DOI MAT KHAU");
            if (ycu == 30) lightBar(xcu, ycu, 30, 2, 1, "           QUAY LAI");
            xcu = xp;
            ycu = yp;
            if (yp == 12) lightBar(xp, yp, 30, 2, 75, "       XEM TOAN BO SACH");
            if (yp == 14) lightBar(xp, yp, 30, 2, 75, "     XEM SACH CO THE MUON");
            if (yp == 16) lightBar(xp, yp, 30, 2, 75, "    TIM KIEM THEO TEN SACH");
            if (yp == 18) lightBar(xp, yp, 30, 2, 75, "    TIM KIEM THEO THE LOAI");
            if (yp == 20) lightBar(xp, yp, 30, 2, 75, "    TIM KIEM THEO TAC GIA");
            if (yp == 22) lightBar(xp, yp, 30, 2, 75, "      YEU CAU MUON SACH");
            if (yp == 24) lightBar(xp, yp, 30, 2, 75, "   XEM TOAN BO SACH DANG MUON");
            if (yp == 26) lightBar(xp, yp, 30, 2, 75, "      DOI TEN DANG NHAP");
            if (yp == 28) lightBar(xp, yp, 30, 2, 75, "         DOI MAT KHAU");
            if (yp == 30) lightBar(xp, yp, 30, 2, 75, "           QUAY LAI");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 12)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 12)
                {
                    kt = true;
                    yp = 30;
                }
                else if (c == 80 && yp != 30)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 30)
                {
                    kt = true;
                    yp = 12;
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

List menuUser(List l, Node<User>* P)
{
    User Us = P->getData();
    int i;
    while (TRUE)
    {
        system("cls");
        box(49, 5, 30, 2, 11, 1, "    THU VIEN DHBK DA NANG    ");
        box(49, 10, 30, 2, 11, 1, "=============MENU=============");
        box(49, 12, 30, 2, 11, 1, "       XEM TOAN BO SACH ");
        gotoXY(49, 12); cout << char(195);
        gotoXY(79, 12); cout << char(180);
        box(49, 14, 30, 2, 11, 1, "     XEM SACH CO THE MUON ");
        gotoXY(49, 14); cout << char(195);
        gotoXY(79, 14); cout << char(180);
        box(49, 16, 30, 2, 11, 1, "    TIM KIEM THEO TEN SACH");
        gotoXY(49, 16); cout << char(195);
        gotoXY(79, 16); cout << char(180);
        box(49, 18, 30, 2, 11, 1, "    TIM KIEM THEO THE LOAI");
        gotoXY(49, 18); cout << char(195);
        gotoXY(79, 18); cout << char(180);
        box(49, 20, 30, 2, 11, 1, "    TIM KIEM THEO TAC GIA");
        gotoXY(49, 20); cout << char(195);
        gotoXY(79, 20); cout << char(180);
        box(49, 22, 30, 2, 11, 1, "      YEU CAU MUON SACH");
        gotoXY(49, 22); cout << char(195);
        gotoXY(79, 22); cout << char(180);
        box(49, 24, 30, 2, 11, 1, "   XEM TOAN BO SACH DANG MUON");
        gotoXY(49, 24); cout << char(195);
        gotoXY(79, 24); cout << char(180);
        box(49, 26, 30, 2, 11, 1, "      DOI TEN DANG NHAP");
        gotoXY(49, 26); cout << char(195);
        gotoXY(79, 26); cout << char(180);
        box(49, 28, 30, 2, 11, 1, "         DOI MAT KHAU");
        gotoXY(49, 28); cout << char(195);
        gotoXY(79, 28); cout << char(180);
        box(49, 30, 30, 2, 11, 1, "           QUAY LAI");
        gotoXY(49, 30); cout << char(195);
        gotoXY(79, 30); cout << char(180);
        int option = dynamicUserMenu(49, 12, 49, 12, true);
        switch (option)
        {
        case 12:
            Us.displayBook(l.lbook());
            break;
        case 14:
            Us.displayAvailable(l.lbook());
            break;
        case 16:
            Us.findBookName(l.lbook());
            break;
        case 18:
            Us.findCategory(l.lbook());
            break;
        case 20:
            Us.findAuthor(l.lbook());
            break;
        case 22:
            Us.menuRequest(l.lbook());
            break;
        case 24:
            i = Us.displayBorrow(l.lbook(), 0);
            break;
        case 26:
            Us.newUsername(l.luser());
            break;
        case 28:
            Us.newPassword();
            break;
        case 30:
            P->setData(Us);
            writeFileUser(l.luser());
            return l;
        default:
            break;
        }
    }
}