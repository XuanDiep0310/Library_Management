#include "ServiceBook.h"

ServiceBook::ServiceBook()
{
    //ctor
}
void ServiceBook::rentBook() // rent book
{
    char name[50];
    cin.ignore();
    cout << "Enter name book want rent: ";
    cin.getline(name, 50);
    if (updateRentBook(name) == true)
    {
        cout << "Rent Book Successfully :)" << endl;
        system("pause");
    }
    else
    {
        cout << "Please check the book information or you information :(" << endl;
        system("pause");
    }
}

void ServiceBook::returnBook() // return book
{
    char name[50];
    cin.ignore();
    cout << "Enter name book want return: ";
    cin.getline(name, 50);
    if (updateBookReturn(name) == true)
    {
        cout << "Return Book Successfully :)" << endl;
        system("pause");
    }
    else
    {
        cout << "Please check the book information or you information :(" << endl;
        system("pause");
    }
}

ServiceBook::~ServiceBook()
{
    //dtor
}
