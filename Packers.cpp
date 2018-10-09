// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"

HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
COORD CurrentCursorPosition;


void gotoXY (int x, int y) {
  COORD Position;
  Position.X = x;
  Position.Y = y;
  SetConsoleCursorPosition (consoleHandle, Position);
}



class Area {
  int rows;
  int columns;
  struct materials {
    std::string hWalls { u8"━" };
    std::string vWalls { u8"┃" };
    std::string edges[4] { u8"┏",u8"┗",u8"┛",u8"┓" };
    std::string pack { u8"♣" };
  } stuff;
public:

  Area (unsigned char mode) :rows (20), columns (90) {

    for (int i = 2; i <= 22; i++) {
      for (int j = 10; j <= 100; j++) {
        gotoXY (j, i);

        // first horizontal wall
        if (i == 2 && j != 100) {

          // left top edge
          if (i == 2 && j == 10)
            std::cout << stuff.edges[0];
          std::cout << stuff.hWalls;
        }

        // right top edge
        if (i == 2 && j == 100)
          std::cout << stuff.edges[3];

        // left bottom edge
        if (i == 22 && j == 10)
          std::cout << stuff.edges[1];

        // second horizontal wall
        if (i == 22 && j != 100)
          std::cout << stuff.hWalls;
        else
          // right bottom edge
          if (i == 22 && j == 100)
            std::cout << stuff.edges[2];
          else

            // vertical walls
            if (j == 10 || j == 100)
              if (i != 2)
                std::cout << stuff.vWalls;

        if (mode == 1) {
          // packs
          if (i != 2 && i != 22 && i % 2 == 0)
            if (j != 10 && j != 100 && j % 2 == 0)
              //if (j!=11&&j!=99)
              ColourCout (stuff.pack, 0x02);
        }
        std::cout << u8"\n";
      }
    }


  };
  //Area(//userchoice) :rows (),columns() {};

  void yellow (COORD position) {
    int i = position.Y;
    int j = position.X;
    //gotoXY (0, 1); std::cout << i << '\t' << j;

    if (j - 1 != 10) {
      if (i - 1 != 2)
        gotoXY (j - 1, i - 1); ColourCout (u8"♣", 0x0e);
      if (i + 1 != 22)
        gotoXY (j - 1, i + 1); ColourCout (u8"♣", 0x0e);
    }
    if (j + 1 != 100) {
      if (i + 1 != 22)
        gotoXY (j + 1, i + 1); ColourCout (u8"♣", 0x0e);
      if (i - 1 != 2)
        gotoXY (j + 1, i - 1); ColourCout (u8"♣", 0x0e);
    }
  }
  void red () {

  }




};


class packMan {
  char Sign;
public:
  COORD position;
  static void blinkPacking (std::list<packMan> input, unsigned char mode) {
    //▪▫
    //add: if for characters
    short modeToMilliS { 0 };
    switch (mode) {
    case 1:
      modeToMilliS = 500;
      break;
    case 2:
      modeToMilliS = 400;
      break;
    case 3:
      modeToMilliS = 300;
      break;
    case 4:
      modeToMilliS = 200;
      break;
    case 5:
      modeToMilliS = 1000;
      break;
    default:
      modeToMilliS = 500;
      break;
    }
    const packMan & p = input.front ();

    gotoXY (p.position.X, p.position.Y);
    ColourCout (u8" ", 0x0f);
    gotoXY (p.position.X, p.position.Y);
    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown
    ColourCout (u8"▪", 0x0f);
    gotoXY (p.position.X, p.position.Y);
    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown
    ColourCout (u8" ", 0x0f);
    gotoXY (p.position.X, p.position.Y);
    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown
    ColourCout (u8"☻", 0x0f);
    gotoXY (p.position.X, p.position.Y);
    std::this_thread::sleep_for (std::chrono::milliseconds (modeToMilliS));; // add delays to the countdown

  };
  packMan (int quickReSeed) {
    int i { 0 };
    int j { 0 };
    srand ((unsigned int)time (NULL) + quickReSeed);
    do {
      i = rand () % (21 - 3) + 3;
      j = rand () % (99 - 11) + 11;
    } while (i % 2 == 0 || j % 2 == 0);
    gotoXY (j, i); ColourCout (u8"☻", 0x0f);
    position.X = j;
    position.Y = i;
  };










  //packMan (//userchoice) :Sign () {};

  //COORD GetPackerCursorPosition (HANDLE hConsoleOutput) {
  //  CONSOLE_SCREEN_BUFFER_INFO consoleScreenBinfo;
  //  if (GetConsoleScreenBufferInfo (hConsoleOutput, &consoleScreenBinfo)) {
  //    return consoleScreenBinfo.dwCursorPosition;
  //  }
  //  else {
  //    // call GetLastError() for detail
  //    COORD invalid {0,0};
  //    return invalid;
  //  }
  //}
};


