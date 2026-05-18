#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
int main() {
    nhap();
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