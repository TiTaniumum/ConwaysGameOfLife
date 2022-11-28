#include <iostream>
#include <random>
#include <string>
#include "win10.h"
using namespace std;

string fileName = "quickSave.txt"; 
string TemplateFile = "template.txt";
const int poleRow = 50, poleCol = 105, steps = 15;
bool isRandomGeneration = false;
bool isColoringOn = false;
bool isBufferingOn = false;
bool pole[poleRow][poleCol]{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

bool poleSteps[steps][poleRow][poleCol]{};
bool tempPole[poleRow][poleCol]{};
int cellColor[poleRow][poleCol]{};
int oldCellColor[poleRow][poleCol]{};

void fillGameArr();
void printGameArr();
int borders(int i, int j);
void refresh();
void editMode();
void clearTempPole();
bool saveToFile(string saveFileName = "", bool isSavingManual = false);
void loadFromFile();
void GetCellColor();
int bordersColoring(int i, int j);
void refreshColoring();
void clearOldColoring();
void refreshSteps();
void loadFromSteps(int selection);
void stepObserveMode(); 
void clearPole();
void saveGame(int row, int col);
void manualFilLoad(string fileName);

void game() {
  if (isRandomGeneration) fillGameArr(); //заполнение поля исходя из настроек
  clearTempPole(); // для корректного отоброжения при повторном включении игры
  printGameArr();
  refresh();
  while (true) {
    for (int i = 0; i < poleRow; i++)
    {
      for (int j = 0; j < poleCol; j++)
      {
        //смотреть объяснение правил игры в About
        switch (borders(i, j)) { //анализирует старое поле -> заносит значение в новое
        case 0:
        case 1:
          pole[i][j] = 0;
          break;
        case 2:
          break;
        case 3:
          pole[i][j] = 1;
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          pole[i][j] = 0;
          break;
        }
      }
    }
    printGameArr();
    int key = _getch();
    switch (key) {
    case _KEY::SPACE:
      editMode(); // режим редактирования поля
      break;
    case _KEY::TAB:
      if (isBufferingOn)
        stepObserveMode(); // режим просмотра предыдущих шагов
      break;
    case _KEY::ESC:
      SetColor(0, 7);
      return;
    }
    refresh();
  }
  cin.get();
}

void GetCellColor() {
  for (int i = 0; i < poleRow; i++)
  {
    for (int j = 0; j < poleCol; j++)
    {
      switch (bordersColoring(i, j)) {
      case 0:
        cellColor[i][j] = 8;
        break;
      case 1:
        cellColor[i][j] = 7;
        break;
      case 2:
        cellColor[i][j] = 15;
        break;
      case 3:
        cellColor[i][j] = 3;
        break;
      case 4:
        cellColor[i][j] = 2;
        break;
      case 5:
        cellColor[i][j] = 6;
        break;
      case 6:
        cellColor[i][j] = 5;
        break;
      case 7:
        cellColor[i][j] = 12;
        break;
      case 8:
        cellColor[i][j] = 4;
        break;
      }
    }
  }
}

void editMode() { //режим редактирования поля во время игры 
  bool isPlace = true; // режим рисования или стирания
  int mRow, mCol;
  GetMouseCoord(mRow, mCol);
  int tempMRow = mRow, tempMCol = mCol;
  while (true) {
    GetMouseCoord(mRow, mCol);
    if (tempMRow != mRow || tempMCol != mCol) { // передвижение курсора для удобства
      SetPos(tempMRow, tempMCol);
      SetColor((pole[tempMRow][tempMCol / 2] ? (isColoringOn ? cellColor[tempMRow][tempMCol / 2] : 7) : 0), 0); //возвращает прежний цвет для живых клеток
      cout << " ";
      SetPos(mRow, mCol);
      SetColor(6, 6);
      cout << " ";
      tempMRow = mRow;
      tempMCol = mCol;
    }
    if (isLButtonDown()) {
      //Sleep(100);
      if (mRow >= 0 && mRow < poleRow && mCol >= 0 && mCol / 2 < poleCol) { //для исключения выхода за границу
        SetPos(mRow, (mCol / 2) * 2);// что бы корректно нарисовать квадратик, нужно что бы столбец был четным
        if (isPlace) { //рисование
          SetColor((isColoringOn ? cellColor[mRow][mCol / 2] : 7), 7);
          cout << "  ";
          pole[mRow][(mCol) / 2] = 1;
        }
        else { //стирание
          SetColor(0, 0);
          cout << "  ";
          pole[mRow][(mCol) / 2] = 0;
        }
      }
    }
    if (_kbhit()) {
      int key = _getch();
      switch (key) {
      case _KEY::ENTER:
        isPlace = (isPlace) ? false : true; // смена режима
        break;
      case _KEY::SPACE: // выход из режима редактирования
        SetPos(mRow, mCol);
        SetColor((pole[mRow][mCol / 2] ? 7 : 0), 0); //стриание курсора при завершении рисования
        cout << " ";
        return;
      case's':case'S':
        saveToFile(); // быстрое сохранение игры 
        break;
      case'l':case'L':
        loadFromFile(); // быстрая загрузка игры 
        break;
      }
    }
  }
}

void stepObserveMode() {
  clearTempPole(); // для дальнейшего правильного отображения нового хода
  int selection = 0;
  while (true) {
    int key = _getch();
    switch (key) {
    case _KEY::LEFT: case _KEY::UP: // передвижение в прошлое
      selection = (selection == steps - 1) ? 0 : selection + 1;
      SetColor(0, 7);
      cout << selection;
      system("cls");
      loadFromSteps(selection); // загрузка поля из буфера в главное 
      printGameArr();
      break;
    case _KEY::RIGHT: case _KEY::DOWN: // передвижение обратно
      selection = (selection) ? selection - 1 : steps - 1;
      SetColor(0, 0);
      system("cls");
      loadFromSteps(selection);
      printGameArr();
      break;
    case _KEY::ESC: case _KEY::ENTER:
      return;
    }
  }
}

bool saveToFile(string saveFileName, bool isSavingManual) { //сохранение вручную или быстрое сохранение
  ofstream file;
  if (isSavingManual)
    file.open(saveFileName);
  else
    file.open(fileName);
  if (!file.is_open())return false;
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      file << pole[i][j] << " ";
    }
    file << '\n';
  }
  return true;
}

