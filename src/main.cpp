#include <iostream>
#include <windows.h>
#include <conio.h>

#include "ui_screen.h"
#include "config.h"
#include "snake.h"
#include "food.h"

int main() {
    Snake r;
    int huong = 0;
    int t;
    SetConsoleOutputCP(65001);
    // An con tro
    anConTro();
    // Set mau
    system("color 02");
    veGiaoDien();
    r.tocDo = doKho;
    veConMoi(r);
    r.veThanRan();
    return 0;
}