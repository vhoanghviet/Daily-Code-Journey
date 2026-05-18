#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
vector<pair<int,int>> dscanh;
void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dscanh.push_back({x,y});
    }
}
int main() {
    nhap();
    sort(dscanh.begin(), dscanh.end());
    for(auto it : dscanh) {
        ke[it.first].push_back(it.second);
    }
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
    }
    for(int i = 1; i<= n ; i++) {
        cout << i << " : ";
        for(auto it : ke[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}