#include <bits/stdc++.h>
using namespace std;
int adj[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int dinh_dau, dinh_cuoi;
        cin >> dinh_dau >> dinh_cuoi;
        adj[dinh_dau][dinh_cuoi] = 1;
        adj[dinh_cuoi][dinh_dau] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";                
        }
        cout << endl;
    }
    return 0;
}