#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            i++;
        } else {
            cnt++;
            i++;
            j++;
        }
    }

    cout << cnt;
    return 0;
}