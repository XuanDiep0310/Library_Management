#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <limits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Dohoa.h"
#undef max
using namespace std;
HANDLE color1;
Book::Book()
{

}

// write file
fstream fp, fp1;
Book bk;


void Book::addBook() //menu add book
{
    Book::rentUsers.clear();
    system("cls");
    cout << "             .__________.\n";
    cout << "||-----------| New Book |-----------||" << endl;
    cout << "             '----------'\n";

    // ID input and validation
    while (true) {
        cout << "Enter id (> 0 and < 9999999): ";
        cin >> id;
        if (!cin.good() || id <= 0 || id >= 9999999) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. ";
            continue;
        }

        // Check for duplicate ID in text file
        ifstream inFile("book.txt");
        bool idExists = false;
        int tempId;

        while (inFile >> tempId) {
            inFile.ignore(100, '\n'); // Ignore the rest of the line
            if (tempId == id) {
                cout << ".----------------------------.\n";
                cout << "|  This ID already exists!   |" << endl;
                cout << "'----------------------------'\n";
                idExists = true;
                break;
            }
        }
        inFile.close();

        if (!idExists) break;
    }
    cin.ignore(256, '\n');  // Clear input buffer

    // Input book details
    do {
        cout << "Enter book name: ";
        getline(cin, name); // Using getline for std::string
    } while (name.empty()); // Check if the string is empty

    do {
        cout << "Enter book brand: ";
        getline(cin, brand); // Using getline for std::string
    } while (brand.empty()); // Check if the string is empty

    do {
        cout << "Enter book author: ";
        getline(cin, author); // Using getline for std::string
    } while (author.empty()); // Check if the string is empty

    // Quantity input and validation
    while (true) {
        cout << "Enter quantity (> 0): ";
        cin >> quantity;
        if (!cin.good() || quantity <= 0) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid quantity. ";
        }
        else {
            cin.ignore(256, '\n');
            break;
        }
    }

    // Write book details to text file
    ofstream outFile("book.txt", ios::app);
    if (outFile.is_open()) {
        outFile << id << " " << name << " " << brand << " " << author << " " << quantity << endl;
        outFile.close();
        cout << "Book added successfully!\n";
    }
    else {
        cerr << "Error: Could not open file to write book data.\n";
    }

    format();
}

void Book::updateBook() // Update book with id and name in text file
{
    system("cls");
    ifstream inFile("book.txt");
    ofstream outFile("temp.txt");
    bool found = false;
    int n;
    string s, line;

    cout << "              ._____________.\n";
    cout << "--------------| Update Book |---------------" << endl;
    cout << "              '-------------'\n";

    // ID input and validation
    cout << "Enter id of book to update: ";
    cin >> n;
    while (!cin.good() || n < 1 || n > 9999999)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << ".--------------------------------------------.\n";
        cout << "|  Error: Invalid ID. Please try again!      |\n";
        cout << "'--------------------------------------------'\n";
        cout << "Enter id of book to update: ";
        cin >> n;
    }
    cin.ignore(256, '\n');  // Clear buffer

    cout << "Enter name of book to update: ";
    getline(cin, s);

    if (!inFile || !outFile) {
        cout << ".----------------------------------------------.\n";
        cout << "|  File could not be opened! Press any Key...  |\n";
        cout << "'----------------------------------------------'\n";
        return;
    }

    // Read and update book details
    while (getline(inFile, line)) {
        int fileId;
        string fileName, fileBrand, fileAuthor;
        int fileQuantity;

        std::istringstream record(line);
        record >> fileId >> ws;
        getline(record, fileName, ' ');
        record >> ws;
        getline(record, fileBrand, ' ');
        record >> ws;
        getline(record, fileAuthor, ' ');
        record >> fileQuantity;

        // Check if current line matches the book ID and name
        if (fileId == n && fileName == s) {
            cout << "[ CURRENT DATA ]" << endl;
            cout << "ID: " << fileId << ", Name: " << fileName
                << ", Brand: " << fileBrand << ", Author: " << fileAuthor
                << ", Quantity: " << fileQuantity << endl;
            system("pause");

            // Input new details
            cout << "Enter the new details of the book:\n";
            cout << "Enter new name: ";
            getline(cin, fileName);
            cout << "Enter new brand: ";
            getline(cin, fileBrand);
            cout << "Enter new author: ";
            getline(cin, fileAuthor);
            cout << "Enter new quantity (> 0): ";
            while (!(cin >> fileQuantity) || fileQuantity <= 0) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Enter new quantity (> 0): ";
            }
            cin.ignore(256, '\n');

            outFile << fileId << " " << fileName << " " << fileBrand << " "
                << fileAuthor << " " << fileQuantity << endl;

            cout << ".________________________.\n";
            cout << "| Update Successfully !! |\n";
            cout << "'------------------------'\n";
            found = true;
        }
        else {
            // Write the line as is to the temporary file
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    // Replace old file with updated data
    remove("book.txt");
    rename("temp.txt", "book.txt");

    if (!found) {
        cout << ".________________________.\n";
        cout << "|  Record Not Found !!   |\n";
        cout << "'------------------------'\n";
    }
    system("pause");
}

