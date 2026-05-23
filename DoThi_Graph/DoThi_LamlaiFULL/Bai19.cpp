#include <bits/stdc++.h>
using namespace std;

int m, n ;
const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m ;i++) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void dinhtru() {
    int ans = 0;
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1 ; i <= n; i++) {
        if(!visited[i]) {
            tplt++;
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        // Loại bỏ i khỏi đồ thị
        memset(visited, false, sizeof(visited)); // Reset mảng visited mỗi lần kiểm tra đỉnh trụ
        visited[i] = true;
        int dem = 0; // đếm số tplt sau khi bỏ đỉnh i
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                dem++;
                dfs(j);
            }
        }
        if(dem > tplt) {
            ans++;
        }
    }
    cout << ans;
}

int main() {
    nhap();
    dinhtru();
    return 0;
}