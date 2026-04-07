#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> &a) {
    int m = a[0];
    for(int i = 1; i < (int)a.size(); i++) {
        if(m < a[i]) m = a[i];
    }
    return m;
}

void countingSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n);
    vector<int> count(10,0);

    // Xây dựng mảng count đếm số lần xuất hiện của digit
    for(int i = 0; i < n; i++) {
        int digit = (a[i]/exp) % 10;
        count[digit]++;
    }
    // Xây dựng mảng count cộng dồn để lưu trữ VỊ TRÍ CUỐI CÙNG của phần tử có DIGIT
    for(int i = 1; i < 10; i++) { // Lỗi : Vòng lặp này luôn lặp từ 1-9
        count[i] += count[i-1];
    }
    // Xây dựng mảng output để ghi kết quả:
    for(int i = n-1; i >= 0; i--) { // i-- ko phải i++
        int digit = (a[i]/exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    // Copy output paste cho a
    a = output;
}

void radixSort(vector<int> &a) {
    if(a.empty()) return;
    int n = a.size();


    int m = getMax(a);


    for(int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(a, exp);
    }
}