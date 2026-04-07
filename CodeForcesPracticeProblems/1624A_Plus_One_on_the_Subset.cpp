// 1624A: Plus One on the Subset

#include <iostream>
#include <vector>
using namespace std;


void solve() {
    int t;
    cin >> t;
    while(t--) {
        int max_value = -1e9, min_value = 1e9;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int temp; cin >> temp;
            if(temp > max_value) max_value = temp;
            if(temp < min_value) min_value = temp;
        }
        cout << max_value - min_value << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}