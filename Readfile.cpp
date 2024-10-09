#include "ReadFile.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "user.h"
#include "Book.h"
#include "Person.h"
#include "admin.h"
#define EXIT_FAILURE 1
using namespace std;

LinkedList<User> *readFileUser()
{
  LinkedList<User> *luser = new LinkedList<User>();
  ifstream ip("E:\\Sinhvien.txt");
  ifstream ip4("E:\\Borrow.txt");
  ifstream ip5("E:\\Request.txt");
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
  string idUser;
  string userName;
  string dateOfBirth;
  string phone;
  string un;
  string pw;
  string numborrow;
  string idBorow[5];
  string dayBorrow[5];
  string dayExpiry[5];
  string numRequest;
  string idRequest[5];
  string accept[5];
  while (ip.peek() != EOF && ip4.peek() != EOF && ip5.peek() != EOF)
  {
    getline(ip, idUser, ',');
    getline(ip, userName, ',');
    getline(ip, dateOfBirth, ',');
    getline(ip, phone, ',');
    getline(ip, un, ',');
    getline(ip, pw, '\n');
    getline(ip4, IdUser, ',');
    getline(ip4, numborrow, ',');
    getline(ip4, idBorow[4], ',');
    getline(ip4, idBorow[3], ',');
    getline(ip4, idBorow[2], ',');
    getline(ip4, idBorow[1], ',');
    getline(ip4, idBorow[0], ',');
    getline(ip4, dayBorrow[4], ',');
    getline(ip4, dayBorrow[3], ',');
    getline(ip4, dayBorrow[2], ',');
    getline(ip4, dayBorrow[1], ',');
    getline(ip4, dayBorrow[0], ',');
    getline(ip4, dayExpiry[4], ',');
    getline(ip4, dayExpiry[3], ',');
    getline(ip4, dayExpiry[2], ',');
    getline(ip4, dayExpiry[1], ',');
    getline(ip4, dayExpiry[0], '\n');
    getline(ip5, idUser, ',');
    getline(ip5, numRequest, ',');
    getline(ip5, idRequest[4], ',');
    getline(ip5, idRequest[3], ',');
    getline(ip5, idRequest[2], ',');
    getline(ip5, idRequest[1], ',');
    getline(ip5, idRequest[0], ',');
    getline(ip5, accept[4], ',');
    getline(ip5, accept[3], ',');
    getline(ip5, accept[2], ',');
    getline(ip5, accept[1], ',');
    getline(ip5, accept[0], '\n');
    Date D(dateOfBirth);
    User user;
    user.setId(idUser);
    user.setName(userName);
    user.setDayOfBirth(D);
    
    user.setPhone(phone);
    user.setUsername(un);
    user.setPassword(pw);
    int Numborrow = stoi(numborrow);
    Date Db4(dayBorrow[4]);
    Date Db3(dayBorrow[3]);
    Date Db2(dayBorrow[2]);
    Date Db1(dayBorrow[1]);
    Date Db0(dayBorrow[0]);
    Date De4(dayExpiry[4]);
    Date De3(dayExpiry[3]);
    Date De2(dayExpiry[2]);
    Date De1(dayExpiry[1]);
    Date De0(dayExpiry[0]);
    user.setNumborrow(Numborrow);
    user.setBorrow(idBorow[4], Db4, De4, 4);
    user.setBorrow(idBorow[3], Db3, De3, 3);
    user.setBorrow(idBorow[2], Db2, De2, 2);
    user.setBorrow(idBorow[1], Db1, De1, 1);
    user.setBorrow(idBorow[0], Db0, De0, 0);
    int Numrequest = stoi(numrequest);
    int Accept[5];
    Accept[4] = stoi(accept[4]);
    Accept[3] = stoi(accept[3]);
    Accept[2] = stoi(accept[2]);
    Accept[1] = stoi(accept[1]);
    Accept[0] = stoi(accept[0]);
    user.setNumRequest(Numrequest);
    user.setRequest(idRequest[4], Accept[4], 4);
    user.setRequest(idRequest[3], Accept[3], 3);
    user.setRequest(idRequest[2], Accept[2], 2);
    user.setRequest(idRequest[1], Accept[1], 1);
    user.setRequest(idRequest[0], Accept[0], 0);
    luser->addTail(user);
  }
  ip.close();
  ip4.close();
  ip5.close();
  return luser;
}

LinkedList<Book> *docFileBook()
{
  LinkedList<Book> *lbook = new LinkedList<Book>();
  Book book;
  ifstream ip2("E:\\Book.txt");
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
    book.setFixedAmount(fixedAmount);
    book.setAmount(Amount);
    book.setLocation(location);
    lbook->addTail(book);
  }
  ip2.close();
  return lbook;
}

List readfileData()
{
  ifstream ip3("E:\\data.txt");
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
    l.setTime(Time);
    l.setMoney(Money);
  }
  ip3.close();
  return l;
}
