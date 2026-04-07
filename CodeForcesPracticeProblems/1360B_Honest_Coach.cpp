//B. Honest Coach

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= mid) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l; k <= r; k++) a[k] = temp[k-l];
}

void mergeSort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}

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
        
        mergeSort(a, 0, n-1);
       
        int ans = 1e9;
        for(int i = 0; i < n-1; i++) {
            int dif = a[i+1] - a[i];
            if(dif < 0) dif = -1 * dif;
            if(dif < ans) ans = dif;
        }
            
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}