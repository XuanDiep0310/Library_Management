#include "System.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Book.h"
#include "User.h"

using namespace std;

HANDLE color;
System::System()
{
    //ctor
}
void System::run()
{
    menu_main();
}
void System::HideCursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

bool System::login()
{
    char userAdmin[10];
    char passAdmin[10];
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 4);
    cout << "              ._______________.\n";
    cout << "||=-----------|  Admin Login  |-----------=||" << endl;
    cout << "              '---------------'\n";
    cout << "Enter Username: ";
    cin >> userAdmin;
    cout << "Enter Password: ";
    char str[10] = { 0 };
    int n, index = 0;
    bool showPassword = false;
    do {
        n = _getch();
        if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z') || n == ' ' || n == '.' || n == '@') && index < 28) {
            str[index++] = n;
            if (!showPassword) cout << "*";
            else cout << (char)n;
        }
        else if (n == '\b' && index > 0) {
            cout << "\b \b";
            str[--index] = 0;
        }
        else if (n == '\t') {
            showPassword = !showPassword;
            cout << "\rEnter Password: ";
            for (int i = 0; i < index; i++) {
                if (!showPassword) {
                    cout << "*";
                }
                else {
                    cout << str[i];
                }
            }
        }
    } while (n != 13);
    //cin >> passAdmin;
    system("cls");
    if( (strcmp(userAdmin, ADMINUSER) == 0) &&
	    (strcmp(str, ADMINPASSWORD) == 0)) {
	        return true;
	}
	return false;
}
bool System::login_user()
{
    User us;
    ifstream File;  // Use ifstream for reading text files
    char user[15];
    char str[20];  // Increased size to match your password expectations
    int n;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 3);
    cout << "              ._______________.\n";
    cout << "||=-----------|   User Login  |-----------=||" << endl;
    cout << "              '---------------'            \n";
    cout << "Enter Username: ";
    cin.getline(user, 15);
    cout << "Enter Password: ";
    char tempPassword[20] = { 0 };
    int num, index = 0;
    bool showPassword = false;

    do {
        num = _getch();
        if (((num >= '0' && num <= '9') || (num >= 'A' && num <= 'Z') || (num >= 'a' && num <= 'z') || num == ' ' || num == '.' || num == '@') && index < 20) {
            tempPassword[index++] = num;
            if (!showPassword) cout << "*";
            else cout << (char)num;
        }
        else if (num == '\b' && index > 0) {
            cout << "\b \b";
            tempPassword[--index] = 0;
        }
        else if (num == '\t') {
            showPassword = !showPassword;
            cout << "\rEnter Password: ";
            for (int i = 0; i < index; i++) {
                if (!showPassword) {
                    cout << "*";
                }
                else {
                    cout << tempPassword[i];
                }
            }
        }
    } while (num != 13);

    File.open("user.txt");  // Open the text file for reading
    if (!File) {
        cout << "Could not open user.txt!" << endl;
        return false;
    }

    // Read each line from the file
    string line;
    while (getline(File, line)) {
        // Assuming the line format is "username,password"
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string fileUsername = line.substr(0, commaPos);
            string filePassword = line.substr(commaPos + 1);

            // Compare the entered username and password
            if (fileUsername == user && filePassword == tempPassword) {
                File.close();  // Close the file before returning
                return true;   // Login successful
            }
        }
    }

    File.close();  // Close the file after reading all lines
    return false;  // Login failed
}

