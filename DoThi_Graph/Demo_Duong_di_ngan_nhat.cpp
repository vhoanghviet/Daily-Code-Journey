#include <bits/stdc++.h>
using namespace std;
int s,t,u,v;
char a[1001][1001];
int d[1001][1001];
bool visited[1001][1001];

int n,m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
char dir[4] = {'U','L','R','D'};
void bfs(int i , int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    a[i][j] = 'x'; // Đường đi là 'o' thì không đi thì đánh 'x'
    d[i][j] = 0;
    while(!q.empty()) {
        pair<int,int> top = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            // duyệt các đỉnh kề.
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && a[i1][j1] != 'x') {
                d[i1][j1] = d[top.first][top.second] + 1;
                if(a[i1][j1] == 'B') return; 
                q.push({i1,j1});
                a[i1][j1] = 'x';
            }
        }
    }
}
void inp() {
    cin >> n >> m;
    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                s = i, t = j;
            }
            if(a[i][j] == 'B') {
                u = i, v = j;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    bfs(s,t);
    if(!d[u][v]) {
        cout << "Khong co duong di\n";
    } else {
        cout << d[u][v] << "\n";
    }
}

// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
bool DFS(int i, int j) {
    if(a[i][j] == 'B') {
        return true;
    }
    a[i][j] = 'x'; // Chỉ đi được trên 'o' nên đánh dấu 'x'
    for(int k = 0; k < 4 ; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
            if(DFS(i1,j1)) return true;
        }
    }
    return false;
}
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------
// ---------------------------------------------------

int main() {
    inp();
    return 0;
}