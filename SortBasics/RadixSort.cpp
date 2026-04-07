#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm lấy giá trị lớn nhất trong vector
int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int x : arr) {
        if (x > mx) mx = x;
    }
    return mx;
}

// Hàm Counting Sort sắp xếp theo chữ số ở hàng 'exp' (1, 10, 100,...)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Vector tạm để lưu kết quả
    vector<int> count(10, 0); // Đếm số lần xuất hiện của các chữ số từ 0-9

    // Bước 1: Đếm tần suất xuất hiện của chữ số hàng 'exp'
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Bước 2: Biến đổi count[i] thành vị trí (index) trong mảng output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Bước 3: Xây dựng mảng output (duyệt ngược để giữ tính ổn định - Stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Bước 4: Cập nhật lại vector gốc
    arr = output; // Phép gán vector trong C++ sẽ copy toàn bộ nội dung
}

// Hàm chính của Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Tìm số lớn nhất để xác định số lượng chữ số tối đa
    int m = getMax(arr);

    // Lặp qua từng hàng chữ số: đơn vị, chục, trăm...
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(data);

    cout << "Mang sau khi xap xep: ";
    for (int x : data) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}