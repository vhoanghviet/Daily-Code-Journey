// 750A : New Year and Hurry
// Divide and Conquer
#include <iostream>
#include <vector>

using namespace std;

long long tong(int n) {
    if(n <= 0) return 0;
    return n + tong(n-1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    int l = 0, r = n;
    int ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;

        if(5*tong(mid) + k <= 4*60) {
            ans = mid;
            // cout << "Gia tri cua m: " << m << endl;
            l = mid+1;
        } else {
            r = mid-1;
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