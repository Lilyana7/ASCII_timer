// ASCII_timer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <ASCII_timer.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

const char* d0[11][10] = { "0","0","0","0","0","0","0","0","0","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0"," "," "," "," "," "," "," "," ","0",
                            "0","0","0","0","0","0","0","0","0","0", };
const char* d1[11][10] = { " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1",
                               " "," "," "," "," "," "," "," "," ","1", };
const char* d2[11][10] = { "2","2","2","2","2","2","2","2","2","2",
                           " "," "," "," "," "," "," "," "," ","2",
                           " "," "," "," "," "," "," "," "," ","2",
                           " "," "," "," "," "," "," "," "," ","2",
                           " "," "," "," "," "," "," "," "," ","2",
                           "2","2","2","2","2","2","2","2","2","2",
                           "2"," "," "," "," "," "," "," "," "," ",
                           "2"," "," "," "," "," "," "," "," "," ",
                           "2"," "," "," "," "," "," "," "," "," ",
                           "2"," "," "," "," "," "," "," "," "," ",
                           "2","2","2","2","2","2","2","2","2","2" };
const char* d3[11][10] = { "3","3","3","3","3","3","3","3","3","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           "3","3","3","3","3","3","3","3","3","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           " "," "," "," "," "," "," "," "," ","3",
                           "3","3","3","3","3","3","3","3","3","3" };
const char* d4[11][10] = { "4"," "," "," "," "," "," "," "," ","4",
                           "4"," "," "," "," "," "," "," "," ","4",
                           "4"," "," "," "," "," "," "," "," ","4",
                           "4"," "," "," "," "," "," "," "," ","4",
                           "4"," "," "," "," "," "," "," "," ","4",
                           "4","4","4","4","4","4","4","4","4","4",
                           " "," "," "," "," "," "," "," "," ","4",
                           " "," "," "," "," "," "," "," "," ","4",
                           " "," "," "," "," "," "," "," "," ","4",
                           " "," "," "," "," "," "," "," "," ","4",
                           " "," "," "," "," "," "," "," "," ","4", };
const char* d5[11][10] = { "5","5","5","5","5","5","5","5","5","5",
                           "5"," "," "," "," "," "," "," "," "," ",
                           "5"," "," "," "," "," "," "," "," "," ",
                           "5"," "," "," "," "," "," "," "," "," ",
                           "5"," "," "," "," "," "," "," "," "," ",
                           "5","5","5","5","5","5","5","5","5","5",
                           " "," "," "," "," "," "," "," "," ","5",
                           " "," "," "," "," "," "," "," "," ","5",
                           " "," "," "," "," "," "," "," "," ","5",
                           " "," "," "," "," "," "," "," "," ","5",
                           "5","5","5","5","5","5","5","5","5","5", };
const char* d6[11][10] = { "6","6","6","6","6","6","6","6","6","6 ",
                           "6"," "," "," "," "," "," "," "," "," ",
                           "6"," "," "," "," "," "," "," "," "," ",
                           "6"," "," "," "," "," "," "," "," "," ",
                           "6"," "," "," "," "," "," "," "," "," ",
                           "6","6","6","6","6","6","6","6","6","6",
                           "6"," "," "," "," "," "," "," "," ","6",
                           "6"," "," "," "," "," "," "," "," ","6",
                           "6"," "," "," "," "," "," "," "," ","6",
                           "6"," "," "," "," "," "," "," "," ","6",
                           "6","6","6","6","6","6","6","6","6","6", };
const char* d7[11][10] = { "7","7","7","7","7","7","7","7","7","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7",
                           " "," "," "," "," "," "," "," "," ","7", };
const char* d8[11][10] = { "8","8","8","8","8","8","8","8","8","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8","8","8","8","8","8","8","8","8","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8"," "," "," "," "," "," "," "," ","8",
                            "8","8","8","8","8","8","8","8","8","8", };
const char* d9[11][10] = { "9","9","9","9","9","9","9","9","9","9",
                            "9"," "," "," "," "," "," "," "," ","9",
                            "9"," "," "," "," "," "," "," "," ","9",
                            "9"," "," "," "," "," "," "," "," ","9",
                            "9"," "," "," "," "," "," "," "," ","9",
                            "9","9","9","9","9","9","9","9","9","9",
                            " "," "," "," "," "," "," "," "," ","9",
                            " "," "," "," "," "," "," "," "," ","9",
                            " "," "," "," "," "," "," "," "," ","9",
                            " "," "," "," "," "," "," "," "," ","9",
                            "9","9","9","9","9","9","9","9","9","9", };
