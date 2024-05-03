#pragma once
#ifndef SNAKE_H
#define SNAKE_H

class Snake {
public:
    Point dotRan[500];
    int doDai;
    int tocDo;
    bool lonLen;

    Snake();
    void khoiTaoThanRan();
};

#endif //SNAKE_H
