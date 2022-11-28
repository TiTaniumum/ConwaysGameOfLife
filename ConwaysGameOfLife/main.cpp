#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include "win10.h"
using namespace std;

string mainMenu[]{
  "  StartGame  ",
  " Clear Pole  ",
  "Manual P save",
  "Manual P load",
  "Load Template",
  "  Settings   ",
  "   About     ",
  "    Exit     "
};

string settingMenu[]{
  "Random generation of a Pole",
  "Coloring of Cells          ",
  "Buffering of Steps         ",
};

string menuLoad[]{
  "stable cells and ascillators 1",
  "stable cells and ascillators 2",
  "glider template               ",
  "shifters template             ",
  "infinite stable producer cells",
  "producer cell template        ",
  "horizontal straight line      ",
  "vertical straight line        ",
};

int row = 20, col = 90;
int mainMenulength = sizeof(mainMenu) / sizeof(mainMenu[0]);
int settingLength = sizeof(settingMenu) / sizeof(settingMenu[0]);
int loadMenulength = sizeof(menuLoad) / sizeof(menuLoad[0]);

int menu(string* m, int length, int row, int col, int select = 0);
void settings(string* m, int length, int row, int col);
bool loadMenu(string* m, int length, int row, int col, bool isLoadingManual = false);
void about();
void game();
bool loadingSetting();
void changeSettingBool(int a);
void clearPole();
void clearTempPole();
void saveGame(int row, int col);
void loadFile();

int main() {
  srand(time(NULL));
  CursorHide();
  int select = 0;
  while (true) {
    switch (menu(mainMenu, mainMenulength, row, col, select)) {
    case 0:
      game();
      break;
    case 1:
      clearTempPole(); // очистка главного поля
      clearPole();
      break;
    case 2:
      saveGame(row, col);
      break;
    case 3:
      loadFile();
      break;
    case 4:
      if (loadMenu(menuLoad, loadMenulength, row, col)) { // если был выбран шаблон то идет смена настроек с рандомной генерацией
        bool isLoaded = loadingSetting();
        game();
        if (isLoaded)changeSettingBool(0);
      }
      break;
    case 5:
      settings(settingMenu, settingLength, row, col);
      break;
    case 6:
      about();
      break;
    case 7:
    case -1:
      SetColor(0, 7);
      return 0;
    }
  }
}

void about() {
  SetPos(10, 50);
  SetColor(7, 0);
  cout << "  Maid by Yelemanov Temrlan   ";
  SetPos(11, 50);
  cout << "    Idea owner John Conway    ";
  SetPos(12, 50);
  cout << " started making in 16.09.2022 ";
  SetPos(13, 50);
  cout << " release  date  in 16.10.2022 ";
  SetPos(15, 50);
  cout << "                    controls:                            ";
  SetPos(16, 50);
  cout << " Hold ENTER To progress                                  ";
  SetPos(17, 50);
  cout << " Or press ENTER one time to progress one step            ";
  SetPos(18, 50);
  cout << " press SPACE to edit the pole by mouse                   ";
  SetPos(19, 50);
  cout << " Hold left mouse button to draw                          ";
  SetPos(20, 50);
  cout << " press ENTER while editting to change mode (draw, erase) ";
  SetPos(21, 50);
  cout << " press SPACE again to exit editting mode                 ";
  SetPos(22, 50);
  cout << " press S to quick save current pole while editting       ";
  SetPos(23, 50);
  cout << " press L to load your last quick save while editting     ";
  SetPos(24, 50);
  cout << " press ESC to exit the game                              ";
  SetPos(26, 50);
  cout << "                               game rules:                                      ";
  SetPos(27, 50);
  cout << " cell that has 2 naighbours will stay alive or stay dead                        ";
  SetPos(28, 50);
  cout << " cell that has 3 naighbours will be born                                        ";
  SetPos(29, 50);
  cout << " cell that has less than 2 or more than 3 naighbours will die                   ";
  SetPos(30, 50);
  cout << " black cells are dead                                                           ";
  SetPos(31, 50);
  cout << " white cells are alive                                                          ";
  SetPos(32, 50);
  cout << " there is no goal in this game, it's just satisfing to watch. it's life sim  :) ";
  SetPos(33, 50);
  cout << " in case you can't draw you have to toggle down mouse selection in cmd settings ";
  SetPos(35, 50);
  cout << "                              Observing mode                                    ";
  SetPos(36, 50);
  cout << " to observe previous steps turn on buffering in settings                        ";
  SetPos(37, 50);
  cout << " press TAB to start observing mode while playing (it contains 15 steps)         ";
  SetPos(38, 50);
  cout << " press LEFT or UP to scroll to past while using observing mode                  ";
  SetPos(39, 50);
  cout << " press RIGHT or DOWN to scroll back while using observing mode                  ";
  SetPos(40, 50);
  cout << " press ENTER or ESC to quit observing mode and continue on a current step       ";
  SetColor(0, 7);
  cin.get();
}