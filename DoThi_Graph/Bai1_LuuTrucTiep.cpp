#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> adj[1001];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int dinh_dau, dinh_cuoi;
        cin >> dinh_dau >> dinh_cuoi;
        adj[dinh_dau].push_back(dinh_cuoi);
        adj[dinh_cuoi].push_back(dinh_dau);
    }
    for(int i = 0; i < m ; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}