#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n, greater<int>());
    int lit_sua_da_mat = 0;
    int tong_lit = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= lit_sua_da_mat;
        if(a[i] > 0) tong_lit += a[i];
        lit_sua_da_mat++;
    }
    cout << tong_lit;
    return 0;
}