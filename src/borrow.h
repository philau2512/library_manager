#ifndef BORROW_H
#define BORROW_H
#include "data.h"

// Các mảng lưu trữ thông tin phiếu mượn
extern char maDocGiaMuon[MAX_BORROW_RECORDS][MAX_DOC_GIA_ID_LENGTH];       // Mã độc giả mượn
extern char ngayMuon[MAX_BORROW_RECORDS][MAX_DATE_LENGTH];           // Ngày mượn
extern char ngayTraDuKien[MAX_BORROW_RECORDS][MAX_DATE_LENGTH];      // Ngày trả dự kiến
extern char danhSachISBNMuon[MAX_BORROW_RECORDS][MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH ];  // Danh sách ISBN sách mượn ( giới hạn mượn max 5 cuốn )

extern int soLuongPhieuMuon;  // Số lượng phiếu mượn hiện tại

void quanLyMuonSach(); // Hàm quản lý mượn sách
void showMenuMuonSach(); // show menu chuc nang
void lapPhieuMuonSach(); // Hàm lập phiếu mượn sách
void hienThiPhieuMuon(); // Hiển thị tất cả phiếu mượn

int timPhieuMuon(const char *id); // hàm tìm index phiếu mượn theo Mã Độc Giả
#endif //BORROW_H