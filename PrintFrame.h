#pragma once

#include "Graphic.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

void box(int x, int y, int w, int h, int t_color, int b_color,int nd);
void box(int x, int y, int w, int h, int t_color, int b_color,string nd);
void box(int x, int y, int w, int h, int t_color, int b_color,int nd1,int nd2);
void box(int x, int y, int w, int h, int t_color, int b_color,Date nd);
void box(int x, int y, int w, int h, int t_color, int b_color);
void lightbar(int x, int y, int w, int h, int b_color,string nd);
void lightbar(int x, int y, int w, int h, int b_color);
string limit(int x,int y,int l);
