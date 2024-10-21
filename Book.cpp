#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Dohoa.h"

using namespace std;
HANDLE color1;
Book::Book()
{

}

// write file
fstream fp, fp1;
Book bk;


void Book::addBook() //menu add book
{
loop:
    char null[1] = { '\x00' };
    system("cls");
    cout << "             .__________.\n";
    cout << "||-----------| New Book |-----------||" << endl;
    cout << "             '----------'\n";
    cout << "Enter id (> 0 and < 9999999): ";
    cin >> id;
    while (!cin.good() || id < 0 || id > 9999999)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter id(> 0 and < 9999999): ";
        cin >> id;
    }
    cin.ignore(256, '\n');
    fstream File;
    Book bk1;
    File.open("book.dat", ios::binary | ios::in | ios::out);
    while (!File.eof())
    {
        File.read(reinterpret_cast<char*> (&bk1), sizeof(Book));
        if (bk1.retId() == id)
        {
            cout << ".----------------------------.\n";
            cout << "|  This ID already exists!   |" << endl;
            cout << "'----------------------------'\n";
            system("pause");
            goto loop;
        }
    }
    File.close();
    fflush(stdin);
    do
    {
        cout << "Enter book name:";
        cin.getline(name, 50);
    } while (strlen(name) < 1);
    do
    {
        cout << "Enter book brand: ";
        cin.getline(brand, 50);
    } while (strlen(brand) < 1);
    do
    {
        cout << "Enter book author: ";
        cin.getline(author, 50);
    } while (strlen(author) < 1);
    cout << "Enter quantity (> 0): ";
    cin >> quantity;
    while (!cin.good() || quantity <= 0)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid quantity. Enter quantity (> 0): ";
        cin >> quantity;
    }
    cin.ignore(256, '\n');
    strcpy_s(rentUser, sizeof(rentUser), null);
    format();
}

void Book::updateBook() //update book with id and name in file
{
    system("cls");
    fstream File;
    bool found = false;
    int n;
    string s;

    cout << "              ._____________.\n";
    cout << "--------------| Update Book |---------------" << endl;
    cout << "              '-------------'\n";
    cout << "Enter id of book update: ";
    cin >> n;
    while (n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << ".--------------------------------------------.\n";
        cout << "|  Error: Invalid Choice. Please try again!  |\n";
        cout << "'--------------------------------------------'\n";
        system("pause");
        system("cls");
        cout << "Enter id of book: ";
        cin >> n;
    }
    cin.ignore();
    cout << "Enter name of book update: ";
    getline(cin, s);
    system("cls");
    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << ".----------------------------------------------.\n";
        cout << "|  File could not be open !! Press any Key...  |\n";
        cout << "'----------------------------------------------'\n";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&bk), sizeof(Book));
        if (bk.retId() == n && bk.retName() == s)
        {
            cout << "[ CURRENT DATA ]" << endl;
            bk.showBook();
            system("pause");
            cout << endl << endl;;
            cout << "Enter The New Details of Book: " << endl;
            system("pause");
            bk.addBook();
            int pos = (-1) * static_cast<int>(sizeof(Book));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&bk), sizeof(Book));
            cout << ".________________________.\n";
            cout << "| Update Successfully !! |\n";
            cout << "'------------------------'\n";
            found = true;
            system("pause");
        }
    }
    File.close();
    if (found == false) {
        cout << ".________________________.\n";
        cout << "|  Record Not Found !!   |\n";
        cout << "'------------------------'\n";
    }
    system("pause");
}

void Book::deleteBook() //delete book with id and name in file
{
    system("cls");
    int n;
    string s;

    cout << "               ._____________.\n";
    cout << "---------------| DELETE BOOK |---------------" << endl;
    cout << "               '-------------'\n";
    cout << "Enter id of book delete: ";
    cin >> n;
    while (n < 0 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << ".------------------------------------------------.\n";
        cout << "|    Error: Invalid Choice. Please try again!    |\n";
        cout << "'------------------------------------------------'\n";
        system("pause");
        system("cls");
        cout << "Enter id of book delete: ";
        cin >> n;
    }
    cin.ignore();
    cout << "Enter name of book delete: ";
    getline(cin, s);

    ifstream inFile;
    ofstream outFile;
    inFile.open("book.dat", ios::binary);
    if (!inFile)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&bk), sizeof(Book)))
    {
        if (bk.retId() != n && bk.retName() != s)
        {
            outFile.write(reinterpret_cast<char*> (&bk), sizeof(Book));
        }
    }
    inFile.close();
    outFile.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    cout << ".-----------------------------------.\n";
    cout << "|       Delete Successfully         |\n";
    cout << "'-----------------------------------'\n";
    system("pause");
}

#include <algorithm> // For std::transform and std::tolower
#include <string>

void Book::searchBook() // search book by name (case-insensitive)
{
    string s;
    bool found = false;
    fstream File;
    system("cls");

    cout << "              ._____________________.\n";
    cout << "--------------| Search Book |------------" << endl;
    cout << "              '---------------------'\n";
    cin.ignore();
    cout << "Enter name of book: ";
    getline(cin, s);

    // Convert the search string to lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }

    while (File.read(reinterpret_cast<char*>(&bk), sizeof(Book)) && !found)
    {
        string bookName = bk.retName();

        // Convert the book name to lowercase for case-insensitive comparison
        std::transform(bookName.begin(), bookName.end(), bookName.begin(), ::tolower);

        if (bookName == s)
        {
            system("cls");
            bk.showBook();  // Display book details
            system("pause");
            found = true;
        }
    }

    File.close();

    if (!found)
    {
        cout << ".__________________.\n";
        cout << "| Record Not Found |\n";
        cout << "'------------------'\n";
    }

    system("pause");
}


