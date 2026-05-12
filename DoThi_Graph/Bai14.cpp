#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int parent[1001];

void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
            parent[v] = u;
        }
    }
}
void BFS(int u ) {
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(!visited[v]) {
            parent[v] = u;
            q.push(v);
            visited[v] = true;
        }
    }
}

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << i << " next to : ";
    //     for(int j : ke[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    DFS(s);
    if(!visited[t]) cout << "-1\n";
    else {
        // Truy vết đường đi
        vector<int> ans;
        while(t != s) {
            ans.push_back(t);
            t = parent[t];
        }
        ans.push_back(s);
        reverse(ans.begin(), ans.end());
        for(int x : ans) cout << x << " ";
    }
    return 0;
}