bool running = true;
int a { 1 }, b { 1 }, c { 1 };
bool flag = false;



void pressed (void) {
  if (GetAsyncKeyState (VK_DOWN)) {
    if (a == 1 && flag == false) {
      gotoXY (74, 26); ColourCout (u8"  ", 0x0c);
      gotoXY (74, 27); ColourCout (u8"->", 0x0c);
      a = 2;
      flag = true;
    }
    if (a == 2 && flag == false) {
      gotoXY (74, 27); ColourCout (u8"  ", 0x0c);
      gotoXY (74, 28); ColourCout (u8"->", 0x0c);
      a = 3;
      flag = true;
      //break;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_UP)) {
    if (a == 2 && flag == false) {
      gotoXY (74, 26); ColourCout (u8"->", 0x0c);
      gotoXY (74, 27); ColourCout (u8"  ", 0x0c);
      a = 1;
      flag = true;
    }
    if (a == 3 && flag == false) {
      gotoXY (74, 27); ColourCout (u8"->", 0x0c);
      gotoXY (74, 28); ColourCout (u8"  ", 0x0c);
      a = 2;
      flag = true;
    }
    flag = false;
  }
  if (GetAsyncKeyState (VK_LEFT)) {

  }
  if (GetAsyncKeyState (VK_RIGHT)) {

  }
  if (GetAsyncKeyState (VK_RETURN)) {
    if (a == 1 && flag == false) {
      gotoXY (74, 26); ColourCout (u8"-> Involve me!", 0x04);
    }
  }
}


int main () {
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", 0x09);
  // screen
  COORD leftANDtop { 15,15 };
  COORD widthANDheight { 110,32 };
  COLORREF backColour { RGB (50,50,50) };
  ConsoleScreen_SizeColourPosition (leftANDtop, widthANDheight, backColour);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP (); // for later use
  SetConsoleOutputCP (CP_UTF8); // https://docs.microsoft.com/de-de/windows/desktop/Intl/code-page-identifiers
  // cursor
  ConsoleCursor_State (false);


  Area area1 (1);


  std::list<packMan> dataset;

  packMan Packer1 (102);
  dataset.insert (dataset.begin (), Packer1);
  packMan Packer2 (323);
  dataset.insert (dataset.begin (), Packer1);

  packMan Packer3 (766);
  dataset.insert (dataset.begin (), Packer1);

  packMan Packer4 (332);
  dataset.insert (dataset.begin (), Packer1);

  packMan Packer5 (373);
  dataset.insert (dataset.begin (), Packer1);






  area1.yellow (Packer1.position);
  area1.yellow (Packer2.position);
  area1.yellow (Packer3.position);
  area1.yellow (Packer4.position);
  area1.yellow (Packer5.position);




  gotoXY (17, 1);
  std::cout << u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";


  gotoXY (13, 24); ColourCout (u8"Packing speed:", 0x0a);
  gotoXY (13, 25); ColourCout (u8"  Stone age.", 0x0a);
  gotoXY (12, 25); ColourCout (u8"->", 0x0c);
  gotoXY (13, 26); ColourCout (u8"  Middle age..", 0x0a);
  gotoXY (13, 27); ColourCout (u8"  Industry age....", 0x0a);
  gotoXY (13, 28); ColourCout (u8"  Advanced age...........", 0x0a);
  gotoXY (13, 29); ColourCout (u8"  Hollow age..     .          .", 0x0a);
  gotoXY (50, 24); ColourCout (u8"Character Choices:", 0x0a);
  gotoXY (50, 25); ColourCout (u8"  ☺  ", 0x07);
  gotoXY (55, 25); ColourCout (u8"    ☻", 0x0f);
  gotoXY (55, 25); ColourCout (u8"->", 0x0c);
  gotoXY (75, 26); ColourCout (u8"  Involve me!", 0x0a);
  gotoXY (74, 26); ColourCout (u8"->", 0x0c);
  gotoXY (75, 27); ColourCout (u8"  Let me furnish! :)", 0x0a);
  gotoXY (75, 28); ColourCout (u8"  Enough!", 0x0a);





  // coding for action area

  for (int i = 0; i < 100; i++) {
    packMan::blinkPacking (dataset, 1);
    //blinkPacking (1);
    //blinkPacking (1);
    //blinkPacking (1);
    //blinkPacking (1);

  }












  while (running) {
    system ("pause>nul");


    pressed ();





  }




  SetConsoleOutputCP (consoleOutputCPstorage); // important: always set codec back to what it was
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
