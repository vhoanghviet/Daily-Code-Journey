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

// KOSARAJU  O(2*(V+E))
// Bước 1: Gọi thuật toán DFS để xây dựng stack là : THỨ TỰ DUYỆT DFS (để sau đó duyệt tranpose graph)
// Bước 2: Xây dựng tranpose graph (t_ke)
// Bước 3: Lần lượt pop các đỉnh trong stack ở bước 1 và 
// gọi thuật toán dfs lần lượt để thiệt kê các thành phần liên thông mạnh (Strongly Connected Components)

void dfs1(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs1(v);
        }
    }
    dfs_order.push(u); // Thứ tự topo của DAG
}

void dfs(int u) {
    visited[u] = true;
    for(int v : t_ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void SCC() {
    memset(visited, false, sizeof(visited)) ;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs1(i);
        }
    }
    memset(visited,false,sizeof(visited));

    int scc = 0;
    while(!dfs_order.empty()) {
        int x = dfs_order.top(); dfs_order.pop();
        if(!visited[x]) {
            scc++;
            dfs(x);
        }
    }
    cout << scc;
}

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y); // Có hướng
        t_ke[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin() , ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}





int main() {
    nhap();
    SCC();
    return 0;
}