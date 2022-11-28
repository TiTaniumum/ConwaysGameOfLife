#include <iostream>
#include <string>
#include "win10.h"
using namespace std;

string backGround[]{
  "      ██████    ██████   ██     ██  ██       ██   ████    ██     ██  ██   ███████      ",
  "     ██        ██    ██  ████   ██  ██       ██  ██  ██    ██   ██   ██  ██            ",
  "     ██        ██  █ ██  ██ ██  ██   ██  █  ██   ██  ██     ██  ██       ██            ",
  "     ██        ██ █  ██  ██  ██ ██   ██ █ █ ██   ██████      ████         ██████       ",
  "     ██        ██    ██  ██   ████    ██   ██    ██  ██       ██               ██      ",
  "      ██████    ██████   ██     ██    ██   ██    ██  ██      ██          ███████       ",
  "                                                                                       ",
  " ██████    ████   ██     ██  ██████      ██████   ██████     ██      ██  ██████  ██████",
  "██    ██  ██  ██  ███   ███  ██         ██    ██  ██         ██          ██      ██    ",
  "██        ██  ██  ██ █ █ ██  ██         ██ ██ ██  ██         ██      ██  ██      ██    ",
  "██   ███  ██████  ██  █  ██  ██████     ██ ██ ██  ██████     ██      ██  ██████  ██████",
  "██    ██  ██  ██  ██     ██  ██         ██    ██  ██         ██      ██  ██      ██    ",
  " ██████   ██  ██  ██     ██  ██████      ██████   ██         ██████  ██  ██      ██████",
};
string obj1[]{
  "  ██  ",
  "██  ██",
  "  ██  ",
};
string obj2[]{
  "  ██  ",
  "██  ██",
  "  ████"
};
string obj3[]{
  "  ████  ",
  "██    ██",
  "  ██  ██",
  "    ██  ",
};
string obj4[]{
  "  ████  ",
  "██    ██",
  "  ████  ",
};
string obj5[]{
  "████",
  "  ██",
  "██  ",
  "████",
};
string obj6[]{
  "  ████    ",
  "██    ██  ",
  "████  ██  ",
  "  ██  ████",
  "  ██    ██",
  "    ████  ",
};
string obj7[]{
  "████",
  "████",
};
string obj8[]{
  "    ██",
  "██  ██",
  "  ████"
};
int backgroundLength = sizeof(backGround) / sizeof(backGround[0]);
int obj1Length = sizeof(obj1) / sizeof(obj1[0]);
int obj2Length = sizeof(obj2) / sizeof(obj2[0]);
int obj3Length = sizeof(obj3) / sizeof(obj3[0]);
int obj4Length = sizeof(obj4) / sizeof(obj4[0]);
int obj5Length = sizeof(obj5) / sizeof(obj5[0]);
int obj6Length = sizeof(obj6) / sizeof(obj6[0]);
int obj7Length = sizeof(obj7) / sizeof(obj7[0]);
int obj8Length = sizeof(obj8) / sizeof(obj8[0]);

bool getSettingBool(int a);
void changeSettingBool(int a);
int selectionMove(int& select, int length);
void printBackGround();
void printObject(string* str, int length, int row, int col);
string* addFile(string* str, int& length, string addStr);
void loadFile();
void manualFilLoad(string fileName);

int menu(string* m, int length, int row, int col, int select = 0) { // главное меню
  SetConsoleSize(210, 50);
  system("cls");
  printBackGround(); // прорисовка заднего плана
  while (true) {
    SetColor(0, 1);
    for (int i = 0; i < length; i++)
    {
      SetPos(row + i, col);
      if (select == i) {
        SetColor(0, 5);
        cout << "[" << m[i] << "]";
        SetColor(0, 1);
      }
      else {
        cout << " " << m[i] << " ";
      }
    }
    switch (selectionMove(select, length)) {
    case 0: break;
    case -1:
    case 1:
      system("cls");
      return select;
    }
  }
}

void settings(string* m, int length, int row, int col) { // меню настроек
  int select = 0;
  system("cls");
  while (true) {
    SetPos(10, 90);
    SetColor(7, 0);
    cout << "    Press ESC to go Back     ";
    SetPos(11, 90);
    cout << "Press ENTER to change setting";
    SetColor(0, 1);
    for (int i = 0; i < length; i++)
    {
      SetPos(row + i, col);
      if (select == i) {
        SetColor(0, 5);
        cout << "[" << m[i] << "]";
        SetColor(0, 1);
        cout << " = " << boolalpha << getSettingBool(i);
      }
      else {
        cout << " " << m[i] << " ";
        cout << " = " << boolalpha << getSettingBool(i);
      }
    }
    switch (selectionMove(select, length)) {
    case 0:break;
    case 1:
      system("cls");
      changeSettingBool(select); // смена настройки
      break;
    case -1:
      system("cls");
      return;
    }
  }
}

