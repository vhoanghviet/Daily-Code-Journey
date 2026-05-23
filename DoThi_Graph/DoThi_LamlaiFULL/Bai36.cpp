#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
int chieu_cao[maxn];
int n ;
void bfs(int u) {
    visited[u] = true;
    queue<int> q; q.push(u);
    chieu_cao[u] = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x : ke[v]) {
            if(!visited[x]) {
                visited[x] = true;
                chieu_cao[x] = chieu_cao[v] + 1;
                q.push(x);
            }
        }
    }
}

void nhap() {
     cin >> n;
    for(int i = 0 ; i < n- 1; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}

int main() {
    nhap();
    bfs(1);
    for(int i = 1; i<= n; i++) {
        cout << chieu_cao[i] << " ";
    }
    return 0;
}