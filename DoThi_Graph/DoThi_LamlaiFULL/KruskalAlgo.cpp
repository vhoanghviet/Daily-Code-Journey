#include <bits/stdc++.h>
using namespace std;


const int maxn = 1005;
vector<pair<int,int>> ke[maxn];
bool visited[maxn];
int so_gian[maxn];
int n, m ;
int parent[maxn];
int sz[maxn];

struct edge {
    int x,y,w;
};
vector<edge> canh;
void make_set() {
    for(int i = 1; i <= n ;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u) {
    if(u == parent[u]) {
        return u;
    } else {
        return parent[u] = parent[parent[u]];
    }
}
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) {
        swap(u,v);
    }
    parent[v] = u;
    sz[u] += sz[v];
    return true;    
}

void nhap() {
    cin >> n >> m;

    for(int i = 0 ; i < n - 1; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge e = {x,y,w};
        canh.push_back(e);
    }
    for(int i = 1; i <= n ;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}
void kruskal() {
    // Bước 1 tạo cây khung cực tiểu rỗng MST
    vector<edge> MST;
    int d = 0; // trọng số cả cây khung cực tiểu 
    // Bước 2 sort danh sách cạnh theo chiều dài / weight / cân nặng tăng dần
    sort(canh.begin(), canh.end(), cmp) ;
    // Bước 3 Lặp
    for(int i = 0; i < m ;i++) {
        if(MST.size() == n-1) break; // Khi cây khung có n-1 cạnh -> đã đủ cạnh rồi
        edge e = canh[i]; // duyệt từng cạnh (từ ngắn đến dài nhất) 
        if(Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    if(MST.size() != n-1) {
        cout << "Đồ thị không liên thông";
    } else {
        cout << "MST : " << d << endl;
        for(auto e : MST) cout << e.x << " " << e.y <<  " " << e.y << endl;
    }
}


int main() {
    
    nhap();
    make_set();
    kruskal;
    return 0;
}