#include <iostream>
#include <string.h>
#include "user.h"
#include "utils.h"
using namespace std;

int soLuongDocGia = 3; // Số lượng độc giả hiện tại

// Tạo danh sách độc giả demo
char maDocGia[MAX_USERS][10] = {"DG001", "DG002", "DG003"};
char hoTen[MAX_USERS][100] = {"Nguyen Thi Lan", "Tran Minh Tu", "Nguyen Van C"};
char cmnd[MAX_USERS][20] = {"123456789", "987654321", "456789125"};
char birth[MAX_USERS][11] = {"21/03/1998", "15/05/2000", "13/07/2001"};
char gioiTinh[MAX_USERS][5] = {"Nu", "Nam", "Nam"};
char email[MAX_USERS][100] = {"lannt@gmail.com", "tmtu@gmail.com", "nguyenvanc@gmail.com"};
char diaChi[MAX_USERS][100] = {"123 Le Lai, TP.HCM", "456 Nguyen Thi Minh Khai, TP.HCM", "11 Hong Bang, TPHCM"};
char ngayLapThe[MAX_USERS][11] = {"01/01/2022", "15/02/2021", "12/09/2023"};
char ngayHetHan[MAX_USERS][11] = {"01/01/2026", "15/02/2025", "12/09/2027"};

// Hàm hiển thị menu quản lý độc giả
void showMenuDocGia() {
    cout << "1. Xem danh sach doc gia\n";
    cout << "2. Them doc gia moi\n";
    cout << "3. Chinh sua thong tin doc gia\n";
    cout << "4. Xoa thong tin doc gia\n";
    cout << "5. Tim kiem doc gia theo CMND\n";
    cout << "6. Tim kiem doc gia theo ho ten\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "--> Nhap lua chon: ";
}

