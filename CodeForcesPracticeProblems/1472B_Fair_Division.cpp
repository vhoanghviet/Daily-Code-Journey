// 1472B: Fair Division
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
        long long sum = 0;
        int cnt_1 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 1) cnt_1++;
        }
        if(sum % 2 != 0) {
            cout << "NO\n";
        } else {
            int half = sum / 2;
            if((half % 2 != 0) && cnt_1 == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
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