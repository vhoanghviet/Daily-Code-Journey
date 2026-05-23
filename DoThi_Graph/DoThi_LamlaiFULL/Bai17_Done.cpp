#include <bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
bool visited[1005];
int parent[1005];
int n, m, s, t;
void BFS(int u) {
    visited[u] = true;
    queue<int> q; q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x : ke[v]) {
            if(!visited[x]) {
                visited[x]=true;
                parent[x] = v;
                q.push(x);
            }
        }
    }
}


int main() {
    
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    BFS(s); 
    if(!visited[t]) {
        cout << -1; return 0;
    } else {
        vector<int> path; 
        while(t != s) { // Truy vết đường đi
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int x : path) cout << x << " ";
    }
    return 0;
}