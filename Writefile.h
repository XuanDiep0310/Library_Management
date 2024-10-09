#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

void writrFileUser(LinkedList<User>* luser);
void writrFileBook(LinkedList<Book>* lbook);
void writeFileData(int money,int time);
