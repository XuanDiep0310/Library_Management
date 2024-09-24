#pragma once
#include "Account.h"
#include <conio.h> // Thu vien su dung _getch()

// Hàm đăng kí thông tin nguòi dùng
bool Account::registerUser(const string &fileName, const string &name, const string &password)
{
    ofstream file(fileName, ios::app); //
    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
        return false;
    }
    file << name << " " << password << 0 << endl;
    file.close();
    return true;
}
// Hàm kiểm tra xem tên người dùng đã tồn tại chưa
bool Account::checkUsername(const string &username)
{
    ifstream file("Account/accounts.txt");
    if (!file.is_open())
    {
        cout << "Unable to open file to check user" << endl;
        return false;
    }
    string name;
    while (file >> name)
    {
        if (name == username)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
// Tạo tài khoản
void Account::registerAccout()
{
    string username, password;
    cout << "Dang Ki: " << endl;
    do
    {
        cout << "Nhap Ten Tai Khoan: ";
        cin >> username;
        if (checkUsername(username))
        {
            cout << "Ten Tai Khoan Da Ton Tai!" << endl;
            cout << "Ban Co Muon Nhap Lai Khong (Y/N): ";
            char s;
            cin >> s;
            if (s == 'N' || s == 'n')
                exit(0); // Thoat Chuong Trinh
            system("cls");
            cout << "Dang Ki: " << endl;
        }
    } while (checkUsername(username));
    this->username = username;

    // Nhap Password
    
    cout << "Nhap Mat Khau: ";
    this->password = inputPassword(password);
    // Xac Nhan lai Mk
    int n = 5;
    int ok = 0;
    while (n--)
    {
        string password_check;
        if (!ok)
        {
            cout << "Ban co muon xem mat khau khong (Y/N): ";
        }
        char c;
        cin >> c;
        ok = (c == 'Y' || c == 'y');
        system("cls");
        cout << "Dang Ki: " << endl;
        cout << "Nhap Ten Tai Khoan: " << this->username << endl;
        if (ok)
        {
            cout << "Nhap Mat Khau: " << this->password << endl;
        }
        else
        {
            cout << "Nhap Mat Khau: ";
            for (int i = 0; i < this->password.size(); ++i)
                cout << '*';
            cout << endl;
        }
        cout << "Xac Nhan Lai Mat Khau: ";
        password_check = inputPassword(password_check);
        if (password_check == this->password)
            break;
        else
        {
            if (n == 0)
                exit(0); // Nhap qua 5 lan
            system("cls");
            cout << "Dang Ki: " << endl;
            cout << "Nhap Ten Tai Khoan: " << this->username << endl;
            if (ok)
            {
                cout << "Nhap Mat Khau: " << this->password << endl;
            }
            else
            {
                cout << "Nhap Mat Khau: ";
                for (int i = 0; i < this->password.size(); ++i)
                    cout << '*';
                cout << endl;
            }
        }
    }
    if (registerUser("Account/accounts.txt", this->username, this->password))
    {
        cout << "Dang Ki Thanh Cong" << endl;
    }
    else
        cout << "Dang Ki That Bai" << endl;
}

// Ham Dang Nhap
void Account::login()
{
    

}
// check Dang nhap Dung hay không
bool Account::checkLogin(const string &fileName, const string &username, const string &password)
{

    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "\033[31m" << "Unable to open file" << "\033[0m" << endl;
        return false;
    }

    string username_ok, password_ok;
    while (file >> username_ok >> password_ok)
    {
        if (username_ok == username && password_ok == password)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
// Nhap password bi che boi '*'
string inputPassword(string &password)
{
    char c;
    while ((c = _getch()) != '\r') // '\r': ky tu Enter
    {
        if (c == '\b') // '\b' : ky tu Backspace
        {
            if (password.size())
                password.pop_back();
            cout << '\b' << '\b';
        }
        else
        {
            password += c;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}
