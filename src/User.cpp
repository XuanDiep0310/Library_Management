#include "User.h"
#include "General.h"
#include "Person.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
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

User::User() : rentedBookCount(0)
{

}

int User::retId()const
{
    return Person::getId();
}

void User::show_user() // show user
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    Person::display();
    cout << "Class: " << clas << endl;

    // Hiển thị danh sách sách đã thuê
    cout << "Books rented: ";
    if (rentedBooks.empty()) {
        cout << "None" << endl; // Nếu không có sách nào
    }
    else {
        for (const auto& bookId : rentedBooks) {
            cout << bookId << " "; // Hiển thị từng sách
        }
        cout << endl; // Xuống dòng sau khi in danh sách
    }

    cout << "Number of books rented: " << rentedBooks.size() << endl; // Hiển thị số lượng sách đã thuê
}

void User::add_user() // menu add user
{
    User us1;
    string line;

loop:
    cout << "----------------New user-----------------" << endl;
    cin.ignore();
    do
    {
        cout << "Enter username: ";
        cin.getline(username, sizeof(username));
    } while (strlen(username) < 1);

    // Mở file với chế độ đọc
    fstream File("user.txt", ios::in | ios::out | ios::app);
    if (!File) {
        cout << "Could not open user.txt!" << endl;
        return; // Nếu không mở được file, thoát hàm
    }

    // Kiểm tra trùng username
    while (getline(File, line))
    {
        istringstream iss(line);
        string existingUsername;
        // Giả định username là trường đầu tiên trong dòng
        iss >> existingUsername;
        if (existingUsername == username)
        {
            cout << "This username already exists!" << endl;
            system("pause");
            system("cls");
            File.clear(); // Reset trạng thái của file
            File.close(); // Đóng file trước khi tiếp tục
            goto loop;
        }
    }

    // Đến đây, username chưa tồn tại
    File.clear(); // Reset trạng thái của file
    File.seekp(0, ios::end); // Đặt con trỏ ghi ở cuối file

    do
    {
        cout << "Enter password: ";
        cin.getline(password, sizeof(password));
    } while (strlen(password) < 1);

    Person::input(); // Giả sử hàm này nhập các thông tin cho Person
    do {
        cout << "Enter class: ";
        getline(cin, clas);  // Đọc dữ liệu vào biến clas
    } while (clas.empty());  // Kiểm tra nếu clas trống

    rentedBookCount = 0;
    rentedBooks.clear(); // Đảm bảo vector sách đã mượn được khởi tạo trống

    // Ghi thông tin người dùng vào file
    File << username << " " << password << " " << clas << " "
        << rentedBookCount << " "; // Ghi số lượng sách đã mượn

    // Ghi danh sách sách đã mượn
    for (const auto& book : rentedBooks) {
        File << book << " "; // Ghi từng sách trong vector
    }
    File << endl; // Kết thúc dòng

    File.close(); // Đừng quên đóng file
}

