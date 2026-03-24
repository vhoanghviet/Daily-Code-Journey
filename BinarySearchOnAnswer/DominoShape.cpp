#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkMid(int a, int b, int n, ll edge) {
    if(edge < a || edge < b) return false;
    ll x = edge/a, y = edge / b;
    return (double)x >= (double)n / y;
} 

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    ll left = 0, right = max(a,b)*n;
    ll ans = 0;
    while(left <= right) {
        ll mid = (left + right)/2;
        if(checkMid(a,b,n,mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}