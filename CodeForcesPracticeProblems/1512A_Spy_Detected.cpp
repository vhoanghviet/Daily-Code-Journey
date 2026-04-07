// 1512A: Spy detected

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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n - 1; i++) {
            int j = i+1;
            if(i == 0) {
                if(a[i] != a[j] && a[j] != a[j+1]) {
                    cout << j+1 << endl;
                    break;
                } else if(a[i] != a[j] && a[j] == a[j+1]) {
                    cout << i+1 << endl;
                    break;
                }
            } else if(j == n - 1) {
                if(a[i] != a[j]) {
                    cout << j+1 << endl;
                    break;
                }
            } else {
                if(a[i] != a[j]) {
                    cout << j+1 << endl;
                    break;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}