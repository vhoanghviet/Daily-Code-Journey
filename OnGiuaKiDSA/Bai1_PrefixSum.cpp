#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), prefix_sum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix_sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    for(int x : prefix_sum) {
        cout << x << " ";
    }
    return 0;
}