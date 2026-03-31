// SinhHoanVi.cpp



#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n, a[100], final = 0;

void ktao() {
    for(int i = 1; i <= n; i++) {
        a[i] = n-i + 1;
    }
}
void sinh() {
    int i = n-1;
    while(i >= 1 && a[i] >= a[i+1]) {
        i--;
    }
    if(i == 0) {
        final = 1;
    } else {
        int j = n;
        while(a[j] <= a[i]) j--;
        swap(a[j],a[i]);
        reverse(a+i+1,a+n+1);
    }
}


int main() {
    cout << "N = ";
    cin >> n;
    ktao();
    // while(final == 0) {
    //     for(int i = 1; i <= n; i++) {
    //         cout << a[i];
    //     }
    //     cout << endl;
    //     sinh();
    // }
    // ......._______---------^^^^^<<<<<<< CÁCH - 2 >>>>>>>>^^^^^-----_______....... //
    while(prev_permutation(a+1, a+n+1)) {
        for(int i = 1; i <= n; i++) cout << a[i];
        cout << endl;
    }
    // while(next_permutation(a+1, a+n+1)) {
    //     for(int i = 1; i <= n; i++) cout << a[i];
    //     cout << endl;
    // }
    // int X[] = {1,2,6,9,8,7,5,4,3};
    // next_permutation(X, X+9); // Hàm mà có cấu hình tiếp theo -> Trả về true và xử lí
    // Nếu không có -> Trả về false
    // for(int i : X) cout << i;
    return 0;
}