void User::update_user() // update user in file
{
    system("cls");
    fstream File;
    bool found = false;
    int n;
    string s, line;

    cout << "---------------UPDATE USER----------------" << endl;
    cout << "Enter id of user to update: ";
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
    cout << "Enter username of user to update: ";
    cin >> s;

    // Mở file với chế độ đọc và ghi
    File.open("user.txt", ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened!! Press any key...";
        return;
    }

    // Tạo một tệp tạm để lưu thông tin người dùng đã cập nhật
    fstream tempFile("temp.txt", ios::out);

    while (getline(File, line)
        && !found) // Đọc từng dòng từ file
    {
        istringstream iss(line);
        string existingUsername;
        int existingId;
        iss >> existingUsername >> existingId; // Giả định ID là trường thứ hai trong dòng

        // Kiểm tra xem ID và username có khớp không
        if (existingId == n && existingUsername == s)
        {
            cout << "\n\n[CURRENT DATA]" << endl;
            // Chuyển đổi dòng thành đối tượng User (nếu cần)
            // Bạn có thể viết một hàm để phân tích dòng và cập nhật thuộc tính cho đối tượng User
            us.show_user(); // Hiển thị thông tin hiện tại
            system("pause");
            cout << endl << endl;
            cout << "---Enter The New Details of User---" << endl;
            us.add_user(); // Nhập thông tin mới

            // Ghi thông tin người dùng đã cập nhật vào tệp tạm
            tempFile << us.retUsername() << " " << us.retId() << " "
                << us.retClass() << " " << us.rentedBookCount << " ";

            // Ghi sách đã mượn từ vector
            for (const auto& book : us.rentedBooks) {
                tempFile << book << " "; // Ghi từng sách trong vector
            }
            tempFile << endl; // Kết thúc dòng

            cout << "Update Successfully !!";
            system("pause");
            found = true;
        }
        else
        {
            // Nếu không khớp, ghi lại dòng gốc vào tệp tạm
            tempFile << line << endl;
        }
    }

    File.close();
    tempFile.close();

    // Xóa file cũ và đổi tên file tạm thành file gốc
    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (!found)
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
    cout << "Enter id of user to delete: ";
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
    cout << "Enter username of user to delete: ";
    cin >> s;

    ifstream inFile("user.txt");
    if (!inFile)
    {
        cout << "File could not be opened!! Press any key...";
        return;
    }

    // Tạo tệp tạm để lưu thông tin không bị xóa
    ofstream outFile("temp.txt");
    bool deleted = false; // Cờ kiểm tra xem có xóa được người dùng hay không

    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string existingUsername;
        int existingId;

        // Giả định ID là trường thứ hai trong dòng
        iss >> existingUsername >> existingId;

        // Nếu không khớp, ghi lại vào tệp tạm
        if (existingUsername != s || existingId != n)
        {
            outFile << line << endl; // Ghi lại dòng vào tệp tạm
        }
        else
        {
            deleted = true; // Đánh dấu là đã xóa người dùng
        }
    }

    inFile.close();
    outFile.close();

    // Xóa file cũ và đổi tên file tạm thành file gốc
    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (deleted)
    {
        cout << "Delete Successfully" << endl;
    }
    else
    {
        cout << "User not found." << endl;
    }

    system("pause");
}

void User::search_user() // search user by name (case-insensitive)
{
    string s;
    bool found = false;
    ifstream File("user.txt"); // Mở file txt để đọc
    char ch;
    vector<string> suggestions;

    if (!File)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }

    while (true) {
        system("cls");  // Xóa màn hình trên mỗi lần nhập ký tự
        Sleep(100);     // Thêm độ trễ 100ms để giảm độ nhấp nháy màn hình

        cout << "              ._____________________.\n";
        cout << "--------------| Search User By Name |------------" << endl;
        cout << "              '---------------------'\n";
        cout << "Enter username of user: " << s << endl;

        // Bước 1: Thu thập gợi ý
        suggestions.clear();
        File.clear();  // Reset trạng thái file
        File.seekg(0); // Quay lại đầu file

        string line;
        while (getline(File, line))
        {
            istringstream iss(line);
            string existingUsername;
            int existingId; // Giả định rằng ID là trường thứ hai

            // Đọc username và ID từ dòng
            iss >> existingUsername >> existingId;

            // Chuyển username thành chữ thường để so sánh không phân biệt chữ hoa chữ thường
            std::transform(existingUsername.begin(), existingUsername.end(), existingUsername.begin(), ::tolower);

            // Kiểm tra xem username hiện tại có chứa chuỗi nhập vào không
            if (existingUsername.find(s) != string::npos)
            {
                suggestions.push_back(existingUsername);
            }
        }

        // Bước 2: Hiển thị gợi ý nếu tìm thấy
        if (!suggestions.empty()) {
            cout << "\nSuggestions:\n";
            for (const string& suggestion : suggestions) {
                cout << " - " << suggestion << endl;
            }
        }
        else {
            cout << ".____________________________________________.\n";
            cout << "| No suggestions found for entered characters |\n";
            cout << "'--------------------------------------------'\n";
        }

        // Bước 3: Lấy ký tự tiếp theo từ người dùng
        ch = _getch(); // Lấy ký tự nhập vào mà không cần nhấn Enter
        if (ch == '\r') // Nếu nhấn Enter, dừng lại
            break;
        else if (ch == '\b' && !s.empty()) // Xử lý phím backspace
            s.pop_back();
        else if (isalnum(ch) || isspace(ch)) // Thêm ký tự vào chuỗi tìm kiếm
            s += ch;
    }

    // Bước 4: Tìm kiếm bản ghi khớp chính xác
    string line;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    found = false;
    File.clear();  // Reset trạng thái file
    File.seekg(0); // Quay lại đầu file
    while (getline(File, line) && !found)
    {
        istringstream iss(line);
        string existingUsername;
        int existingId;

        // Đọc username và ID từ dòng
        iss >> existingUsername >> existingId;
        std::transform(existingUsername.begin(), existingUsername.end(), existingUsername.begin(), ::tolower);

        if (existingUsername == s)
        {
            system("cls");
            // Hiển thị thông tin người dùng
            cout << "User ID: " << existingId << endl;
            cout << "Username: " << existingUsername << endl;
            // Có thể gọi us.show_user() nếu muốn hiển thị thêm thông tin từ đối tượng User
            system("pause");
            found = true;
        }
    }

    File.close();

    if (!found)
    {
        cout << ".__________________.\n";
        cout << "| Record Not Found |\n";
        cout << "'------------------'\n";
    }

    system("pause");
}

