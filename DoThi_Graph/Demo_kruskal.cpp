#include <bits/stdc++.h>
using namespace std;

int parent[1001];
int sz[1001];
int n;

void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i]  = 1;  
    }
}

int Find(int u) {
    if(u == parent[u]) {
        return u;
    } else {
        return parent[u] = Find(parent[u]);
    }
}
bool Union(int u, int v) {
    int u = Find(u);
    int v = Find(v);
    if(u == v) return false;
    else {
        if(sz[u] > sz[v]) {
            swap(u,v);
        }
        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
}



int main() {
    return 0;
}