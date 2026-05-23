#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 1001;
vector<int> ke[maxn];
bool visited[maxn];
vector<int> topo;

void nhap() {
    cin >> n >> m ;
    for(int i = 0; i < m; i++) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

int main() {
    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(int x : topo) {
        cout << x << " ";
    }
    return 0;
}