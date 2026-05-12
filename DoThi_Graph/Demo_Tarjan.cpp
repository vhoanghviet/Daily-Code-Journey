#include <bits/stdc++.h>
using namespace std;

// Thuật toán tarjan -> Giúp xác định đỉnh trụ và cạnh cầu tốc độ nhanh hơn.
// Thuật toán tarjan : Nhanh hơn 2 lần vì chỉ duyệt 1 lần DFS là xác định được đỉnh trụ, cạnh cầu
// Không cần phải xóa thử rồi thêm lại như brute-force DFS. (Phải duyệt 2 lần)
int n,m, timer = 0;
vector<int> ke[1001];
int disc[1001], low[1001];
bool visited[1001], AP[1001];

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m ;i++) {
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(AP,false, sizeof(AP));
}
void DFS(int u, int par) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int child = 0;
    for(int v : ke[u]) {
        if(v == par) continue;
        if(!visited[v]) {
            DFS(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if(par != -1 && low[v] >= disc[u]) { // Check mỗi đỉnh của cây con DFS
                AP[u] = true;
            }
        }
        else {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(par == -1 && child > 1) AP[u] = true; // Xét đỉnh nguồn có phải đỉnh cầu hay không
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);    
    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS(i, -1);
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        if(AP[i]) cout << i << " ";
    }
    return 0;
}