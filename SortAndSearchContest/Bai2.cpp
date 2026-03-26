#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool cmp(int a, int b) {
    return abs(a) < abs(b); // nhỏ đến lớn ( 1 -> 999999)
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    stable_sort(a.begin(), a.end(), cmp);
    for(int x : a) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}