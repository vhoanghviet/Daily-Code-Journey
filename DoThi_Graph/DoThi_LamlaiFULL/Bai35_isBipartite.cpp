#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];

int n,m;
int color[maxn];

// White = -1;
// Red = 0;
// Blue = 1;

bool bfs(int u) {
    color[u] = 0;     
    queue<int> q; q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x : ke[v]) {
            if(color[x] == -1) {
                color[x] = 1 - color[v];
                q.push(x);
            } else if(color[x] == color[v]) return false;
        }
    }
    return true;
}




void nhap() {
    cin >> n >> m;

    for(int i = 0; i < m ;i++ ) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x); 
    }
    for(int i = 1 ; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(color, -1, sizeof(color)) ;
}

int main() {
    nhap();
    bool isBipartite = true;
    for(int i = 1; i <= n ;i++) {
        if(color[i] == -1) {
            if(!bfs(i)) {
                isBipartite = false;
                break;
            }
        }
    }
    if(isBipartite) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}