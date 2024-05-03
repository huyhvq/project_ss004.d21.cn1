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

void Snake::diChuyen(int Huong)
{
    if (!lonLen)
    {
        // xóa hiển thị đốt cuối cùng khi di chuyển
        xoaDotCuoi();
    }
    else
        lonLen = false;

    // vị trí đầu rẵn sẽ là vị trí thân rắn khi di chuyên
    diChuyenCotDong(dotRan[0].cot,dotRan[0].dong);
    std::cout << "+";

    for (int i = doDai-1; i>0; i--)
        dotRan[i] = dotRan[i-1];
    if (Huong==0) dotRan[0].cot = dotRan[0].cot + 1;// rẽ phải
    if (Huong==1) dotRan[0].dong = dotRan[0].dong + 1;// đi xuống
    if (Huong==2) dotRan[0].cot = dotRan[0].cot - 1;// rẽ trái
    if (Huong==3) dotRan[0].dong = dotRan[0].dong - 1;// đi lên

    // Điều chỉnh tọa độ nếu rắn đi qua tường
    if(choPhepQuaTuong)
        ranDiChuyenQuaTuong();
}