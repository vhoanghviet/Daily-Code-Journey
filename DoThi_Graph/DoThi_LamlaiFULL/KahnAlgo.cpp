#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 1001;
vector<int> ke[maxn];
bool visited[maxn];
vector<int> topo;
int in[maxn];

void nhap() {
    cin >> n >> m ;
    for(int i = 0; i < m; i++) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y);
        in[y]++; // Tính bán bậc vào của mỗi đỉnh
    }
    memset(visited, false, sizeof(visited));
}

void kahn() {
    queue<int> q;
    for(int i = 1; i<= n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : ke[u]) {
            in[v]--;
            if(in[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int x : topo) cout << x << " ";
}

int main() {
    nhap();
    kahn();
    // reverse(topo.begin(), topo.end());
    // for(int x : topo) {
    //     cout << x << " ";
    // }
    return 0;
}