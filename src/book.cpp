#include <iostream>
#include <string.h>
#include "book.h"
using namespace std;

// Tạo danh sách Sách demo
char maSach[MAX_BOOKS][10] = {"B001", "B002", "B003", "B004", "B005"};
char tenSach[MAX_BOOKS][100] = {
    "Toi Tham Mieu", "Doi Moi", "Viet Nam Lua Chon", "Cac Cuon Sach Hay", "Tinh Yeu Va Cuoc Song"
};
char tacGia[MAX_BOOKS][100] = {"Author 1", "Author 2", "Author 3", "Author 4", "Author 5"};
char nhaXuatBan[MAX_BOOKS][100] = {"Kim Dong", "Nha Xuat Ban Tre", "Alpha Books", "Thai Ha Books", "NXB Giao Duc"};
char namXuatBan[MAX_BOOKS][10] = {"2024", "2023", "2022", "2021", "2020"};
char theLoai[MAX_BOOKS][50] = {"Van Hoc", "Kinh Te", "Van Hoc", "Kinh Te", "Van Hoc"};
double giaSach[MAX_BOOKS] = {10000.0, 15000.5, 20000.75, 12000.25, 8000.0};
int soLuong[MAX_BOOKS] = {5, 3, 2, 0, 1};

int soLuongSach = 5; // tổng số lượng sách có trong thư viện

void showMenuQuanLySach() {
    cout << "1. Xem danh sach 'Sach'\n";
    cout << "2. Them sach moi\n";
    cout << "3. Chinh sua sach\n";
    cout << "4. Xoa sach\n";
    cout << "5. Tim kiem sach theo ISBN ( maSach )\n";
    cout << "6. Tim kiem sach theo ten\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "Chon chuc nang: ";
}

void quanLySach() {
    int choice;
    int indexBook = -1;
    do {
        showMenuQuanLySach();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                xemSach();
                break;
            case 2:
                themSach();
                break;
            case 3:
                chinhSuaSach();
                break;
            case 4:
                xoaSach();
                break;
            case 5:
                indexBook = timSachTheoISBN();
                if (indexBook == -1) {
                    cout << "[X] Khong tim thay sach !." << endl;
                } else {
                    printBookInfo(indexBook);
                }
                break;
            case 6:
                indexBook = timSachTheoTen();
                if (indexBook == -1) {
                    cout << "[X] Khong tim thay sach !." << endl;
                } else {
                    printBookInfo(indexBook);
                }
                break;
            case 0:
                cout << "Quay lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}

void xemSach() {
    if (soLuongSach == 0) {
        cout << "Danh sach sach rong.\n";
        return;
    }
    cout << "Danh sach sach:\n";
    cout << "STT | Ma Sach | Ten Sach | Tac Gia | Nha Xuat Ban | Nam Xuat Ban | The Loai | Gia Sach | So Luong\n";
    for (int i = 0; i < soLuongSach; i++) {
        cout << "[" << i + 1 << "]" << " | "
                << maSach[i] << " | "
                << tenSach[i] << " | "
                << tacGia[i] << " | "
                << nhaXuatBan[i] << " | "
                << namXuatBan[i] << " | "
                << theLoai[i] << " | "
                << giaSach[i] << " | "
                << soLuong[i] << "\n";
    }
    cout << endl;
}

void themSach() {
    if (soLuongSach >= MAX_BOOKS) {
        cout << "[X] Danh sach sach day. Khong the them moi.\n";
        return;
    }
    cout << "Nhap thong tin sach moi:\n";

    cout << "Ma Sach: ";
    cin.getline(maSach[soLuongSach], 10);

    if (tonTaiMaSach(maSach[soLuongSach])) {
        cout << "[X] Ma sach da ton tai. Khong the them moi.\n";
        return;
    }

    cout << "Ten Sach: ";
    cin.getline(tenSach[soLuongSach], 100);
    cout << "Tac Gia: ";
    cin.getline(tacGia[soLuongSach], 100);
    cout << "Nha Xuat Ban: ";
    cin.getline(nhaXuatBan[soLuongSach], 100);
    cout << "Nam Xuat Ban: ";
    cin.getline(namXuatBan[soLuongSach], 10);
    cout << "The Loai: ";
    cin.getline(theLoai[soLuongSach], 50);
    cout << "Gia Sach: ";
    cin >> giaSach[soLuongSach];
    cout << "So Luong: ";
    cin >> soLuong[soLuongSach];

    soLuongSach++;
    cout << "[OK] Them sach moi thanh cong!\n";
}

void chinhSuaSach() {
    char maSachToEdit[10];
    cout << "Nhap ma sach can chinh sua: ";
    cin.getline(maSachToEdit, 10);

    // Tìm vị trí sách cần chỉnh sửa
    int index = -1;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSachToEdit, maSach[i]) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Khong tim thay sach co ma '" << maSachToEdit << "'.\n";
        return;
    }

    cout << "Nhap thong tin sach " << maSachToEdit<< " muon chinh sua:\n";

    cout << "Ten Sach: ";
    cin.getline(tenSach[index], 100);
    cout << "Tac Gia: ";
    cin.getline(tacGia[index], 100);
    cout << "Nha Xuat Ban: ";
    cin.getline(nhaXuatBan[index], 100);
    cout << "Nam Xuat Ban: ";
    cin.getline(namXuatBan[index], 10);
    cout << "The Loai: ";
    cin.getline(theLoai[index], 50);
    cout << "Gia Sach: ";
    cin >> giaSach[index];
    cout << "So Luong: ";
    cin >> soLuong[index];

    cout << "[OK] Chinh sua sach co ISBN " << maSachToEdit << " thanh cong!\n";
}

