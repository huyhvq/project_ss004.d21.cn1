#include <iostream>

#include "snake.h"
#include "animation.h"
#include "config.h"

void veLaiDiemVienBiXoa(Point dauRan);
void capNhatDiem(int diem);

Snake::Snake() {
    doDai = doDaiMacDinh;
    tocDo = tocDoThap;
    lonLen = false;
    khoiTaoThanRan();
}

void Snake::khoiTaoThanRan() {
    Point start = layDiemTrungTam();
    for(int i = 0; i < doDai; i++)
    {
        dotRan[i].cot = start.cot--;
        dotRan[i].dong = start.dong;
    }
}