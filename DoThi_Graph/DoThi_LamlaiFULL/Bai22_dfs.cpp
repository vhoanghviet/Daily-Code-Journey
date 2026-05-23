#include <bits/stdc++.h>
using namespace std;

int m, n ;
int first, last;
const int maxn = 1005;
vector<int> ke[maxn];
vector<pair<int,int>> dscanh;
bool visited[maxn];
//-----------------------------------------------------
int color[maxn]; // |-> COLOR GRAPHHHHHHHHHHHHHHHHHHHH
//-----------------------------------------------------
int parent[maxn];

bool fake_dfs(int u , int par) { // -> KIỂM TRA ĐỒ THỊ CÓ CHU TRÌNH (CYCLE);
    visited[u] = true ;
    for( int v : ke[u]) {
        if(!visited[v]) {
            if(fake_dfs(v,u)) return true; 
            // -> LƯU Ý : Ở ĐÂY KHÔNG ĐƯỢC RETURN DFS(v,u);
            // VÌ SẼ LÀM MẤT NHÁNH CỦA ĐỒ THỊ
        }
        else if(v != par) return true;
    }
    return false;
}

// Real dfs : color graph
// Kiểm tra chu trình trên đồ thị có hướng.
// Detect cycle in directed graph.


bool dfs(int u ) {
    color[u] = 1; // Grey color
    for(int v : ke[u]) {
        if(color[v] == 0) {
            color[v] = 1;
            if(dfs(v)) return true; // Cẩn thận
            // Kiểm tra nếu có bất kì nhánh DFS nào tìm ra được chu trình
            // Thì trả về : -----TRUE ---------
        }else if(color[v] == 1) {
            first = u; last = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}




void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y); // Có hướng 
    }
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
}

int main() {
    nhap();
    for(int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end()) ;
    }
    bool ok = false;
    for(int i = 1; i <= n ; i++) {
        if(!visited[i] ) {
            if(dfs(i)) {
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << "1\n";
    else cout << "0\n";
    return 0;
}