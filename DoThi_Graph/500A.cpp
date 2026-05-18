#include <bits/stdc++.h>
using namespace std;



int n, t;
vector<int> ke[30005];
bool visited[30005];

void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        ke[i].push_back(i+x);
    }
    DFS(1);
    if(visited[t]) {
        cout << "YES";
    } else cout << "NO";
    return 0;
}