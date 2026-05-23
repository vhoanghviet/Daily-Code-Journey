#include <bits/stdc++.h>
using namespace std;

int k,m, n ;
int first;
int last;
const int maxn = 1005;
vector<int> ke[maxn];
bool visited[maxn];
vector<int> dia_diem;
int cnt[maxn]; // Lưu số lượng người có thể đến địa điểm u

void nhap() {
    cin >> k >> n >> m;
    for(int b = 1; b <= k ; b++) { // có k người ; người thứ b đứng ở dia_diem[b]
        int x; cin >> x;
        dia_diem.push_back(x); // Địa điểm người thứ i đang đứng
        // dòng i+1 chứa một số nguyên trong khoảng (1..N) cho biết địa điểm mà người thứ i đang đứng.
    }
    for(int i = 0; i < m ;i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y); // Có hướng
    }
    for(int i = 1; i <= n ; i++) {
        sort(ke[i].begin() , ke[i].end());
    }
    memset(visited, false, sizeof(visited));
}


void dfs(int u) {
    visited[u] = true;
    cnt[u]++; // Đếm số người có thể thăm được đỉnh u.
    for(int v : ke[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    nhap();
    for(int i = 0; i < k; i++) {
        memset(visited, false, sizeof(visited));
        if(!visited[dia_diem[i]]) {
            dfs(dia_diem[i]);
        }
    }
    int so_diem_hop_mat = 0;
    for(int i = 1; i <= n ;i++) {
        if(cnt[i] == k) {
            so_diem_hop_mat++;
        }
    }
    cout << so_diem_hop_mat;

    return 0;
}