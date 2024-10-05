#include "Person.h"
#include "PrintFrame.h"
#include <cstring>
#include <iostream>
using namespace std;
Person::Person() {

}

Person::Person(string username, string password) {
    this->username = username;
    this->password = password;
}

void Person::setUsername(string username) {
    this->username = username;
}

void Person::setPassword(string password) {
    this->password = password;
}

string Person::getUsername() {
    return username;
}

string Person::getPassword() {
    return password;
}

string chuhoa(string s) 
{
    for(int i = 0; i < s.length(); i++) 
    {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    return s;
}



void Person::displayAvailable(LinkedList<Book>* lbook) 
{
    system("cls");
    box(1,5,124,2,11,1,"**********************************************TOAN BO SACH CON TRONG THU VIEN***********************************************");
    box(1,7,11,2,11,1,"MA SO SACH");
    gotoXY(1,7); cout << char(195);
    box(12,7,25,2,11,1,"        TEN SACH");
    box(37,7,15,2,11,1,"   THE LOAI");
    box(52,7,20,2,11,1,"    NHA XUAT BAN");
    box(72,7,15,2,11,1," NAM XUAT BAN");
    box(87,7,20,2,11,1,"      TAC GIA");
    box(107,7,9,2,11,1," VI TRI");
    box(116,7,9,2,11,1,"SO LUONG");
    gotoXY(12,7); cout << char(194);
    gotoXY(12,9); cout << char(193);
    gotoXY(37,7); cout << char(194);
    gotoXY(37,9); cout << char(193);
    gotoXY(52,7); cout << char(194);
    gotoXY(52,9); cout << char(193);
    gotoXY(72,7); cout << char(194);
    gotoXY(72,9); cout << char(193);
    gotoXY(87,7); cout << char(194);
    gotoXY(87,9); cout << char(193);
    gotoXY(107,7); cout << char(194);
    gotoXY(107,9); cout << char(193);
    gotoXY(116,7); cout << char(194);
    gotoXY(116,9); cout << char(193);
    gotoXY(125,7); cout << char(180);
    lbook->printNextavailble();
    lbook->printNext();
    int i = lbook->getCount() * 2;
    gotoXY(12,9+i); cout << char(193);
    gotoXY(37,9+i); cout << char(193);
    gotoXY(52,9+i); cout << char(193);
    gotoXY(72,9+i); cout << char(193);
    gotoXY(87,9+i); cout << char(193);
    gotoXY(107,9+i); cout << char(193);
    gotoXY(116,9+i); cout << char(193);
    cin.get();   
}

void Person::displayBook(LinkedList<Book>* lbook) 
{
    system("cls");
    box(1,5,124,2,11,1,"************************************************TOAN BO SACH TRONG THU VIEN*************************************************");
    box(1,7,11,2,11,1,"MA SO SACH");
    gotoXY(1,7); cout << char(195);
    box(12,7,25,2,11,1,"        TEN SACH");
    box(37,7,15,2,11,1,"   THE LOAI");
    box(52,7,20,2,11,1,"    NHA XUAT BAN");
    box(72,7,15,2,11,1," NAM XUAT BAN");
    box(87,7,20,2,11,1,"      TAC GIA");
    box(107,7,9,2,11,1," VI TRI");
    box(116,7,9,2,11,1,"SO LUONG");
    gotoXY(12,7); cout << char(194);
    gotoXY(12,9); cout << char(193);
    gotoXY(37,7); cout << char(194);
    gotoXY(37,9); cout << char(193);
    gotoXY(52,7); cout << char(194);
    gotoXY(52,9); cout << char(193);
    gotoXY(72,7); cout << char(194);
    gotoXY(72,9); cout << char(193);
    gotoXY(87,7); cout << char(194);
    gotoXY(87,9); cout << char(193);
    gotoXY(107,7); cout << char(194);
    gotoXY(107,9); cout << char(193);
    gotoXY(116,7); cout << char(194);
    gotoXY(116,9); cout << char(193);
    gotoXY(125,7); cout << char(180);
    lbook->printNext();
    int i = lbook->getCount() * 2;
    gotoXY(12,9+i); cout << char(193);
    gotoXY(37,9+i); cout << char(193);
    gotoXY(52,9+i); cout << char(193);
    gotoXY(72,9+i); cout << char(193);
    gotoXY(87,9+i); cout << char(193);
    gotoXY(107,9+i); cout << char(193);
    gotoXY(116,9+i); cout << char(193);
    cin.get();
}

void Person::findBookName(LinkedList<Book>* lbook) 
{
    cin.ignore();
    while(true) 
    {
        system("cls");
        box(1,1,124,2,11,1,"***************************************************TIM KIEM THEO TEN SACH***************************************************");
        box(1,3,124,2,11,1,"Nhap ten sach can tim kiem : ");
        gotoXY(1,3); cout << char(195);
        gotoXY(125,3); cout << char(180);
        gotoXY(35,4);
        string bookname(limit(35,4,30));
        int c = 0;
        int i = 2;
        bool check = false;
        for(Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext()) 
        {
            string name = P->getData().getName();
            if(chuhoa(bookname) == chuhoa(name)) 
            {
                c = 1;
                box(1,5,124,2,11,1,"********************************************************SACH CAN TIM********************************************************");
                gotoXY(1,5); cout << char(195);
                gotoXY(125,5); cout << char(180);
                box(1,7,11,2,11,1,"MA SO SACH");
                gotoXY(1,7); cout << char(195);
                box(12,7,25,2,11,1,"        TEN SACH");
                box(37,7,15,2,11,1,"   THE LOAI");
                box(52,7,20,2,11,1,"    NHA XUAT BAN");
                box(72,7,15,2,11,1," NAM XUAT BAN");
                box(87,7,20,2,11,1,"      TAC GIA");
                box(107,7,9,2,11,1," VI TRI");
                box(116,7,9,2,11,1,"SO LUONG");
                gotoXY(12,7); cout << char(194);
                gotoXY(12,9); cout << char(193);
                gotoXY(37,7); cout << char(194);
                gotoXY(37,9); cout << char(193);
                gotoXY(52,7); cout << char(194);
                gotoXY(52,9); cout << char(193);
                gotoXY(72,7); cout << char(194);
                gotoXY(72,9); cout << char(193);
                gotoXY(87,7); cout << char(194);
                gotoXY(87,9); cout << char(193);
                gotoXY(107,7); cout << char(194);
                gotoXY(107,9); cout << char(193);
                gotoXY(116,7); cout << char(194);
                gotoXY(116,9); cout << char(193);
                gotoXY(125,7); cout << char(180);
                P->print(P,i,1);
                i += 2;
                check = true;
            }
        }
        if(check == true) 
        {
            gotoXY(12,9+i-2); cout << char(193);
            gotoXY(37,9+i-2); cout << char(193);
            gotoXY(52,9+i-2); cout << char(193);
            gotoXY(72,9+i-2); cout << char(193);
            gotoXY(87,9+i-2); cout << char(193);
            gotoXY(107,9+i-2); cout << char(193);
            gotoXY(116,9+i-2); cout << char(193);
        }
        cin.get();
        if( c == 0) 
        {
            gotoXY(65,4);
            cout << "Khong co sach nay trong thu vien !!!" << endl;
            cin.get();
        }
        gotoXY(65,4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc!!!" << endl;
        char key = _getch();
        if(key == 27) 
        {
            return;
        }
    }
}

void Person::findCategory(LinkedList<Book>* lbook) 
{
    cin.ignore();
    while(true) 
    {
        system("cls");
        box(1,1,124,2,11,1,"***************************************************TIM KIEM THEO THE LOAI***************************************************");
        box(1,3,124,2,11,1,"Nhap the loai can tim : ");
        gotoXY(1,3); cout << char(195);
        gotoXY(125,3); cout << char(180);
        gotoXY(30,4);
        string category(limit(30,4,30));
        int c = 0;
        int i = 2;
        bool check = false;
        for(Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext()) 
        {
            string Category = P->getData().getCategory();
            if(chuhoa(category) == chuhoa(Category)) 
            {
                if(c == 0) 
                {
                    box(1,5,124,2,11,1,"********************************************************SACH CAN TIM********************************************************");
                    gotoXY(1,5); cout << char(195);
                    gotoXY(125,5); cout << char(180);
                    box(1,7,11,2,11,1,"MA SO SACH");
                    gotoXY(1,7); cout << char(195);
                    box(12,7,25,2,11,1,"        TEN SACH");
                    box(37,7,15,2,11,1,"   THE LOAI");
                    box(52,7,20,2,11,1,"    NHA XUAT BAN");
                    box(72,7,15,2,11,1," NAM XUAT BAN");
                    box(87,7,20,2,11,1,"      TAC GIA");
                    box(107,7,9,2,11,1," VI TRI");
                    box(116,7,9,2,11,1,"SO LUONG");
                    gotoXY(12,7); cout << char(194);
                    gotoXY(12,9); cout << char(193);
                    gotoXY(37,7); cout << char(194);
                    gotoXY(37,9); cout << char(193);
                    gotoXY(52,7); cout << char(194);
                    gotoXY(52,9); cout << char(193);
                    gotoXY(72,7); cout << char(194);
                    gotoXY(72,9); cout << char(193);
                    gotoXY(87,7); cout << char(194);
                    gotoXY(87,9); cout << char(193);
                    gotoXY(107,7); cout << char(194);
                    gotoXY(107,9); cout << char(193);
                    gotoXY(116,7); cout << char(194);
                    gotoXY(116,9); cout << char(193);
                    gotoXY(125,7); cout << char(180);
                }
                c = 1;
                P->print(P,i,1);
                i += 2;
                check = true;
            }
        }
        if(check == true) 
        {
            gotoXY(12,9+i-2); cout << char(193);
            gotoXY(37,9+i-2); cout << char(193);
            gotoXY(52,9+i-2); cout << char(193);
            gotoXY(72,9+i-2); cout << char(193);
            gotoXY(87,9+i-2); cout << char(193);
            gotoXY(107,9+i-2); cout << char(193);
            gotoXY(116,9+i-2); cout << char(193);
        }
        cin.get();
        if( c == 0) 
        {
            gotoXY(65,4);
            cout << "Khong co the loai nay trong thu vien !!!" << endl;
            cin.get();
        }
        gotoXY(65,4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc!!!" << endl;
        char key = _getch();
        if(key == 27) 
        {
            return;
        }
    }
}

void Person::findAuthor(LinkedList<Book>* lbook) 
{
    cin.ignore();
    while(true) 
    {
        system("cls");
        box(1,1,124,2,11,1,"***************************************************TIM KIEM THEO TAC GIA***************************************************");
        box(1,3,124,2,11,1,"Nhap tac gia can tim : ");
        gotoXY(1,3); cout << char(195);
        gotoXY(125,3); cout << char(180);
        gotoXY(30,4);
        string author(limit(30,4,30));
        int c = 0;
        int i = 2;
        bool check = false;
        for(Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext()) 
        {
            string Author = P->getData().getAuthor();
            if(chuhoa(author) == chuhoa(Author)) 
            {
                if(c == 0) 
                {
                    box(1,5,124,2,11,1,"********************************************************SACH CAN TIM********************************************************");
                    gotoXY(1,5); cout << char(195);
                    gotoXY(125,5); cout << char(180);
                    box(1,7,11,2,11,1,"MA SO SACH");
                    gotoXY(1,7); cout << char(195);
                    box(12,7,25,2,11,1,"        TEN SACH");
                    box(37,7,15,2,11,1,"   THE LOAI");
                    box(52,7,20,2,11,1,"    NHA XUAT BAN");
                    box(72,7,15,2,11,1," NAM XUAT BAN");
                    box(87,7,20,2,11,1,"      TAC GIA");
                    box(107,7,9,2,11,1," VI TRI");
                    box(116,7,9,2,11,1,"SO LUONG");
                    gotoXY(12,7); cout << char(194);
                    gotoXY(12,9); cout << char(193);
                    gotoXY(37,7); cout << char(194);
                    gotoXY(37,9); cout << char(193);
                    gotoXY(52,7); cout << char(194);
                    gotoXY(52,9); cout << char(193);
                    gotoXY(72,7); cout << char(194);
                    gotoXY(72,9); cout << char(193);
                    gotoXY(87,7); cout << char(194);
                    gotoXY(87,9); cout << char(193);
                    gotoXY(107,7); cout << char(194);
                    gotoXY(107,9); cout << char(193);
                    gotoXY(116,7); cout << char(194);
                    gotoXY(116,9); cout << char(193);
                    gotoXY(125,7); cout << char(180);
                }
                c = 1;
                P->print(P,i,1);
                i += 2;
                check = true;
            }
        }
        if(check == true) 
        {
            gotoXY(12,9+i-2); cout << char(193);
            gotoXY(37,9+i-2); cout << char(193);
            gotoXY(52,9+i-2); cout << char(193);
            gotoXY(72,9+i-2); cout << char(193);
            gotoXY(87,9+i-2); cout << char(193);
            gotoXY(107,9+i-2); cout << char(193);
            gotoXY(116,9+i-2); cout << char(193);
        }
        cin.get();
        if( c == 0) 
        {
            gotoXY(65,4);
            cout << "Khong co tac gia nay trong thu vien !!!" << endl;
            cin.get();
        }
        gotoXY(65,4);
        cout << "Nhan [ESC] de thoat, nhan [ENTER] de tiep tuc!!!" << endl;
        char key = _getch();
        if(key == 27) 
        {
            return;
        }
    }
}