bool loadMenu(string* m, int length, int row, int col, bool isLoadingManual) {//меню загрузки шаблонов или загрузки вручную
  int select = 0;
  system("cls");
  while (true) {
    SetPos(10, 90);
    SetColor(7, 0);
    cout << "    Press ESC to go Back    ";
    SetPos(11, 90);
    if (isLoadingManual)
      cout << "Press ENTER to load file    ";
    else
      cout << "Press ENTER to load Template";
    SetColor(0, 1);
    for (int i = 0; i < length; i++)
    {
      SetPos(row + i, col);
      if (select == i) {
        SetColor(0, 5);
        cout << "[" << m[i] << "]";
        SetColor(0, 1);
      }
      else {
        cout << " " << m[i] << " ";
      }
    }
    switch (selectionMove(select, length)) {
    case 0:break;
    case 1:
      system("cls");
      if (isLoadingManual)
        manualFilLoad(m[select]); // загрузка вручную
      else
        loadTemplate(select); // загрузка шаблона
      return true;
    case -1:
      system("cls");
      return false;
    }
  }
}

void printBackGround() { // прорисовка заднего плана
  printObject(backGround, backgroundLength, 3, 55);
  printObject(obj1, obj1Length, 10, 30);
  printObject(obj1, obj2Length, 10, 55 + backGround[0].size() + 25);
  printObject(obj2, obj2Length, 30, 26);
  printObject(obj2, obj2Length, 45, 55 + backGround[0].size() + 12);
  printObject(obj3, obj3Length, 5, 5);
  printObject(obj3, obj3Length, 5, 55 + backGround[0].size() + 50);
  printObject(obj6, obj6Length, 23, 45);
  printObject(obj4, obj4Length, 34, 80);
  printObject(obj4, obj4Length, 28, 123);
  printObject(obj5, obj5Length, 40, 190);
  printObject(obj7, obj7Length, 46, 30);
  printObject(obj8, obj8Length, 31, 175);
}

void printObject(string* str, int length, int row, int col) { // прорисовка отдельного объекта
  SetColor(0, 7);
  for (int i = 0; i < length; i++)
  {
    SetPos(row + i, col);
    for (size_t j = 0; j < str[i].size(); j++)
    {
      if (str[i][j] == ' ') {
        SetColor(0, 0);
        cout << ' ';
      }
      else {
        SetColor(7, 7);
        cout << ' ';
      }
    }
  }
}

int selectionMove(int& select, int length) { //функция сдвига по меню
  int key = _getch();
  switch (key) {
  case _KEY::UP:
    select = (select == 0) ? length - 1 : select - 1;
    return 0;
    break;
  case _KEY::DOWN:
    select = (select == length - 1) ? 0 : select + 1;
    return 0;
    break;
  case _KEY::ENTER:
    return 1;
    break;
  case _KEY::ESC:
    select = -1;
    return -1;
    break;
  }
}

void loadFile() { // ручная загрузка, анализ файлов
  int loadfileMenulength = 0;
  string* loadFileMenu = new string[loadfileMenulength]; // массив файлов
  string fileMask = "*.save.txt";
  _finddata_t find{};
  intptr_t hfind = _findfirst(fileMask.c_str(), &find);
  if (hfind > 0) {
    loadFileMenu = addFile(loadFileMenu, loadfileMenulength, find.name); //добавление нового файла в массив
    while (!_findnext(hfind, &find)) {
      loadFileMenu = addFile(loadFileMenu, loadfileMenulength, find.name);
    }
    _findclose(hfind);
    loadMenu(loadFileMenu, loadfileMenulength, 20, 90, true); // меню с данным массивом файлов
  }
  else {
    SetPos(20, 90);
    SetColor(7, 0);
    cout << "No save files, nothing to load, press enter to go back.";
    SetColor(0, 7);
    cin.get();
  }
  delete[]loadFileMenu;
}

string* addFile(string* str, int& length, string addStr) { // динамическое увеличение массива, добавление нового имени файла, возврат адреса к новому массиву
  string* newStr = new string[length + 1];
  for (size_t i = 0; i < length; i++)
  {
    newStr[i] = str[i];
  }
  newStr[length] = addStr;
  length++;
  delete[]str;
  return newStr;
}