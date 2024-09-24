#pragma once
#include "Header.h"
#include "Book.h"

class User {
protected:
    string id;                    // Ma Dinh Danh Cua Nguoi Dung
    string name;                  // Ten Nguoi Dung
    string accountName;           // Ten Tai Khoan Dang Nhap Cua Nguoi Dung
    string password;              // Mat Khau Nguoi Dung
    vector<Book> borrowedBooks;   // Danh sách sách mà người dùng đang mượn.
    vector<Book> requestedBooks;  // Danh sách sách mà người dùng đã yêu cầu mượn.
    bool isAdmin;                 // Biến để xác định người dùng có phải là Admin không.
public:
    bool login(string id, string password);  // Kiểm tra thông tin đăng nhập của người dùng.
    void viewBorrowedBooks();                // Hiển thị danh sách sách đang mượn.
    void requestBook(Book book);             // Yêu cầu mượn một cuốn sách.
    void cancelRequest(Book book);           // Hủy yêu cầu mượn sách.
};