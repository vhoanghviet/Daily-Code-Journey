// SinhPhanHoach.cpp



#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n, a[100], final = 0, cnt;

void ktao() {
    cnt = 1;
    a[1] = n;
}

void sinh() {
    int i = cnt;
    while(i >= 1 && a[i] == 1) {
        --i;
    }
    if(i == 0) {
        final = 1;
    } else {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i];
        int r = d % a[i];
        for(int j = 1; j <= q; j++) {
            a[i+j] = a[i];
            ++cnt;
        }
        if(r != 0) {
            ++cnt;
            a[cnt] = r;
        }
    }
}

int main() {
    cout << "N = ";
    cin >> n;
    ktao();
    while(final == 0) {
        for(int i = 1; i <= n; i++) {
            if(a[i] != 0) cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}