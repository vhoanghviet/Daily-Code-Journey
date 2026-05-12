#include <bits/stdc++.h>
using namespace std;

int parent[1001];
int n, m;
void ktao() {
    for(int i = 1 ; i <= n; i++) {
        parent[i] = i;
    }
}

int Find(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    else {
        if(u < v) parent[v] = u;
        else parent[u] = v;
        return true;
    }
}

int main() {
    cin >> n >> m;
    int dem = 0;
    ktao();
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        Union(u,v);
    }
    for(int i = 1 ; i <= n; i++) {
// --------------------------------------------------------------------------------------
        if(i == parent[i]) dem++; 
// Đếm được số đỉnh đại diện cho chính thành phần liên thông của đồ thị vô hướng đang xét
    }
    cout << dem;
    return 0;
}