void xoaSach() {
    char maSachToDelete[10];
    cout << "Nhap ma sach can xoa: ";
    cin.getline(maSachToDelete, 10);

    // Tìm vị trí sách cần xóa
    int index = -1;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSachToDelete, maSach[i]) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Khong tim thay sach co ma '" << maSachToDelete << "'.\n";
        return;
    }

    // Xóa sách tại vị trí index ( dịch chuyển sách phía sau lên)
    for (int i = index; i < soLuongSach - 1; i++) {
        strcpy(maSach[i], maSach[i + 1]);
        strcpy(tenSach[i], tenSach[i + 1]);
        strcpy(tacGia[i], tacGia[i + 1]);
        strcpy(nhaXuatBan[i], nhaXuatBan[i + 1]);
        strcpy(namXuatBan[i], namXuatBan[i + 1]);
        strcpy(theLoai[i], theLoai[i + 1]);
        giaSach[i] = giaSach[i + 1];
        soLuong[i] = soLuong[i + 1];
    }

    soLuongSach--;
    cout << "[OK] Xoa sach co ISBN " << maSachToDelete << " thanh cong!\n";
}

int timSachTheoISBN() {
    char maSachToSearch[10];
    cout << "Nhap ma sach can tim: ";
    cin.getline(maSachToSearch, 10);

    // Tìm sách theo ISBN
    int foundIndex = -1;
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSachToSearch, maSach[i]) == 0) {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

int timSachTheoTen() {
    char tenSachToSearch[100];
    cout << "Nhap ten sach can tim: ";
    cin.getline(tenSachToSearch, 100);

    // Tìm sách theo tên
    int foundIndex = -1;

    // dùng strstr để lấy tên gần đúng ( có phân biệt hoa thường ) || dùng strcmp để tìm chính xác tên
    for (int i = 0; i < soLuongSach; i++) {
        char temp[100];
        strcpy(temp, tenSach[i]);
        strlwr(temp);
        strlwr(tenSachToSearch);

        if (strstr(temp, tenSachToSearch) != NULL) {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

bool tonTaiMaSach(const char *id) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSach[i], id) == 0) {
            return true;
        }
    }
    return false;
}

bool coTheMuonSach(const char *id) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSach[i], id) == 0 && soLuong[i] > 0) {
            return true;
        }
    }
    return false;
}

bool giamSoLuongSach(const char *id) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSach[i], id) == 0) {
            soLuong[i]--;
            return true;
        }
    }
    return false;
}

bool tangSoLuongSach(const char *id) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(maSach[i], id) == 0) {
            soLuong[i]++;
            return true;
        }
    }
    return false;
}

void printBookInfo(int index) {
    cout << "STT | Ma Sach | Ten Sach | Tac Gia | Nha Xuat Ban | Nam Xuat Ban | The Loai | Gia Sach | So Luong\n";
    cout << "[" << index + 1 << "]" << " | "
            << maSach[index] << " | "
            << tenSach[index] << " | "
            << tacGia[index] << " | "
            << nhaXuatBan[index] << " | "
            << namXuatBan[index] << " | "
            << theLoai[index] << " | "
            << giaSach[index] << " | "
            << soLuong[index] << "\n";
    cout << endl;
}