#include <iostream>
#include <string.h>
using namespace std;
#include "return.h"
#include "borrow.h"
#include "book.h"

// Mảng dữ liệu mẫu
char maDocGiaTra[MAX_RETURN_RECORDS][MAX_DOC_GIA_ID_LENGTH] = {"DG001"};
char ngayTraThucTe[MAX_RETURN_RECORDS][MAX_DATE_LENGTH] = {"05/02/2025"};
char danhSachISBNTra[MAX_RETURN_RECORDS][MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH] = {
    {"B001", "B002", "B003", "B004", "B005"}
};

int soLuongPhieuTra = 1;

void showMenuTraSach() {
    cout << "1. Lap phieu tra" << endl;
    cout << "2. Hien thi phieu tra" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyTraSach() {
    int choice;
    do {
        showMenuTraSach();
        cin >> choice;
        switch (choice) {
            case 1:
                lapPhieuTraSach();
                break;
            case 2:
                hienThiPhieuTra();
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai. Vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void lapPhieuTraSach() {
    if (soLuongPhieuTra >= MAX_RETURN_RECORDS) {
        cout << "Danh sach phieu tra day. Khong the them moi." << endl;
        return;
    }

    cout << "Nhap ma doc gia tra: ";
    cin.ignore();
    cin.getline(maDocGiaTra[soLuongPhieuTra], 10);

    int indexPhieuMuon = timPhieuMuon(maDocGiaTra[soLuongPhieuTra]);
    if (indexPhieuMuon == -1) {
        cout << "Doc gia khong co phieu muon sach." << endl;
        return;
    }

    cout << "Nhap ngay tra thuc te (dd/mm/yyyy): ";
    cin.getline(ngayTraThucTe[soLuongPhieuTra], 11);

    // Gán danh sách ISBN mượn cho danh sách ISBN trả
    int j = 0;
    while (danhSachISBNMuon[indexPhieuMuon][j][0] != '\0' && j < MAX_BOOKS_PER_RECORD) {
        // Sao chép từng ISBN từ danhSachISBNMuon vào danhSachISBNTra
        strcpy(danhSachISBNTra[soLuongPhieuTra][j], danhSachISBNMuon[indexPhieuMuon][j]);

        bool status = tangSoLuongSach(danhSachISBNTra[soLuongPhieuTra][j]);
        if (!status) {
            cout << "Co loi xay ra khi tra sach." << endl;
            return;
        }
        j++;
    }

    soLuongPhieuTra++;
    cout << "[OK] Lap phieu tra thanh cong !" << endl;
}

void hienThiPhieuTra() {
    if (soLuongPhieuTra == 0) {
        cout << "Danh sach phieu tra rong." << endl;
        return;
    }

    cout << "Danh sach phieu tra:" << endl;

    for (int i = 0; i < soLuongPhieuTra; i++) {
        cout << "Phieu tra thu " << i + 1 << ":" << endl;
        cout << "Ma doc gia: " << maDocGiaTra[i] << endl;
        cout << "Ngay tra thuc te: " << ngayTraThucTe[i] << endl;
        cout << "Danh sach ISBN tra:" << endl;
        for (int j = 0; j < MAX_BOOKS_PER_RECORD; j++) {
            if (danhSachISBNTra[i][j][0] != '\0') {
                cout << danhSachISBNTra[i][j] << " ";
            } else {
                break;
            }
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}
