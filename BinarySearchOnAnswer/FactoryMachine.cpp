#include <bits/stdc++.h>
#include <vector>
using ll = long long;
using namespace std;

bool check(vector<int> &k, int n, int t, ll time) {
    ll dem = 0;
    for(int i = 0; i < n; i++) {
        dem += time / k[i];
        // Có thể tràn long long
        if(dem >= t) return true;
    }
    return dem >= t;
}

void solve() {
    int n, t; cin >> n >> t;
    vector<int> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        
        k.push_back(x);
    }
    ll r = 2e9+7, l = 0;
    ll ans = -1;
    while(l <= r) {
        ll mid = (l+r)/2;
        // check mid
        if(check(k, n, t, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

// chặt nhị phân:
// r = min * t
// l = 0,1

// Dạng bài này thường rơi vào 1. Quy hoạch động, 2. Tham lam, 3. Chia và trị, 4. Chặt nhị phân kết quả
