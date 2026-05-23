#include <bits/stdc++.h>
using namespace std;

int m, n ;
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
int color[maxn];
char a[maxn][maxn];


vector<int> area;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int cur_area = 0;
void dfs(int i , int j) {
    visited[i][j] = true;
    cur_area++;
    for(int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(    i1 >= 0 && j1 >= 0 
            && i1 < n && j1 < m
            && !visited[i1][j1] 
            && a[i1][j1] == '.') {
            dfs(i1,j1);
        }
    }
}
void nhap() {
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n ;i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        for(int j = 0; j < m ;j++) {
            a[i][j] = s[j];
        }
    }
}

int main() {
    nhap();
    int room = 0;
    for(int i =0 ; i < n ;i++) {
        for(int j = 0; j < m ; j++) {
            if(!visited[i][j] && a[i][j] == '.') {
                cur_area = 0;
                dfs(i,j);
                area.push_back(cur_area);
            }
        }
    }
    for(int x : area) cout << x << " ";
    return 0;
}