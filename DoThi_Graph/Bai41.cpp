#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x,y,w;
};

using ll = long long;

int n,m;
vector<edge> dscanh;
int parent[100005], sz[100005];

void ktao() {
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        parent[i] = i;
    }
}
void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back((edge){x,y,w});
    }
}

int Find(int u) {
    if(u == parent[u]){
        return u;
    } else {
        return parent[u] = Find(parent[u]);
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
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool{
        return a.w < b.w;
    });
    ll d = 0;
    vector<edge> MST;
    for(int i = 0; i < m; i++) {
        if(MST.size() == n - 1) break;
        edge e = dscanh[i];
        if(Union(e.x,e.y)) {
            MST.push_back(e);
            d += (ll)e.w;
        }
    }
    if(MST.size() < n - 1) cout << "IMPOSSIBLE\n";
    else cout << d << endl;
}

int main() {
    nhap();
    ktao();
    kruskal();
    return 0;
}