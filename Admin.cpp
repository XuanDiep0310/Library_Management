#include "Admin.h"
#include <cstring>
#include <iostream>

#define TRUE 1
using namespace std;

Admin::Admin()
{

}

int dynamicFixMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 7) lightbar(xcu, ycu, 30, 2, 1, "       SUA MA SO SACH");
            if (ycu == 9) lightbar(xcu, ycu, 30, 2, 1, "        SUA TEN SACH");
            if (ycu == 11) lightbar(xcu, ycu, 30, 2, 1, "      SUA THE LOAI SACH");
            if (ycu == 13) lightbar(xcu, ycu, 30, 2, 1, "      SUA NHA XUAT BAN");
            if (ycu == 15) lightbar(xcu, ycu, 30, 2, 1, "         SUA TAC GIA");
            if (ycu == 17) lightbar(xcu, ycu, 30, 2, 1, "      SUA NAM XUAT BAN");
            if (ycu == 19) lightbar(xcu, ycu, 30, 2, 1, "    SUA SO LUONG HIEN CO");
            if (ycu == 21) lightbar(xcu, ycu, 30, 2, 1, "    SUA SO LUONG BAN DAU");
            if (ycu == 23) lightbar(xcu, ycu, 30, 2, 1, "        SUA VI TRI");
            if (ycu == 25) lightbar(xcu, ycu, 30, 2, 1, "           QUAY LAI");
            if (ycu == 27) lightbar(xcu, ycu, 30, 2, 1, "            THOAT");
            xcu = xp;
            ycu = yp;
            if (yp == 7) lightbar(xp, yp, 30, 2, 75, "       SUA MA SO SACH");
            if (yp == 9) lightbar(xp, yp, 30, 2, 75, "        SUA TEN SACH");
            if (yp == 11) lightbar(xp, yp, 30, 2, 75, "      SUA THE LOAI SACH");
            if (yp == 13) lightbar(xp, yp, 30, 2, 75, "      SUA NHA XUAT BAN");
            if (yp == 15) lightbar(xp, yp, 30, 2, 75, "         SUA TAC GIA");
            if (yp == 17) lightbar(xp, yp, 30, 2, 75, "      SUA NAM XUAT BAN");
            if (yp == 19) lightbar(xp, yp, 30, 2, 75, "    SUA SO LUONG HIEN CO");
            if (yp == 21) lightbar(xp, yp, 30, 2, 75, "    SUA SO LUONG BAN DAU");
            if (yp == 23) lightbar(xp, yp, 30, 2, 75, "        SUA VI TRI");
            if (yp == 25) lightbar(xp, yp, 30, 2, 75, "           QUAY LAI");
            if (yp == 27) lightbar(xp, yp, 30, 2, 75, "            THOAT");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 7)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 7)
                {
                    kt = true;
                    yp = 27;
                }
                else if (c == 80 && yp != 27)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 27)
                {
                    kt = true;
                    yp = 7;
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

LinkedList<Book>* Admin::fixBook(LinkedList<Book>* lbook, LinkedList<User>* luser)
{
    cin.ignore();
    Book S;
    string ID;
    string Name;
    string Category;
    string Publisher;
    int Year;
    string Author;
    int Amount;
    int fixedAmount;
    string location;
    Date D;
    bool check = true;
    while (check)
    {
        system("cls");
        box(1, 1, 124, 2, 11, 1, "***************************************************SUA DOI THONG TIN SACH**************************************************");
        box(1, 3, 124, 2, 11, 1, "Nhap ma sach:");
        gotoXY(1, 3); cout << char(195);
        gotoXY(125, 3); cout << char(180);
        gotoXY(35, 4);
        string ms(limit(35, 4, 20));
        Node<Book>* P = lbook->get(ms);
        if (P != NULL)
        {
            box(1, 7, 30, 2, 11, 1, "       SUA MA SO SACH");
            box(1, 9, 30, 2, 11, 1, "        SUA TEN SACH");
            gotoXY(1, 9); cout << char(195);
            gotoXY(31, 9); cout << char(180);
            box(1, 11, 30, 2, 11, 1, "      SUA THE LOAI SACH");
            gotoXY(1, 11); cout << char(195);
            gotoXY(31, 11); cout << char(180);
            box(1, 13, 30, 2, 11, 1, "      SUA NHA XUAT BAN");
            gotoXY(1, 13); cout << char(195);
            gotoXY(31, 13); cout << char(180);
            box(1, 15, 30, 2, 11, 1, "         SUA TAC GIA");
            gotoXY(1, 15); cout << char(195);
            gotoXY(31, 15); cout << char(180);
            box(1, 17, 30, 2, 11, 1, "      SUA NAM XUAT BAN");
            gotoXY(1, 17); cout << char(195);
            gotoXY(31, 17); cout << char(180);
            box(1, 19, 30, 2, 11, 1, "    SUA SO LUONG HIEN CO");
            gotoXY(1, 19); cout << char(195);
            gotoXY(31, 19); cout << char(180);
            box(1, 21, 30, 2, 11, 1, "    SUA SO LUONG BAN DAU");
            gotoXY(1, 21); cout << char(195);
            gotoXY(31, 21); cout << char(180);
            box(1, 23, 30, 2, 11, 1, "        SUA VI TRI");
            gotoXY(1, 23); cout << char(195);
            gotoXY(31, 23); cout << char(180);
            box(1, 25, 30, 2, 11, 1, "           QUAY LAI");
            gotoXY(1, 25); cout << char(195);
            gotoXY(31, 25); cout << char(180);
            box(1, 27, 30, 2, 11, 1, "            THOAT");
            gotoXY(1, 27); cout << char(195);
            gotoXY(31, 27); cout << char(180);
            box(55, 10, 50, 10, 11, 1);
            bool check2 = true;
            while (check2)
            {
                int option = dynamicFixMenu(1, 7, 1, 7, true);
                switch (option)
                {
                case 7:
                    cin.ignore();
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Ma so sach hien tai:          " << P->getData().getID();
                    gotoXY(60, 16);
                    cout << "Ma so sach moi:";
                    gotoXY(90, 16);
                    ID = limit(90, 16, 15);
                    if (lbook->get(ID) == NULL && ID.empty() == false)
                    {
                        S = P->getData();
                        S.setID(ID);
                        P->setData(S);
                        for (Node<User>* K = luser->getHead(); K != NULL; K = K->getNext())
                        {
                            User U = K->getData();
                            for (int i = 4; i >= U.getNumBorrow() + 1; i--)
                            {
                                if (U.getBorrow(i).IDborrow == ms)
                                {
                                    U.setBorrow(ID, U.getBorrow(i).Dayborrow, U.getBorrow(i).Dayexpiry, i);
                                }
                            }
                            for (int i = 4; i >= U.getNumRequest() + 1; i--)
                            {

                                if (U.getRequest(i).idRequest == ms)
                                {
                                    U.setRequest(ID, U.getRequest(i).accept, i);
                                }
                            }
                            K->setData(U);
                        }
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else if (ID.empty())
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Ma so sach nay da ton tai !!!" << endl;
                        cin.get();
                    }
                    break;
                case 9:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Ten sach hien tai:   " << P->getData().getName();
                    gotoXY(60, 16);
                    cout << "Ten sach moi:";
                    gotoXY(83, 16);
                    Name = limit(83, 16, 22);
                    if (Name.empty() == false)
                    {
                        S = P->getData();
                        S.setName(Name);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 11:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "The loai hien tai:   " << P->getData().getCategory();
                    gotoXY(60, 16);
                    cout << "The loai moi:";
                    gotoXY(83, 16);
                    Category = limit(83, 16, 22);
                    if (Category.empty() == false)
                    {
                        S = P->getData();
                        S.setCategory(Category);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 13:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Nha xuat ban hien tai:   " << P->getData().getPublisher();
                    gotoXY(60, 16);
                    cout << "Nha xuat ban moi:";
                    gotoXY(83, 16);
                    Publisher = limit(83, 16, 22);
                    if (Publisher.empty() == false)
                    {
                        S = P->getData();
                        S.setPublisher(Publisher);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 15:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Tac gia hien tai:   " << P->getData().getAuthor();
                    gotoXY(60, 16);
                    cout << "Tac gia moi:";
                    gotoXY(83, 16);
                    Author = limit(83, 16, 22);
                    if (Author.empty() == false)
                    {
                        S = P->getData();
                        S.setAuthor(Author);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 17:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Nam xuat ban hien tai:   " << P->getData().getYear();
                    gotoXY(60, 16);
                    cout << "Nam xuat ban moi:";
                    gotoXY(83, 16);
                    cin >> Year;
                    if (Year <= D.now().getYear() && Year >= 0)
                    {
                        S = P->getData();
                        S.setYear(Year);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Du lieu sai !!!" << endl;
                        cin.get();
                    }
                    break;
                case 19:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "So luong hien co hien tai:   " << P->getData().getAmount();
                    gotoXY(60, 16);
                    cout << "So luong hien co moi:";
                    gotoXY(83, 16);
                    cin >> Amount;
                    if (Amount >= 0 && Amount <= P->getData().getFixedAmount())
                    {
                        S = P->getData();
                        S.setAmount(Amount);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Du lieu sai !!!" << endl;
                        cin.get();
                    }
                    break;
                case 21:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "So luong ban dau hien tai:   " << P->getData().getFixedAmount();
                    gotoXY(60, 16);
                    cout << "So luong ban dau moi:";
                    gotoXY(83, 16);
                    cin >> fixedAmount;
                    if (fixedAmount >= 0 && fixedAmount >= P->getData().getAmount())
                    {
                        S = P->getData();
                        S.setFixedAmount(fixedAmount);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Du lieu sai !!!" << endl;
                        cin.get();
                    }
                    break;
                case 23:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Vi tri hien tai:   " << P->getData().getLocation();
                    gotoXY(60, 16);
                    cout << "Vi tri moi:";
                    gotoXY(83, 16);
                    location = limit(83, 16, 22);
                    if (location.empty() == false)
                    {
                        bool check3 = true;
                        for (Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext())
                        {
                            if (location == P->getData().getLocation())
                            {
                                check3 = false;
                                break;
                            }
                        }
                        if (check3 == true)
                        {
                            S = P->getData();
                            S.setLocation(location);
                            P->setData(S);
                            gotoXY(70, 18);
                            cout << "Thay doi thanh cong !!!" << endl;
                            cin.get();
                        }
                        else
                        {
                            gotoXY(70, 18);
                            cout << "Vi tri da ton tai !!!" << endl;
                            cin.get();
                        }
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 25:
                    check2 = false;
                    break;
                case 27:
                    check = false;
                    check2 = false;
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            gotoXY(55, 4);
            cout << "Ma so sach nay khong ton tai !!!" << endl;
            cin.get();
        }
        gotoXY(55, 4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc................!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return lbook;
        }
    }
}

LinkedList<Book>* Admin::addBook(LinkedList<Book>* lbook)
{
    ShowCur(1);
    cin.ignore();
    Book P;
    int Year;
    string Author;
    int fixedAmount;
    Date D;
    bool check2 = true;
    while (true)
    {
        system("cls");
        box(49, 8, 30, 2, 11, 1, "   THEM SACH VAO THU VIEN");
        gotoXY(25, 12);
        cout << "Nhap ma so sach:";
        box(49, 11, 30, 2, 11, 1);
        gotoXY(25, 14);
        cout << "Nhap ten sach:";
        box(49, 13, 30, 2, 11, 1);
        gotoXY(49, 13); cout << char(195);
        gotoXY(79, 13); cout << char(180);
        gotoXY(25, 16);
        cout << "Nhap the loai:";
        box(49, 15, 30, 2, 11, 1);
        gotoXY(49, 15); cout << char(195);
        gotoXY(79, 15); cout << char(180);
        gotoXY(25, 18);
        cout << "Nhap nha xuat ban:";
        box(49, 17, 30, 2, 11, 1);
        gotoXY(49, 17); cout << char(195);
        gotoXY(79, 17); cout << char(180);
        gotoXY(25, 20);
        cout << "Nhap tac gia:";
        box(49, 19, 30, 2, 11, 1);
        gotoXY(49, 19); cout << char(195);
        gotoXY(79, 19); cout << char(180);
        gotoXY(25, 22);
        cout << "Nhap nam xuat ban:";
        box(49, 21, 30, 2, 11, 1);
        gotoXY(49, 21); cout << char(195);
        gotoXY(79, 21); cout << char(180);
        gotoXY(25, 24);
        cout << "Nhap so luong:";
        box(49, 23, 30, 2, 11, 1);
        gotoXY(49, 23); cout << char(195);
        gotoXY(79, 23); cout << char(180);
        gotoXY(25, 26);
        cout << "Nhap vi tri:";
        box(49, 25, 30, 2, 11, 1);
        gotoXY(49, 25); cout << char(195);
        gotoXY(79, 25); cout << char(180);
        gotoXY(51, 12);
        string ID(limit(51, 12, 28));
        gotoXY(51, 14);
        string Name(limit(51, 14, 28));
        gotoXY(51, 16);
        string Category(limit(51, 16, 28));
        gotoXY(51, 18);
        string Publisher(limit(51, 18, 28));
        gotoXY(51, 20);
        string Author(limit(51, 20, 28));
        gotoXY(51, 22);
        cin >> Year;
        gotoXY(51, 24);
        cin >> fixedAmount;
        gotoXY(51, 26);
        cin.ignore();
        string location(limit(51, 26, 28));
        bool kt = true;
        if (ID.length() != 5)
        {
            kt = false;
            gotoXY(82, 12);
            cout << "Loi du lieu !!!" << endl;
        }
        else if (lbook->get(ID) != NULL)
        {
            kt = false;
            gotoXY(82, 12);
            cout << "Ma so sach nay da ton tai !!!" << endl;
        }
        if (Name.empty())
        {
            kt = false;
            gotoXY(82, 14);
            cout << "Khong the trong !!!" << endl;
        }
        if (Category.empty())
        {
            kt = false;
            gotoXY(82, 16);
            cout << "Khong the trong !!!" << endl;
        }
        if (Publisher.empty())
        {
            kt = false;
            gotoXY(82, 18);
            cout << "Khong the trong !!!" << endl;
        }
        if (Author.empty())
        {
            kt = false;
            gotoXY(82, 20);
            cout << "Khong the trong !!!" << endl;
        }
        if (Year > D.now().getYear() || Year <= 0)
        {
            kt = false;
            gotoXY(82, 22);
            cout << "Loi du lieu !!!" << endl;
        }
        if (fixedAmount <= 0 || fixedAmount > 300000)
        {
            kt = false;
            gotoXY(82, 24);
            cout << "Loi du lieu !!!" << endl;
        }
        if (location.empty())
        {
            kt = false;
            gotoXY(82, 26);
            cout << "Khong the trong !!!" << endl;
        }
        else
        {
            for (Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext())
            {
                if (location == P->getData().getLocation())
                {
                    check2 = false;
                    break;
                }
            }
            if (check2 == false)
            {
                kt = false;
                gotoXY(82, 26);
                cout << "Vi tri da ton tai !!!" << endl;
            }
        }
        _getch();
        if (kt == true)
        {
            P.setID(ID);
            P.setName(Name);
            P.setCategory(Category);
            P.setPublisher(Publisher);
            P.setAuthor(Author);
            P.setYear(Year);
            P.setFixedAmount(fixedAmount);
            P.setAmount(fixedAmount);
            P.setLocation(location);
            lbook->addTail(P);
            gotoXY(51, 28);
            cout << "Them sach thanh cong !!!" << endl;
            _getch();
        }
        gotoXY(40, 30);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc................!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return lbook;
        }
    }
}

LinkedList<Book>* Admin::delBook(LinkedList<Book>* lbook)
{
    ShowCur(1);
    cin.ignore();
    string ID;
    while (true)
    {
        system("cls");
        box(1, 1, 124, 2, 11, 1, "*************************************************XOA SACH RA KHOI THU VIEN*************************************************");
        box(1, 3, 124, 2, 11, 1, "Nhap ma sach can xoa :");
        gotoXY(1, 3); cout << char(195);
        gotoXY(125, 3); cout << char(180);
        gotoXY(35, 4);
        ID = limit(35, 4, 20);
        Node<Book>* head = lbook->getHead();
        Node<Book>* tail = lbook->getTail();
        Node<Book>* p = lbook->get(ID);
        if (p != NULL)
        {
            if (p->getData().getFixedAmount() == p->getData().getAmount())
            {
                if (head == NULL)
                {
                    gotoXY(55, 4);
                    cout << "Khong co gi de xoa !!!" << endl;
                    cin.get();
                }
                else if (head->getData().getID() == ID)
                {
                    head = head->getNext();
                    lbook->setHead(head);
                    gotoXY(55, 4);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                else if (tail->getData().getID() == ID)
                {
                    tail->getPrev()->setNext(NULL);
                    tail = tail->getPrev();
                    lbook->setTail(tail);
                    gotoXY(55, 4);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                else
                {
                    p->getPrev()->setNext(p->getNext());
                    gotoXY(55, 4);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                lbook->setCount(lbook->getCount() - 1);
            }
            else
            {
                gotoXY(55, 4);
                cout << "Khong hop le, sach chua duoc tra du !!!" << endl;
                cin.get();
            }
        }
        else
        {
            gotoXY(55, 4);
            cout << "Ma so sach khong ton tai !!!" << endl;
            cin.get();
        }
        gotoXY(55, 4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc....!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return lbook;
        }
    }
}

void Admin::displayUser(LinkedList<User>* luser)
{
    system("cls");
    box(1, 5, 124, 2, 11, 1, "*********************************************TOAN BO NGUOI DUNG TRONG THU VIEN**********************************************");
    box(1, 7, 20, 2, 11, 1, " MA SO NGUOI DUNG");
    gotoXY(1, 7); cout << char(195);
    box(21, 7, 30, 2, 11, 1, "       TEN NGUOI DUNG");
    box(51, 7, 20, 2, 11, 1, "     NGAY SINH");
    box(71, 7, 20, 2, 11, 1, "   SO DIEN THOAI");
    box(91, 7, 20, 2, 11, 1, " SO SACH DANG MUON");
    box(111, 7, 14, 2, 11, 1, " SO YEU CAU");
    gotoXY(21, 7); cout << char(194);
    gotoXY(21, 9); cout << char(193);
    gotoXY(51, 7); cout << char(194);
    gotoXY(51, 9); cout << char(193);
    gotoXY(71, 7); cout << char(194);
    gotoXY(71, 9); cout << char(193);
    gotoXY(91, 7); cout << char(194);
    gotoXY(91, 9); cout << char(193);
    gotoXY(111, 7); cout << char(194);
    gotoXY(111, 9); cout << char(193);
    gotoXY(125, 7); cout << char(180);
    luser->printNext();
    int i = luser->getCount() * 2;
    gotoXY(21, 9 + i); cout << char(193);
    gotoXY(51, 9 + i); cout << char(193);
    gotoXY(71, 9 + i); cout << char(193);
    gotoXY(91, 9 + i); cout << char(193);
    gotoXY(111, 9 + i); cout << char(193);
    cin.get();
}

List Admin::delUser(List l)
{
    ShowCur(1);
    cin.ignore();
    LinkedList<User>* luser = l.luser();
    string ID;
    while (true)
    {
        system("cls");
        box(1, 5, 124, 2, 11, 1, "**********************************************XOA NGUOI DUNG RA KHOI THU VIEN**********************************************");
        box(1, 7, 124, 2, 11, 1);
        gotoXY(1, 7); cout << char(195);
        gotoXY(125, 7); cout << char(180);
        gotoXY(2, 8);
        cout << "Nhap ma nguoi dung can xoa : ";
        gotoXY(40, 8);
        ID = limit(40, 8, 30);
        Node<User>* head = luser->getHead();
        Node<User>* tail = luser->getTail();
        Node<User>* p = luser->get(ID);
        if (p != NULL)
        {
            if (p->getData().getNumBorrow() == 4)
            {
                if (head == NULL)
                {
                    gotoXY(70, 8);
                    cout << "Khong co gi de xoa !!!" << endl;
                    cin.get();
                }
                else if (head == p)
                {
                    head = head->getNext();
                    luser->setHead(head);
                    l.setListUser(luser);
                    gotoXY(70, 8);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                else if (tail == p)
                {
                    tail->getPrev()->setNext(NULL);
                    tail = tail->getPrev();
                    luser->setTail(tail);
                    l.setListUser(luser);
                    gotoXY(70, 8);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                else
                {
                    p->getPrev()->setNext(p->getNext());
                    gotoXY(70, 8);
                    cout << "Xoa thanh cong !!!" << endl;
                    cin.get();
                }
                luser->setCount(luser->getCount() - 1);
            }
            else
            {
                gotoXY(70, 8);
                cout << "Khong hop le, nguoi dung dang muon sach !!!" << endl;
                cin.get();
            }
        }
        else
        {
            gotoXY(70, 8);
            cout << "Ma so nguoi dung khong ton tai !!!" << endl;
            cin.get();
        }
        gotoXY(70, 8);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc....!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return l;
        }
    }
}

void Admin::findUser(LinkedList<User>* luser, LinkedList<Book>* lbook)
{
    cin.ignore();
    while (true)
    {
        system("cls");
        string ID;
        box(1, 1, 124, 2, 11, 1, "***********************************************TIM KIEM THONG TIN NGUOI DUNG************************************************");
        box(1, 3, 124, 2, 11, 1, "Nhap ma so sinh vien can xem thong tin :");
        gotoXY(1, 3); cout << char(195);
        gotoXY(125, 3); cout << char(180);
        gotoXY(50, 4);
        ID = limit(50, 4, 15);
        if (luser->get(ID) != NULL)
        {
            Node<User>* P = luser->get(ID);
            box(1, 5, 20, 2, 11, 1, " MA SO NGUOI DUNG");
            gotoXY(1, 5); cout << char(195);
            box(21, 5, 30, 2, 11, 1, "       TEN NGUOI DUNG");
            box(51, 5, 20, 2, 11, 1, "     NGAY SINH");
            box(71, 5, 20, 2, 11, 1, "   SO DIEN THOAI");
            box(91, 5, 20, 2, 11, 1, " SO SACH DANG MUON");
            box(111, 5, 14, 2, 11, 1, " SO YEU CAU");
            gotoXY(21, 5); cout << char(194);
            gotoXY(21, 7); cout << char(193);
            gotoXY(51, 5); cout << char(194);
            gotoXY(51, 7); cout << char(193);
            gotoXY(71, 5); cout << char(194);
            gotoXY(71, 7); cout << char(193);
            gotoXY(91, 5); cout << char(194);
            gotoXY(91, 7); cout << char(193);
            gotoXY(111, 5); cout << char(194);
            gotoXY(111, 7); cout << char(193);
            gotoXY(125, 5); cout << char(180);
            P->print(P, 0, 0);
            int k = P->getData().displayBorrow(lbook, 4);
            P->getData().displayRequest(lbook, 6 + k);
            cin.get();
        }
        else
        {
            gotoXY(80, 4);
            cout << "Ma so khong co trong thu vien !!!";
            cin.get();
        }
        gotoXY(65, 4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc....!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return;
        }
    }
}

void Admin::borrowBook(List l, int time)
{
    LinkedList<User>* luser = l.luser();
    LinkedList<Book>* lbook = l.lbook();
    string IDuser;
    cin.ignore();
    while (true)
    {
        system("cls");
        box(1, 1, 124, 2, 11, 1, "******************************************************CHO MUON SACH********************************************************");
        box(1, 3, 38, 2, 11, 1, "MA SO SINH VIEN:");
        gotoXY(1, 3); cout << char(195);
        box(39, 3, 38, 2, 11, 1, "MA SO SACH YEU CAU:");
        box(77, 3, 18, 2, 11, 1, "MA SO YEU CAU:");
        box(95, 3, 30, 2, 11, 1, "CHAP NHAN/TU CHOI(1/2):");
        gotoXY(39, 3); cout << char(194);
        gotoXY(77, 3); cout << char(194);
        gotoXY(95, 3); cout << char(194);
        gotoXY(125, 3); cout << char(180);
        box(1, 5, 124, 2, 11, 1);
        box(1, 5, 23, 2, 11, 1);
        gotoXY(24, 5); cout << char(194);
        gotoXY(2, 6);
        cout << "SO LUONG YEU CAU: ";
        gotoXY(1, 5); cout << char(195);
        gotoXY(39, 5); cout << char(193);
        gotoXY(77, 5); cout << char(193);
        gotoXY(95, 5); cout << char(193);
        gotoXY(125, 5); cout << char(180);
        box(1, 7, 84, 2, 11, 1, "                                              YEU CAU");
        box(85, 7, 16, 2, 11, 1, " MA SO YEU CAU");
        box(101, 7, 24, 2, 11, 1, "      TRANG THAI");
        gotoXY(1, 7); cout << char(195);
        gotoXY(24, 7); cout << char(193);
        gotoXY(85, 7); cout << char(194);
        gotoXY(85, 9); cout << char(193);
        gotoXY(101, 7); cout << char(194);
        gotoXY(101, 9); cout << char(193);
        gotoXY(125, 7); cout << char(180);
        gotoXY(19, 4);
        IDuser = limit(19, 4, 20);
        if (luser->get(IDuser) != NULL)
        {
            Node<User>* U = luser->get(IDuser);
            User C = U->getData();
            int ya = 4;
            for (int i = 4; i >= C.getNumRequest() + 1; i--)
            {
                box(1, 5 + ya, 84, 2, 11, 1);
                gotoXY(1, 5 + ya); cout << char(195);
                box(85, 5 + ya, 16, 2, 11, 1);
                gotoXY(85, 5 + ya); cout << char(197);
                gotoXY(2, 6 + ya);
                cout << "Sinh vien ma so " << C.getId() << " yeu cau muon sach ma so " << C.getRequest(i).idRequest << " : " << endl;
                gotoXY(93, 6 + ya);
                cout << i;
                if (C.getRequest(i).accept == 0)
                {
                    box(101, 5 + ya, 24, 2, 11, 1);
                    gotoXY(101, 5 + ya); cout << char(197);
                    gotoXY(125, 5 + ya); cout << char(180);
                    gotoXY(102, 6 + ya);
                    cout << "Dang cho duyet.";
                }
                else if (C.getRequest(i).accept == 1)
                {
                    box(101, 5 + ya, 24, 2, 11, 1);
                    gotoXY(101, 5 + ya); cout << char(197);
                    gotoXY(125, 5 + ya); cout << char(180);
                    gotoXY(102, 6 + ya);
                    cout << "Chap nhan.";
                }
                else if (C.getRequest(i).accept == 2)
                {
                    box(101, 5 + ya, 24, 2, 11, 1);
                    gotoXY(101, 5 + ya); cout << char(197);
                    gotoXY(125, 5 + ya); cout << char(180);
                    gotoXY(102, 6 + ya);
                    cout << "Tu choi.";
                }
                ya += 2;
            }

            if (C.getNumBorrow() >= 0)
            {
                string IDbook;
                int ms;
                int yc;
                bool check = false;
                gotoXY(61, 4);
                IDbook = limit(61, 4, 16);
                gotoXY(93, 4);
                cin >> ms;
                gotoXY(121, 4);
                cin >> yc;
                if (l.lbook()->get(IDbook) != NULL && yc >= 1 && yc <= 2)
                {
                    for (int i = 4; i >= C.getNumRequest() + 1; i--)
                    {
                        if (C.getRequest(i).idRequest == IDbook && i == ms && C.getRequest(i).accept == 0)
                        {
                            Node<Book>* P = l.lbook()->get(IDbook);
                            Book B = P->getData();
                            if (yc == 1)
                            {
                                check = true;
                                C.setRequest(IDbook, yc, i);
                                B.setAmount(B.getAmount() - 1);
                                Date D;
                                D = D.now();
                                Date De;
                                De = De.now();
                                C.setBorrow(IDbook, D, De.expiry(time), C.getNumBorrow());
                                C.setNumBorrow(C.getNumBorrow() - 1);
                                gotoXY(60, 6);
                                cout << "Muon sach thanh cong !";
                                _getch();
                            }
                            else if (yc == 2)
                            {
                                check = true;
                                C.setRequest(IDbook, yc, i);
                                gotoXY(60, 6);
                                cout << "Tu choi cho muon !";
                                _getch();
                            }
                            P->setData(B);
                            U->setData(C);
                            break;
                        }
                        else if (C.getRequest(i).idRequest == IDbook && i == ms && (C.getRequest(i).accept == 1 || C.getRequest(i).accept == 2))
                        {
                            check = true;
                            gotoXY(60, 6);
                            cout << "Sach da duoc xet duyet !";
                            _getch();
                            break;
                        }
                    }
                    if (check == false)
                    {
                        gotoXY(45, 6);
                        cout << "Sinh vien khong yeu cau muon ma so sach, hoac khong co ma so yeu cau nay!!!";
                        _getch();
                    }
                }
                else
                {
                    gotoXY(60, 6);
                    cout << "Du lieu loi !!!" << endl;
                    _getch();
                }
            }
            else
            {
                gotoXY(60, 6);
                cout << "Sinh vien da muon toi da 5 cuon sach !!!" << endl;
                cin.get();
            }
        }
        else
        {
            gotoXY(60, 6);
            cout << "Ma so khong co trong thu vien !!!" << endl;
            cin.get();
        }
        gotoXY(60, 6);
        cout << " Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return;
        }
    }
}

void Admin::giveBackBook(List l, int money)
{
    LinkedList<User>* luser = l.luser();
    LinkedList<Book>* lbook = l.lbook();
    cin.ignore();
    while (true)
    {
        system("cls");
        box(1, 5, 124, 2, 11, 1, "*********************************************************TRA SACH**********************************************************");
        box(1, 7, 124, 2, 11, 1);
        gotoXY(2, 8);
        cout << "Nhap ma so sinh vien :";
        box(1, 9, 124, 2, 11, 1);
        gotoXY(2, 10);
        cout << "Nhap ma so sach can tra :";
        box(1, 11, 124, 2, 11, 1);
        gotoXY(1, 7); cout << char(195);
        gotoXY(125, 7); cout << char(180);
        gotoXY(1, 9); cout << char(195);
        gotoXY(125, 9); cout << char(180);
        gotoXY(1, 11); cout << char(195);
        gotoXY(125, 11); cout << char(180);
        string IDuser;
        gotoXY(30, 8);
        IDuser = limit(30, 8, 20);
        if (luser->get(IDuser) != NULL)
        {
            int nop = 1;
            Node<User>* U = luser->get(IDuser);
            User C = U->getData();
            string ID;
            Date D;
            bool check = false;
            gotoXY(30, 10);
            ID = limit(30, 10, 25);
            for (int i = C.getNumBorrow() + 1; i <= 4; i++)
            {
                if (ID == C.getBorrow(i).IDborrow)
                {
                    check = true;
                    if (C.getBorrow(i).Dayexpiry < D.now())
                    {
                        int Money = D.overdue(C.getBorrow(i).Dayexpiry) * money;
                        gotoXY(2, 12);
                        cout << "Sinh vien tra sach qua :" << D.overdue(C.getBorrow(i).Dayexpiry) << " ngay." << "Sinh vien can nop phat :" << Money << " VND." << "Sinh vien da nop phat chua ? (1/0):";
                        gotoXY(105, 12);
                        cin >> nop;
                    }
                    else
                    {
                        gotoXY(55, 12);
                        cout << "Sach chua qua han !!!";
                        cin.get();
                    }
                    if ((D.now() < C.getBorrow(i).Dayexpiry || D.now() == C.getBorrow(i).Dayexpiry) && nop == 1)
                    {
                        for (int j = i; j > C.getNumBorrow() + 1; j--)
                        {
                            C.setBorrow(C.getBorrow(j - 1).IDborrow, C.getBorrow(j - 1).Dayborrow, C.getBorrow(j - 1).Dayexpiry, j);
                        }
                        for (int t = C.getNumBorrow() + 1; t >= 0; t--)
                        {
                            Date D(1, 1, 1900);
                            C.setBorrow("0", D, D, t);
                        }
                        C.setNumBorrow(C.getNumBorrow() + 1);
                        Node<Book>* P = lbook->get(ID);
                        Book B = P->getData();
                        B.setAmount(P->getData().getAmount() + 1);
                        P->setData(B);
                        U->setData(C);
                        gotoXY(2, 12);
                        cout << "                                                Tra sach thanh cong !                                                     ";
                        char j = _getch();
                        break;
                    }
                    else if (C.getBorrow(i).Dayexpiry < D.now() && nop == 1)
                    {
                        for (int j = i; j > C.getNumBorrow() + 1; j--)
                        {
                            C.setBorrow(C.getBorrow(j - 1).IDborrow, C.getBorrow(j - 1).Dayborrow, C.getBorrow(j - 1).Dayexpiry, j);
                        }
                        for (int t = C.getNumBorrow() + 1; t >= 0; t--)
                        {
                            Date D(1, 1, 1900);
                            C.setBorrow("0", D, D, t);
                        }
                        C.setNumBorrow(C.getNumBorrow() + 1);
                        Node<Book>* P = lbook->get(ID);
                        Book B = P->getData();
                        B.setAmount(P->getData().getAmount() + 1);
                        P->setData(B);
                        U->setData(C);
                        gotoXY(2, 12);
                        cout << "                                                Tra sach thanh cong !                                                     ";
                        char z = _getch();
                        break;
                    }
                    else if (nop == 0)
                    {
                        gotoXY(2, 12);
                        cout << "                                      Sinh vien can nop tien phat !!!                                  ";
                        char t = _getch();
                    }
                    else if (nop != 1 && nop != 0)
                    {
                        gotoXY(2, 12);
                        cout << "                                           Sai du lieu !!!                                  ";
                        char k = _getch();
                    }
                }
            }
            if (check == false)
            {
                gotoXY(50, 12);
                cout << "Sinh vien khong muon ma sach nay !!!";
                char l = _getch();
            }
        }
        else
        {
            gotoXY(50, 12);
            cout << "Ma so khong co trong thu vien !!!";
            char m = _getch();
        }
        gotoXY(2, 12);
        cout << "                                     Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc!!!                                     ";
        char c = _getch();
        if (c == 27)
        {
            return;
        }
    }
}

void Admin::resetPasswork(LinkedList<User>* luser)
{
    string ID;
    cin.ignore();
    while (true)
    {
        system("cls");
        box(1, 5, 124, 2, 11, 1, "***********************************************CAP LAI TAI KHOAN NGUOI DUNG************************************************");
        box(1, 7, 124, 2, 11, 1);
        gotoXY(2, 8);
        cout << "Nhap ma so sinh vien can cap lai tai khoan :";
        box(1, 9, 124, 2, 11, 1);
        gotoXY(2, 10);
        cout << "Ten dang nhap moi:";
        box(1, 11, 124, 2, 11, 1);
        gotoXY(2, 12);
        cout << "Mat khau moi:      ";
        gotoXY(1, 7); cout << char(195);
        gotoXY(125, 7); cout << char(180);
        gotoXY(1, 9); cout << char(195);
        gotoXY(125, 9); cout << char(180);
        gotoXY(1, 11); cout << char(195);
        gotoXY(125, 11); cout << char(180);
        gotoXY(50, 8);
        ID = limit(50, 8, 30);
        if (luser->get(ID) != NULL)
        {
            Node<User>* P = luser->get(ID);
            User U = P->getData();
            U.setUsername(U.getId());
            U.setPassword(U.getId());
            gotoXY(35, 10); cout << U.getUsername();
            gotoXY(35, 12); cout << U.getPassword();
            P->setData(U);
        }
        else
        {
            gotoXY(80, 8);
            cout << "Ma so sinh vien chua duoc dang ky !!!" << endl;
            cin.get();
        }
        gotoXY(50, 8);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc.........................!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return;
        }
    }
}
#define leapYearu(year) ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? true : false
int nummonthu[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int nummonthplusu[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int dynamicFixedUserMenu(int xp, int yp, int xcu, int ycu, bool kt)
{
    ShowCur(0);
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            if (ycu == 7) lightbar(xcu, ycu, 30, 2, 1, "     SUA MA SO SINH VIEN");
            if (ycu == 9) lightbar(xcu, ycu, 30, 2, 1, "     SUA TEN NGUOI DUNG");
            if (ycu == 11) lightbar(xcu, ycu, 30, 2, 1, "        SUA NGAY SINH");
            if (ycu == 13) lightbar(xcu, ycu, 30, 2, 1, "      SUA SO DIEN THOAI");
            if (ycu == 15) lightbar(xcu, ycu, 30, 2, 1, "           QUAY LAI");
            if (ycu == 17) lightbar(xcu, ycu, 30, 2, 1, "            THOAT");
            xcu = xp;
            ycu = yp;
            if (yp == 7) lightbar(xp, yp, 30, 2, 75, "     SUA MA SO SINH VIEN");
            if (yp == 9) lightbar(xp, yp, 30, 2, 75, "     SUA TEN NGUOI DUNG");
            if (yp == 11) lightbar(xp, yp, 30, 2, 75, "        SUA NGAY SINH");
            if (yp == 13) lightbar(xp, yp, 30, 2, 75, "      SUA SO DIEN THOAI");
            if (yp == 15) lightbar(xp, yp, 30, 2, 75, "           QUAY LAI");
            if (yp == 17) lightbar(xp, yp, 30, 2, 75, "            THOAT");
            kt = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {
                c = _getch();
                if (c == 72 && yp != 7)
                {
                    kt = true;
                    yp -= 2;
                }
                else if (c == 72 && yp == 7)
                {
                    kt = true;
                    yp = 17;
                }
                else if (c == 80 && yp != 17)
                {
                    kt = true;
                    yp += 2;
                }
                else if (c == 80 && yp == 17)
                {
                    kt = true;
                    yp = 7;
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

void Admin::updateInfor(LinkedList<User>* luser)
{
    cin.ignore();
    User S;
    string ms;
    string ID;
    string Name;
    Date Dob;
    string Phone;
    int year, month, day;
    Date D;
    bool check = true;
    bool kt = true;
    while (check)
    {
        system("cls");
        box(1, 1, 124, 2, 11, 1, "************************************************SUA DOI THONG TIN NGUOI DUNG***********************************************");
        box(1, 3, 124, 2, 11, 1, "Nhap ma so sinh vien:");
        gotoXY(1, 3); cout << char(195);
        gotoXY(125, 3); cout << char(180);
        gotoXY(35, 4);
        ms = limit(35, 4, 20);
        Node<User>* P = luser->get(ms);
        if (P != NULL)
        {
            box(1, 7, 30, 2, 11, 1, "     SUA MA SO SINH VIEN");
            box(1, 9, 30, 2, 11, 1, "     SUA TEN NGUOI DUNG");
            gotoXY(1, 9); cout << char(195);
            gotoXY(31, 9); cout << char(180);
            box(1, 11, 30, 2, 11, 1, "        SUA NGAY SINH");
            gotoXY(1, 11); cout << char(195);
            gotoXY(31, 11); cout << char(180);
            box(1, 13, 30, 2, 11, 1, "      SUA SO DIEN THOAI");
            gotoXY(1, 13); cout << char(195);
            gotoXY(31, 13); cout << char(180);
            box(1, 15, 30, 2, 11, 1, "           QUAY LAI");
            gotoXY(1, 15); cout << char(195);
            gotoXY(31, 15); cout << char(180);
            box(1, 17, 30, 2, 11, 1, "            THOAT");
            gotoXY(1, 17); cout << char(195);
            gotoXY(31, 17); cout << char(180);
            box(55, 10, 50, 10, 11, 1);
            bool check2 = true;
            while (check2)
            {
                int option = dynamicFixedUserMenu(1, 7, 1, 7, true);
                switch (option)
                {
                case 7:
                    cin.ignore();
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Ma so sinh vien hien tai:          " << P->getData().getId();
                    gotoXY(60, 16);
                    cout << "Ma so sinh vien moi:";
                    gotoXY(90, 16);
                    ID = limit(90, 16, 15);
                    if (luser->get(ID) == NULL && ID.empty() == false && ID.length() == 9)
                    {
                        S = P->getData();
                        S.setId(ID);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else if (ID.empty() && ID.length() != 9)
                    {
                        gotoXY(70, 18);
                        cout << "Du lieu sai !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Ma so sinh vien nay da ton tai !!!" << endl;
                        cin.get();
                    }
                    break;
                case 9:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "Ten nguoi dung hien tai:   " << P->getData().getName();
                    gotoXY(60, 16);
                    cout << "Ten nguoi dung moi:";
                    gotoXY(83, 16);
                    Name = limit(83, 16, 22);
                    if (Name.empty() == false)
                    {
                        S = P->getData();
                        S.setName(Name);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 11:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 11);
                    cout << "Ngay sinh hien tai:   " << P->getData().getDateOfBirth();
                    gotoXY(60, 13);
                    cout << "Nam sinh moi:";
                    gotoXY(60, 15);
                    cout << "Thang sinh moi:";
                    gotoXY(60, 17);
                    cout << "Ngay sinh moi:";
                    gotoXY(80, 13);
                    cin >> year;
                    Dob.setYear(year);
                    gotoXY(80, 15);
                    cin >> month;
                    Dob.setMonth(month);
                    gotoXY(80, 17);
                    cin >> day;
                    Dob.setDay(day);
                    if (Dob.getYear() > D.now().getYear() || Dob.getYear() < 1900 || Dob.getMonth() < 1 || Dob.getMonth() > 12)
                    {
                        kt = false;
                        gotoXY(70, 19);
                        cout << "Sai du lieu !!!" << endl;
                        cin.get();
                    }
                    else if (leapYearu(Dob.getYear()) == true && Dob.getDay() >= 1 && Dob.getDay() <= nummonthplusu[Dob.getMonth()])
                    {
                        kt = true;
                    }
                    else if (leapYearu(Dob.getYear()) == false && Dob.getDay() >= 1 && Dob.getDay() <= nummonthu[Dob.getMonth()])
                    {
                        kt = true;
                    }
                    else
                    {
                        kt = false;
                        gotoXY(70, 19);
                        cout << "Sai du lieu !!!" << endl;
                        cin.get();
                    }
                    if (kt)
                    {
                        S = P->getData();
                        S.setDateOfBirth(Dob);
                        P->setData(S);
                        gotoXY(70, 19);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 13:
                    box(55, 10, 50, 10, 11, 1);
                    gotoXY(60, 14);
                    cout << "So dien thoai hien tai:   " << P->getData().getPhone();
                    gotoXY(60, 16);
                    cout << "So dien thoai moi:";
                    gotoXY(85, 16);
                    Phone = limit(85, 16, 20);
                    if (Phone.empty() == false)
                    {
                        S = P->getData();
                        S.setPhone(Phone);
                        P->setData(S);
                        gotoXY(70, 18);
                        cout << "Thay doi thanh cong !!!" << endl;
                        cin.get();
                    }
                    else
                    {
                        gotoXY(70, 18);
                        cout << "Khong the rong !!!" << endl;
                        cin.get();
                    }
                    break;
                case 15:
                    check2 = false;
                    break;
                case 17:
                    check = false;
                    check2 = false;
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            gotoXY(55, 4);
            cout << "Ma so nguoi dung nay khong ton tai !!!" << endl;
            cin.get();
        }
        gotoXY(55, 4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc................!!!" << endl;
        char c = _getch();
        if (c == 27)
        {
            return;
        }
    }
}

void Admin::statistic(LinkedList<Book>* lbook, LinkedList<User>* luser)
{
    int Sosach = 0;
    int Sosachmuon = 0;
    int Sosachkhongcon = 0;
    box(30, 10, 70, 2, 11, 1, "                  THONG KE SO LIEU TRONG THU VIEN");
    box(30, 12, 35, 2, 11, 1, "          THONG KE SACH");
    box(65, 12, 35, 2, 11, 1, "       THONG KE NGUOI DUNG");
    box(30, 14, 35, 8, 11, 1);
    box(65, 14, 35, 8, 11, 1);
    gotoXY(30, 12); cout << char(195);
    gotoXY(65, 12); cout << char(194);
    gotoXY(100, 12); cout << char(180);
    gotoXY(30, 14); cout << char(195);
    gotoXY(65, 14); cout << char(197);
    gotoXY(100, 14); cout << char(180);
    gotoXY(65, 22); cout << char(193);
    gotoXY(31, 15); cout << "So dau sach:" << lbook->getCount();
    for (Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext())
    {
        Sosach += P->getData().getFixedAmount();
        Sosachmuon += P->getData().getAmount();
        if (P->getData().getAmount() == 0)
        {
            Sosachkhongcon += 1;
        }
    }
    gotoXY(31, 17); cout << "Tong so quyen sach: " << Sosach;
    gotoXY(31, 19); cout << "Tong so sach da cho muon:" << Sosach - Sosachmuon;
    gotoXY(31, 21); cout << "Tong so sach da het:" << Sosachkhongcon;
    gotoXY(66, 18); cout << "Tong nguoi dung:" << luser->getCount();
}