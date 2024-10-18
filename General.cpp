#include "General.h"
#include <string.h>

string General::toLowerStr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    return str;
}

string General::toUpperStr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return str;

}
void General::remove(char a[], int k, int& n)
{
    for (int i = k; i <= n; i++)    //a[n]='\0';
        a[i] = a[i + 1];
    n--;
}

char* General::format(char a[])
{
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[0] == ' ') {
            remove(a, 0, n);
        }

        if (a[n - 1] == ' ') remove(a, n - 1, n);

        if (a[i] == ' ' && a[i + 1] == ' ') {
            remove(a, i, n);
            i--;
        }
    }
    char* s = _strdup(a);
    upper(a, n);
    return s;
}
void General::upperTitle(char a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] <= 'Z' && a[i] >= 'A') a[i] += 32; // chuyen xau thanh chu thuong

    if (a[0] >= 'a' && a[0] <= 'z') a[0] -= 32;

    for (int i = 0; i < n - 1; i++)
        if (a[i] == ' ' && a[i + 1] != ' ') a[i + 1] -= 'a' - 'A';
}
void General::upper(char a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] <= 'Z' && a[i] >= 'A') a[i] += 32; // chuyen xau thanh chu thuong

    if (a[0] >= 'a' && a[0] <= 'z') a[0] -= 32;

    for (int i = 0; i < n - 1; i++)
        if (a[i] == ' ' && a[i + 1] != ' ') a[i + 1] -= 'a' - 'A';
}
string General::format_string(string s)
{
    int size = s.length();
    char* a = new char[size + 1];  // Allocate memory for the string and null terminator
    for (int i = 0; i < size; i++) {
        a[i] = s[i];
    }
    a[size] = '\0';  // Add null terminator

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (a[0] == ' ') {
            remove(a, 0, n);
        }

        if (a[n - 1] == ' ') remove(a, n - 1, n);

        if (a[i] == ' ' && a[i + 1] == ' ') {
            remove(a, i, n);
            i--;
        }
    }
    upper(a, n);
    string result(a);  // Convert char* to string

    delete[] a;  // Free the dynamically allocated memory
    return result;
}
void General::clearStdin()
{
    cin.clear();
    fflush(stdin);
}
