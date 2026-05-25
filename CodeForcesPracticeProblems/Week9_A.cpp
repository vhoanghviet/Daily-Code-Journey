#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
const int maxn = 1005;
char a[maxn][maxn];
bool visited[maxn][maxn];
int ans[maxn][maxn];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<int> x_cord;
vector<int> y_cord;

void nhap() {
    cin >> n >> m >> k;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; i++) {
        int t1, t2; cin >> t1 >> t2;
        x_cord.push_back(t1);
        y_cord.push_back(t2);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int i, int j) {
    if(a[i][j] == '*') return;
    
    int picture = 0; 
    visited[i][j] = true;
    
    queue<pair<int,int>> q; 
    vector<pair<int, int>> comp;
    
    q.push({i, j});
    comp.push_back({i, j});
    
    while(!q.empty()) {
        pair<int,int> front = q.front(); q.pop();
        for(int z = 0; z < 4; z++) {
            int i1 = front.first + dx[z], j1 = front.second + dy[z];
            if(i1 >= 0 && j1 >= 0 && i1 < n && j1 < m) {
                if(a[i1][j1] == '.' && !visited[i1][j1]) {
                    visited[i1][j1] = true;
                    q.push({i1, j1});
                    comp.push_back({i1, j1});
                } else if(a[i1][j1] == '*') {
                    picture++;
                }
            }
        }
    }
    
    for(auto cell : comp) {
        ans[cell.first][cell.second] = picture;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    nhap();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }
    
    for(int p = 0; p < k ; p++) {
        int r = x_cord[p] - 1;
        int c = y_cord[p] - 1;
        cout << ans[r][c] << '\n';
    }
    
    return 0;
}