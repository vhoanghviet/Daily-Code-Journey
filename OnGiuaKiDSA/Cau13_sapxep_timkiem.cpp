#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; if(n < 1) return 0;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a+n);
    int nex = 1e9;
    int r = a[n-1];
    int cnt = 1;
    for(int i = n-1; i > 0; i--) {
        nex = a[i-1];
        if(nex < r) {
            r = nex;
        } else {
            r -= 1;
        }
        if(r > 0) {
            cnt++;
        } else {
            break;
        }
    }  
    cout << cnt;
    return 0;
}