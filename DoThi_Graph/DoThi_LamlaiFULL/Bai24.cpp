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



bool dfs(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            parent[v] = u;
            if(dfs(v)) return true; // Nếu có thấy chu trình thì kết luận có
        } else if(v != parent[u]) return true; // Found cycle, Tìm thấy Back edge
    }
    return false;
}

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



int main() {
    nhap();
    bool is_tree = true;
    for(int i = 1; i <= n ;i++) {
        if(!visited[i]) {
            if(dfs(i)) is_tree = false;
        }
    }
    if(is_tree) cout << 1;
    else cout << 0;
    return 0;
}