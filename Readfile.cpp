#include "Readfile.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "user.h"
#include "Book.h"
#include "Node.h"
#include "Person.h"
#include "admin.h"
#define EXIT_FAILURE 1
using namespace std;

linkedlist<User>* readfileuser()
{
    linkedlist<User>* luser = new linkedlist<User>();
    ifstream ip("Data\\Sinhvien.txt");
    ifstream ip4("Data\\Borrow.txt");
    ifstream ip5("Data\\Request.txt");
    if (!ip)
    {
        cout << "Co loi khi mo file : Sinhvien.txt " << endl;
        exit(EXIT_FAILURE);
    }
    if (!ip4)
    {
        cout << "Co loi khi mo file : Borrow.txt " << endl;
        exit(EXIT_FAILURE);
    }
    if (!ip5)
    {
        cout << "Co loi khi mo file : Request.txt " << endl;
        exit(EXIT_FAILURE);
    }
    string IDuser;
    string UserName;
    string dob;
    string phone;
    string un;
    string pw;
    string numborrow;
    string IDborow[5];
    string dayborrow[5];
    string dayexpiry[5];
    string numrequest;
    string idrequest[5];
    string accept[5];
    while (ip.peek() != EOF && ip4.peek() != EOF && ip5.peek() != EOF)
    {
        getline(ip, IDuser, ',');
        getline(ip, UserName, ',');
        getline(ip, dob, ',');
        getline(ip, phone, ',');
        getline(ip, un, ',');
        getline(ip, pw, '\n');
        getline(ip4, IDuser, ',');
        getline(ip4, numborrow, ',');
        getline(ip4, IDborow[4], ',');
        getline(ip4, IDborow[3], ',');
        getline(ip4, IDborow[2], ',');
        getline(ip4, IDborow[1], ',');
        getline(ip4, IDborow[0], ',');
        getline(ip4, dayborrow[4], ',');
        getline(ip4, dayborrow[3], ',');
        getline(ip4, dayborrow[2], ',');
        getline(ip4, dayborrow[1], ',');
        getline(ip4, dayborrow[0], ',');
        getline(ip4, dayexpiry[4], ',');
        getline(ip4, dayexpiry[3], ',');
        getline(ip4, dayexpiry[2], ',');
        getline(ip4, dayexpiry[1], ',');
        getline(ip4, dayexpiry[0], '\n');
        getline(ip5, IDuser, ',');
        getline(ip5, numrequest, ',');
        getline(ip5, idrequest[4], ',');
        getline(ip5, idrequest[3], ',');
        getline(ip5, idrequest[2], ',');
        getline(ip5, idrequest[1], ',');
        getline(ip5, idrequest[0], ',');
        getline(ip5, accept[4], ',');
        getline(ip5, accept[3], ',');
        getline(ip5, accept[2], ',');
        getline(ip5, accept[1], ',');
        getline(ip5, accept[0], '\n');
        Date D(dob);
        User user;
        user.setID(IDuser);
        user.setName(UserName);
        user.setDob(D);
        user.setPhone(phone);
        user.setUn(un);
        user.setPw(pw);
        int Numborrow = stoi(numborrow);
        Date Db4(dayborrow[4]);
        Date Db3(dayborrow[3]);
        Date Db2(dayborrow[2]);
        Date Db1(dayborrow[1]);
        Date Db0(dayborrow[0]);
        Date De4(dayexpiry[4]);
        Date De3(dayexpiry[3]);
        Date De2(dayexpiry[2]);
        Date De1(dayexpiry[1]);
        Date De0(dayexpiry[0]);
        user.setNumborrow(Numborrow);
        user.setBorrow(IDborow[4], Db4, De4, 4);
        user.setBorrow(IDborow[3], Db3, De3, 3);
        user.setBorrow(IDborow[2], Db2, De2, 2);
        user.setBorrow(IDborow[1], Db1, De1, 1);
        user.setBorrow(IDborow[0], Db0, De0, 0);
        int Numrequest = stoi(numrequest);
        int Accept[5];
        Accept[4] = stoi(accept[4]);
        Accept[3] = stoi(accept[3]);
        Accept[2] = stoi(accept[2]);
        Accept[1] = stoi(accept[1]);
        Accept[0] = stoi(accept[0]);
        user.setNumRequest(Numrequest);
        user.setRequest(idrequest[4], Accept[4], 4);
        user.setRequest(idrequest[3], Accept[3], 3);
        user.setRequest(idrequest[2], Accept[2], 2);
        user.setRequest(idrequest[1], Accept[1], 1);
        user.setRequest(idrequest[0], Accept[0], 0);
        luser->addTail(user);
    }
    ip.close();
    ip4.close();
    ip5.close();
    return luser;
}

linkedlist<Book>* docfilebook()
{
    linkedlist<Book>* lbook = new linkedlist<Book>();
    Book book;
    ifstream ip2("Data\\Book.txt");
    if (!ip2)
    {
        cout << "Co loi khi mo file : Book.txt " << endl;
        exit(EXIT_FAILURE);
    }
    string ID;
    string BookName;
    string Category;
    string Publisher;
    string year;
    string Author;
    string amount;
    string fixedamount;
    string location;
    while (ip2.peek() != EOF)
    {

        getline(ip2, ID, ',');
        getline(ip2, BookName, ',');
        getline(ip2, Category, ',');
        getline(ip2, Publisher, ',');
        getline(ip2, year, ',');
        getline(ip2, Author, ',');
        getline(ip2, fixedamount, ',');
        getline(ip2, amount, ',');
        getline(ip2, location, '\n');
        int Year = stoi(year);
        int Amount = stoi(amount);
        int fixedAmount = stoi(fixedamount);
        book.setID(ID);
        book.setName(BookName);
        book.setCategory(Category);
        book.setPublisher(Publisher);
        book.setYear(Year);
        book.setAuthor(Author);
        book.setfixedAmount(fixedAmount);
        book.setAmount(Amount);
        book.setlocation(location);
        lbook->addTail(book);
    }
    ip2.close();
    return lbook;
}

list readfiledata()
{
    ifstream ip3("Data\\data.txt");
    list l;
    if (!ip3)
    {
        cout << "Co loi khi mo file : data.txt " << endl;
        exit(EXIT_FAILURE);
    }
    string time;
    string money;
    while (ip3.peek() != EOF)
    {
        getline(ip3, money, '\n');
        getline(ip3, time, '\n');
        int Time = stoi(time);
        int Money = stoi(money);
        l.settime(Time);
        l.setmoney(Money);
    }
    ip3.close();
    return l;
}