string User::getRentedBooksAsString() const {
    stringstream ss;
    for (const auto& book : rentedBooks) {
        ss << book << ","; // Concatenate each book followed by a comma
    }
    string result = ss.str();
    if (!result.empty()) {
        result.pop_back(); // Remove the last comma
    }
    return result;
}

// save file
void User::write_user() {
    vector<User> users;  // Vector to store all users
    User newUser;

    // Read all existing users from the text file into the vector
    ifstream inFile("user.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string username, password, clas;
            int rentedBookCount;
            string rentedBooks;

            // Read data from the line
            iss >> username >> password >> clas >> rentedBookCount;
            getline(iss, rentedBooks); // Read the remaining rented books

            // Initialize User from the read data
            User user;
            user.setUsername(username);
            user.setPassword(password);
            user.setClass(clas);
            user.setRentedBookCount(rentedBookCount);

            // Assuming rentedBooks is a comma-separated string
            stringstream rentedBooksStream(rentedBooks);
            string book;
            while (getline(rentedBooksStream, book, ',')) {
                user.rentedBooks.push_back(book); // Add each rented book to the user's vector
            }

            users.push_back(user);
        }
        inFile.close();
    }

    // Add a new user
    newUser.add_user(); // This should populate newUser's details
    users.push_back(newUser);

    // Sort users by ID
    std::sort(users.begin(), users.end(), compareById);

    // Write back to the text file with the updated user list
    ofstream outFile("user.txt", ios::trunc); // Use ios::trunc to clear the old content
    for (const auto& user : users) {
        outFile << user.retUsername() << " "
            << user.retPassword() << " "
            << user.retClass() << " "
            << user.retRentedBookCount() << " "
            << user.getRentedBooksAsString() << endl; // Convert rentedBooks vector to string
    }
    outFile.close();

    // Notify successful addition of the user
    cout << ".---------------------------------------.\n";
    cout << "|        Add User Successfully !        |\n";
    cout << "'---------------------------------------'\n";
    system("pause");
    system("cls");
}

