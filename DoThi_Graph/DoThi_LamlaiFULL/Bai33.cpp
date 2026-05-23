#include <bits/stdc++.h>
using namespace std;

int m, n ;
int first;
int last;
const int maxn = 1005;
vector<int> ke[maxn];
vector<int> t_ke[maxn];
vector<pair<int,int>> dscanh;
bool visited[maxn];
int parent[maxn];
int in_degree[maxn];
vector<int> topo;
stack<int> dfs_order;
int color[maxn];


void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y); 
        ke[y].push_back(x);// vô hướng
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin() , ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}
int so_dinh = 0;
int so_canh = 0;
void dfs(int u) {
    visited[u] = true;
    so_dinh++;
    so_canh += ke[u].size();
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    nhap();
    bool ok = false;
    for(int i = 1; i <= n; i++) {
        so_dinh = 0;
        so_canh = 0;
        if(!visited[i]) {
            dfs(i);
            ok = (so_canh == (so_dinh*(so_dinh - 1)/2));
            break;
        }
        
    }
    if(ok)cout << "YES\n";
    else cout << "NO\n";

    return 0;
}