#include <bits/stdc++.h>
using namespace std;

// DSU + union - Thao tác find : Tìm ra đỉnh v1 và v2 thuộc thành phần liên thông thứ mấy, có gộp được không
// Cùng tplt -> Không gộp
// Khác tplt -> Gộp đc

int n;
int parent[1001];
int sz[1001];
void ktao() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u) { // tìm đỉnh đại diện cho tập chứa u
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

int Find_OPTIMIZED(int u) {
    if(u == parent[u]) return u;
    else {
        return parent[u] = Find(parent[u]);
    }
}


bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    else {
        if(u < v) parent[v] = u;
        else parent[u] = v;

        return true;
    }
}
bool Union_OPTIMIZED_SIZE(int u, int v) {
    u = Find_OPTIMIZED(u);
    v = Find_OPTIMIZED(v);
    if(u == v) return false;
    // BƯỚC QUAN TRỌNG -> Mặc định đặt u là đỉnh có Size lớn hơn
    if(sz[u] < sz[v]) {
        swap(u, v); 
    }
    //  Kích thước u tăng
    //  Cập nhật: Thằng nào có kích thước lớn hơn, THẰNG ĐÓ LÀ CHA
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main() {
    ktao();
    cout << Union(6,7) << endl;
    cout << Union(5,6) << endl;
    cout << Union(4,5) << endl;
    cout << Union(4,7) << endl;

    for(int i = 1; i <= n; i++) {
        cout << i << " " << parent[i] << endl;
    }
    return 0;
}