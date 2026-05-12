#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 1;
    sort(a, a+n);
    for(int i = 1; i < n; i++) {
        if((int)abs(a[i-1]- a[i]) > k) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}