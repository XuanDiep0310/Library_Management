#pragma once

#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include "windows.h" 
//======= lấy tọa độ x của con trỏ hiện tại =============
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(SHORT x, SHORT y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();
void TextColor(int x);
