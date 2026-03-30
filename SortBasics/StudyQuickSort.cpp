#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int partitionLomuto(vector<int> &t, int l, int r) {
    int pivot = t[r]; // Chọn pivot cuối
    int i = l - 1; // Con trỏ bên trái
    // duyệt từ l đến r-1
    for(int j = l; j < r; j++) {
        if(t[j] < pivot) {
            i++;
            swap(t[i],t[j]);
        }
    }
    // Đặt pivot vào vị trí đúng
    swap(t[i+1], t[r]);
    return i+1;
}

int partitionHoare(vector<int> &t, int l, int r) {
    int pivot = t[l];
    int i = l - 1;
    int j = r + 1;
    while(true) {
        do {
            i++;
        }
    }
}