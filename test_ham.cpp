#include <stdio.h>
#include <iostream>
using namespace std;

// Hàm tính xem ngày trả thực tế - ngày mượn xem có > 7 không
bool isExpired(const char* ngayMuon, const char* ngayTraThucTe) {
    int dayMuon, monthMuon, yearMuon;
    int dayTra, monthTra, yearTra;
    sscanf(ngayMuon, "%d/%d/%d", &dayMuon, &monthMuon, &yearMuon);
    sscanf(ngayTraThucTe, "%d/%d/%d", &dayTra, &monthTra, &yearTra);

    // Tính toán số ngày kể từ ngày đầu tiên của năm
    int daysMuon = 0;
    for (int i = 1; i < monthMuon; i++) {
        if (i == 2) {
            if ((yearMuon % 4 == 0 && yearMuon % 100 != 0) || yearMuon % 400 == 0) {
                daysMuon += 29;
            } else {
                daysMuon += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            daysMuon += 30;
        } else {
            daysMuon += 31;
        }
    }
    daysMuon += dayMuon;

    int daysTra = 0;
    for (int i = 1; i < monthTra; i++) {
        if (i == 2) {
            if ((yearTra % 4 == 0 && yearTra % 100 != 0) || yearTra % 400 == 0) {
                daysTra += 29;
            } else {
                daysTra += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            daysTra += 30;
        } else {
            daysTra += 31;
        }
    }
    daysTra += dayTra;

    // Tính toán số ngày chênh lệch
    int daysDiff = (yearTra - yearMuon) * 365 + daysTra - daysMuon;

    // So sánh số ngày
    return daysDiff > 7;
}

int main () {
    char startDate[11] = "25/02/2025";
    char expiryDate[11] = "05/03/2025";

    bool status = isExpired(startDate, expiryDate);

    cout << "status : " << status << endl;

    return 0;
}