#ifndef RETURN_H
#define RETURN_H
#include "data.h"

extern int soLuongPhieuTra;

extern char maDocGiaTra[MAX_RETURN_RECORDS][MAX_DOC_GIA_ID_LENGTH];
extern char ngayTraThucTe[MAX_RETURN_RECORDS][MAX_DATE_LENGTH];
extern char danhSachISBNTra[MAX_RETURN_RECORDS][MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH];

void quanLyTraSach(); // Hàm quản lý trả sách
void showMenuTraSach(); // Hàm show menu chức năng trả
void lapPhieuTraSach(); // Hàm lập phiếu trả
void hienThiPhieuTra(); // Hàm hiển thị các phiếu trả
#endif //RETURN_H
