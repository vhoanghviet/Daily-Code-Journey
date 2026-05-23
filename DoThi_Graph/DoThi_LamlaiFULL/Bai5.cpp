#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10007];
int a[1001][1001];

int main() {
    int n; cin >> n;
    vector<pair<int,int>> dscanh;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n ;j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                if(i > j) dscanh.push_back({i+1, j+1});
                ke[i+1].push_back(j+1);
            }
        }
    }
    for(auto it : dscanh) {
        cout << it.first << " " << it.second << '\n';
    }
    cout << '\n';
    for(int i = 1 ; i <= n; i++) {
        cout << i << " : ";
        for(int x : ke[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}