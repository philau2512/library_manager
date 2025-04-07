#include <iostream>
#include <string.h>
#include "borrow.h"
#include "utils.h"
#include "user.h"
#include "book.h"
using namespace std;

// Định nghĩa và khởi tạo các mảng lưu trữ thông tin phiếu mượn ( dữ liệu demo )
char maDocGiaMuon[MAX_BORROW_RECORDS][MAX_DOC_GIA_ID_LENGTH] = {"DG001", "DG002"};
char ngayMuon[MAX_BORROW_RECORDS][MAX_DATE_LENGTH] = {"01/01/2025", "15/02/2025"};
char ngayTraDuKien[MAX_BORROW_RECORDS][MAX_DATE_LENGTH] = {"05/01/2025", "15/03/2025"};
char danhSachISBNMuon[MAX_BORROW_RECORDS][MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH] = {
    {"B001", "B002", "B003", "B004", "B005"}, // mảng ISBN cho DG001
    {"B003", "B004"} // mảng ISBN cho DG002
};

int soLuongPhieuMuon = 2; // Số lượng phiếu mượn hiện có

void showMenuMuonSach() {
    cout << "1. Lap phieu muon" << endl;
    cout << "2. Hien thi phieu muon" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyMuonSach() {
    int choice;
    do {
        showMenuMuonSach();
        cin >> choice;
        switch (choice) {
            case 1:
                lapPhieuMuonSach();
                break;
            case 2:
                hienThiPhieuMuon();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void lapPhieuMuonSach() {
    cout << "Nhap ma doc gia muon: ";
    cin.ignore(); // Bỏ qua ký tự newline (\n) còn lại trong bộ đệm
    cin.getline(maDocGiaMuon[soLuongPhieuMuon], 10);

    if (!tonTaiMaDocGia(maDocGiaMuon[soLuongPhieuMuon])) {
        cout << "[X] Ma doc gia - " << maDocGiaMuon[soLuongPhieuMuon] << " khong ton tai, hay kiem tra lai." << endl;
        return;
    }
    cout << "Nhap ngay muon (dd/mm/yyyy): ";
    cin.getline(ngayMuon[soLuongPhieuMuon], 11);

    tinhNgayTraSachDuKien(ngayMuon[soLuongPhieuMuon], ngayTraDuKien[soLuongPhieuMuon]);

    int numBookBorrow;
    cout << "Nhap so luong sach muon: ";
    cin >> numBookBorrow;

    if (numBookBorrow > MAX_BOOKS_PER_RECORD) {
        cout << "[X] So luong sach muon khong duoc qua " << MAX_BOOKS_PER_RECORD << "." << endl;
        return;
    }

    cin.ignore();

    cout << "Nhap danh sach ISBN muon: " << endl;
    for (int i = 0; i < numBookBorrow; i++) {
        cout << "Nhap ma IBSN thu " << i + 1 << ": ";
        cin.getline(danhSachISBNMuon[soLuongPhieuMuon][i], 10);

        if (tonTaiMaSach(danhSachISBNMuon[soLuongPhieuMuon][i])) {
            // kiểm tra mã sách tồn tại
            if (coTheMuonSach(danhSachISBNMuon[soLuongPhieuMuon][i])) {
                // kiểm tra số lượng sách đó > 0
                bool status = giamSoLuongSach(danhSachISBNMuon[soLuongPhieuMuon][i]); // giảm 1 cuốn đã cho mượn
                if (!status) {
                    cout << "[X] Loi khi them sach - " << danhSachISBNMuon[soLuongPhieuMuon][i] << endl;
                    return;
                }
            } else {
                cout << "[X] Sach - " << danhSachISBNMuon[soLuongPhieuMuon][i] << " da het, khong the muon." << endl;
                return;
            }
        } else {
            cout << "[X] Ma ISBN - " << danhSachISBNMuon[soLuongPhieuMuon][i] << " khong ton tai, hay kiem tra lai." <<
                    endl;
            return;
        }
    }

    soLuongPhieuMuon++;
    cout << "[OK] Lap phieu muon sach thanh cong." << endl;
}

void hienThiPhieuMuon() {
    if (soLuongPhieuMuon == 0) {
        cout << "Khong co phieu muon nao." << endl;
        return;
    }

    for (int i = 0; i < soLuongPhieuMuon; i++) {
        cout << "Phieu muon thu " << i + 1 << ":" << endl;
        cout << "Ma doc gia: " << maDocGiaMuon[i] << endl;
        cout << "Ngay muon: " << ngayMuon[i] << endl;
        cout << "Ngay tra du kien: " << ngayTraDuKien[i] << endl;
        cout << "Danh sach ISBN muon:" << endl;
        for (int j = 0; j < MAX_BOOKS_PER_RECORD; j++) {
            if (danhSachISBNMuon[i][j][0] != '\0') {
                cout << danhSachISBNMuon[i][j] << "\t";
            } else {
                break;
            }
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}

int timPhieuMuon(const char *id) {
    int index = -1;
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (strcmp(maDocGiaMuon[i], id) == 0) {
            index = i;
            break;
        }
    }
    return index;
}