#ifndef UI_SCREEN_H
#define UI_SCREEN_H
#include <string>

#include "point.h"

using namespace std;

void initialScreenSize();
void anConTro();
void veGiaoDien();
void veMenu();
void inGiuaCot1Cot2(int cot1, int cot2, int dong, string noiDung);
void hienThiThongTin();
void veKhungVien(Point gocTrai, Point gocPhai, int netVien);
void veBongDoKhungVien();
void hienBangThongBao(int cdBang, int crBang, char *tieuDe, char *noiDung);
void hienTrangThai(char trangThai[]);
void hienThiThongTin1();
void capNhatDiem(int diem);
void hienThiDiemCao();
void xoaBangThongBao(int cdBang, int crBang);
void veLaiDiemVienBiXoa(Point dauRan);

#endif //UI_SCREEN_H
