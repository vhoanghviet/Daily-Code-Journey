#include <bits/stdc++.h>
using namespace std;

bool visited[1001][1001];
int grid[1001][1001];
int n,m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void bfs(int i , int j) {
    visited[i][j] = true;
    queue<pair<int,int>> q;
    q.push({i,j});
    for(int k = 0; k < 4; k++) {
        pair<int,int> top = q.front(); q.pop();
        int i1 = top.first + dx[k];
        int j1 = top.second + dy[k];
        if(i1 >= 0 && j1 >= 0 && i1 < n && j1 < m 
            && grid[i1][j1] == '1' && !visited[i1][j1]) {
            q.push({i1,j1});
            visited[i1][j1] = true;
        }
    }
}

int main() {
    return 0;
}