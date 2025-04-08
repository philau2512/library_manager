#include <iostream>
#include <string.h>
using namespace std;
#include "statistics.h"
#include "user.h"
#include "book.h"
#include "borrow.h"
#include "return.h"
#include "utils.h"

void showMenuThongKe() {
    cout << "1. Thong ke so luong sach trong thu vien" << endl;
    cout << "2. Thong ke so luong sach theo the loai" << endl;
    cout << "3. Thong ke so luong doc gia" << endl;
    cout << "4. Thong ke so luong doc gia theo gioi tinh" << endl;
    cout << "5. Thong ke so sach dang duoc muon" << endl;
    cout << "6. Thong ke danh sach doc gia bi tre han" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyThongKe() {
    int choice;
    do {
        showMenuThongKe();
        cin >> choice;
        switch (choice) {
            case 1:
                thongKeSoLuongSach();
                break;
            case 2:
                thongKeSoLuongSachTheoTheLoai();
                break;
            case 3:
                thongKeSoLuongDocGia();
                break;
            case 4:
                thongKeSoLuongDocGiaTheoGioiTinh();
                break;
            case 5:
                thongKeSoSachDangDuocMuon();
                break;
            case 6:
                thongKeDanhSachDocGiaBiTreHan();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void thongKeSoLuongSach() {
    cout << "So luong cac sach trong thu vien: " << endl;
    int sum = 0;
    for (int i = 0; i < soLuongSach; i++) {
        cout << i + 1 << ". " << tenSach[i] << " - " << soLuong[i] << endl;
        sum += soLuong[i];
    }
    cout << "Tong so luong sach trong thu vien: " << sum << endl;
    cout << endl;
}

void thongKeSoLuongSachTheoTheLoai() {
    cout << "So luong cac sach theo the loai: " << endl;
    for (int i = 0; i < soLuongSach; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (strcmp(theLoai[i], theLoai[j]) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            int count = 0;
            for (int k = 0; k < soLuongSach; k++) {
                if (strcmp(theLoai[i], theLoai[k]) == 0) {
                    count += soLuong[k];
                }
            }
            cout << theLoai[i] << ": " << count << endl;
        }
    }
    cout << endl;
}

void thongKeSoLuongDocGia() {
    cout << "So luong doc gia trong thu vien: " << soLuongDocGia << endl;
    cout << endl;
}

void thongKeSoLuongDocGiaTheoGioiTinh() {
    cout << "So luong doc gia theo gioi tinh: " << endl;
    int countMale = 0;
    int countFemale = 0;

    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(gioiTinh[i], "Nam") == 0) {
            countMale++;
        } else if (strcmp(gioiTinh[i], "Nu") == 0) {
            countFemale++;
        }
    }

    cout << "Nam: " << countMale << endl;
    cout << "Nu: " << countFemale << endl;
    cout << endl;
}

void thongKeSoSachDangDuocMuon() {
    int count = 0;
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        for (int j = 0; j < MAX_BOOKS_PER_RECORD; j++) {
            if (danhSachISBNMuon[i][j][0] != '\0') {
                count++;
            }
        }
    }
    cout << "So luong sach dang duoc muon: " << count << endl;
    cout << endl;
}

void thongKeDanhSachDocGiaBiTreHan() {
    cout << "Danh sach doc gia bi tre han: " << endl;
    bool hasUser = false;
    int indexMuon = 0;
    int indexTra = 0;
    int count = 0;

    for (int i = 0; i < soLuongDocGia; i++) {
        // Kiểm tra xem độc giả có phiếu trả hay không
        bool hasReturned = false;

        // Kiểm tra xem mã độc giả có tồn tại trong phiếu trả không
        for (int j = 0; j < MAX_RETURN_RECORDS; j++) {
            if (strcmp(maDocGia[i], maDocGiaTra[j]) == 0) {
                indexMuon = i;
                indexTra = j;
                hasReturned = true; // Nếu có phiếu trả
                break;
            }
        }

        // Nếu có phiếu trả, kiểm tra trễ hạn
        if (hasReturned) {
            int daysDiff = isExpired(ngayMuon[indexMuon], ngayTraThucTe[indexTra]);
            if (daysDiff > 0) {
                hasUser = true;
                count++;
                cout << "[*] " << maDocGia[i] << " - " << hoTen[i] << " - tre " << daysDiff << " ngay" <<
                        endl;
            }
        }
    }
    if (!hasUser) {
        cout << "Khong co doc gia bi tre han." << endl;
    } else {
        cout << "Co " << count << " doc gia bi tre han." << endl;
    }

    cout << endl;
}
