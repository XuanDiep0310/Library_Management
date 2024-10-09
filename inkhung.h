#pragma once

#include "dohoa.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

void box(int x, int y, int w, int h, int t_color, int b_color, int nd);
void box(int x, int y, int w, int h, int t_color, int b_color, string nd);
void box(int x, int y, int w, int h, int t_color, int b_color, int nd1, int nd2);
void box(int x, int y, int w, int h, int t_color, int b_color, Date nd);
void box(int x, int y, int w, int h, int t_color, int b_color);
void thanhsang(int x, int y, int w, int h, int b_color, string nd);
void thanhsang(int x, int y, int w, int h, int b_color);
string gioihan(int x, int y, int l);