#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkMid(vector<int> &a, int n, int k, double length) { 
    // Tìm length max
    if(length < 1e-9) return true;
    ll n_doan_con = 0;
    for(int i = 0; i < n; i++) {
        n_doan_con += a[i] / length;
    }
    // nếu length max thỏa -> cố gắng tìm chiều dài lớn hơn
    // nghĩa là cập nhật trỏ left = mid + 1 khi đúng ( bước gán ans = mid );
    return n_doan_con >= k;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n); double max_val = 0.0;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; if(max_val < a[i]) max_val = a[i];
    }
    double left = 0, right = max_val;
    double ans = 0;
    for(int i = 0; i < 100; i++) {
        double mid = (left+right)/2.0;
        if(checkMid(a,n,k,mid)) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(6) << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}