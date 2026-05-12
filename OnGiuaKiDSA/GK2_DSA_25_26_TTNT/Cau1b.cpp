#include <iostream>

using namespace std;

int X[100];
int n;

void in(int k) {
    for (int i = 1; i <= k; i++) {
        cout << X[i] << (i == k ? "" : " + ");
    }
    cout << endl;
}

void Try(int i, int cur_sum) {
    
    int limit;
    if (i == 1) {
        limit = n; // Vị trí đầu tiên chạy từ n -> 1
    } else {
        limit = 1; // Các vị trí sau chỉ lấy số 1
    }

    for (int j = limit; j >= 1; j--) {
        X[i] = j;
        if (cur_sum + j == n) {
            in(i);
        } else if (cur_sum + j < n) {
            Try(i + 1, cur_sum + j);
        }
    }
}

int main() {
    cout << "Nhap n: ";
    cin >> n;
    Try(1, 0);
    return 0;
}