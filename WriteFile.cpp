#include "WriteFile.h"

using namespace std;

void writrFileUser(LinkedList<User>* luser) 
{
    ofstream ip("E:\\Sinhvien.txt");
    ofstream ip4("E:\\Borrow.txt");
    ofstream ip5("E:\\Request.txt");
    for(Node<User>* P = luser->getHead(); P != NULL; P = P->getNext()) 
    {
      ip << P->getData().getId();
      ip << ",";
      ip << P->getData().getName();
      ip << ",";
      ip << P->getData().getDateOfBirth();
      ip << ",";
      ip << P->getData().getPhone();
      ip << ",";
      ip << P->getData().getUsername();
      ip << ",";
      ip << P->getData().getPassword();
      ip << "\n";
      ip4 << P->getData().getId();
      ip4<< ",";
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
      ip5 << P->getData().getId();
      ip5 << ",";
      ip5 << P->getData().getNumrequest();
      ip5 << ",";
      ip5 << P->getData().getRequest(4).idRequest;
      ip5 << ",";
      ip5 << P->getData().getRequest(3).idRequest;
      ip5 << ",";
      ip5 << P->getData().getRequest(2).idRequest;
      ip5 << ",";
      ip5 << P->getData().getRequest(1).idRequest;
      ip5 << ",";
      ip5 << P->getData().getRequest(0).idRequest;
      ip5 << ",";
      ip5 << P->getData().getRequest(4).accept;
      ip5 << ",";
      ip5 << P->getData().getRequest(3).accept;
      ip5 << ",";
      ip5 << P->getData().getRequest(2).accept;
      ip5 << ",";
      ip5 << P->getData().getRequest(1).accept;
      ip5 << ",";
      ip5 << P->getData().getRequest(0).accept;
      ip5 << "\n";
    }
    ip.close();
    ip4.close();
    ip5.close();
}

void writrFileBook(LinkedList<Book>* lbook) 
{
    ofstream ip1("E:\\Book.txt");
    for(Node<Book>* P = lbook->getHead(); P != NULL; P = P->getNext()) 
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
      ip1 << P->getData().getFixedAmount();
      ip1 << ",";
      ip1 << P->getData().getAmount();
      ip1 << ",";
      ip1 << P->getData().getLocation();
      ip1 << "\n";
    }
    ip1.close();
}

void writeFileData(int money,int time) 
{
      ofstream ip3("E:\\data.txt");
      ip3 << money;
      ip3 << "\n";
      ip3 << time;
      ip3 << "\n"; 
      ip3.close();
}