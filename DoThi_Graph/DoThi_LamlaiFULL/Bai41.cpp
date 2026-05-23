#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<pair<int,int>> ke[maxn];
bool visited[maxn];
int parent[maxn];
int sz[maxn];
int n, m , s;

struct edge{
    int x,y,w;
};
vector<edge> canh;
bool cmp(edge a, edge b) {
    return a.w < b.w;
}
void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        ke[x].push_back({y,w});
        ke[y].push_back({x, w});
        canh.push_back({x,y,w});
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    
    memset(visited, false, sizeof(visited));
}

void make_set() {
    for(int i = 1; i <= n ;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u) {
    if(u == parent[u]) {
        return u;
    } else {
        return parent[u] = parent[parent[u]];
    }
}
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) {
        swap(u,v);
    }
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}
void kruskal() {
    vector<edge> MST;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m ; i++) {
        if(MST.size() == n - 1) break; // Tìm được MST;
        edge e = canh[i];
        if(Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    if(MST.size() != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << d;
    }
}

int main() {
    nhap();
    make_set();
    kruskal();
    return 0;
}