#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int ID[100];
int parent[1001]; // đỉnh parent[u] là cha của thằng đỉnh u
int n,m;
int dem = 0;
void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        ID[x] = dem;
        for(int y : adj[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
void DFS(int u) {
    // cout << u << " ";
    visited[u] = true;
    ID[u] = dem;
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++) {
        if(!visited[i]) {
            dem++;
            DFS(i);
        }
    }

    int q; cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(ID[x] == ID[y]) cout << "1\n";
        else cout << "-1\n";
    }

    // while(q--) {
    //     int x, y;
    //     cin >> x >> y;
    //     memset(visited, false, sizeof(visited));
    //     DFS(x);
    //     if(visited[y] == true) cout << 1 << endl;
    //     else cout << -1 << endl;
    // }
    return 0;
}