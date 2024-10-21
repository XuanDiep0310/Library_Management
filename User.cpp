#include "User.h"
#include "Person.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
HANDLE color2;
User us;
fstream fp3;

User::User()
{

}

int User::retId()const
{
    return Person::getId();
}

void User::show_user() //show user
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    Person::display();
    cout << "Class: " << clas << endl;
    cout << "Book renting: " << rentBook << endl;
}

void User::add_user() //menu add user
{
    User us1;
    char null[1] = { '\x00' };
loop:
    cout << "----------------New user-----------------" << endl;
    cin.ignore();
    do
    {
        cout << "Enter username: ";
        cin.getline(username, 15);
    } while (strlen(username) < 1);
    fstream File;
    File.open("user.dat", ios::binary | ios::in | ios::out);
    while (!File.eof())
    {
        File.read(reinterpret_cast<char*> (&us1), sizeof(User));
        if (strcmp(us1.retUsername(), username) == 0)
        {
            cout << "This ID already exists!" << endl;
            system("pause");
            system("cls");
            goto loop;
        }
    }
    File.close();
    do
    {
        cout << "Enter password: ";
        cin.getline(password, 20);
    } while (strlen(password) < 1);
    Person::input();
    do
    {
        cout << "Enter class: ";
        cin.getline(clas, 15);
    } while (strlen(clas) < 1);
    status = 0;
    strcpy_s(rentBook, sizeof(rentBook), null);
    format();
}

void User::update_user() //update user in file
{
    system("cls");
    fstream File;
    bool found = false;
    int n;
    string s;

    cout << "---------------UPDATE USER----------------" << endl;
    cout << "Enter id of user update: ";
    cin >> n;
    while (n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
    cout << "Enter username of user update: ";
    cin >> s;

    File.open("user.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&us), sizeof(User));
        if (us.retId() == n && us.retUsername() == s)
        {
            cout << "\n\n[CURRENT DATA]" << endl;
            us.show_user();
            system("pause");
            cout << endl << endl;
            cout << "---Enter The New Details of User---" << endl;
            us.add_user();
            int pos = (-1) * static_cast<int>(sizeof(User));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&us), sizeof(User));
            cout << "Update Successfully !!";
            system("pause");
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        cout << "Record Not Found ";
        system("pause");
    }
}

