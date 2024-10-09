#include "PrintFrame.h"


void box(int x, int y, int w, int h, int t_color, int b_color,string nd) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(7);
    gotoXY(x+1,y+1);
    cout << nd;
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        gotoXY(ix,y);
        cout << char(196);
        gotoXY(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        gotoXY(x,iy);
        cout << char(179);
        gotoXY(x+w,iy);
        cout << char(179);
    }
    gotoXY(x,y); cout << char(218);
    gotoXY(x+w,y); cout << char(191);
    gotoXY(x,y+h); cout << char(192);
    gotoXY(x+w,y+h); cout << char(217);
}

void box(int x, int y, int w, int h, int t_color, int b_color,int nd) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(7);
    gotoXY(x+1,y+1);
    cout << nd;
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        gotoXY(ix,y);
        cout << char(196);
        gotoXY(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        gotoXY(x,iy);
        cout << char(179);
        gotoXY(x+w,iy);
        cout << char(179);
    }
    gotoXY(x,y); cout << char(218);
    gotoXY(x+w,y); cout << char(191);
    gotoXY(x,y+h); cout << char(192);
    gotoXY(x+w,y+h); cout << char(217);
}

void box(int x, int y, int w, int h, int t_color, int b_color, int nd1, int nd2) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(7);
    gotoXY(x+1,y+1);
    cout << nd1 << "/" << nd2;
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        gotoXY(ix,y);
        cout << char(196);
        gotoXY(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        gotoXY(x,iy);
        cout << char(179);
        gotoXY(x+w,iy);
        cout << char(179);
    }
    gotoXY(x,y); cout << char(218);
    gotoXY(x+w,y); cout << char(191);
    gotoXY(x,y+h); cout << char(192);
    gotoXY(x+w,y+h); cout << char(217);
}

void box(int x, int y, int w, int h, int t_color, int b_color,Date nd) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(7);
    gotoXY(x+1,y+1);
    cout << nd;
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        gotoXY(ix,y);
        cout << char(196);
        gotoXY(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        gotoXY(x,iy);
        cout << char(179);
        gotoXY(x+w,iy);
        cout << char(179);
    }
    gotoXY(x,y); cout << char(218);
    gotoXY(x+w,y); cout << char(191);
    gotoXY(x,y+h); cout << char(192);
    gotoXY(x+w,y+h); cout << char(217);
}

void box(int x, int y, int w, int h, int t_color, int b_color) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        gotoXY(ix,y);
        cout << char(196);
        gotoXY(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        gotoXY(x,iy);
        cout << char(179);
        gotoXY(x+w,iy);
        cout << char(179);
    }
    gotoXY(x,y); cout << char(218);
    gotoXY(x+w,y); cout << char(191);
    gotoXY(x,y+h); cout << char(192);
    gotoXY(x+w,y+h); cout << char(217);
}

void lightbar(int x, int y, int w, int h, int b_color,string nd) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x+1,y+1);
    cout << nd;
    TextColor(1);
}

void lightbar(int x, int y, int w, int h, int b_color) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            gotoXY(ix,iy); cout << " ";
        }
    }
    TextColor(1);
}

string limit(int x, int y,int l) 
{
    char str1[1000];
    int n1,index1=0;
    do
    {    n1=getch();
        if (n1 != '\b' && n1 != 13 && index1 < l) 
        {
            gotoXY(x+index1,y);
            cout <<char(n1);
            str1[index1++]=n1;
        }
        else if (n1=='\b' && index1>0)
        {
            cout <<"\b \b";
            str1[--index1]= 0;
        }
    }
    while (n1!=13);
    str1[index1]=0;
    string str(str1);
    return str;
}
