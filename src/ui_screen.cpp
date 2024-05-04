#include <cmath>
#include <windows.h>
#include <iostream>
#include <conio.h>

#include "ui_screen.h"
#include "config.h"
#include "animation.h"

void anConTro() {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void veGiaoDien() {
    system("cls");
    veMenu();
    hienThiThongTin();
    hienThiThongTin1();
    capNhatDiem(0);
    hienThiDiemCao();
    veKhungVien(gocTraiTren, gocPhaiDuoi, 2);
    veBongDoKhungVien();
}

void veMenu() {
    char x;
    system("cls");
    hienThiThongTin();
    // Vẽ khung viền nét đôi
    veKhungVien(gocTraiTren, gocPhaiDuoi, 2);
    veBongDoKhungVien();
    hienBangThongBao(22, 5, const_cast<char *>("Chọn chế độ chơi"), const_cast<char *>(""));
    diChuyenCotDong(gocTraiTren.cot + 34, gocTraiTren.dong + 9);
    cout << "1: Cổ điển" << endl;
    diChuyenCotDong(gocTraiTren.cot + 34, gocTraiTren.dong + 10);
    cout << "2: Hiện đại" << endl;
    diChuyenCotDong(gocTraiTren.cot + 25, gocPhaiDuoi.dong + 3);
    cout << "Dùng phím số để chọn chế độ chơi";
    diChuyenCotDong(gocTraiTren.cot + 25, gocPhaiDuoi.dong + 4);
    cout << "Dùng phím <ESC> để thoát chương trình" << endl;
    do {
        x = getch();
    } while (x != '1' && x != '2' && x != 27);

    if (x == '2') {
        choPhepQuaTuong = true;
    } else if (x == '1') {
        choPhepQuaTuong = false;
    } else if (x == 27) {
        system("cls");
        exit(0);
    }

    system("cls");
    hienThiThongTin();
    // Vẽ khung viền nét đôi
    veKhungVien(gocTraiTren, gocPhaiDuoi, 2);
    veBongDoKhungVien();
    hienBangThongBao(22, 6, const_cast<char *>("Chọn độ khó"), const_cast<char *>("Chọn độ khó"));
    diChuyenCotDong(gocTraiTren.cot + 34, gocTraiTren.dong + 8);
    cout << "1: Dễ" << endl;
    diChuyenCotDong(gocTraiTren.cot + 34, gocTraiTren.dong + 9);
    cout << "2: Trung bình" << endl;
    diChuyenCotDong(gocTraiTren.cot + 34, gocTraiTren.dong + 10);
    cout << "3: Khó" << endl;

    diChuyenCotDong(gocTraiTren.cot + 25, gocPhaiDuoi.dong + 3);
    cout << "Dùng phím số để chọn độ khó";
    diChuyenCotDong(gocTraiTren.cot + 25, gocPhaiDuoi.dong + 4);
    cout << "Dùng phím <ESC> để thoát chương trình" << endl;
    do {
        x = getch();
    } while (x != '1' && x != '2' & x != '3' && x != 27);

    if (x == '1') {
        capDo = 1;
        doKho = tocDoThap;
    } else if (x == '2') {
        capDo = 2;
        doKho = tocDoTrungBinh;
    } else if (x == '3') {
        capDo = 3;
        doKho = tocDoCao;
    } else if (x == 27) {
        system("cls");
        exit(0);
    }
    system("cls");
}

void hienThiThongTin() {
    // In logo
    inGiuaCot1Cot2(1, gocTraiTren.cot, gocTraiTren.dong - 3, "SS004.D21.CN1");
    inGiuaCot1Cot2(0, gocTraiTren.cot, gocTraiTren.dong - 2, "CN1.2023.2");
    inGiuaCot1Cot2(0, gocTraiTren.cot, gocTraiTren.dong - 1, "Nhóm 15");
    // In giới thiệu
    inGiuaCot1Cot2(gocTraiTren.cot + 8, gocPhaiDuoi.cot, gocTraiTren.dong - 4, "CHƯƠNG TRÌNH RẮN SĂN MỒI");
    inGiuaCot1Cot2(gocTraiTren.cot, gocPhaiDuoi.cot, gocTraiTren.dong - 3, "oOo");
    inGiuaCot1Cot2(gocTraiTren.cot + 18, gocPhaiDuoi.cot, gocTraiTren.dong - 2,
                   "[ Phạm Trấn Hào <23730083@ms.uit.edu.vn> | Phan Hoàng Thái <23730124@ms.uit.edu.vn> ]");
    inGiuaCot1Cot2(gocTraiTren.cot + 18, gocPhaiDuoi.cot, gocTraiTren.dong - 1,
                   "[ Huỳnh Viết Quang Huy <23730090@ms.uit.edu.vn> | Nguyễn Thuỵ Nghi Quân <23730090@ms.uit.edu.vn>]");
}

void inGiuaCot1Cot2(int cot1, int cot2, int dong, string noiDung) {
    int nuaDoan = round(abs(cot2 - cot1) / 2);
    int nuaNoiDung = round(noiDung.length() / 2);
    diChuyenCotDong(abs((cot1 + nuaDoan) - nuaNoiDung), dong);
    cout << noiDung;
}

void veKhungVien(Point gocTrai, Point gocPhai, int netVien) {
    SetConsoleOutputCP(consoleOCP);
    if (netVien == 1) {
        for (int i = gocTrai.cot + 1; i < gocPhai.cot; i++) {
            diChuyenCotDong(i, gocTrai.dong); // Dòng trên cùng
            cout << (char) 196;
            diChuyenCotDong(i, gocPhai.dong); // Dòng dưới cùng
            cout << (char) 196;
        }
        for (int i = gocTrai.dong + 1; i < gocPhai.dong; i++) {
            diChuyenCotDong(gocTrai.cot, i); // Cột bên trái
            cout << (char) 179;
            diChuyenCotDong(gocPhai.cot, i); // Cột phải
            cout << (char) 179;
        }
        // Vẽ 4 góc của khung
        diChuyenCotDong(gocTrai.cot, gocTrai.dong);
        cout << (char) 218;
        diChuyenCotDong(gocPhai.cot, gocTrai.dong);
        cout << (char) 191;
        diChuyenCotDong(gocTrai.cot, gocPhai.dong);
        cout << (char) 192;
        diChuyenCotDong(gocPhai.cot, gocPhai.dong);
        cout << (char) 217;
    } else if (netVien == 2) {
        for (int i = gocTrai.cot + 1; i < gocPhai.cot; i++) {
            diChuyenCotDong(i, gocTrai.dong); // Dòng trên cùng
            cout << (char) 205;
            diChuyenCotDong(i, gocPhai.dong); // Dòng dưới cùng
            cout << (char) 205;
        }
        for (int i = gocTrai.dong + 1; i < gocPhai.dong; i++) {
            diChuyenCotDong(gocTrai.cot, i); // Cột bên trái
            cout << (char) 186;
            diChuyenCotDong(gocPhai.cot, i); // Cột phải
            cout << (char) 186;
        }
        // Vẽ 4 góc của khung
        diChuyenCotDong(gocTrai.cot, gocTrai.dong);
        cout << (char) 201;
        diChuyenCotDong(gocPhai.cot, gocTrai.dong);
        cout << (char) 187;
        diChuyenCotDong(gocTrai.cot, gocPhai.dong);
        cout << (char) 200;
        diChuyenCotDong(gocPhai.cot, gocPhai.dong);
        cout << (char) 188;
    }
    // Trả lại trang thai xuất tiếng việt có dấu ra màn hình
    SetConsoleOutputCP(65001);
}

void veBongDoKhungVien() {
    SetConsoleOutputCP(consoleOCP);
    for (int i = gocTraiTren.cot + 1; i <= gocPhaiDuoi.cot + 2; i++) {
        diChuyenCotDong(i, gocPhaiDuoi.dong + 1); // Dòng đổ bóng dưới cùng
        cout << (char) 176;
    }
    for (int i = gocTraiTren.dong + 1; i <= gocPhaiDuoi.dong; i++) {
        diChuyenCotDong(gocPhaiDuoi.cot + 1, i); // Cột đổ bóng bên phải 1
        cout << (char) 176;
        diChuyenCotDong(gocPhaiDuoi.cot + 2, i); // Cột đổ bóng bên phải 2
        cout << (char) 176;
    }
    // Trả lại trang thai xuất tiếng việt có dấu ra màn hình
    SetConsoleOutputCP(65001);
}

void hienBangThongBao(int cdBang, int crBang, char *tieuDe, char *noiDung) {
    Point gocTrai, gocPhai;
    Point diemGiua = layDiemTrungTam();
    gocTrai.cot = diemGiua.cot - cdBang / 2;
    gocTrai.dong = diemGiua.dong - crBang / 2;
    gocPhai.cot = diemGiua.cot + cdBang / 2;
    gocPhai.dong = diemGiua.dong + crBang / 2;
    veKhungVien(gocTrai, gocPhai, 1);
    // Thông báo thua với tiêu đề và nội dung
    inGiuaCot1Cot2(gocTrai.cot + 6, gocPhai.cot, gocTrai.dong, tieuDe); // Vì tiếng việt có 6 dấu
    // Nội dung trong bảng
    diChuyenCotDong(gocTrai.cot + 1, gocTrai.dong + 1);
    cout << noiDung;
}

void hienThiThongTin1() {
    // In thông báo điểm - độ khó - trạng thái
    inGiuaCot1Cot2(2, gocTraiTren.cot, gocTraiTren.dong + 2, "ĐIỂM");
    inGiuaCot1Cot2(3, gocTraiTren.cot, gocTraiTren.dong + 5, "ĐỘ KHÓ");
    if (capDo == 1)
        inGiuaCot1Cot2(2, gocTraiTren.cot, gocTraiTren.dong + 6, "Dễ");
    else if (capDo == 2)
        inGiuaCot1Cot2(1, gocTraiTren.cot, gocTraiTren.dong + 6, "Trung Bình");
    else if (capDo == 3)
        inGiuaCot1Cot2(1, gocTraiTren.cot, gocTraiTren.dong + 6, "Khó");
    inGiuaCot1Cot2(2, gocTraiTren.cot, gocTraiTren.dong + 8, "TRẠNG THÁI");
    hienTrangThai(trangThaiDangChoi);
    // In hướng dẫn

    diChuyenCotDong(gocTraiTren.cot, gocPhaiDuoi.dong + 3);
    cout << "Phím Mũi tên hay <A-S-W-D> để Di chuyển";
    diChuyenCotDong(gocPhaiDuoi.cot - 32, gocPhaiDuoi.dong + 3);
    cout << "<R> Chơi lại >><< Để gọi Menu <M>";
    diChuyenCotDong(gocTraiTren.cot, gocPhaiDuoi.dong + 4);
    cout << "Dùng phím <SPACE> để Tạm dừng";
    diChuyenCotDong(gocPhaiDuoi.cot - 23, gocPhaiDuoi.dong + 4);
    cout << "Dùng phím <ESC> để Thoát";
}

void hienTrangThai(char trangThai[]) {
    // Xóa trạng thái cũ
    inGiuaCot1Cot2(2, gocTraiTren.cot, gocTraiTren.dong + 9, "          ");
    inGiuaCot1Cot2(2, gocTraiTren.cot, gocTraiTren.dong + 9, trangThai);
}

void capNhatDiem(int diem) {
    // Xóa điểm cũ
    inGiuaCot1Cot2(0, gocTraiTren.cot, gocTraiTren.dong + 3, "    ");
    // Ghi điểm mới
    diChuyenCotDong(5, gocTraiTren.dong + 3);
    cout << " " << diem;
}

void hienThiDiemCao() {
    diChuyenCotDong(gocPhaiDuoi.cot + 4, 1);
    cout << "Điểm cao: " << diemCao << "/" << luotChoi;
}

void xoaBangThongBao(int cdBang, int crBang) {
    Point diemGiua = layDiemTrungTam();
    for (int i = (diemGiua.dong - crBang / 2); i < diemGiua.dong + crBang / 2 + 2; i++) {
        diChuyenCotDong(diemGiua.cot - cdBang / 2, i); // Cột bên trái
        cout << "                         ";
    }
}

void veLaiDiemVienBiXoa(Point dauRan)
{
    SetConsoleOutputCP(consoleOCP);
    diChuyenCotDong(dauRan.cot, dauRan.dong);
    if(dauRan.cot == gocTraiTren.cot)
    {
        cout << (char)186;
    }
    else if (dauRan.cot == gocPhaiDuoi.cot)
    {
        cout << (char)186;
    }
    else if(dauRan.dong == gocTraiTren.dong)
    {
        cout<< (char)205;
    }
    else if(dauRan.dong == gocPhaiDuoi.dong)
    {
        cout<< (char)205;
    }
    SetConsoleOutputCP(65001);
}