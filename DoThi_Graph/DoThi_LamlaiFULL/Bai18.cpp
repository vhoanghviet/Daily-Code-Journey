#include <bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
int parent[1005];
bool visited[1005];

void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    int n,m,Q;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++) {
        sort(ke[i].begin(), ke[i].end());
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int s,t;
        cin >> s >> t;
        memset(visited, false, sizeof(visited));
        DFS(s); 
        if(!visited[t]) {
            cout << "-1\n";
        } else {
            cout << "1\n";
        }
    }
    return 0;
}