#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int so_gian[maxn];
int n, m,s ;
int parent[maxn];
int sz[maxn];


void nhap() {
    cin >> n >> m >> s;

    for(int i = 0 ; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int s) {
    visited[s] = true;
    for(int v : ke[s]) {
        if(!visited[v]) {
            cout << s << "->" << v << '\n';
            dfs(v);
        }
    }
}



int main() {
    
    nhap();
    dfs(s);
    return 0;
}