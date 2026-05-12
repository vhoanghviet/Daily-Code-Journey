#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;


struct Doan {
    int bat_dau;
    int ket_thuc;
};

bool so_sanh(Doan a, Doan b) {
    return a.ket_thuc < b.ket_thuc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Doan> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].bat_dau >> a[i].ket_thuc; 
    }
    sort(a.begin(), a.end(), so_sanh);
    int cnt = 0;
    int last_end = -1;
    for(int i = 0; i < n; i++) {
        if(a[i].bat_dau > last_end) {
            cnt++;
            last_end = a[i].ket_thuc;
        }
    }
    cout << cnt;
    return 0;
}