void saveGame(int row, int col) { // ручное сохранение игры
  string saveFileName;
  SetPos(row, col);
  SetColor(7, 0);
  cout << "ENTER NAME FOR SAVE FILE";
  SetPos(row + 1, col);
  cout << "->";
  getline(cin, saveFileName);
  saveFileName += ".save.txt"; // расширение файлу
  SetPos(row + 2, col);
  if (saveToFile(saveFileName, true)) {
    cout << "Saving successful! press Enter to go back.";
  }
  else {
    cout << "Saving failed! press Enter to go back.";
  }
  SetColor(0, 7);
  cin.get();
}

void loadFromFile() { // загрузка из быстрого сохранения
  ifstream file(fileName);
  if (!file.is_open())return;
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      file >> pole[i][j];
    }
  }
  SetColor(0, 7);
  system("cls");
  clearTempPole();
  printGameArr();
  refresh();
}

void loadFromSteps(int selection) { // загрузка поля из буфера
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = poleSteps[selection][i][j];
    }
  }
}

void refresh() { // копирования массива для дальнейшего обновления главного массива
  if(isBufferingOn) //буферизация
  refreshSteps();
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      tempPole[i][j] = pole[i][j];
      if(isBufferingOn)
      poleSteps[0][i][j] = pole[i][j];
    }
  }
}

void refreshSteps() { // обновление буфера
  for (size_t i = steps - 1; i > 0; i--)
  {
    for (size_t j = 0; j < poleRow; j++)
    {
      for (size_t l = 0; l < poleCol; l++)
      {
        poleSteps[i][j][l] = poleSteps[i - 1][j][l];
      }
    }
  }
}

void refreshColoring() { // копирования массива для дальнейшего обновления главного массива цветности
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      oldCellColor[i][j] = cellColor[i][j];
    }
  }
}

