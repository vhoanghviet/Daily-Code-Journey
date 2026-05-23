#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int chieu_cao[maxn];
int n ;


void nhap() {
     cin >> n;
    for(int i = 0 ; i < n- 1; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for(int v : ke[u] ) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int tplt_ban_dau = 1;
void dinhcau() {
    int so_dinh_cau = 0;
    for(int i = 1; i <= n; i++) {
        visited[i] = true;
        int tplt = 0;
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                tplt++;
                dfs(j);
            }
        }
        if(tplt > tplt_ban_dau) {
            so_dinh_cau++;
        }
    }
    cout << so_dinh_cau;
}


int main() {
    nhap();
    dinhcau();
    return 0;
}