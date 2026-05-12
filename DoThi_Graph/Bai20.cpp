#include <bits/stdc++.h>
#include <set>
#include <algorithm>
using namespace std;

set<int> ke[1001];
vector<pair<int,int>> dscanh;
bool visited[1001];
int n,m;

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dscanh.push_back({x,y});
        ke[x].insert(y);
        ke[y].insert(x);
    }
}
void in() {
    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : ke[i]) cout << x << " ";
        cout << endl;
    }
}
void DFS(int u ) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}
int tplt() {
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++dem;
            DFS(i);
        }
    }
    return dem;
}

void canh_cau() {
    int cc = tplt();
    int dem = 0;
    for(auto it : dscanh) {
        memset(visited,false,sizeof(visited));
        int x = it.first, y = it.second;
        ke[x].erase(y);
        ke[y].erase(x);
        if(cc < tplt()) {
            dem++;
        }
        ke[x].insert(y);
        ke[y].insert(x);
    }
    cout << dem;
}

void DFS(int u, int s, int t) {
    visited[u] = true;
    for(int v : ke[u]) {
        if((u == s && v == t) || (u == t && v == s))
            continue;
        if(!visited[v]){
            DFS(v,s,t);
        }
    }
}
int tplt(int s, int t) {
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++dem;
            DFS(i,s,t);
        }
    }
    return dem;
}

void canh_cau_Cach2() {
    int dem = 0;
    int cc = tplt(INT_MIN,INT_MIN);
    for(auto it : dscanh) {
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        if(cc < tplt(x,y)) {
            dem++;
        }
    }
    cout << dem;
}
int main() {
    nhap();
    // in();
    canh_cau_Cach2();
    return 0;
}