#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a[N+1][M+1];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    int prefix_sum[N+1][M+1];
    prefix_sum[0][0] = a[0][0];
    for(int i = 1 ; i < N; i++) {
        prefix_sum[i][0] = a[i][0] + prefix_sum[i-1][0]; 
    }
    for(int j = 1; j < M; j++) {
        prefix_sum[0][j] = a[0][j] + prefix_sum[0][j-1];
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++) {
            prefix_sum[i][j] = a[i][j] + prefix_sum[i][j-1]
            + prefix_sum[i-1][j] - prefix_sum[i-1][j-1];
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1-= 1;
        x2-= 1;
        y1-= 1;
        y2-= 1;
        if(x1 > 0 && y1 > 0) {
            int total = prefix_sum[x2][y2] - prefix_sum[x2][y1-1]
            - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1];
            cout << total << endl;
        } else if(x1 > 0) {
            int total = prefix_sum[x2][y2] - prefix_sum[x1-1][y2];
            cout << total << endl;
        } else if(y1 > 0) {
            int total = prefix_sum[x2][y2] - prefix_sum[x2][y1-1];
            cout << total << endl;
        } else {
            int total = prefix_sum[x2][y2];
            cout << total << endl;
        }
    }
    return 0;
}