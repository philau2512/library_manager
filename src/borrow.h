#ifndef BORROW_H
#define BORROW_H

const int MAX_BORROW_RECORDS = 100;  // Giới hạn số lượng phiếu mượn tối đa
const int MAX_BOOKS_PER_BORROW_RECORD = 5; // Giới hạn số sách mượn tối đa
// Các mảng lưu trữ thông tin phiếu mượn
extern char maDocGiaMuon[MAX_BORROW_RECORDS][10];       // Mã độc giả mượn
extern char ngayMuon[MAX_BORROW_RECORDS][11];           // Ngày mượn
extern char ngayTraDuKien[MAX_BORROW_RECORDS][11];      // Ngày trả dự kiến
extern char danhSachISBNMuon[MAX_BORROW_RECORDS][5][10];  // Danh sách ISBN sách mượn ( giới hạn mượn max 5 cuốn )

extern int soLuongPhieuMuon;  // Số lượng phiếu mượn hiện tại

void quanLyMuonSach(); // Hàm quản lý mượn sách
void showMenuMuonSach(); // show menu chuc nang
void lapPhieuMuonSach(); // Hàm lập phiếu mượn sách
void hienThiPhieuMuon(); // Hiển thị tất cả phiếu mượn
#endif //BORROW_H