void User::delete_user() // delete user in file
{
    system("cls");
    int n;
    string s;
    cout << "----------------DELETE USER----------------" << endl;
    cout << "Enter id of user delete: ";
    cin >> n;
    while (n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
    cout << "Enter username of user detele: ";
    cin >> s;
    ifstream inFile;
    ofstream outFile;
    inFile.open("user.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&us), sizeof(User)))
    {
        if (us.retUsername() != s && us.retId() != n)
        {
            outFile.write(reinterpret_cast<char*> (&us), sizeof(User));
        }
    }
    inFile.close();
    outFile.close();
    remove("user.dat");
    rename("Temp.dat", "user.dat");
    cout << "Delete Successfully" << endl;
    system("pause");
}

void User::search_user() // search user in file
{
    int n;
    string s;
    bool found = false;
    fstream File;
    system("cls");
    cout << "---------------Search User With ID-------------" << endl;
    cout << "Enter id of user: ";
    cin >> n;
    while (n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
    cout << "Enter username of user: ";
    cin >> s;
    File.open("user.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&us), sizeof(User));
        if (us.retUsername() == s && us.retId() == n)
        {
            system("cls");
            us.show_user();
            system("pause");
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "Record Not Found " << endl;
    system("pause");
}
// save file
void User::write_user()
{
    vector<User> users;  // Tạo một vector để lưu tất cả sách
    User newUser;

    // Đọc tất cả các cuốn sách hiện có từ file vào vector
    ifstream inFile("user.dat", ios::binary);
    if (inFile.is_open()) {
        User temp;
        while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(User))) {
            users.push_back(temp);
        }
        inFile.close();
    }

    // Thêm sách mới vào
    newUser.add_user();
    users.push_back(newUser);

    // Sắp xếp sách theo ID
    std::sort(users.begin(), users.end(), compareById);

    // Ghi đè lại file với danh sách sách đã sắp xếp
    ofstream outFile("book.dat", ios::binary | ios::trunc);  // Sử dụng ios::trunc để xóa nội dung file cũ
    for (const auto& book : users) {
        outFile.write(reinterpret_cast<const char*>(&book), sizeof(users));
    }
    outFile.close();

    // Thông báo thêm sách thành công
    cout << ".---------------------------------------.\n";
    cout << "|        Add User Successfully !        |\n";
    cout << "'---------------------------------------'\n";
    system("pause");
    system("cls");
    outFile.close();
}

bool User::updateUserRent(char s[]) //rent book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    bool found = false;
    cout << "Enter username of you (username as registered): ";
    cin.getline(tempName, 50);
    cout << "Enter password of you: ";
    cin.getline(tempPass, 50);

    File.open("user.dat", ios::binary | ios::in | ios::out);
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(User));
        if (strcmp(tempName, retUsername()) == 0 && strcmp(tempPass, retPassword()) == 0)
        {
            if (status == 1)
            {
                return false;
            }
            else
            {
                *username = *retUsername();
                *password = *retPassword();
                Person::setValueDefaut();
                for (int i = 0; i < strlen(s); i++)
                {
                    rentBook[i] = s[i];
                }
                *clas = *retClass();
                status = 1;
                int pos = (-1) * static_cast<int>(sizeof(User));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*> (this), sizeof(User));
                return true;
            }
        }
    }
    File.close();
    return false;
}
bool User::updateUserReturn(char s[]) // return book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    char null[1] = { '\x00' };
    bool found = false;

    cout << "Enter username of you (username as registered): ";
    cin.getline(tempName, 50);
    cout << "Enter password of you: ";
    cin.getline(tempPass, 50);

    File.open("user.dat", ios::binary | ios::in | ios::out);
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(User));
        if (strcmp(tempName, retUsername()) == 0 && strcmp(tempPass, retPassword()) == 0)
        {
            if (status == 0)
            {
                return false;
            }
            else
            {
                *username = *retUsername();
                *password = *retPassword();
                Person::setValueDefaut();
                strcpy_s(rentBook, sizeof(rentBook), null);
                *clas = *retClass();
                status = 0;
                int pos = (-1) * static_cast<int>(sizeof(User));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*> (this), sizeof(User));
                return true;
            }
        }
    }
    File.close();
    return false;
}


void User::report()
{
    // In thông tin User với định dạng hợp lý hơn
    cout << left << setw(20) << username  // Username có độ rộng 15
        << left << setw(20) << password; // Password có độ rộng 15

    // Gọi hàm Person::report() để in thông tin Person
    Person::report();

    // In các thông tin khác của User
    cout << left << setw(12) << clas       // Class có độ rộng 10
        << left << setw(15) << status      // Status có độ rộng 5
        << left << setw(20) << rentBook   // Rent Book có độ rộng 20
        << endl;  // Xuống dòng sau khi in hết các cột của bản ghi
}

void User::display()
{
    system("cls");  // Xóa màn hình
    fp3.open("user.dat", ios::in);  // Mở file để đọc
    color2 = GetStdHandle(STD_OUTPUT_HANDLE);

    // Đặt màu đỏ cho tiêu đề
    SetConsoleTextAttribute(color2, 12);
    cout << "\t\t\t\t\t\t\t\t\tUser LIST" << endl;
    cout << "============================================================================================================================================================\n";

    // In tiêu đề cột
    cout << left << setw(20) << "Username"
        << left << setw(20) << "Password"
        << left << setw(10) << "ID"
        << left << setw(20) << "Name"
        << left << setw(5) << "Age"
        << left << setw(35) << "Mail"
        << left << setw(10) << "Class"
        << left << setw(10) << "Status"
        << left << setw(20) << "Rent Book" << endl;

    cout << "============================================================================================================================================================\n";

    // Đặt màu vàng cho dữ liệu
    SetConsoleTextAttribute(color2, 14);

    // Đọc và hiển thị từng bản ghi từ file
    while (fp3.read(reinterpret_cast<char*>(&us), sizeof(User)))
    {
        us.report();  // Hàm report() hiển thị thông tin của đối tượng User
    }

    fp3.close();  // Đóng file sau khi đọc xong
    _getch();  // Đợi người dùng nhấn phím để tiếp tục
}

char* User::retUsername()
{
    return username;
}

char* User::retPassword()
{
    return password;
}

char* User::retClass()
{
    return clas;
}

void User::format()
{
    char* s;
    s = General::format(clas);
}

User::~User()
{
    //dtor
}
