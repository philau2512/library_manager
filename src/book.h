#ifndef BOOK_H
#define BOOK_H

// Khai báo số lượng sách tối đa
const int MAX_BOOKS = 100;

// Khai báo các mảng chứa thông tin sách
extern char maSach[MAX_BOOKS][10];
extern char tenSach[MAX_BOOKS][100];
extern char tacGia[MAX_BOOKS][100];
extern char nhaXuatBan[MAX_BOOKS][100];
extern char namXuatBan[MAX_BOOKS][10];
extern char theLoai[MAX_BOOKS][50];
extern double giaSach[MAX_BOOKS];
extern int soLuong[MAX_BOOKS];

// Số lượng sách hiện có
extern int soLuongSach;

void quanLySach(); // Hàm quản lý sách
void showMenuQuanLySach(); // hàm hiển thị menu chức năng
void xemSach(); // Xem danh sách sách có trong thư viện
void themSach(); // Thêm sách mới
void chinhSuaSach(); // Chỉnh sửa sách
void xoaSach(); // Xóa sách
void timSachTheoISBN(); // Tìm sách theo mã sách
void timSachTheoTen(); // Tìm sách theo tên sách

bool tonTaiMaSach(const char *id); // kiểm tra sự tồn tại của mã sách ( true/false )
bool coTheMuonSach(const char *id); // Kiểm tra nếu số lượng sách > 0 thì cho mượn !
bool giamSoLuongSach(const char *id); // Giảm số lượng sách khi mượn
bool tangSoLuongSach(const char *id); // Tăng số lượng sách khi trả

#endif // BOOK_H
