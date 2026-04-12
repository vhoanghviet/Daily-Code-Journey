#include <bits/stdc++.h>

using namespace std;

void merge(string &sorted_s, int l, int m, int r) {
    string temp;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(sorted_s[i] <= sorted_s[j]) temp.push_back(sorted_s[i++]);
        else temp.push_back(sorted_s[j++]);
    }
    while(i <= m) temp.push_back(sorted_s[i++]);
    while(j <= r) temp.push_back(sorted_s[j++]);
    for(int k = l; k <= r; k++) sorted_s[k] = temp[k-l];
}
void mergeSort(string &sorted_s, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(sorted_s,l,m);
    mergeSort(sorted_s,m+1,r);
    merge(sorted_s,l,m,r);
}

void solve() {
    int n; cin >> n;
    string s, sorted_s;
    cin >> s;
    sorted_s = s;
    mergeSort(sorted_s, 0, n-1);
    // cout << "Mang s da sap xep hien tai: " << sorted_s << endl;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != sorted_s[i]) cnt++;
    }
    cout << cnt << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>> t; 
    while(t--) solve();
    return 0;
}