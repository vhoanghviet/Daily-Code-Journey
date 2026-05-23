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



void nhap() {
    cin >> n;
    for(int i = 0; i < n-1 ;i++) { // n-1 cạnh
        int x, y; cin >> x >> y;
        ke[x].push_back(y); 
        ke[y].push_back(x);// vô hướng
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}


int d[maxn][maxn];
int dist[maxn];

int bfs(int i , int j) {
    memset(visited, false, sizeof(visited));
    visited[i] = true;
    queue<int> q; q.push(i);
    dist[i] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        // NHỚ : LUÔN DUYỆT ĐỈNH QUEUE 
        if(u == j) return dist[u];
        for(int v : ke[u]) {
            if(!visited[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    nhap();
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n; j++) {
            d[i][j] = bfs(i,j);
        }
    }
    int cnt = 0;
    for(int i = 1; i <=n ;i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] == d[1][j] - d[i][1]) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}