#include <iostream>
#include <windows.h>
#include <conio.h>

#include "ui_screen.h"
#include "snake.h"
#include "food.h"
#include "config.h"
#include "handler.h"

int main() {
    Snake r;
    int huong = 0;
    int t;
    SetConsoleOutputCP(65001);
    // Ẩn con trỏ
    anConTro();
    // Set màu
    system("color 02");
    veGiaoDien();
    r.tocDo = doKho;
    veConMoi(r);
    r.veThanRan();
    while (true) {
        r.veDauRan();
        // Kiểm tra nếu rắn đụng biên hay cắn thân
        if (r.ktConRanPhamQuy()) {
            khiConRanPhamQuy(&r);
        }
        Sleep(r.tocDo);
        if (kbhit()) {
            t = getch();
            if (t == 224) {
                char c = getch();
                if (c == 75 && huong != 0) huong = 2;
                else if (c == 72 && huong != 1) huong = 3;
                else if (c == 77 && huong != 2) huong = 0;
                else if (c == 80 && huong != 3) huong = 1;
            }
            if ((t == 'a' || t == 'A') && huong != 0) huong = 2;
            else if ((t == 'w' || t == 'W') && huong != 1) huong = 3;
            else if ((t == 'd' || t == 'D') && huong != 2) huong = 0;
            else if ((t == 's' || t == 'S') && huong != 3) huong = 1;
            else if (t == ' ') // Dừng game
                tamDung(&r, huong);
            else if (t == 'r' || t == 'R')
                thaoTacPhimR(&r, huong);
            else if (t == 'm' || t == 'M')
                thaoTacPhimM(&r, huong);
            else if (t == 27)
                //thaoTacPhimEsc(); Đang trong game ta về menu chinh
                    thaoTacPhimM(&r, huong);
        }
        if (r.ktDungConMoi()) {
            r.anConMoi();
            veConMoi(r);
            capNhatDiem(diem);
            if (r.tocDo >= 100 && diem > 0 && diem % 50 == 0)
                r.tocDo -= 20;
        }
        r.diChuyen(huong);
    }
    return 0;
}
