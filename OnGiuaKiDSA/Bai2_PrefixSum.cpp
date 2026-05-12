#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n), prefix_sum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix_sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    while(q--) {
        int L, R;
        cin >> L >> R;
        if(L > 0) {
            cout << prefix_sum[R] - prefix_sum[L-1] << endl;
        } else if (L == 0) {
            cout << prefix_sum[R] << endl;
        }
    }
    return 0;
}