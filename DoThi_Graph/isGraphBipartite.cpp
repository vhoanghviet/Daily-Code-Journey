#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10007];
int color[10007];
int n, m;

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
}

// RED : 0
// BLUE : 1

bool bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0; // 0 : RED
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x : ke[v]) {
            if(color[x] == -1) {
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if(color[x] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    nhap();
    bool ok = true;
    for(int i = 1 ; i <= n ; i++) {
        if(color[i] == -1) {
            if(bfs(i) == false) {
                ok = false; break;
            }
        }
        
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}