// Hàm quản lý độc giả
void quanLyDocGia() {
    int choice;
    do {
        showMenuDocGia();
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự '\n' còn lại trong buffer
        switch (choice) {
            case 1:
                xemDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                chinhSuaDocGia();
                break;
            case 4:
                xoaDocGia();
                break;
            case 5:
                timDocGiaTheoCmnd();
                break;
            case 6:
                timDocGiaTheoHoTen();
                break;
            case 0:
                cout << "Quay lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}

void xemDanhSachDocGia() {
    if (soLuongDocGia == 0) {
        cout << "Danh sach doc gia rong.\n";
        return;
    }
    cout << "Danh sach doc gia:\n";
    cout << "STT | Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        cout << "[" << i + 1 << "]" << " | "
                << maDocGia[i] << " | "
                << hoTen[i] << " | "
                << cmnd[i] << " | "
                << birth[i] << " | "
                << gioiTinh[i] << " | "
                << email[i] << " | "
                << diaChi[i] << " | "
                << ngayLapThe[i] << " | "
                << ngayHetHan[i] << "\n";
    }
    cout << endl;
};

void themDocGia() {
    if (soLuongDocGia >= MAX_USERS) {
        cout << "Danh sach doc gia da day. Khong the them moi.\n";
        return;
    }

    cout << "Nhap thong tin doc gia moi:\n";

    cout << "Nhap ma doc gia: ";
    cin.getline(maDocGia[soLuongDocGia], 10);
    cout << "Nhap ho ten: ";
    cin.getline(hoTen[soLuongDocGia], 100);
    cout << "Nhap CMND: ";
    cin.getline(cmnd[soLuongDocGia], 20);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(birth[soLuongDocGia], 11);
    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin.getline(gioiTinh[soLuongDocGia], 5);
    cout << "Nhap email: ";
    cin.getline(email[soLuongDocGia], 100);
    cout << "Nhap dia chi: ";
    cin.getline(diaChi[soLuongDocGia], 100);
    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    cin.getline(ngayLapThe[soLuongDocGia], 11);

    calculateExpiryDate(ngayLapThe[soLuongDocGia], ngayHetHan[soLuongDocGia]);

    soLuongDocGia++;
    cout << "[OK] Them doc gia thanh cong!\n";
};

void chinhSuaDocGia() {
    char id[10];
    cout << "Nhap ma doc gia can chinh sua: ";
    cin.getline(id, 10);

    // Tìm vị trí độc giả cần chỉnh sửa
    int index = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Doc gia co ma " << id << " khong ton tai.\n";
        return;
    }

    cin.ignore();

    cout << "Nhap thong tin doc gia can chinh sua:\n";

    cout << "Nhap ma doc gia: ";
    cin.getline(maDocGia[index], 10);
    cout << "Nhap ho ten: ";
    cin.getline(hoTen[index], 100);
    cout << "Nhap CMND: ";
    cin.getline(cmnd[index], 20);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(birth[soLuongDocGia], 11);
    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin.getline(gioiTinh[soLuongDocGia], 5);
    cout << "Nhap email: ";
    cin.getline(email[index], 100);
    cout << "Nhap dia chi: ";
    cin.getline(diaChi[index], 100);
    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    cin.getline(ngayLapThe[index], 11);

    calculateExpiryDate(ngayLapThe[index], ngayHetHan[index]);

    cout << "[OK] Chinh sua doc gia thanh cong!\n";
};

void xoaDocGia() {
    char id[10];
    cout << "Nhap ma doc gia can xoa: ";
    cin.getline(id, 10);

    // Tìm vị trí độc giả cần xóa
    int index = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (stricmp(maDocGia[i], id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Doc gia co ma " << id << " khong ton tai.\n";
        return;
    }

    // dịch chuyển các độc giả phía sau lên ( ghì đè vị trí độc giả cần xóa )
    for (int i = index; i < soLuongDocGia - 1; i++) {
        strcpy(maDocGia[i], maDocGia[i + 1]);
        strcpy(hoTen[i], hoTen[i + 1]);
        strcpy(cmnd[i], cmnd[i + 1]);
        strcpy(birth[i], birth[i + 1]);
        strcpy(gioiTinh[i], gioiTinh[i + 1]);
        strcpy(email[i], email[i + 1]);
        strcpy(diaChi[i], diaChi[i + 1]);
        strcpy(ngayLapThe[i], ngayLapThe[i + 1]);
        strcpy(ngayHetHan[i], ngayHetHan[i + 1]);
    }

    // Trừ 1 độc giả
    soLuongDocGia--;

    cout << "[OK] Xoa doc gia thanh cong!\n";
};

void timDocGiaTheoCmnd() {
    char cmndToFind[20];
    cout << "Nhap CMND cua doc gia can tim: ";
    cin.getline(cmndToFind, 20);

    bool found = false;
    cout << "Danh sach doc gia co CMND " << cmndToFind << ":\n";
    cout << "STT | Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(cmnd[i], cmndToFind) == 0) {
            cout << "[" << i + 1 << "]" << " | "
                    << maDocGia[i] << " | "
                    << hoTen[i] << " | "
                    << cmnd[i] << " | "
                    << birth[i] << " | "
                    << gioiTinh[i] << " | "
                    << email[i] << " | "
                    << diaChi[i] << " | "
                    << ngayLapThe[i] << " | "
                    << ngayHetHan[i] << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay doc gia co CMND " << cmndToFind << ".\n";
    }
    cout << endl;
};

void timDocGiaTheoHoTen() {
    char hoTenToFind[100];
    cout << "Nhap ho ten cua doc gia can tim: ";
    cin.getline(hoTenToFind, 100);

    bool found = false;
    cout << "Danh sach doc gia co ten - " << hoTenToFind << ":\n";
    cout << "STT | Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";

    // dùng strstr để lấy tên gần đúng || dùng strcmp để tìm chính xác tên
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strstr(hoTen[i], hoTenToFind) != NULL) {
            cout << "[" << i + 1 << "]" << " | "
                    << maDocGia[i] << " | "
                    << hoTen[i] << " | "
                    << cmnd[i] << " | "
                    << birth[i] << " | "
                    << gioiTinh[i] << " | "
                    << email[i] << " | "
                    << diaChi[i] << " | "
                    << ngayLapThe[i] << " | "
                    << ngayHetHan[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay doc gia co ten " << hoTenToFind << ".\n";
    }
    cout << endl;
};

bool tonTaiMaDocGia(const char *id) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], id) == 0) {
            return true;
        }
    }
    return false;
}
