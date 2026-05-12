#include <iostream>
#include <cmath>
using namespace std;

const int M = 300007;
long long hashTable[M]; // Tất cả phần tử trong bảng băm giờ là 0
bool visited[M]; // Tất cả giá trị trong hàm visited này là 0

// Hàm băm
int f(long long x) {
    return abs(x) % M;
}
// Hàm chèn và kiểm tra xem đã tồn tại hay chưa
bool insert(long long x) {
    int h = f(x);
    // Linear Probing: Nếu đụng độ thì nhảy sang ô tiếp theo
    while(visited[h]) {
        if(hashTable[h] == x) return false; // Đã tồn tại, không đếm lại
        h = (h + 1) % M;
    }
    // Chèn 'x' vào ô vị trí 'h' của bảng băm
    hashTable[h] = x;
    visited[h] = true;
    return true; // Chèn mới thành công
}


void solve() {
    int n;
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if(insert(x)) {
            count++;
        }
    }
    cout << count << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}