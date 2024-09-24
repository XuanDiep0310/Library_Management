#pragma once
#include <iostream>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "LinkedList.h"

class Library {
private:
    LinkedList<Book> books; // Danh sách liên kết chứa tất cả sách trong thư viện.
    LinkedList<User> users; // Danh sách liên kết chứa tất cả người dùng đã đăng ký.
public:
    Library() {
        loadBooks();
        loadUsers();
    }
    ~Library() {

    }
    void loadBooks();  // Tải danh sách sách từ file hoặc khởi tạo dữ liệu mặc định.
    void loadUsers();  // Tải danh sách người dùng từ file hoặc khởi tạo dữ liệu mặc định.
    void searchBook(const std::string& criteria); // Tìm sách theo tiêu chí như ID, tiêu đề, tác giả, hoặc thể loại.
    void displayBooks();  // Hiển thị danh sách tất cả các sách.
    void displayAvailableBooks(); // Hiển thị danh sách các sách còn có thể mượn.
    // Other methods...
};

void Library::loadBooks() {
    std::ifstream file("books.txt");
    if(file.is_open()) {
        // Tải sách từ file
        // while (file >> bookData) {books.add(new Book(bookData));}
    } else {
        std::cout << "Không thể mở file Sách! Khởi tạo sách mặc định. \n";
        // Thêm sách mặc định vào danh sách 'Books'
    }
    file.close();
}   

void Library::loadUsers() {
    // Xử lí file hoặc khởi tạo người dùng mặc định
    std::ifstream file("users.txt");
    if(file.is_open()) {
        // Tải người dùng từ file
        // while (file >> userData) {users.add(new User(userData));}
    } else {
        std::cout << "Không thể mở file người dùng! Khởi tạo người dùng mặc định. \n";
        // Thêm người dùng mặc định vào danh sách 'Users'
    }
    file.close();
}

void Library::searchBook(const std::string& criteria) {
    bool found = false;
    for(int i = 0; i < books.size(); i++) {
        Book currBook = books.getNode(i);
        if(currBook.matchesCriteria(criteria)) {
            std::cout << currBook.getDetails() << std::endl;
            found = true;
        }
    }
    
    if(!found) std::cout << "Không có kết quả trùng khớp với: " << criteria << std::endl;
}

void Library::displayBooks() {
    if(books.getSize() == 0) {
        std::cout << "Thư viện hiện không có sách.\n";
        return;
    }

    for (int i = 0; i < books.getSize(); ++i) {
        Book currBook = books.getNode(i);  
        std::cout << currBook.getDetails() << std::endl;  
        std::cout << "----------------------------------" << std::endl;
    }
}

void Library::displayAvailableBooks() {
    
}