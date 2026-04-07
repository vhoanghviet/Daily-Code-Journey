// 1399A. Remove Smallest
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l; k <= r; k++) a[k] = temp[k-l];
}
void mergeSort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}

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
        mergeSort(a, 0, n-1);
        // for(int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        // CÁCH 1:
        // for(int i = 0; i < a.size(); i++) {
        //     int j = i + 1;
        //     if(j < a.size()) {
        //         if(a[j] - a[i] <= 1) {
        //             // delete integers at position [i];
        //             for(int k = i; k < n-1; k++) {
        //                 a[k] = a[k+1];
        //             }
        //             a.pop_back();
        //             i--;
        //         }
        //     }
        // }
        // if(a.size() == 1) cout << "YES\n";
        // else cout << "NO\n";

        // CÁCH 2:
        int possible = true;
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            if(j < n) {
               if(a[j] - a[i] > 1) {
                possible = false;
               }
            }
        }
        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}