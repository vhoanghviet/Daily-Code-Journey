#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j; 
            }
        }
        if (min_idx != i) {
            cout << i << " " << min_idx << endl;
            int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}