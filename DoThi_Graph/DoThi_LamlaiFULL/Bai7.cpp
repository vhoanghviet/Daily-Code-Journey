#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10007];
int a[1001][1001];

int main() {
    int n,m; cin >> n >> m;

    vector<pair<int,int>> dscanh;
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int x, y ; cin >> x >> y;
        adj_matrix[x-1][y-1] = 1;
        adj_matrix[y-1][x-1] = 1;
    }
    for(int i = 0 ; i < n ; i++)  {
        for(int j = 0; j <n ; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}