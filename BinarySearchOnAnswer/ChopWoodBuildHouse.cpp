#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkMid(vector<int> &h, int n, ll l, ll length) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(length < h[i]) sum += h[i] - length;
        if(sum >= l) return true;
    }
    return sum >= l;
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> h;
    for(int i =0; i < n; i++) {
        int temp; cin >> temp;
        h.push_back(temp);
    }
    ll left = 0, right = 1e9;
    ll ans = -1;
    while(left <= right) {
        ll mid = (left + right)/2;
        if(checkMid(h,n,l,mid)) { // sum >= l , hmid này thỏa rồi, giờ tìm h lớn nhất thì phải dịch con trỏ left
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