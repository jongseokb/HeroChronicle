//DebugLog.cpp

#include "DebugLog.h"
#include <iostream>
#include <Windows.h>

using namespace std;

#ifdef _DEBUG
void DebugLog(const char* msg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD oldColor = csbi.wAttributes;

    SetConsoleTextAttribute(
        hConsole,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
    );

    cout << "[DEBUG] " << msg << endl;

    SetConsoleTextAttribute(hConsole, oldColor);
}
#endif