void Book::deleteBook() // Delete book with id and name in text file
{
    system("cls");
    int n;
    string s;

    cout << "               ._____________.\n";
    cout << "---------------| DELETE BOOK |---------------" << endl;
    cout << "               '-------------'\n";
    cout << "Enter id of book to delete: ";
    cin >> n;

    // Input validation for book ID
    while (cin.fail() || n < 1 || n > 9999999)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << ".------------------------------------------------.\n";
        cout << "|    Error: Invalid ID. Please try again!        |\n";
        cout << "'------------------------------------------------'\n";
        cout << "Enter id of book to delete: ";
        cin >> n;
    }
    cin.ignore(256, '\n'); // Clear buffer
    cout << "Enter name of book to delete: ";
    getline(cin, s);

    ifstream inFile("book.txt");
    ofstream outFile("temp.txt");

    // Check if the input file opened successfully
    if (!inFile)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be opened !! Press any Key...       |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }

    bool found = false;
    string line;
    while (getline(inFile, line))
    {
        // Parse the current line to extract book details
        istringstream record(line);
        int fileId;
        string fileName, fileBrand, fileAuthor;
        int fileQuantity;

        record >> fileId;
        record.ignore(std::numeric_limits<std::streamsize>::max(), ' '); // Ignore until space
        getline(record, fileName, ' ');
        record.ignore(std::numeric_limits<std::streamsize>::max(), ' '); // Ignore until space
        getline(record, fileBrand, ' ');
        record.ignore(std::numeric_limits<std::streamsize>::max(), ' '); // Ignore until space
        getline(record, fileAuthor, ' ');
        record >> fileQuantity;

        // Check if the current record matches the book ID and name
        if (fileId != n || fileName != s) {
            outFile << line << endl; // Write to temp file if not deleted
        }
        else {
            found = true; // Set flag if record is found
        }
    }

    inFile.close();
    outFile.close();

    // Remove original file and rename temporary file
    remove("book.txt");
    rename("temp.txt", "book.txt");

    if (found) {
        cout << ".-----------------------------------.\n";
        cout << "|       Delete Successfully         |\n";
        cout << "'-----------------------------------'\n";
    }
    else {
        cout << ".-----------------------------------.\n";
        cout << "|       Record Not Found           |\n";
        cout << "'-----------------------------------'\n";
    }

    system("pause");
}

