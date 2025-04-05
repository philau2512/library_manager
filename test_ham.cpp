#include <stdio.h>

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
    sprintf(expiryDate, "%02d-%02d-%d", day, month, year);
}

int main () {
    char startDate[11] = "04/04/2025";
    char expiryDate[11];

    calculateExpiryDate(startDate, expiryDate);

    printf("Expiry Date: %s\n", expiryDate);

    return 0;
}