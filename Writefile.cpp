#include "Writefile.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

void writrfileuser(linkedlist<User>* luser)
{
    ofstream ip("C:\\Users\\XuanDiep\\Documents\\LibManagement\\x64\\Debug\\Sinhvien.txt");
    ofstream ip4("C:\\Users\\XuanDiep\\Documents\\LibManagement\\x64\\Debug\\Borrow.txt");
    ofstream ip5("C:\\Users\\XuanDiep\\Documents\\LibManagement\\x64\\Debug\\Request.txt");
    for (node<User>* P = luser->getHead(); P != NULL; P = P->getNext())
    {
        ip << P->getData().getID();
        ip << ",";
        ip << P->getData().getName();
        ip << ",";
        ip << P->getData().getDob();
        ip << ",";
        ip << P->getData().getPhone();
        ip << ",";
        ip << P->getData().getUn();
        ip << ",";
        ip << P->getData().getPw();
        ip << "\n";
        ip4 << P->getData().getID();
        ip4 << ",";
        ip4 << P->getData().getNumborrow();
        ip4 << ",";
        ip4 << P->getData().getBorrow(4).IDborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(3).IDborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(2).IDborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(1).IDborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(0).IDborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(4).Dayborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(3).Dayborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(2).Dayborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(1).Dayborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(0).Dayborrow;
        ip4 << ",";
        ip4 << P->getData().getBorrow(4).Dayexpiry;
        ip4 << ",";
        ip4 << P->getData().getBorrow(3).Dayexpiry;
        ip4 << ",";
        ip4 << P->getData().getBorrow(2).Dayexpiry;
        ip4 << ",";
        ip4 << P->getData().getBorrow(1).Dayexpiry;
        ip4 << ",";
        ip4 << P->getData().getBorrow(0).Dayexpiry;
        ip4 << "\n";
        ip5 << P->getData().getID();
        ip5 << ",";
        ip5 << P->getData().getNumrequest();
        ip5 << ",";
        ip5 << P->getData().getRequest(4).IDrequest;
        ip5 << ",";
        ip5 << P->getData().getRequest(3).IDrequest;
        ip5 << ",";
        ip5 << P->getData().getRequest(2).IDrequest;
        ip5 << ",";
        ip5 << P->getData().getRequest(1).IDrequest;
        ip5 << ",";
        ip5 << P->getData().getRequest(0).IDrequest;
        ip5 << ",";
        ip5 << P->getData().getRequest(4).Accept;
        ip5 << ",";
        ip5 << P->getData().getRequest(3).Accept;
        ip5 << ",";
        ip5 << P->getData().getRequest(2).Accept;
        ip5 << ",";
        ip5 << P->getData().getRequest(1).Accept;
        ip5 << ",";
        ip5 << P->getData().getRequest(0).Accept;
        ip5 << "\n";
    }
    ip.close();
    ip4.close();
    ip5.close();
}

void writrfilebook(linkedlist<Book>* lbook)
{
    ofstream ip1("C:\\Users\\XuanDiep\\Documents\\LibManagement\\x64\\Debug\\Book.txt");
    for (node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext())
    {
        ip1 << P->getData().getID();
        ip1 << ",";
        ip1 << P->getData().getName();
        ip1 << ",";
        ip1 << P->getData().getCategory();
        ip1 << ",";
        ip1 << P->getData().getPublisher();
        ip1 << ",";
        ip1 << P->getData().getYear();
        ip1 << ",";
        ip1 << P->getData().getAuthor();
        ip1 << ",";
        ip1 << P->getData().getfixedAmount();
        ip1 << ",";
        ip1 << P->getData().getAmount();
        ip1 << ",";
        ip1 << P->getData().getlocation();
        ip1 << "\n";
    }
    ip1.close();
}

void writefiledata(int money, int time)
{
    ofstream ip3("C:\\Users\\XuanDiep\\Documents\\LibManagement\\x64\\Debug\\data.txt");
    ip3 << money;
    ip3 << "\n";
    ip3 << time;
    ip3 << "\n";
    ip3.close();
}
