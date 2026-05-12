#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int n, m;

void DFS(int u) {
    // cout << u << " ";
    visited[u] = true;
    // adj[u] là tập các đỉnh kề khác đỉnh u;
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

void input_adj() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int dinh_dau, dinh_cuoi;
        cin >> dinh_dau >> dinh_cuoi;
        adj[dinh_dau].push_back(dinh_cuoi);
        adj[dinh_cuoi].push_back(dinh_dau);
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
}

int main() {

    input_adj();
    
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i);
            ++dem;
        }
    }
    cout << dem;

    return 0;
}