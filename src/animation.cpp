#include "animation.h"

#include "config.h"

void diChuyenCotDong(int cot, int dong) {
    COORD coord;
    coord.X = cot;
    coord.Y = dong;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
