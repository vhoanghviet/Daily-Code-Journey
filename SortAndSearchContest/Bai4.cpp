#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// Extra essential function here

void solve() 
{
    // Solution here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> differ(n);
    int ans = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        differ[i] = a[i+1] - a[i];
        if(ans > differ[i]) ans = differ[i];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
