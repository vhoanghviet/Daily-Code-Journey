#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int so_gian[maxn];
int n, m ;


void nhap() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> so_gian[i];
    }
    for(int i = 0 ; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}


int so_ca = 0;
void bfs(int u) {
    visited[u] = true;
    queue<int> q ; q.push(u);

    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(int x : ke[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true; 
                if(so_gian[x] == 1) {
                    so_gian[x] = so_gian[v] + 1;
                }
            }
        }
    }
    // duyệt số cá ăn được sau cùng? YES
    memset(visited, false, sizeof(visited));
    
    visited[u] = true;
    q.push(u);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        bool is_leaf = true;
        if(so_gian[v] > m) continue;
        for(int x : ke[v]) {
            if(!visited[x]) {
                is_leaf = false;
                visited[x] = true;
                q.push(x);
            }
        }
        if(is_leaf) so_ca++;
    }
}



int main() {
    nhap();
    bfs(1);
    cout << so_ca;
    return 0;
}