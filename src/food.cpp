#include <ctime>
#include <stdlib.h>
#include <iostream>

#include "food.h"
#include "animation.h"
#include "snake.h"

void veConMoi(Snake r) {
    srand(time(0));
    while (true) {
        // random tọa độ của con mồi
        conMoi.cot = (rand() % (gocPhaiDuoi.cot - gocTraiTren.cot - 1)) + gocTraiTren.cot + 1;
        conMoi.dong = (rand() % (gocPhaiDuoi.dong - gocTraiTren.dong - 1)) + gocTraiTren.dong + 1;
        // kiểm tra nếu tạo độ con mồi trùng với con rắn thì tạo lại
        if (ktConMoiTrungConRan(r))
            continue;
        break;
    }

    // di chuyển con trỏ tới tọa độ của con mồi để vẽ con mồi
    diChuyenCotDong(conMoi.cot, conMoi.dong);
    std::cout << "x";
}

bool ktConMoiTrungConRan(Snake r) {
    for (int i = 0; i < r.doDai; i++)
    {
        if (conMoi.cot == r.dotRan[i].cot && conMoi.dong == r.dotRan[i].dong)
            return true;
    }
    return false;
}

void xoaConMoi()
{
    diChuyenCotDong(conMoi.cot, conMoi.dong);
    std::cout << " ";
}