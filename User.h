#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

class User {
protected:
    string id;                    // Mã định danh của người dùng.
    string name;                  // Mã định danh của người dùng.
    string password;              // Mật khẩu của người dùng
    vector<Book> borrowedBooks;   // Danh sách sách mà người dùng đang mượn.
    vector<Book> requestedBooks;  // Danh sách sách mà người dùng đã yêu cầu mượn.
    bool isAdmin;                 // Biến để xác định người dùng có phải là Admin không.
public:
    bool login(string id, string password);  // Kiểm tra thông tin đăng nhập của người dùng.
    void viewBorrowedBooks();                // Hiển thị danh sách sách đang mượn.
    void requestBook(Book book);             // Yêu cầu mượn một cuốn sách.
    void cancelRequest(Book book);           // Hủy yêu cầu mượn sách.
    // Other methods...
    //Test
};