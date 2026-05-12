#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> adj[1001];
vector<pair<int, int>> dscanh;
int a[1001][1001];
bool visited[1001];
int n, m;

void DFS1(int u) {
    cout << u << " ";
    visited[u] = true;
    
    for(int v : adj[u] ) {
        if(!visited[v]) {
            DFS1(v);
        }
    }
}

void DFS2(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int i = 1; i <= n; i++) {
        if(a[u][i] == 1) { // Phát hiện cạnh
            if(!visited[i]) { // Phát hiện chưa thăm
                DFS2(i);
            }
        }
        
    }
}

// u = dscanh[i].first;
void DFS3(int u) {
    cout << u << " ";
    visited[u] = true;
    for(auto it : dscanh) {
        if(it.first == u) { // phát hiện cạnh
            if(!visited[it.second]) { // phát hiện chưa thăm
                DFS3(it.second);
            }
        }
        if(it.second == u) {
            if(!visited[it.first]) {
                DFS3(it.first);
            }
        }
    }
}

int main() {
    
    return 0;
}