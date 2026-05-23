#include <bits/stdc++.h>
using namespace std;

int m, n ;
int first;
int last;
const int maxn = 1005;
vector<int> ke[maxn];
vector<pair<int,int>> dscanh;
bool visited[maxn];
int parent[maxn];
vector<int> g_cycle;


bool dfs(int u , int par) { 
    visited[u] = true ;
    for( int v : ke[u]) {
        if(!visited[v]) {
            if(dfs(v,u)) return true; 
        }
        else if(v != par) return true;
    }
    return false;
}
bool dfs2(int u){
    visited[u] = true;
    for(int v : ke[u]) {
        // Cạnh ngược : nếu v đã thăm rồi mà còn không phải cha trực tiếp của u
        if(!visited[v]) {
            parent[v] = u;
            if(dfs2(v)) return true;
        } else if(parent[u] != v) { // Tìm đỉnh đầu , đỉnh cuối của chu trình ; 
            // u là đỉnh đang duyệt
            first = v; 
            last = u;
            return true;
        }
    }
    return false;
}


bool bfs(int u) {
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty() ) {
        int v = q.front() ; q.pop();
        for(int x : ke[v]) {
            if(!visited[x]) {
                visited[x] = true;
                parent[x] = v;
                q.push(x);
            } else if (x != parent[v]) { // đỉnh đang xét (v) có là cha của thằng kề không
                first = v;
                last = x;
                return true;
            }
        }
    }
    return false;
}





void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
}
int main() {
    nhap();
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end()) ;
    }
    bool ok = false;
    for(int i = 1; i <= n ; i++) {
        if(!visited[i] ) {
            if(bfs(i)) {
                ok = true;
                // g_cycle.push_back(first);
                // while(last != first) {
                //     g_cycle.push_back(last) ;
                //     last = parent[last];
                // }
                // g_cycle.push_back(first);
                // reverse(g_cycle.begin(), g_cycle.end());
                // for(int x : g_cycle) {
                //     cout << x << " ";
                // }
            }
        }
    }
    if(ok) cout << "1\n";
    else cout << "0\n";
    return 0;
}