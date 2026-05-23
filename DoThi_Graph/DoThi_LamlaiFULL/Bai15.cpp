#include <bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
bool visited[1005];
int n, m, s, t;
void BFS1(int u) {
    visited[u] = true;
    queue<int> q; q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        // cout << v << " ";
        for(int x : ke[v]) {
            if(!visited[x]) {
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void BFS2(int u) {
    visited[u] = true;
    queue<int> q; q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        if(v == t) return;
        for(int x : ke[v]) {
            if(!visited[x]) {
                visited[x]=true;
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
        ke[v].push_back(u);
    }
    // for(int i = 1; i <= n; i++) {
    //     sort(ke[i].begin(),ke[i].end());
    // }
    memset(visited, false, sizeof(visited));
    BFS1(s); if(!visited[t]) {
        cout << -1; return 0;
    }
    memset(visited, false, sizeof(visited));
    BFS2(s);
    return 0;
}