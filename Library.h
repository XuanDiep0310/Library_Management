#pragma once
#include <iostream>
#include "Book.h"
#include "User.h"

class Library {
private:
    LinkedList<Book> books; // Danh sách liên kết chứa tất cả sách trong thư viện.
    LinkedList<User> users; // Danh sách liên kết chứa tất cả người dùng đã đăng ký.
public:
    void loadBooks();  // Tải danh sách sách từ file hoặc khởi tạo dữ liệu mặc định.
    void loadUsers();  // Tải danh sách người dùng từ file hoặc khởi tạo dữ liệu mặc định.
    void searchBook(string criteria, string value); // Tìm sách theo tiêu chí như ID, tiêu đề, tác giả, hoặc thể loại.
    void displayBooks();  // Hiển thị danh sách tất cả các sách.
    void displayAvailableBooks(); // Hiển thị danh sách các sách còn có thể mượn.
    // Other methods...
};
