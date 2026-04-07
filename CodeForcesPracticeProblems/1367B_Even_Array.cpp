// 1367B. Even Array
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i= 0; i < n; i++) {
            cin >> a[i];
        }
        int bad_odd = 0;
        int bad_even = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                if(i % 2 == 1) {
                    bad_even++;
                }
            } else {
                if(i % 2 == 0) {
                    bad_odd++;
                }
            }
        }
        if(bad_odd == bad_even) cout << bad_odd << endl;
        else cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}