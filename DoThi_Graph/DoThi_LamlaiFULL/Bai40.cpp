#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int n, m , s;


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


void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : ke[u]) {
            if(!visited[v]) {
                visited[v] = true;
                cout << u << "->" << v << '\n';
                q.push(v);
            }
        }
    }
}



int main() {
    nhap();
    bfs(s);
    return 0;
}