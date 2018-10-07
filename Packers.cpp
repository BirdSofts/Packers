// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"

HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
COORD CurrentCursorPosition;

class packMan {
  char Sign;
public:
  packMan () :Sign ('$') {};
  //packMan (//userchoice) :Sign () {};

  COORD GetPackerCursorPosition (HANDLE hConsoleOutput) {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBinfo;
    if (GetConsoleScreenBufferInfo (hConsoleOutput, &consoleScreenBinfo)) {
      return consoleScreenBinfo.dwCursorPosition;
    }
    else {
      // call GetLastError() for detail
      COORD invalid {0,0};
      return invalid;
    }
  }
};

class Area {
  int rows;
  int columns;
  struct materials {
    std::string hWalls {u8"━"};
    std::string vWalls {u8"┃"};
    std::string edges[4] {u8"┏",u8"┗",u8"┛",u8"┓"};
    std::string pack {u8"♣"};
  } stuff;
public:
  Area () :rows (20), columns (90) {
    for (int i = 2; i<=22; i++) {
      for (int j = 10; j<=100; j++) {
        gotoXY (i, j);

        // first horizontal wall
        if (i==2&&j!=100) {

          // left top edge
          if (i==2&&j==10)
            std::cout<<stuff.edges[0];
          std::cout<<stuff.hWalls;
        }

        // right top edge
        if (i==2&&j==100)
          std::cout<<stuff.edges[3];

        // left bottom edge
        if (i==22&&j==10)
          std::cout<<stuff.edges[1];

        // second horizontal wall
        if (i==22&&j!=100)
          std::cout<<stuff.hWalls;
        else
          // right bottom edge
          if (i==22&&j==100)
            std::cout<<stuff.edges[2];
          else

            // vertical walls
            if (j==10||j==100)
              if (i!=2)
                std::cout<<stuff.vWalls;

        // packs
        if (i!=2&&i!=22)
          if (j!=10&&j!=100)
            if (j!=11&&j!=99)
              ColourCout (stuff.pack, 0x02);
      }
      std::cout<<u8"\n";
    }



  };
  //Area(//userchoice) :rows (),columns() {};
  void gotoXY (int y, int x) {
    COORD CursorPosition;
    CursorPosition.Y = y;
    CursorPosition.X = x;
    SetConsoleCursorPosition (consoleHandle, CursorPosition);
  }


};




int main () {
  // font
  COORD fontS {10,20};
  ConsoleFont_SizeColour (fontS, L"Consolas", 0x09);
  // screen
  COORD leftANDtop {15,15};
  COORD widthANDheight {110,32};
  COLORREF backColour {RGB (50,50,50)};
  ConsoleScreen_SizeColourPosition (leftANDtop, widthANDheight, backColour);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP (); // for later use
  SetConsoleOutputCP (CP_UTF8); // https://docs.microsoft.com/de-de/windows/desktop/Intl/code-page-identifiers
  // cursor
  ConsoleCursor_State (false);

  bool running = true;
  int a {1}, b {1}, c {1};
  bool flag = false;

  packMan Packer1;
  Area area1;

  area1.gotoXY (1, 17);
  std::cout<<u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";


  area1.gotoXY (24, 13); ColourCout (u8"Packing speed:", 0x0a);
  area1.gotoXY (25, 13); ColourCout (u8"  Stone age.", 0x0a);
  area1.gotoXY (25, 12); ColourCout (u8"->", 0x0c);
  area1.gotoXY (26, 13); ColourCout (u8"  Middle age..", 0x0a);
  area1.gotoXY (27, 13); ColourCout (u8"  Industry age....", 0x0a);
  area1.gotoXY (28, 13); ColourCout (u8"  Advanced age...........", 0x0a);
  area1.gotoXY (29, 13); ColourCout (u8"  Hollow age..     .          .", 0x0a);
  area1.gotoXY (24, 50); ColourCout (u8"Character Choices:", 0x0a);
  area1.gotoXY (25, 50); ColourCout (u8"  ☺  ", 0x07);
  area1.gotoXY (25, 55); ColourCout (u8"    ☻", 0x0f);
  area1.gotoXY (25, 55); ColourCout (u8"->", 0x0c);
  area1.gotoXY (26, 75); ColourCout (u8"  Involve me!", 0x0a);
  area1.gotoXY (26, 74); ColourCout (u8"->", 0x0c);
  area1.gotoXY (27, 75); ColourCout (u8"  Let me furnish! :)", 0x0a);
  area1.gotoXY (28, 75); ColourCout (u8"  Enough!", 0x0a);





  while (running) {
    system ("pause>nul");
    if (GetAsyncKeyState (VK_DOWN)) {
      if (a==1&&flag==false) {
        area1.gotoXY (26, 74); ColourCout (u8"  ", 0x0c);
        area1.gotoXY (27, 74); ColourCout (u8"->", 0x0c);
        a = 2;
        flag = true;
      }
      if (a==2&&flag==false) {
        area1.gotoXY (27, 74); ColourCout (u8"  ", 0x0c);
        area1.gotoXY (28, 74); ColourCout (u8"->", 0x0c);
        a = 3;
        flag = true;
        break;
      }
      flag = false;
    }
    if (GetAsyncKeyState (VK_UP)) {
      if (a==2&&flag==false) {
        area1.gotoXY (26, 74); ColourCout (u8"->", 0x0c);
        area1.gotoXY (27, 74); ColourCout (u8"  ", 0x0c);
        a = 1;
        flag = true;
      }
      if (a==3&&flag==false) {
        area1.gotoXY (27, 74); ColourCout (u8"->", 0x0c);
        area1.gotoXY (28, 74); ColourCout (u8"  ", 0x0c);
        a = 2;
        flag = true;
      }
      flag = false;
    }
    if (GetAsyncKeyState (VK_LEFT)) {

    }
    if (GetAsyncKeyState (VK_RIGHT)) {

    }


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
