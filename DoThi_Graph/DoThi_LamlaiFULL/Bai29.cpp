#include <bits/stdc++.h>
using namespace std;

int m, n ;
int s,t,u,v;

int first;
int last;
const int maxn = 1005;
vector<int> ke[maxn];
vector<int> t_ke[maxn];
vector<pair<int,int>> dscanh;
bool visited[maxn][maxn];
int parent[maxn];
int in_degree[maxn];
vector<int> topo;
stack<int> dfs_order;
int a[maxn][maxn];
vector<int> path;
int dist[maxn][maxn];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int bfs(int i , int j) {

    visited[i][j] = true;
    queue<pair<int,int>> q ; q.push({i,j}) ;
    dist[i][j] = 0;

    while(!q.empty()) {
        pair<int,int> front = q.front(); q.pop();
            
        int i = front.first;
        int j = front.second;

        if(i == u && j == v) return dist[i][j];

        for(int k = 0; k < 8; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];

            if(i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n 
            && !visited[i1][j1] && a[i1][j1] == 1) {

                dist[i1][j1] = dist[i][j] + 1; // Siêu quan trọng
                // Ô i1;j1 = bước tới ô i;j + 1
                visited[i1][j1] = true;
                q.push({i1,j1});

            }
        }
    }
    return -1;
}

void nhap() {
    cin >> n;
    cin >> s >> t >> u >> v;
    for(int i = 1; i <= n ;i++) {
        for(int j = 1; j <= n ; j++) {
            cin >> a[i][j];
        }
    }
}



int main() {
    nhap();
    cout << bfs(s,t);

    return 0;
}