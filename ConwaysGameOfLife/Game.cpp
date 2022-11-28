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
  if (isRandomGeneration) fillGameArr(); //���������� ���� ������ �� ��������
  clearTempPole(); // ��� ����������� ����������� ��� ��������� ��������� ����
  printGameArr();
  refresh();
  while (true) {
    for (int i = 0; i < poleRow; i++)
    {
      for (int j = 0; j < poleCol; j++)
      {
        //�������� ���������� ������ ���� � About
        switch (borders(i, j)) { //����������� ������ ���� -> ������� �������� � �����
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
      editMode(); // ����� �������������� ����
      break;
    case _KEY::TAB:
      if (isBufferingOn)
        stepObserveMode(); // ����� ��������� ���������� �����
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

void editMode() { //����� �������������� ���� �� ����� ���� 
  bool isPlace = true; // ����� ��������� ��� ��������
  int mRow, mCol;
  GetMouseCoord(mRow, mCol);
  int tempMRow = mRow, tempMCol = mCol;
  while (true) {
    GetMouseCoord(mRow, mCol);
    if (tempMRow != mRow || tempMCol != mCol) { // ������������ ������� ��� ��������
      SetPos(tempMRow, tempMCol);
      SetColor((pole[tempMRow][tempMCol / 2] ? (isColoringOn ? cellColor[tempMRow][tempMCol / 2] : 7) : 0), 0); //���������� ������� ���� ��� ����� ������
      cout << " ";
      SetPos(mRow, mCol);
      SetColor(6, 6);
      cout << " ";
      tempMRow = mRow;
      tempMCol = mCol;
    }
    if (isLButtonDown()) {
      //Sleep(100);
      if (mRow >= 0 && mRow < poleRow && mCol >= 0 && mCol / 2 < poleCol) { //��� ���������� ������ �� �������
        SetPos(mRow, (mCol / 2) * 2);// ��� �� ��������� ���������� ���������, ����� ��� �� ������� ��� ������
        if (isPlace) { //���������
          SetColor((isColoringOn ? cellColor[mRow][mCol / 2] : 7), 7);
          cout << "  ";
          pole[mRow][(mCol) / 2] = 1;
        }
        else { //��������
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
        isPlace = (isPlace) ? false : true; // ����� ������
        break;
      case _KEY::SPACE: // ����� �� ������ ��������������
        SetPos(mRow, mCol);
        SetColor((pole[mRow][mCol / 2] ? 7 : 0), 0); //�������� ������� ��� ���������� ���������
        cout << " ";
        return;
      case's':case'S':
        saveToFile(); // ������� ���������� ���� 
        break;
      case'l':case'L':
        loadFromFile(); // ������� �������� ���� 
        break;
      }
    }
  }
}

void stepObserveMode() {
  clearTempPole(); // ��� ����������� ����������� ����������� ������ ����
  int selection = 0;
  while (true) {
    int key = _getch();
    switch (key) {
    case _KEY::LEFT: case _KEY::UP: // ������������ � �������
      selection = (selection == steps - 1) ? 0 : selection + 1;
      SetColor(0, 7);
      cout << selection;
      system("cls");
      loadFromSteps(selection); // �������� ���� �� ������ � ������� 
      printGameArr();
      break;
    case _KEY::RIGHT: case _KEY::DOWN: // ������������ �������
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

bool saveToFile(string saveFileName, bool isSavingManual) { //���������� ������� ��� ������� ����������
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

void saveGame(int row, int col) { // ������ ���������� ����
  string saveFileName;
  SetPos(row, col);
  SetColor(7, 0);
  cout << "ENTER NAME FOR SAVE FILE";
  SetPos(row + 1, col);
  cout << "->";
  getline(cin, saveFileName);
  saveFileName += ".save.txt"; // ���������� �����
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

void loadFromFile() { // �������� �� �������� ����������
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

void loadFromSteps(int selection) { // �������� ���� �� ������
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = poleSteps[selection][i][j];
    }
  }
}

void refresh() { // ����������� ������� ��� ����������� ���������� �������� �������
  if(isBufferingOn) //�����������
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

void refreshSteps() { // ���������� ������
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

void refreshColoring() { // ����������� ������� ��� ����������� ���������� �������� ������� ���������
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      oldCellColor[i][j] = cellColor[i][j];
    }
  }
}

int borders(int i, int j) {//�������� �� ������� ����� ������ ������ ������[i][j]
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

int bordersColoring(int i, int j) {//�������� �� ������� ����� ������ ������ ������[i][j] ������ ����
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

void clearPole() { // ������� �������� ����
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = 0;
    }
  }
}

void clearTempPole() { // ��� ����������� ����������� ��� ��������� ���������
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      tempPole[i][j] = 0;
    }
  }
}

void clearOldColoring() { // ��� ����������� ����������� ��� ��������� ���������
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      oldCellColor[i][j] = 0;
    }
  }
}

void fillGameArr() { //��������� 
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      pole[i][j] = rand() % 2;
    }
  }
}

void printGameArr() { //��������� ����
  if (isColoringOn)GetCellColor(); // ��������� ������ ������
  for (int i = 0; i < poleRow; i++)
  {
    for (int j = 0; j < poleCol; j++)
    {
      if (tempPole[i][j] != pole[i][j] || cellColor[i][j] != oldCellColor[i][j]) { // ��������� ������ ������������ ������ ��� ����� ������
        SetPos(i, j * 2); // ��������� ������� �� ���� �������� ������� j*2
        if (pole[i][j] == 1) {
          SetColor((isColoringOn ? cellColor[i][j] : 7), 7); // � ����������� �� �������� ������ ���� 
          cout << "  ";
        }
        else {
          SetColor(0, 0);
          cout << "  ";
        }
      }
    }
  }
  if (isColoringOn)refreshColoring(); // ��������� � ������ ���� ������ 
}

bool getSettingBool(int a) { //��������� �������� �������� ��� ���� ��������
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

void changeSettingBool(int a) { // ����� ��������
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

bool loadingSetting() { // ��� �������� �������� ������� ��������� ��������� ���� ��� ��������
  if (isRandomGeneration) {
    isRandomGeneration = false;
    return true;
  }
  else {
    return false;
  }
}

void loadTemplate(int num) { // �������� ��������
  string temp;
  ifstream file(TemplateFile);
  if (!file.is_open())return;
  for (size_t i = 0; i < num; i++)
  {
    for (size_t j = 0; j < poleRow; j++)
    {
      getline(file, temp); // ��������� �� ������������� �������
    }
  }
  for (size_t i = 0; i < poleRow; i++)
  {
    for (size_t j = 0; j < poleCol; j++)
    {
      file >> pole[i][j]; // ��������������� �������� ���������� �������
    }
  }
}

void manualFilLoad(string fileName) { // ������ �������� �� �����
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