#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookId;        // Mã định danh của sách.
    string title;         // Tiêu đề của sách.
    string author;        // Tên tác giả.
    string genre;         // Thể loại sách.
    int totalCopies;      // Tổng số bản sao của sách.
    int availableCopies;  // Số lượng sách còn lại có thể cho mượn.
public:
    string getDetails();  // Lấy thông tin chi tiết của sách.
    bool isAvailable();   // Kiểm tra sách có sẵn để mượn hay không.
    // Other methods...
    //Hàm của em Hoàng thêm vào
    bool matchesCriteria(const std::string& criteria) const {
        return (bookId.find(criteria) != std::string::npos || 
                title.find(criteria) != std::string::npos || 
                author.find(criteria) != std::string::npos || 
                genre.find(criteria) != std::string::npos);
    }
};