#include <bits/stdc++.h>
using namespace std;

int m, n ;
int first;
int last;
const int maxn = 1005;
vector<int> ke[maxn];
vector<pair<int,int>> dscanh;
bool visited[maxn];
int parent[maxn];
int in_degree[maxn];
vector<int> topo;

void nhap() {
    cin >> n >> m;
    memset(in_degree, 0, sizeof(in_degree));

    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y); // Có hướng
        in_degree[y]++;
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin() , ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}
bool bfs() {
    queue<int> q;
    for(int i = 1; i <= n ;i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front(); q.pop();
        topo.push_back(v);
        for(int x : ke[v]) {
            in_degree[x]--;
            if(in_degree[x] == 0) q.push(x);
        }
    }
    return topo.size() == n;
}

int main() {
    nhap();
    if(bfs()) cout << "0\n";
    else cout << "1\n";
    // bool ok = false;
    // for(int i = 1; i<= n ; i++) {
    //     if(!visited[i]) {
    //         if(bfs(i)) {
    //             ok = true;
    //             break;
    //         }
    //     }
    // }
    // if(ok) cout << "1\n";
    // else cout << "0\n";
    return 0;
}