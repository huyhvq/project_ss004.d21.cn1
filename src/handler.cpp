#include <conio.h>

#include "handler.h"
#include "config.h"
#include "food.h"

// Forward declaration
void hienTrangThai(char trangThai[]);

void veGiaoDien();

void hienThiDiemCao();

void hienBangThongBao(int cdBang, int crBang, char *tieuDe, char *noiDung);

void xoaBangThongBao(int cdBang, int crBang);

void thaoTacPhimR(Snake *r, int &huong) {
    r->lamMoiRan();
    r->veThanRan();
    xoaConMoi();
    veConMoi(*r);
    huong = 0;
    hienTrangThai(trangThaiDangChoi);
}

void thaoTacPhimM(Snake *r, int &huong) {
    huong = 0;
    r->lamMoiRan();
    veGiaoDien();
    r->tocDo = doKho;
    veConMoi(*r);
    r->veThanRan();
}

void thaoTacPhimEsc()
{
    system("cls");
    exit(0);
}

void khiConRanPhamQuy(Snake *r) {
    char x;
    luotChoi = luotChoi + 1;
    if (diem > diemCao)
        diemCao = diem;
    hienThiDiemCao();
    // Hiện con rắn chết
    r->veConRanChet();
    // Hiện thông báo chơi lại hay về menu chính giua man hinh
    hienBangThongBao(22, 3, const_cast<char *>("RẮN ĐÃ CHẾT..!"), const_cast<char *>("R(Chơi lại) - M(Menu)"));
    hienTrangThai(trangThaiKetThuc);
    do {
        x = getch();
    } while (x != 'r' && x != 'R' && x != 27 && x != 'm' && x != 'M');

    if (x == 'r' || x == 'R') {
        xoaBangThongBao(22, 3);
        // thaoTacPhimR(r, Huong);
    } else if (x == 'm' || x == 'M') {
        // thaoTacPhimM(r, Huong);
    } else if (x = 27) {
        system("cls");
        exit(0);
    }
}

void tamDung(Snake *r, int &huong) {
    hienTrangThai(trangThaiDung);
    while (true) {
        char nhanPhim = getch();
        if (nhanPhim == ' ') {
            hienTrangThai(trangThaiDangChoi);
            return;
        } else if (nhanPhim == 'r' || nhanPhim == 'R') {
            thaoTacPhimR(r, huong);
            return;
        } else if (nhanPhim == 'm' || nhanPhim == 'M') {
            thaoTacPhimM(r, huong);
            return;
        } else if (nhanPhim == 27)
            thaoTacPhimEsc();
        return;
    }
}