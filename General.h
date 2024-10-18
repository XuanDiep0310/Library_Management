#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

namespace General
{
    string toLowerStr(string str);
    string toUpperStr(string str);
    void upper(char a[], int n);
    void remove(char a[], int k, int& n);
    void upperTitle(char a[], int n);
    char* format(char a[]);
    void clearStdin();
    string format_string(string s);
}