int borders(int i, int j) {//проверка на наличие живых клеток вокруг клетки[i][j]
  int cnt = 0;
  cnt = (tempPole[i][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  // -*
  cnt = (tempPole[i][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  // *-
  cnt = (tempPole[(i == poleRow - 1) ? 0 : i + 1][j] == 1) ? cnt + 1 : cnt;
  // |
  // *
  cnt = (tempPole[(i == 0) ? poleRow - 1 : i - 1][j] == 1) ? cnt + 1 : cnt;
  // *
  // |
  cnt = (tempPole[(i == poleRow - 1) ? 0 : i + 1][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  // \
	//  *
  cnt = (tempPole[(i == poleRow - 1) ? 0 : i + 1][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  //  /
  // *
  cnt = (tempPole[(i == 0) ? poleRow - 1 : i - 1][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  //  *
  // /		
  cnt = (tempPole[(i == 0) ? poleRow - 1 : i - 1][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  // *
  //  \    
  return cnt;
}

int bordersColoring(int i, int j) {//проверка на наличие живых клеток вокруг клетки[i][j] нового поля
  int cnt = 0;
  cnt = (pole[i][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  // -*
  cnt = (pole[i][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  // *-
  cnt = (pole[(i == poleRow - 1) ? 0 : i + 1][j] == 1) ? cnt + 1 : cnt;
  // |
  // *
  cnt = (pole[(i == 0) ? poleRow - 1 : i - 1][j] == 1) ? cnt + 1 : cnt;
  // *
  // |
  cnt = (pole[(i == poleRow - 1) ? 0 : i + 1][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  // \
	//  *
  cnt = (pole[(i == poleRow - 1) ? 0 : i + 1][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  //  /
  // *
  cnt = (pole[(i == 0) ? poleRow - 1 : i - 1][(j == poleCol - 1) ? 0 : j + 1] == 1) ? cnt + 1 : cnt;
  //  *
  // /		
  cnt = (pole[(i == 0) ? poleRow - 1 : i - 1][(j == 0) ? poleCol - 1 : j - 1] == 1) ? cnt + 1 : cnt;
  // *
  //  \    
  return cnt;
}

void clearPole() { // очистка главного поля
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = 0;
    }
  }
}

void clearTempPole() { // для корректного отображения при повторном включении
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      tempPole[i][j] = 0;
    }
  }
}

void clearOldColoring() { // для корректного отображения при повторном включении
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      oldCellColor[i][j] = 0;
    }
  }
}

void fillGameArr() { //генерация 
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = rand() % 2;
    }
  }
}

void printGameArr() { //отрисовка поля
  if (isColoringOn)GetCellColor(); // получение цветов клеток
  for (int i = 0; i < poleRow; i++)
  {
    for (int j = 0; j < poleCol; j++)
    {
      if (tempPole[i][j] != pole[i][j] || cellColor[i][j] != oldCellColor[i][j]) { // отрисовка только изменившихся клеток или цвета клеток
        SetPos(i, j * 2); // квадратик состоит из двух пробелов поэтому j*2
        if (pole[i][j] == 1) {
          SetColor((isColoringOn ? cellColor[i][j] : 7), 7); // в зависимости от настроки ставит цвет 
          cout << "  ";
        }
        else {
          SetColor(0, 0);
          cout << "  ";
        }
      }
    }
  }
  if (isColoringOn)refreshColoring(); // занесение в старое поле цветов 
}

bool getSettingBool(int a) { //получение значений настроек для меню настроек
  switch (a) {
  case 0:
    return isRandomGeneration;
  case 1:
    return isColoringOn;
  case 2:
    return isBufferingOn;
    break;
  }
}

void changeSettingBool(int a) { // смена настроек
  switch (a) {
  case 0:
    isRandomGeneration = (isRandomGeneration) ? false : true;
    break;
  case 1:
    isColoringOn = isColoringOn ? false : true;
    break;
  case 2:
    isBufferingOn = isBufferingOn ? false : true;
    break;
  }
}

bool loadingSetting() { // для загрузки шаблонов сбивает рандомную генерацию если она включена
  if (isRandomGeneration) {
    isRandomGeneration = false;
    return true;
  }
  else {
    return false;
  }
}

void loadTemplate(int num) { // загрузка шаблонов
  string temp;
  ifstream file(TemplateFile);
  if (!file.is_open())return;
  for (size_t i = 0; i < num; i++)
  {
    for (size_t j = 0; j < poleRow; j++)
    {
      getline(file, temp); // прокрутка до определенного шаблона
    }
  }
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      file >> pole[i][j]; // непосредственно загрузка выбранного шаблона
    }
  }
}

void manualFilLoad(string fileName) { // ручная загрузка из файла
  ifstream file(fileName);
  if (!file.is_open())return;
  for (size_t i = 0; i <poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      file >> pole[i][j];
    }
  }
}