void Book::searchBook() // search book by name (case-insensitive)
{
    string s;
    bool found = false;
    fstream File("book.dat", ios::binary | ios::in | ios::out);
    char ch;
    vector<string> suggestions;

    if (!File) {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }

    while (true) {
        cout << "\n--------------| Search Book By Name |--------------\n";
        cout << "Enter name of book: " << s << endl;

        suggestions.clear();
        File.clear();
        File.seekg(0);

        while (File.read(reinterpret_cast<char*>(&bk), sizeof(Book))) {
            string bookName = bk.retName();
            std::transform(bookName.begin(), bookName.end(), bookName.begin(), ::tolower);

            if (bookName.find(s) != string::npos) {
                suggestions.push_back(bk.retName());
            }
        }

        if (!suggestions.empty()) {
            cout << "\nSuggestions:\n";
            for (const string& suggestion : suggestions) {
                cout << " - " << suggestion << endl;
            }
        }
        else {
            cout << "| No suggestions found for entered characters |\n";
        }

        ch = _getch();
        if (ch == '\r')
            break;
        else if (ch == '\b' && !s.empty())
            s.pop_back();
        else if (isalnum(ch) || isspace(ch))
            s += ch;
    }

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    found = false;
    File.clear();
    File.seekg(0);
    while (File.read(reinterpret_cast<char*>(&bk), sizeof(Book)) && !found) {
        string bookName = bk.retName();
        std::transform(bookName.begin(), bookName.end(), bookName.begin(), ::tolower);

        if (bookName == s) {
            bk.showBook();
            found = true;
            break;
        }
    }

    File.close();

    if (!found) {
        cout << "\n.__________________.\n";
        cout << "| Record Not Found |\n";
        cout << "'------------------'\n";
    }

    system("pause");
}

void Book::showBook() // menu show book
{
    cout << "          .___________.\n";
    cout << ".----------| Show book |----------." << endl;
    cout << "|          '-----------'          |\n";
    cout << "'---------------------------------'\n";
    cout << "Book ID: " << id << endl;
    cout << "Book name: " << name << endl;
    cout << "Book brand: " << brand << endl;
    cout << "Book author: " << author << endl;
    cout << "Quantity: " << quantity << endl;

    cout << "Users renting: ";
    if (rentUsers.empty()) {
        cout << "No users renting this book." << endl; // Thông báo nếu không có người thuê
    }
    else {
        for (const auto& user : rentUsers) {
            cout << user << " "; // In ra từng người dùng
        }
        cout << endl;
    }
    system("pause");
}

bool Book::readFromFile(ifstream& inFile) {
    string line;

    // Read and convert ID
    if (!getline(inFile, line)) return false;
    id = std::stoi(line);

    // Read name, brand, and author
    if (!getline(inFile, name)) return false;
    if (!getline(inFile, brand)) return false;
    if (!getline(inFile, author)) return false;

    // Read and convert quantity
    if (!getline(inFile, line)) return false;
    quantity = std::stoi(line);

    // Read the number of rented users
    size_t rentUsersCount;
    if (!getline(inFile, line)) return false;
    rentUsersCount = std::stoul(line);  // Convert the line to an unsigned long

    // Clear the existing list and read each user
    rentUsers.clear();
    for (size_t i = 0; i < rentUsersCount; ++i) {
        if (!getline(inFile, line)) return false;
        rentUsers.push_back(line);
    }

    return !inFile.fail();
}

void Book::writeToFile(ofstream& outFile) const {
    outFile << id <<setw(15)           // Write ID
        << name << setw(15)         // Write name
        << brand << setw(15)         // Write brand
        << author << setw(15)       // Write author
        << quantity;     // Write quantity

    // Write the list of rented users
    outFile << rentUsers.size() << "\n"; // First write the number of users
    for (const auto& user : rentUsers) {
        outFile << user << "\n";         // Write each user on a new line
    }
}

