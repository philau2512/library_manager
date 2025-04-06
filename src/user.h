#ifndef USER_H
#define USER_H

// Khai báo số lượng tối đa độc giả
const int MAX_USERS = 100;

// Khai báo các mảng thông tin độc giả
extern char maDocGia[MAX_USERS][10];
extern char hoTen[MAX_USERS][100];
extern char cmnd[MAX_USERS][20];
extern char birth[MAX_USERS][11];
extern char gioiTinh[MAX_USERS][5];
extern char email[MAX_USERS][100];
extern char diaChi[MAX_USERS][100];
extern char ngayLapThe[MAX_USERS][11];
extern char ngayHetHan[MAX_USERS][11];

// Số lượng độc giả hiện có
extern int soLuongDocGia;

void quanLyDocGia(); // Quản lý độc giả
void showMenuDocGia(); // Hiển thị menu quản lý độc giả
void xemDanhSachDocGia(); // Xem danh sách độc giả
void themDocGia(); // Thêm độc giả mới
void chinhSuaDocGia(); // Chỉnh sửa thông tin độc giả
void xoaDocGia(); // Xóa thông tin độc giả
void timDocGiaTheoCmnd(); // Tìm độc giả theo CMND
void timDocGiaTheoHoTen(); // Tìm độc giả theo họ tên

bool tonTaiMaDocGia(const char *id); // Hàm kiểm tra mã độc giả tồn tại chưa ( true/ false )
#endif //USER_H
