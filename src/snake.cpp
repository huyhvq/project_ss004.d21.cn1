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
    for (int i = 0; i < doDai; i++)
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
    diChuyenCotDong(dotRan[0].cot, dotRan[0].dong);
    std::cout << "+";

    for (int i = doDai - 1; i > 0; i--)
        dotRan[i] = dotRan[i - 1];
    if (Huong == 0) dotRan[0].cot = dotRan[0].cot + 1;// rẽ phải
    if (Huong == 1) dotRan[0].dong = dotRan[0].dong + 1;// đi xuống
    if (Huong == 2) dotRan[0].cot = dotRan[0].cot - 1;// rẽ trái
    if (Huong == 3) dotRan[0].dong = dotRan[0].dong - 1;// đi lên

    // Điều chỉnh tọa độ nếu rắn đi qua tường
    if (choPhepQuaTuong)
        ranDiChuyenQuaTuong();
}

void Snake::ranDiChuyenQuaTuong()
{
    // Kiểm tra xem đầu rắn có ra khỏi màn hình không
    if (dotRan[0].cot == gocTraiTren.cot)
        dotRan[0].cot = gocPhaiDuoi.cot - 1;
    else if (dotRan[0].cot == gocPhaiDuoi.cot)
        dotRan[0].cot = gocTraiTren.cot + 1;
    else if (dotRan[0].dong == gocTraiTren.dong)
        dotRan[0].dong = gocPhaiDuoi.dong - 1;
    else if (dotRan[0].dong == gocPhaiDuoi.dong)
        dotRan[0].dong = gocTraiTren.dong + 1;
}

void Snake::veConRan()
{
    diChuyenCotDong(dotRan[0].cot, dotRan[0].dong);
    std::cout << "O";
    for (int i = 1; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot, dotRan[i].dong);
        std::cout << "+";
    }
}

void Snake::veThanRan()
{
    for (int i = 1; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot, dotRan[i].dong);
        std::cout << "+";
    }
}

void Snake::veDauRan()
{
    diChuyenCotDong(dotRan[0].cot, dotRan[0].dong);
    std::cout << "O";
}

void Snake::xoaDotCuoi()
{
    diChuyenCotDong(dotRan[doDai - 1].cot, dotRan[doDai - 1].dong);
    std::cout << " ";
}

void Snake::xoaConRan()
{
    for (int i = 0; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot, dotRan[i].dong);
        std::cout << " ";
    }
}

void Snake::veConRanChet()
{
    // Ve minh khi chet
    for (int i = 1; i < doDai; i++)
    {
        diChuyenCotDong(dotRan[i].cot, dotRan[i].dong);
        std::cout << ".";
    }
    // Ve cai dau khi chet
    diChuyenCotDong(dotRan[0].cot, dotRan[0].dong);
    std::cout << "*";
}

bool Snake::ktConRanPhamQuy()
{
    if (ktConRanChamKhung())
        return true;
    // Đầu rắn đốt[0] trùng với thân rắn từ đốt[1] đến đốt độ dài con rắn -1
    for (int i = 1; i < doDai; i++)
    {
        if (dotRan[0].cot == dotRan[i].cot && dotRan[0].dong == dotRan[i].dong)
            return true;
    }
    return false;
}

bool Snake::ktConRanChamKhung()
{
    if (choPhepQuaTuong)
    {
        return false;
    }
    // Khi dau ran trùng -> Cot trai || cot phai || dong tren || dong duoi
    if (dotRan[0].cot == gocTraiTren.cot || dotRan[0].cot == gocPhaiDuoi.cot || dotRan[0].dong == gocTraiTren.dong || dotRan[0].dong == gocPhaiDuoi.dong)
        return true;
    return false;
}

void Snake::anConMoi()
{
    dotRan[doDai] = dotRan[doDai - 1];
    doDai += 1;
    diem += 10;
    lonLen = true;
}

bool Snake::ktDungConMoi()
{
    if (dotRan[0].cot == conMoi.cot && dotRan[0].dong == conMoi.dong)
        return true;
    return false;
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