void Book::writeBook() // save book in file
{
    vector<Book> books;
    Book newBook;

    // Read all books from file into vector
    ifstream inFile("book.txt");
    if (inFile.is_open()) {
        Book temp;
        while (temp.readFromFile(inFile)) { // Use text-based reading for each Book
            books.push_back(temp);
        }
        inFile.close();
    }

    // Add the new book
    newBook.addBook();
    books.push_back(newBook);

    // Sort books by ID
    std::sort(books.begin(), books.end(), compareById);

    // Overwrite file with sorted list of books in text format
    ofstream outFile("book.txt", ios::trunc);
    for (const auto& book : books) {
        book.writeToFile(outFile);  // Use text-based writing for each Book
    }
    outFile.close();

    // Display success message
    cout << ".---------------------------------------.\n";
    cout << "|        Add Book Successfully!         |\n";
    cout << "'---------------------------------------'\n";
    system("pause");
    system("cls");
}
void Book::display()  //display book in screen
{
    ifstream inFile;
    inFile.open("book.dat", ios::binary);
    if (!inFile)
    {
        cout << ".----------------------------------------------------------.\n";
        cout << "|       File could not be open !! Press any Key...         |\n";
        cout << "'----------------------------------------------------------'\n";
        return;
    }
    //Dohoa::setColor(2);
    color1 = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color1, 12);
    cout << "\t\t\t\tBook LIST" << endl;
    cout << "====================================================================================\n";
    cout << left << setw(10) << "Book ID" << left << setw(25) << "Book Name" << left << setw(15) << "Book brand" << left << setw(20) << "Book Author" << left << setw(2) << "\tQuantity" << left << setw(20) << endl;
    cout << "====================================================================================\n";
    SetConsoleTextAttribute(color1, 14);
    while (inFile.read(reinterpret_cast<char*>(&bk), sizeof(Book)))
    {
        bk.report();
    }
    fp.close();
    _getch();
}
bool Book::updateRentBook(char s[]) //rent book
{
    User us;
    fstream File;
    bool found = false;

    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "Could not open the file!" << endl;
        return false;
    }

    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(Book));
        if (s == retName())
        {
            if (quantity <= 0)
            {
                return false;
            }
            else
            {
                if (us.updateUserRent(s) == true)
                {
                    id = retId();
                    name = retName();
                    brand = retBrand();
                    author = retAuthor();
                    //Kiểm tra người dùng đã thuê sách
                    if (std::find(rentUsers.begin(), rentUsers.end(), us.retUsername()) != rentUsers.end()) {
                        cout << "This user has rent this book before!" << endl;
                        return false; // Người dùng đã thuê sách
                    }
                    //Thêm user vào vector
                    rentUsers.push_back(us.retUsername());
                    quantity -= 1;

                    //Ghi thông tin sách vào file
                    int pos = (-1) * static_cast<int>(sizeof(Book));
                    File.seekp(pos, ios::cur);
                    File.write(reinterpret_cast<char*> (this), sizeof(Book));
                    found = true;
                    return true;//Thuê thành công
                }
                return false;//Không thể thuê do người dùng không hợp lệ
            }
        }
    }
    File.close();
    return false;//Không tìm được sách
}
bool Book::updateBookReturn(char s[]) //return book
{
    User us;
    fstream File;
    bool found = false;

    File.open("book.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "Could not open the file!" << endl;
        return false;
    }

    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (this), sizeof(Book));
        if (s == retName())
        {
            if (quantity <= 0)
            {
                return false;
            }
            else
            {
                if (us.updateUserReturn(s) == true)
                {
                    auto it = std::remove_if(rentUsers.begin(), rentUsers.end(), [&](const std::string& user) {
                        return user == us.retUsername(); // So sánh với tên người dùng đang trả sách
                    });

                    rentUsers.erase(it, rentUsers.end()); //Xoá người dùng khớp với tên

                    quantity += 1;

                    //update file sau khi xoá người mượn
                    int pos = (-1) * static_cast<int>(sizeof(Book));
                    File.seekp(pos, ios::cur);
                    File.write(reinterpret_cast<char*> (this), sizeof(Book));
                    found = true;
                    return true;
                }
                return false;
            }
        }
    }
    File.close();
    return false;
}

int Book::retId() // return id in class
{
    return id;
}

string Book::retName() //return name in class
{
    return name;
}
string Book::retBrand()
{
    return brand;
}

string Book::retAuthor()
{
    return author;
}
const vector<string>& Book::retRentUsers() const
{
    return rentUsers; // Trả về tham chiếu đến vector rentUser
}

int Book::retQuantity()
{
    return quantity;
}

void Book::format() {
    name = General::format(name.c_str());
    brand = General::format(brand.c_str());
    author = General::format(author.c_str());
}

void Book::report() // show book
{
    cout << left << setw(10) << id
        << left << setw(25) << name
        << left << setw(15) << brand
        << left << setw(25) << author
        << left << setw(10) << quantity   // Hiển thị số lượng sách
        << endl;
}

Book::~Book()
{
    //dtor
}
