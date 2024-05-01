#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "point.h"

class Snake {
public:
    Point dotRan[500];
    int doDai;
    int tocDo;
    bool lonLen;

    Snake();
    void khoiTaoThanRan();
    void diChuyen(int Huong);
    void ranDiChuyenQuaTuong();
    void veConRan();
    void veThanRan();
    void veDauRan();
    void xoaDotCuoi();
    void xoaConRan();
    void veConRanChet();
    bool ktConRanPhamQuy();
    bool ktConRanChamKhung();
    void anConMoi();
    bool ktDungConMoi();
    void lamMoiRan();
};

#endif //SNAKE_H