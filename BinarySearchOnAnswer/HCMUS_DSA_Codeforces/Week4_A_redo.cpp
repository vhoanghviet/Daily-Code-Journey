#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_idx;
    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < n ; j++) {
            if(a[min_idx] > a[j]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            cout << i << " " << min_idx << endl;
            int temp = a[min_idx];
            a[min_idx] = a[i];
            a[i] = temp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}