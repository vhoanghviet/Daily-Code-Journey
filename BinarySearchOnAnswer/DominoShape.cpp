#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkMid(int a, int b, int n, ll edge) {
    int max_val = a;
    if(max_val < b) max_val = b;
    return max_val * n <= edge;
} 

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    ll left = 0, right = 9e18;
    ll ans = 0;
    while(left <= right) {
        ll mid = (left + right)/2;
        if(checkMid(a,b,n,mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
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