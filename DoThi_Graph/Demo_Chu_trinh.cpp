#include <bits/stdc++.h>
#include <set>
#include <algorithm>
using namespace std;

vector<int> ke[1001];
int parent[1001];
bool visited[1001];
int n,m;

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1 ; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}
void in() {
    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : ke[i]) cout << x << " ";
        cout << endl;
    }
}

bool DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            parent[v] = u;
            if(DFS(v)) return true; // -> ĐÚNG
            // return DFS(v); -> SAI
        } else if(parent[u] != v) {
            return true;
        }
    }
    return false;
}

int main() {
    nhap();
    // in();
    bool check = false;
    for(int i = 1; i <= n; i++) {
        if(DFS(i)) {
            check = true;
            break;
        }
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}