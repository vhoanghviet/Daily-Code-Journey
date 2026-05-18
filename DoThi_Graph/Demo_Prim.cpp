#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x,y,w;
};
// int parent[1001], sz[1001]; // cài đặt cấu trúc Disjoint set union
int n, m;
bool taken[1001]; // Đánh dấu đỉnh nào đã nằm trong cây khung
vector<pair<int,int>> adj[1001];

typedef pair<int,int> pii;

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y,w; cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}

void Prim(int s) {
    // Bước 1 : LẤY ĐỈNH NGUỒN
    taken[s] = true; // Nạp s vào cây khung - Đỉnh nguồn
    priority_queue<     pii, vector<pii>, greater<pii>   > Q;
    // Thao tác tạo minHeap cho PQueue
    for(auto it : adj[s]) { // - Xét cạnh kề
        int t = it.first;
        if(!taken[t]) { // Vẫn thuộc tập v
            Q.push({it.second, t}); // weight , vertix
        }
    }
    long long d= 0, dem = 0; // Lưu trọng số cây khung

    // Bước 2 : LẶP
    while(!Q.empty()) {
        // BƯỚC 2.1 : LẤY CẠNH NGẮN NHẤT chưa THUỘC MST
        pair<int,int> e = Q.top(); Q.pop(); // Lấy ra cạnh ngắn nhất
        int w = e.first, u = e.second;
        if(!taken[u]) { // u chưa thuộc tập MST, vẫn thuộc v
            ++dem;
            d += w;
            taken[u] = true;
            // BƯỚC 2.2 : XÉT NHỮNG CẠNH KỀ của Đỉnh kề trong CẠNH NGẮN NHẤT
            for(auto it : adj[u]) {
                // Nếu chưa thuộc MST thì thêm vào
                if(!taken[it.first]) {
                    Q.push({it.second,it.first});
                }
            }
        }
    }
    if(dem == n -1) {
        cout << d << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
    








//------------------------------
// void ktao() {
//     for(int i = 1; i <= n; i++) {
//         sz[i] = 1;
//         parent[i] = i;
//     }
// }
// int Find(int u) {
//     if(u == parent[u]) {
//         return u;
//     } else {
//         return parent[u] = Find(parent[u]);
//     }
// }
// bool Union(int u, int v) {
//     u = Find(u);
//     v = Find(v);
//     if(u == v) return false;
//     if(sz[u] < sz[v]) {
//         swap(u,v); // Mặc định đỉnh u là đỉnh có Kích thước Cây lớn nhất
//     }
//     parent[v] = u;
//     sz[u] += sz[v];
//     return true;
// }
//------------------------------
int main() {
    nhap();
    Prim(1);
    return 0;
}