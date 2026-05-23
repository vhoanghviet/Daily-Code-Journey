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

vector<int> nhom_truong;
int so_ban[maxn];
vector<int> nhom_hien_tai;

void dfs(int u) {
    nhom_hien_tai.push_back(u);
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
        so_ban[x]++;
        so_ban[y]++;
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin() , ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}
int so_ban_max = 0;
int nhom_truong_dukien = 0;
int main() {
    nhap();
    for(int i = 1; i<= n; i++) {
        if(!visited[i] ) {
            nhom_hien_tai.clear();
            dfs(i);
            sort(nhom_hien_tai.begin(),nhom_hien_tai.end());
            nhom_truong_dukien = nhom_hien_tai[0];
            for(int u : nhom_hien_tai) {
                if(so_ban[u] > so_ban[nhom_truong_dukien]) {
                    nhom_truong_dukien = u;
                }
            }
            nhom_truong.push_back(nhom_truong_dukien);
        }
    }
    sort(nhom_truong.begin(), nhom_truong.end());
    for(int x : nhom_truong) cout << x << " ";
    return 0;
}