bool User::updateUserRent(char s[]) // rent book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    bool found = false;

    cout << "Enter your username (username as registered): ";
    cin.getline(tempName, sizeof(tempName));
    cout << "Enter your password: ";
    cin.getline(tempPass, sizeof(tempPass));

    // Open the text file for reading and writing
    File.open("user.txt", ios::in | ios::out);
    if (!File) {
        cout << "Could not open user.txt!" << endl;
        return false; // Check if the file opened successfully
    }

    vector<User> users;
    string line;

    // Read all users from the file into a vector
    while (getline(File, line)) {
        istringstream iss(line);
        User user;
        string username, password, clas, rentedBooks;
        int rentedBookCount;

        // Read data from the line
        if (iss >> username >> password >> clas >> rentedBookCount) {
            // Read rented books as a single string
            getline(iss, rentedBooks);
            user.setUsername(username);
            user.setPassword(password);
            user.setClass(clas);
            user.setRentedBookCount(rentedBookCount);

            // Convert rentedBooks string into a vector
            istringstream rentedBooksStream(rentedBooks);
            string book;
            while (getline(rentedBooksStream, book, ',')) {
                user.rentedBooks.push_back(book);
            }

            users.push_back(user);
        }
    }

    // Search for the user and update rented books
    for (auto& user : users) {
        if (strcmp(tempName, user.retUsername().c_str()) == 0 && strcmp(tempPass, user.retPassword().c_str()) == 0) {
            if (user.retRentedBookCount() <= 0) {
                cout << "No books available to rent." << endl;
                return false; // No books to rent
            }
            else {
                // Add the rented book to the user's list
                user.rentedBooks.push_back(s);
                user.setRentedBookCount(user.retRentedBookCount() + 1); // Increment the rented book count
                found = true;
                break; // User found and updated
            }
        }
    }

    // If user was found, overwrite the file
    if (found) {
        File.close(); // Close the current file before writing

        // Reopen the file to write updated data
        File.open("user.txt", ios::out | ios::trunc);
        for (const auto& user : users) {
            File << user.retUsername() << " "
                << user.retPassword() << " "
                << user.retClass() << " "
                << user.retRentedBookCount() << " "
                << user.getRentedBooksAsString() << endl; // Convert rentedBooks vector to string
        }
        File.close();

        cout << "Book rented successfully!" << endl;
        return true;
    }

    File.close();
    cout << "User not found." << endl;
    return false; // User not found
}

bool User::updateUserReturn(char s[]) // return book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    bool found = false;

    cout << "Enter your username (username as registered): ";
    cin.getline(tempName, sizeof(tempName));
    cout << "Enter your password: ";
    cin.getline(tempPass, sizeof(tempPass));

    // Open the text file for reading and writing
    File.open("user.txt", ios::in | ios::out);
    if (!File) {
        cout << "Could not open user.txt!" << endl;
        return false; // Check if the file opened successfully
    }

    vector<User> users;
    string line;

    // Read all users from the file into a vector
    while (getline(File, line)) {
        istringstream iss(line);
        User user;
        string username, password, clas, rentedBooks;
        int rentedBookCount;

        // Read data from the line
        if (iss >> username >> password >> clas >> rentedBookCount) {
            // Read rented books as a single string
            getline(iss, rentedBooks);
            user.setUsername(username);
            user.setPassword(password);
            user.setClass(clas);
            user.setRentedBookCount(rentedBookCount);

            // Convert rentedBooks string into a vector
            istringstream rentedBooksStream(rentedBooks);
            string book;
            while (getline(rentedBooksStream, book, ',')) {
                user.rentedBooks.push_back(book);
            }

            users.push_back(user);
        }
    }

    // Search for the user and update rented books
    for (auto& user : users) {
        if (strcmp(tempName, user.retUsername().c_str()) == 0 && strcmp(tempPass, user.retPassword().c_str()) == 0) {
            if (user.retRentedBookCount() <= 0) {
                cout << "No books to return." << endl;
                return false; // No books to return
            }
            else {
                // Remove the book from the user's rented books
                auto it = find(user.rentedBooks.begin(), user.rentedBooks.end(), s);
                if (it != user.rentedBooks.end()) {
                    user.rentedBooks.erase(it); // Remove the book from the vector
                    user.setRentedBookCount(user.retRentedBookCount() - 1); // Decrement the rented book count
                }
                else {
                    cout << "This book is not rented by you." << endl;
                    return false; // The book was not found in the rented books
                }
                found = true;
                break; // User found and updated
            }
        }
    }

    // If user was found, overwrite the file
    if (found) {
        File.close(); // Close the current file before writing

        // Reopen the file to write updated data
        File.open("user.txt", ios::out | ios::trunc);
        for (const auto& user : users) {
            File << user.retUsername() << " "
                << user.retPassword() << " "
                << user.retClass() << " "
                << user.retRentedBookCount() << " "
                << user.getRentedBooksAsString() << endl; // Convert rentedBooks vector to string
        }
        File.close();

        cout << "Book returned successfully!" << endl;
        return true;
    }

    File.close();
    cout << "User not found." << endl;
    return false; // User not found
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
        << left << setw(20) << rentedBookCount   // Rent Book có độ rộng 20
        << endl;  // Xuống dòng sau khi in hết các cột của bản ghi
}

