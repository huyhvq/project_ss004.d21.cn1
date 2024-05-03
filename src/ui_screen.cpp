#include <cmath>
#include <windows.h>
#include <iostream>
#include <conio.h>

#include "ui_screen.h"
#include "config.h"
#include "animation.h"

void anConTro() {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
