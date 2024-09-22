#pragma once
#include <iostream>
#include "User.h"
#include "Book.h"

class Admin : public User {
public:
    void addBook(Book book);                      // Thêm sách mới vào thư viện.
    void removeBook(string bookId);               // Xóa sách khỏi thư viện (chỉ xóa khi số lượng sách đủ).
    void updateBook(string bookId, Book newInfo); // Cập nhật thông tin của sách.
    void viewUsers();                             // Xem danh sách tất cả người dùng.
    void approveRequest(User user, Book book);    // Duyệt yêu cầu mượn sách của người dùng.
    void returnBook(User user, string bookId);    // Xử lý trả sách từ người dùng, kiểm tra số ngày quá hạn và tính phí phạt.
    void viewStatistics();                        // Xem thống kê về số lượng sách, số sách đã mượn, số người dùng, v.v.
    // Other methods...
};