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

void Snake::xoaConRan()
{
    for (int i = 0; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot,dotRan[i].dong);
        std::cout<<" ";
    }
}

void Snake::veThanRan()
{
    for (int i = 1; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot,dotRan[i].dong);
        std::cout<<"+";
    }
}

void Snake::veConRanChet()
{
    // Ve minh khi chet
    for (int i = 1; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot, dotRan[i].dong);
        std::cout<< ".";
    }
    // Ve cai dau khi chet
    diChuyenCotDong(dotRan[0].cot, dotRan[0].dong);
    std::cout<< "*";
}

void Snake::lamMoiRan() {
    xoaConRan();
    Point snakeHead = dotRan[0];
    veLaiDiemVienBiXoa(snakeHead);
    doDai = doDaiMacDinh;
    tocDo = doKho;
    khoiTaoThanRan();
    capNhatDiem(0);
}