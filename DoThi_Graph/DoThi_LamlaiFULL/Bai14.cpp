#include <bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
bool visited[1005];
int n, m, s, t;
void DFS1(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS1(v);
        }
    }
}
void DFS2(int u) {
    visited[u] = true;
    cout << u << " ";
    if(u == t) return;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS2(v);
        }
    }
}

int main() {
    
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
    }
    memset(visited, false, sizeof(visited));
    DFS1(s); if(!visited[t]) {
        cout << -1; return 0;
    }
    memset(visited, false, sizeof(visited));
    DFS2(s);
    return 0;
}