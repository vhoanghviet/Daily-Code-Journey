#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool visited[51][51];
    int max_area = 0;
    int dem = 1;
    typedef vector<vector<int>> vvi;
    void DFS(int i, int j,int m, int n, vvi &grid) {
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 0 && i1 < m && j1 >= 0 && j1 < n
            && !visited[i1][j1] && grid[i1][j1] == 1) {
                dem++;
                max_area = max(max_area, dem);
                DFS(i1,j1,m,n, grid);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dem = 1;
                    max_area = max(max_area, dem);
                    DFS(i,j,m,n, grid);
                }
                    
            }
        }
        return max_area;
    }
};