const char* sep[11][10] = { " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," ","##"," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," ","##"," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ",
                               " "," "," "," "," "," "," "," "," "," ", };


int main()
{

    printTitle();
    int hours = 0; int minutes = 0; int seconds;
    cout << "Seconds: "; cin >> seconds;
    while (seconds >= 59)
    {
        if (seconds > 59)
        {
            minutes++;
            seconds -= 60;
            if (minutes > 60)
            {
                hours++;
                minutes -= 60;

            }
        }
    }


    int gap = 11;
    int posX;
    int posY = 10;

    while (seconds != 0 || minutes != 0 || hours != 0)
    {
        system("cls");

        posX = 15;


        if (hours != 0)
        {
            if (hours <= 9)
            {
                printDigit(0, posX, posY);
                printDigit(hours, posX += gap, posY);
            }
            else
            {
                printDigit(hours / 10, posX, posY);
                printDigit(hours % 10, posX += gap, posY);
            }
            printDigit(10, posX += gap, posY);

            if (minutes <= 9)
            {
                printDigit(0, posX += gap, posY);
                printDigit(minutes, posX += gap, posY);
            }
            else
            {
                printDigit(minutes / 10, posX += gap, posY);
                printDigit(minutes % 10, posX += gap, posY);
            }

            printDigit(10, posX += gap, posY);

            if (seconds <= 9)
            {
                printDigit(0, posX += gap, posY);
                printDigit(seconds, posX += gap, posY);
            }
            else
            {
                printDigit(seconds / 10, posX += gap, posY);
                printDigit(seconds % 10, posX += gap, posY);
            }

        }
        else if (hours == 0 && minutes >= 1 && minutes > 14)
        {
            if (minutes <= 9)
            {
                printDigit(0, posX += gap, posY);
                printDigit(minutes, posX += gap, posY);
            }
            else
            {
                printDigit(minutes / 10, posX += gap, posY);
                printDigit(minutes % 10, posX += gap, posY);
            }

            printDigit(10, posX += gap, posY);

            if (seconds <= 9)
            {
                printDigit(0, posX += gap, posY);
                printDigit(seconds, posX += gap, posY);
            }
            else
            {
                printDigit(seconds / 10, posX += gap, posY);
                printDigit(seconds % 10, posX += gap, posY);
            }
        }
        else if (hours == 0 && minutes > 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            if (minutes <= 9)
            {
                printDigitCondition(0, posX += gap, posY);
                printDigitCondition(minutes, posX += gap, posY);
            }
            else
            {
                printDigitCondition(minutes / 10, posX += gap, posY);
                printDigitCondition(minutes % 10, posX += gap, posY);
            }

            printDigit(10, posX += gap, posY);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            if (seconds <= 9)
            {
                printDigitCondition(0, posX += gap, posY);
                printDigitCondition(seconds, posX += gap, posY);
            }
            else
            {
                printDigitCondition(seconds / 10, posX += gap, posY);
                printDigitCondition(seconds % 10, posX += gap, posY);
            }
        }
        if (hours == 0 && minutes == 0 && seconds <= 59)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            if (seconds <= 9)
            {
                printDigitCondition(0, posX += gap, posY);
                printDigitCondition(seconds, posX += gap, posY);
            }
            else
            {
                printDigitCondition(seconds / 10, posX += gap, posY);
                printDigitCondition(seconds % 10, posX += gap, posY);
            }
            while (seconds < 10 && seconds>0)
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printDigitCondition(0, posX, posY);
                printDigitCondition(seconds, posX, posY);
                Sleep(300);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printDigitCondition(0, posX, posY);
                printDigitCondition(seconds, posX, posY);
                Sleep(300);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Sleep(400);
                seconds--;

            }
        }


        if (hours == 0 && minutes == 0 && seconds == 0)
        {
            break;
        }
        if (seconds == 0 && minutes == 0)
        {
            hours--;
            minutes = 60;
        }
        if (seconds == 0)
        {
            minutes--;
            seconds = 60;
        }
        Sleep(1000);
        seconds--;

    }
    bool played = PlaySound(TEXT("alarm_sound.wav"), NULL, SND_SYNC);
    cout << played << endl;

}