void User::display()
{
    system("cls");  // Clear the screen
    ifstream fp3("user.txt");  // Open file for reading
    HANDLE color2 = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set red color for the title
    SetConsoleTextAttribute(color2, 12);
    cout << "\t\t\t\t\t\t\t\t\tUser LIST" << endl;
    cout << "============================================================================================================================================================\n";

    // Print column headers
    cout << left << setw(20) << "Username"
        << left << setw(20) << "Password"
        << left << setw(10) << "ID"
        << left << setw(20) << "Name"
        << left << setw(5) << "Age"
        << left << setw(35) << "Mail"
        << left << setw(10) << "Class"
        << left << setw(20) << "Rent Book" << endl;

    cout << "============================================================================================================================================================\n";

    // Set yellow color for data
    SetConsoleTextAttribute(color2, 14);

    // Read and display each record from the file
    string line;
    while (getline(fp3, line)) {
        istringstream iss(line);
        User us;
        string username, password, clas, name, mail, rentedBooks;
        int age, id, rentedBookCount;

        // Read data from the line
        if (iss >> username >> password >> id >> name >> age >> mail >> clas >> rentedBookCount) {
            // Read the rented books as a single string
            getline(iss, rentedBooks);

            // Set user data (assuming the setter methods are defined)
            us.setUsername(username);
            us.setPassword(password);
            us.setClass(clas);
            us.setRentedBookCount(rentedBookCount);
            // Here you can set name, age, mail, and rentedBooks similarly if needed

            // Display user information (customize as needed)
            cout << left << setw(20) << us.retUsername()
                << left << setw(20) << us.retPassword()
                << left << setw(10) << us.retId()
                << left << setw(20) << name  // Assuming you have a method to get the name
                << left << setw(5) << age    // Assuming you have a method to get the age
                << left << setw(35) << mail   // Assuming you have a method to get the mail
                << left << setw(10) << us.retClass()
                << left << setw(20) << rentedBooks << endl;  // Print rented books
        }
    }

    fp3.close();  // Close the file after reading
    system("pause");  // Wait for user to press a key
}

string User::retUsername() const
{
    return username;
}

string User::retPassword() const
{
    return password;
}

string User::retClass() const
{
    return clas;
}

void User::format() {
    clas = General::format(clas);  // Call to General's format method
}

void User::setUsername(const string& username) {
    strncpy_s(this->username, username.c_str(), sizeof(this->username) - 1);
    this->username[sizeof(this->username) - 1] = '\0'; // Ensure null termination
}

void User::setPassword(const string& password) {
    strncpy_s(this->password, password.c_str(), sizeof(this->password) - 1);
    this->password[sizeof(this->password) - 1] = '\0'; // Ensure null termination
}

void User::setClass(const string& clas) {
    this->clas = clas;
}

void User::setRentedBookCount(int count) {
    this->rentedBookCount = count;
}

// Optional: If you want to allow setting rentedBooks directly
void User::setRentedBooks(const vector<string>& rentedBooks) {
    this->rentedBooks = rentedBooks;
}

int User::retRentedBookCount() const {
    return rentedBookCount; // Or whatever logic you want
}


User::~User()
{
    //dtor
}