void Book::showBook() // menu show book
{
    cout << "          .___________.\n";
    cout << "----------| Show book |----------" << endl;
    cout << "          '-----------'\n";
    cout << "---------------------------------\n";
    cout << "Book ID: " << id << endl;
    cout << "Book name: " << name << endl;
    cout << "Book brand: " << brand << endl;
    cout << "Book author: " << author << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "User renting: " << rentUser << endl;
}

void Book::wirteBook() // save book in file
{
    vector<Book> books;  // Tạo một vector để lưu tất cả sách
    Book newBook;

    // Đọc tất cả các cuốn sách hiện có từ file vào vector
    ifstream inFile("book.dat", ios::binary);
    if (inFile.is_open()) {
        Book temp;
        while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Book))) {
            books.push_back(temp);
        }
        inFile.close();
    }

    // Thêm sách mới vào
    newBook.addBook();
    books.push_back(newBook);

    // Sắp xếp sách theo ID
    std::sort(books.begin(), books.end(), compareById);

    // Ghi đè lại file với danh sách sách đã sắp xếp
    ofstream outFile("book.dat", ios::binary | ios::trunc);  // Sử dụng ios::trunc để xóa nội dung file cũ
    for (const auto& book : books) {
        outFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    outFile.close();

    // Thông báo thêm sách thành công
    cout << ".---------------------------------------.\n";
    cout << "|        Add Book Successfully !        |\n";
    cout << "'---------------------------------------'\n";
    system("pause");
    system("cls");
    outFile.close();
}
void Book::display()  //display book in screen
{
    ifstream inFile;
    inFile.open("book.dat", ios::binary);
    if (!inFile)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }
    //Dohoa::setColor(2);
    color1 = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color1, 12);
    cout << "\t\t\t\tBook LIST" << endl;
    cout << "====================================================================================\n";
    cout << left << setw(10) << "Book ID" << left << setw(25) << "Book Name" << left << setw(15) << "Book brand" << left << setw(20) << "Book Author" << left << setw(2) << "\tQuantity" << left << setw(20) << endl;
    cout << "====================================================================================\n";
    SetConsoleTextAttribute(color1, 14);
    while (inFile.read(reinterpret_cast<char*>(&bk), sizeof(Book)))
    {
        bk.report();
    }
    fp.close();
    _getch();
}
bool Book::updateRentBook(char s[]) //rent book
{
    User us;
    fstream File;
    bool found = false;

    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "Could not open the file!" << endl;
        return false;
    }

    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(Book));
        if (strcmp(s, retName()) == 0)
        {
            if (quantity == 0)
            {
                return false;
            }
            else
            {
                if (us.updateUserRent(s) == true)
                {
                    id = retId();
                    *name = *retName();
                    *brand = *retBrand();
                    *author = *retAuthor();
                    strcpy_s(rentUser, sizeof(rentUser), us.retUsername());
                    quantity -= 1;
                    int pos = (-1) * static_cast<int>(sizeof(Book));
                    File.seekp(pos, ios::cur);
                    File.write(reinterpret_cast<char*> (this), sizeof(Book));
                    found = true;
                    return true;
                }
                return false;
            }
        }
    }
    File.close();
    return false;
}
bool Book::updateBookReturn(char s[]) //return book
{
    User us;
    fstream File;
    bool found = false;
    char null[1] = { '\x00' };

    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "Could not open the file!" << endl;
        return false;
    }

    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(Book));
        if (strcmp(s, retName()) == 0)
        {
            if (quantity == 0)
            {
                return false;
            }
            else
            {
                if (us.updateUserReturn(s) == true)
                {
                    strcpy_s(rentUser, sizeof(rentUser), null);
                    quantity += 1;
                    //update file sau khi xoá người mượn
                    int pos = (-1) * static_cast<int>(sizeof(Book));
                    File.seekp(pos, ios::cur);
                    File.write(reinterpret_cast<char*> (this), sizeof(Book));
                    found = true;
                    return true;
                }
                return false;
            }
        }
    }
    File.close();
    return false;
}

int Book::retId() // return id in class
{
    return id;
}

char* Book::retName() //return name in class
{
    return name;
}
char* Book::retBrand()
{
    return brand;
}

char* Book::retAuthor()
{
    return author;
}
char* Book::retRentUser()
{
    return rentUser;
}

int Book::retQuantity()
{
    return quantity;
}

void Book::format() // format data
{
    char* s;
    s = General::format(name);
    s = General::format(brand);
    s = General::format(author);
}

void Book::report() // show book
{
    cout << left << setw(10) << id
        << left << setw(25) << name
        << left << setw(15) << brand
        << left << setw(25) << author
        << left << setw(10) << quantity   // Hiển thị số lượng sách
        << endl;
}

Book::~Book()
{
    //dtor
}
