#include <stdio.h>
#include "utils.h"
using namespace std;

// hàm kiểm tra năm nhuận
inline bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

// hàm tự động tính ngày hết hạn thẻ đọc giả (48 tháng)
void calculateExpiryDate(const char* startDate, char* expiryDate) {
    int day, month, year;
    sscanf(startDate, "%d/%d/%d", &day, &month, &year);

    month += 48; // Cộng 48 tháng (4 năm)

    // Kiểm tra nếu tháng > 12 thì cộng thêm năm và làm lại tháng
    if (month > 12) {
        year += month / 12; // Cộng thêm năm
        month = month % 12; // Lấy tháng còn lại (từ 1 đến 12)
    }

    // Nếu tháng = 0, thì chỉnh lại tháng thành 12 và giảm năm đi 1
    if (month == 0) {
        month = 12;
        year--;
    }

    // Lưu ngày hết hạn vào mảng expiryDate
    sprintf(expiryDate, "%02d/%02d/%d", day, month, year);
}

// tính ngày trả dự kiến dựa vào ngày mượn ( +7 ngày )
void tinhNgayTraSachDuKien(const char *startDate, char *expiryDate) {
    int day, month, year;
    sscanf(startDate, "%d/%d/%d", &day, &month, &year);

    // Số ngày trong các tháng
    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += 7;

    // Kiểm tra nếu ngày vượt quá số ngày trong tháng thì cộng thêm tháng
    while (day > daysInMonth[month - 1]) {
        day = day - daysInMonth[month - 1];  // Giảm số ngày đi theo tháng
        month++;  // Thêm tháng
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Lưu ngày trả sách dự kiện vào mảng expiryDate
    sprintf(expiryDate, "%02d/%02d/%d", day, month, year);

}
