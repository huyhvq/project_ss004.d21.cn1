#include "point.h"

Point conMoi;
Point gocTraiTren = {15,06};
Point gocPhaiDuoi = {97,24};

Point layDiemTrungTam()
{
    Point diemTT{};
    diemTT.cot = (gocTraiTren.cot + gocPhaiDuoi.cot)/2;
    diemTT.dong = (gocTraiTren.dong + gocPhaiDuoi.dong)/2;
    return diemTT;
}