void System::menu_main()
{
    loop:
    system("cls");
    fflush(stdin);
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, rand()%15);
    cout << "._.    _ ._.\n";
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |   (_)| |__  _ __ __ _ _ __ __ _ _   " << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |   | || '_ \\| '__/ _` | '__/| | | |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |___| || |_) | | | (_| | |   | |_| |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "|_____|_||.__,/|_|  \\__,_|_|    \\__, |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "                                |___/" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "    _                _ _           _   _" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "   / \\   _ __  _ __ | (_) ___ __ _| |_(_) ___  _ __" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "  / _ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << " / ___ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "/_/   \\_\\ .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "        |_|   |_|" << endl;
    SetConsoleTextAttribute(color, 3);
    cout << "\n";
    cout << "||=========================||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||  [1]. Login With Admin  ||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||-------------------------||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||  [2]. Login With User   ||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||-------------------------||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||  [3]. Exit              ||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||-------------------------||" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "||=========================||" << endl;

    int choice = -1;
    SetConsoleTextAttribute(color, 14);
    cout << "Enter your choice: ";
    cin >> choice;
    while(choice < 1 || choice > 3)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    switch(choice)
    {
    case 1: // login with admin
        system("cls");
        while(!login())
        {
            cout << "||--------------------------------------------------------------||\n";
            cout << "||       Invalid username or password. Please try again!        ||" << endl;
            cout << "||--------------------------------------------------------------||\n";
            system("pause");
            system("cls");
        }
        system("cls");
        menu_admin_manager();
        break;
    case 2: //login with user
        system("cls");
        cin.ignore();
        while(!login_user())
        {
            cout << "\n||--------------------------------------------------------------||\n";
            cout << "||       Invalid username or password. Please try again!        ||" << endl;
            cout << "||--------------------------------------------------------------||\n";
            system("pause");
            system("cls");
        }
        system("cls");
        menu_user();
        break;
    case 3:
        cout << "\n||---------------------------------------||\n";
        cout << "||       Thank you for using it!!        ||" << endl;
        cout << "||---------------------------------------||\n";
        exit(0);
    }
}

void System::menu_admin_manager() // menu of admin
{
    int choice;

    /*cout << "||-----------------------------------------||\n";
    cout << "||       Admin Login is Successful!        ||" << endl;
    cout << "||-----------------------------------------||\n";*/
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);
    system("pause");
    system("cls");
    loop:
    cout << "              ._______________.\n";
    cout << "||=-----------| Admin Manager |-----------=||" << endl;
    cout << "||            '---------------'            ||\n";
    cout << "||-----------------------------------------||\n";
    cout << "|| [1]. Book Manager                       ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [2]. User Manager                       ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [3]. Employee Manager                   ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [4]. Logout                             ||" << endl;
    cout << "||=---------------------------------------=||" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 4)
    {
        cin.clear();
        fflush(stdin);
        cout << "||=---------------------------------------------------=||\n";
        cout << "||      Error: Invalid Choice. Please try again!       ||" << endl;
        cout << "||=---------------------------------------------------=||\n";
        system("pause");
        system("cls");
        goto loop;
        cout << "Enter your choice: ";cout << "\n";
        cin >> choice;
    }

    switch(choice)
    {
    case 1:
        menu_book_manager();
        break;
    case 2:
        menu_user_manager();
        break;
    case 3:
        menu_employee_manager();
        break;
    case 4:
        menu_main();
    }
}

void System::menu_user_manager() // menu manager user
{
    loop:
    int choice = -1;
    system("cls");

    cout << "             ._______________.\n";
    cout << "||=----------| Admin Action  |------------=||" << endl;
    cout << "||           '---------------'             ||\n";
    cout << "||-----------------------------------------||\n";
    cout << "|| [1]. Add user                           ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [2]. Update user                        ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [3]. Delete user                        ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [4]. Search user                        ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [5]. Show user                          ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [6]. Back                               ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [7]. Exit                               ||" << endl;
    cout << "||=---------------------------------------=||\n";

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 7)
    {
        cin.clear();
        fflush(stdin);
        cout << "||=---------------------------------------------------=||\n";
        cout << "||      Error: Invalid Choice. Please try again!       ||" << endl;
        cout << "||=---------------------------------------------------=||\n";
        system("pause");
        system("cls");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    User us;
    switch(choice)
    {
    case 1:
        char c;
        do
        {
        system("cls");
         us.write_user();
         cout << "||=-------------------------------------------=||\n";
         cout << "||    Do you want to add more user..(Y/N?):    ||\n";
         cout << "||=-------------------------------------------=||\n";
         cin >> c;
        }while(c=='y'||c=='Y');
        goto loop;
    case 2:
        us.update_user();
        goto loop;
    case 3:
        us.delete_user();
        goto loop;
    case 4:
        us.search_user();
        goto loop;
    case 5:
        us.display();
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "\n||=-----------------------------------=||\n";
        cout << "||       Thank you for using it !!     ||\n";
        cout << "||=-----------------------------------=||\n";
        exit(0);
    }
}

