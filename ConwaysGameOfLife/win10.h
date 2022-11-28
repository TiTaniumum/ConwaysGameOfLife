#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>  // ��� _getch(), _getche(), _kbhit()
#include <io.h> // �������������� ����-�����
#include <fstream>

#define SETLOCAL_RU system( "chcp 1251 > nul" )
#define SETLOCAL_EN system( "chcp 866 > nul" )
#define CLS         system( "cls" )  // cls - clear screen
#define PAUSE       system( "pause > nul" )

#define RAND(min,max)  (rand()%((max)-(min)+1)+(min))
#define CREATE_COLOR(fon,sym)   (((fon) << 4) | (sym))


// ���������� ����������� ����
enum COLOR {
  black,    // = 0
  blue,     // 1 = black + 1
  green,    // 2 = blue + 1
  aqua,     // 3 = green + 1
  red,
  purple,
  yellow,
  white,
  gray,
  light_blue,
  light_green,
  light_aqua,
  light_red,
  light_purple,
  light_yellow,
  bright_white,
};


// ������������ ����� ������ ����������
// ������������ ������������ � ������ KEY
enum _KEY {
  ESC = 27,
  ENTER = 13,
  SPACE = 32,     // ������
  TAB = 9,
  BACKSPACE = 8,
  PLUS = 43, MINUS = 45,

  CURSOR1 = 0, CURSOR2 = 224,

  UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77,

  INS = 82, DEL = 83,
  HOME = 71, END = 79,
  PG_UP = 73, PG_DOWN = 81,

  F1 = 59, F2, F3, F4, F5, F6, F7, F8, F9, F10, // CURSOR1, 59-68
  F11 = 133, F12 = 134, // CURSOR2, 133-134
};

// ��������� �-��� �� ����� Win10.cpp

// ������� ��� ����� �����
void SetColor(int colBkgr, int colSym);
void SetColor(WORD wAttributes);

// ������� ��� ��������� ������� ������� ������
void SetPos(int Row, int Col);

// ������� ��� ������� �������
void CursorHide(BOOL bVisible = FALSE, DWORD dwSize = 10);

// �-��� ����������� �������� ������� ����������� ����
void GetConsoleSize(int& Width, int& Height);

// �-��� ��������� ������� ����������� ����
void SetConsoleSize(int Width, int Height);
void SetConsoleSize(SIZE szConsWin);

void start(int nFont = 5, int Lines = 25, int Columns = 80);

// Mouse function
bool isLButtonDown();
bool isRButtonDown();
bool isMButtonDown();
POINT GetMousePoint();
POINT GetMouseCoord();
void GetMouseCoord(int& Row, int& Col);
void loadTemplate(int num);
