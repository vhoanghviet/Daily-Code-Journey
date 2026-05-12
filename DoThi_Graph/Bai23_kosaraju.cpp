#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100001;
vector<int> ke[SIZE], t_ke[SIZE];
stack<int> st;
bool visited[SIZE];
int n,m;

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        int x,y ; cin >> x >> y;
        ke[x].push_back(y); 
        t_ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS1(int u) {
    visited[u] = true;
    for(int v: ke[u]) {
        if(!visited[v]) {
            DFS1(v);
        }
    }
    st.push(u);
}
void DFS2(int u) {
    visited[u] = true;
    for(int v : t_ke[u]) {
        if(!visited[v]) {
            DFS2(v);
        }
    }
}

void kosaraju(){
    for(int i = 1; i <= n ; i++) {
        if(!visited[i]) {
            DFS1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while(!st.empty()) {
        int top = st.top(); st.pop();
        if(!visited[top]) {
            scc++;
            DFS2(top);
        }
    }
    if(scc == 0) cout << "0\n";
    else cout << "1\n";
}

int main() {
    nhap();
    kosaraju();
    return 0;
}