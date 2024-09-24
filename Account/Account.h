#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Account
{
private:
    string username, password;
    bool isAdmin = 0;
public:

    // Tạo tài khoản
    void registerAccout();

    // Hàm đăng kí thông tin nguòi dùng (Thêm vào file)
    bool registerUser(const string& fileName,const string& name, const string& password);

    // Hàm kiểm tra tên tài khoản có tồn tại hay không
    bool checkUsername (const string& username);
    // 
    bool setRegisterAccount(const string &username, const string &password);

    // Ham Menu Dang Nhap
    void login();
    // check Dang nhap Dung hay không
    bool checkLogin(const string& fileName,const string& username, const string& password);
};

string inputPassword(string &password);