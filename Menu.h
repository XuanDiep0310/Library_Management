#pragma once

class Menu {
public:
    void showAdminMenu();  // Hiển thị các chức năng dành cho Admin.
    void showUserMenu();   // Hiển thị các chức năng dành cho người dùng thường.
    void handleLogin();    // Xử lý quá trình đăng nhập cho cả Admin và người dùng.
    void displayPassword(bool show); // Hiển thị hoặc che giấu mật khẩu khi đăng nhập.
    // Other methods...
};