void System::menu_user() // menu to rent book
{
    loop:
    int choice;

    system("cls");

    cout << "             ._______________.\n";
    cout << "||=----------| Users Action  |------------=||" << endl;
    cout << "||           '---------------'             ||\n";
    cout << "||-----------------------------------------||\n";
    cout << "|| [1]. Rent book                          ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [2]. Return book                        ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [3]. Show list book                     ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [4]. Logout                             ||" << endl;
    cout << "||-----------------------------------------||\n";
    cout << "|| [5]. Exit                               ||" << endl;
    cout << "||=---------------------------------------=||\n";

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 5)
    {
        cin.clear();
        fflush(stdin);
        cout << "||=---------------------------------------------------=||\n";
        cout << "||      Error: Invalid Choice. Please try again!       ||" << endl;
        cout << "||=---------------------------------------------------=||\n";
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    ServiceBook sv;
    Book bk;
    switch(choice)
    {
    case 1:
        sv.rentBook();
        goto loop;
    case 2:
        sv.returnBook();
        goto loop;
    case 3:
        bk.display();
        system("pause");
        goto loop;
    case 4:
        menu_main();
    case 5:
        cout << "\n||=-----------------------------------=||\n";
        cout << "||       Thank you for using it !!     ||\n";
        cout << "||=-----------------------------------=||\n";
        system("pause");
        exit(0);
    }
}

void System::menu_book_manager()
{
    loop:
    int choice;

    system("cls");

    cout << "             ._________________.\n";
    cout << "||=----------| Book Management |------------=||" << endl;
    cout << "||           '-----------------'             ||\n";
    cout << "||-------------------------------------------||\n";
    cout << "|| [1]. Add book                             ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [2]. Update book                          ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [3]. Delete book                          ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [4]. Search book                          ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [5]. Show book                            ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [6]. Back                                 ||" << endl;
    cout << "||-------------------------------------------||\n";
    cout << "|| [7]. Exit                                 ||" << endl;
    cout << "||=-----------------------------------------=||\n";

    cout << "Enter your choice: ";
    cin >>choice;

    while(choice < 1 || choice > 7)
    {
        cin.clear();
        fflush(stdin);
        cout << "||=---------------------------------------------------=||\n";
        cout << "||      Error: Invalid Choice. Please try again!       ||" << endl;
        cout << "||=---------------------------------------------------=||\n";
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    Book bk;
    switch(choice)
    {
    case 1:
        char c;
        do
        {
            system("cls");
            bk.writeBook();
            cout << "||=-------------------------------------------=||\n";
            cout << "||    Do you want to add more book..(Y/N?):    ||\n";
            cout << "||=-------------------------------------------=||\n";;
            cin >> c;
        }while(c=='y' || c=='Y');
        goto loop;
    case 2:
        bk.updateBook();
        goto loop;
    case 3:
        bk.deleteBook();
        goto loop;
    case 4:
        bk.searchBook();
        goto loop;
        break;
    case 5:
        system("cls");
        bk.display();
        cout << "||=-----------------------------------=||\n";
        cout << "|| Press any key to return menu book.  ||\n" << endl;
        cout << "||=-----------------------------------=||\n";
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "\n||=-----------------------------------=||\n";
        cout << "||       Thank you for using it !!     ||\n";
        cout << "||=-----------------------------------=||\n";
        exit(0);
    }

}
void System::menu_employee_manager()
{
    loop:
    int choice;

    system("cls");
    cout << "             ._____________________.\n";
    cout << "||=----------| Employee Management |------------=||" << endl;
    cout << "||           '---------------------'             ||\n";
    cout << "||-----------------------------------------------||\n";
    cout << "|| [1]. Add employee                             ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [2]. Update employee                          ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [3]. Delete employee                          ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [4]. Show employee                            ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [5]. Search employee                          ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [6]. Back                                     ||" << endl;
    cout << "||-----------------------------------------------||\n";
    cout << "|| [7]. Exit                                     ||" << endl;
    cout << "||=---------------------------------------------=||\n";

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 7)
    {
        cout << "||=---------------------------------------------------=||\n";
        cout << "||      Error: Invalid Choice. Please try again!       ||" << endl;
        cout << "||=---------------------------------------------------=||\n";
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    ManagerEmloyee mne;
    switch(choice)
    {
    case 1:
        mne.addEmployee();
        goto loop;
    case 2:
        mne.updateEmployee();
        goto loop;
    case 3:
        mne.deleteEmployee();
        goto loop;
    case 4:
        mne.showEmployee();
        goto loop;
    case 5:
        mne.searchEmployee();
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "\n||=-----------------------------------=||\n";
        cout << "||       Thank you for using it !!     ||\n";
        cout << "||=-----------------------------------=||\n";
        exit(0);
    }
}

System::~System()
{
    //dtor
}
