#include <bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int n,m;

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(),ke[i].end());
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
//3 đỉnh trụ của đồ thị là : 2, 5, 10

void dinh_tru() {
    int dem = 0;
    int cc = tplt();
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(cc < tplt()) {
            dem++;
        }
    }
    cout << dem;
}
int main() {
    nhap();
    // in();
    dinh_tru();
    return 0;
}