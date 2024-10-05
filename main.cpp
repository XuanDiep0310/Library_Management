#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Access.h"
#include "PrintFrame.h"
#define TRUE 1
using namespace std;


int menudong(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            gotoXY(xcu,ycu);
            if(ycu == 16) lightbar(xcu,ycu,30,2,1,"          Dang nhap");
            if(ycu == 18) lightbar(xcu,ycu,30,2,1,"            Thoat");
            xcu = xp;
            ycu = yp;
            if(yp == 16) lightbar(xp,yp,30,2,75,"          Dang nhap");
            if(yp == 18) lightbar(xp,yp,30,2,75,"            Thoat");
            kt = false;
        }
        if(_kbhit()) 
        {
            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 72 && yp != 16) 
                {
                    kt = true;
                    yp -= 2;
                } else if(c == 72 && yp == 16) 
                {
                    kt = true;
                    yp = 18;
                } else if(c == 80  && yp != 18)
                {
                    kt = true;
                    yp += 2;
                } else if(c == 80  && yp == 18)
                {
                    kt = true;
                    yp = 16;
                } 
            }
            else if(c == 13 ) 
                {
                    kt = false;
                    return yp;
                }
        }   
    }
}

int main() 
{
    ShowCur(0);
    List l = readFileData();
    l.setLBook(docFileBook());
    l.setLUser(readFileUser()); 
    // SetConsoleTitle("Quan ly thu vien");
    while(TRUE) 
    {
        system("cls");
        box(49,14,30,2,11,1,"    THU VIEN DHBK DA NANG");
        box(49,16,30,2,11,1,"          Dang nhap");
        gotoXY(49,16); cout << char(195);
        gotoXY(79,16); cout << char(180);
        box(49,18,30,2,11,1,"            Thoat");
        gotoXY(49,18); cout << char(195);
        gotoXY(79,18); cout << char(180); 
        int check = menudong(49,16,49,16,true);              
        switch(check) 
        {
            case 16 :
                l = dangnhap(l);
                break;
            case 18 :
                writrFileBook(l.lbook());
                writrFileUser(l.luser());
                writeFileData(l.getMoney(),l.getTime());
                return 0;
        }                    
    }
    cin.get();
    return 0;
}