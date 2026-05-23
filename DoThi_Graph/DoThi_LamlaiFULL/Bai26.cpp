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



void dfs(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
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
    vector<int> dai_dien;
    for(int i = 1; i<= n; i++) {
        if(!visited[i] ) {
            dai_dien.push_back(i);
            dfs(i);
        }
    }
    int K = dai_dien.size() - 1;
    cout << K << '\n';
    for(int i = 0; i < K; i++) {
        cout << dai_dien[i] << " " << dai_dien[i+1] << '\n';
    }
    return 0;
}