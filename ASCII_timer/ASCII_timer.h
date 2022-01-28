// ASCII_timer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);

}
void ColorRand()
{
    int random;
    srand(time(0));
    random = rand() % 10 + 1;
    SetConsoleTextAttribute(console, random);
}
void ChangeTextColour(int iCoulorValue)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iCoulorValue);
}


void printDigit(int no, int x, int y)
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            switch (no)
            {
            case 0: gotoxy(x + j, y + i); ChangeTextColour(3); cout << d0[i][j]; break;
            case 1: gotoxy(x + j, y + i); ChangeTextColour(7); cout << d1[i][j]; break;
            case 2: gotoxy(x + j, y + i); ChangeTextColour(4); cout << d2[i][j]; break;
            case 3: gotoxy(x + j, y + i); ChangeTextColour(1); cout << d3[i][j]; break;
            case 4: gotoxy(x + j, y + i); ChangeTextColour(5); cout << d4[i][j]; break;
            case 5: gotoxy(x + j, y + i); ChangeTextColour(2); cout << d5[i][j]; break;
            case 6: gotoxy(x + j, y + i); ChangeTextColour(8); cout << d6[i][j]; break;
            case 7: gotoxy(x + j, y + i); ChangeTextColour(9); cout << d7[i][j]; break;
            case 8: gotoxy(x + j, y + i); ChangeTextColour(10); cout << d8[i][j]; break;
            case 9: gotoxy(x + j, y + i); ChangeTextColour(11); cout << d9[i][j]; break;
            case 10: gotoxy(x + j, y + i); ChangeTextColour(12); cout << sep[i][j]; break;
            }
        }
    }
}
void printDigitCondition(int no, int x, int y)
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            switch (no)
            {
            case 0: gotoxy(x + j, y + i);  cout << d0[i][j]; break;
            case 1: gotoxy(x + j, y + i);  cout << d1[i][j]; break;
            case 2: gotoxy(x + j, y + i);  cout << d2[i][j]; break;
            case 3: gotoxy(x + j, y + i);  cout << d3[i][j]; break;
            case 4: gotoxy(x + j, y + i);  cout << d4[i][j]; break;
            case 5: gotoxy(x + j, y + i);  cout << d5[i][j]; break;
            case 6: gotoxy(x + j, y + i);  cout << d6[i][j]; break;
            case 7: gotoxy(x + j, y + i);  cout << d7[i][j]; break;
            case 8: gotoxy(x + j, y + i);  cout << d8[i][j]; break;
            case 9: gotoxy(x + j, y + i);  cout << d9[i][j]; break;
            case 10: gotoxy(x + j, y + i);  cout << sep[i][j]; break;
            }
        }
    }
}
void printTitle()
{
    ColorRand();
    cout << "     _    ____   ____ ___ ___   _____ _" << endl;
    cout << "    / \\  / ___| / ___|_ _|_ _| |_   _(_)_ __ ___   ___ _ __" << endl;
    cout << "   / _ \\ \\___ \\| |    | | | |    | | | | '_ ` _ \\ / _ \\ '__|" << endl;
    cout << "  / ___ \\ ___) | |___ | | | |    | | | | | | | | |  __/ |" << endl;
    cout << " /_/   \\_\\____/ \\____|___|___|   |_| |_|_| |_| |_|\\___|_|" << endl;
}

