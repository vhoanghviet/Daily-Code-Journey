#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 1:28:53

int X[100], a[100], daxet[100];
int n, k, sum = 0;

void in() {
    for(int i = 1; i <= n; i++) {
        cout << X[i];
    }

}

void Try(int i) {
    int j = n;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        memset(daxet,0,sizeof(daxet));
    }

    return 0;
}


// Quay lui sinh hoán vị
// void Try(int i) {
//     for(int j = 1; j <= n; j++) {
//         X[i] = j;
//         if(i == n) {
//             in(); cout << endl;
//         } else {
//             Try(i+1); // Đã in rồi
//         }
//     }
// }
// Quay lui sinh tổ hợp
// void Try(int i) {
//     for(int j = X[i-1]+1; j <= n - k + i ;j++) {
//         X[i] = j;
//         if(i == k) {
//             in(); cout << endl;
//         }
//         else Try(i+1);
//     }
// }

// Quay lui sinh xau nhi phan
// void Try(int i) {
//     for(int j = 0; j <= 1; j++) {
//         X[i] = j;
//         if(i == n) {
//             in();
//             cout << endl;
//         }
//         else Try(i+1);
//     }
// }