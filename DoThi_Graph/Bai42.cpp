#include <bits/stdc++.h>
using namespace std;


struct edge {
    int x,y,w;
};
int parent[1001], sz[1001]; // cài đặt cấu trúc Disjoint set union
int n, m, dem, max_cur = 1;

vector<edge> dscanh;

void ktao() {
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        parent[i] = i;
    }
}
int Find(int u) {
    if(u == parent[u]) {
        return u;
    } else {
        return parent[u] = Find(parent[u]);
    }
}
bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) {
        swap(u,v); // Mặc định đỉnh u là đỉnh có Kích thước Cây lớn nhất
    }
    parent[v] = u;
    sz[u] += sz[v];

    // Ở đây cập nhật kích thước lớn nhất của cụm đường
    // Từng là cập nhật kích thước của Cây khung cực tiểu của Cấu trúc DSU
    // Mỗi ngày thì một con đường mới được kết nối khiến kích thước cây khung cực tiểu trong
    // Thuật toán Kruskal tăng kích thước dần lên
    if(sz[u] > max_cur) max_cur = sz[u];
    return true;
}

void nhap() {
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back((edge){x,y,w});
    }
}
// void Kruskal() { // Có DSU rồi thì rất dễ code
//     // Bước 1 : Sắp xếp danh sách cạnh theo trọng số tăng dần
//     sort(dscanh.begin(), dscanh.end(), [](edge a,edge b)->bool{
//         return a.w < b.w;
//     });
//     // Bước 2: Lặp
//     int d = 0;
//     vector<edge> MST;
//     for(int i = 0; i < m; i++) {
//         if(MST.size() == n - 1) break;
//         edge e = dscanh[i];
//         // MST + e có tạo thành chu trình hay không
//         if(Union(e.x, e.y)) { // Không tạo thành chu trình vì không cùng thành phần liên thông
//             MST.push_back(e);
//             d += e.w ; // Tính tổng trọng số của cây khung
//         }
//     }
//     cout << d << endl;
//     for(auto it : MST) {
//         cout << it.x << " "<< it.y << " " << it.w << endl;
//     }
// }

void Kruskal() {
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool{
        return a.w < b.w;
    });
    long long d= 0;
    vector<edge> MST;
    for(int i = 0; i < m; i++) {
        if(MST.size() == n - 1) break;
        edge e = dscanh[i];
        if(Union(e.x, e.y)) {
            MST.push_back(e);
            d += (long long)e.w;
        }
    }
    cout << d << endl;
    for(auto it : MST) {
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

int main() {
    
    cin >> n >> m;
    ktao();
    int dem = n;
    for(int i = 0 ; i < m ; i++) {
        int x,y; cin >> x >> y;
        if(Union(x, y)) {
            dem--; 
            // Mỗi lần kết nối được 2 đỉnh thì con đường tạo ra khiến 
            // Số cụm con đường giảm, số cụm đường là số thành phần liên thông của đồ thị
            // Bởi vì định nghĩa 1 cụm thành phố là 1 thành phần liên thông
            // Chỉ rõ ở chỗ : "Một cụm thành phố là một nhóm các thành phố trong đó có 
            // ******một tuyến đường giữa hai thành phố bất kỳ****** bằng cách sử dụng các con đường" 
        }
        cout << dem << " " << max_cur << endl;
    }
    return 0;
}