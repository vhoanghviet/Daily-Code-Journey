#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, a[100], final = 0;
void ktao() {
    // Bước 1: Khởi tạo cấu hình đầu tiên
    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

void sinh() {
    int i = n; // Bắt đầu từ bit cuối cùng
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    // Giả sử: xâu bit đang xử lí toàn là 111111 -> i sẽ -> 0
    if(i == 0) {
        final = 1; // Đây là cấu hình cuối cùng;
    } else {
        a[i] = 1;
    }
}
// void sinh() {
//     int i = n;
//     while(i >= 1 && a[i] == 1) {
//         a[i] = 0;
//         --i;
//     }
//     if(i == 0) {
//         final = 1;
//     } else {
//         a[i] = 1;
//     }
// }
int main() {

    // Đi tìm bit 0 đầu tiên từ bên phải
    // Gặp bit 1 thì sẽ chuyển thành bit 0
    // Đây là thuật toán vét cạn
    // Độ phức tạp thuật toán sinh xâu nhị phân: O(2^n)
    cout << "Do dai bit ban muon sinh: ";
    cin >> n;
    ktao();
    while(final == 0) {
        for(int i = 1; i <= n; i++) {
            // if(a[i] == 0) cout << 'A'; else cout << 'B';
            cout << a[i];
        }
        cout << endl;
        sinh();
    }


    return 0;
}