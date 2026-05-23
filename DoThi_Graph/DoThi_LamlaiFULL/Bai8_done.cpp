#include <bits/stdc++.h>
using namespace std;
vector<int> ke[10007];
int a[1001][1001];

struct edge {
    int x,y,w;
};

int main() {
    int n; cin >> n;

    vector<edge> dscanh;
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    
    for(int i = 0 ; i < n ; i++)  {
        for(int j = 0; j <n ; j++) {
            cin >> adj_matrix[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)  {
        for(int j = 0; j <n ; j++) {
            if(adj_matrix[i][j] != 0) {
                int weight = adj_matrix[i][j];
                edge e; e.x = i+1; e.y = j+1 ; e.w = weight;
                if(i < j )dscanh.push_back(e);
            }
        }
    }
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    for(edge e : dscanh) {
        cout << e.x << " " << e.y << " " << e.w << '\n';
    }

    return 0;
}