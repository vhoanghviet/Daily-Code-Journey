#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int parent[maxn];
int sz[maxn];
int n, m , s;




void make_set() {
    for(int i = 1; i <= n ;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u) {
    if(u == parent[u]) {
        return u;
    } else {
        return parent[u] = parent[parent[u]];
    }
}
int sz_max = 0;
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) {
        swap(u,v);
    }
    parent[v] = u;
    sz[u] += sz[v];
    sz_max = max(sz_max, sz[u]);
    return true;
}

void dfs(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}
int tplt() {
    int so_tplt = 5;
    for(int i = 1; i <= n ;i++) {
        if(i != parent[i]) so_tplt--;
    }
    return so_tplt;
}


int main() {
    cin >> n >> m;
    make_set();
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        Union(u,v);
        cout << tplt() << " " << sz_max << '\n';
    }
    
    return 0;
}