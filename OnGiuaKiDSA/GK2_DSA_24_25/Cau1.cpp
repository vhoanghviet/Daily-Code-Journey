#include <iostream>
#include <vector>
#include <string>

using namespace std;
using maTran = vector<vector<float>>;

// Cau 1: a)
maTran TichHaiMaTran(maTran &A, maTran &B, int n) {
    maTran tich(n, vector<float>(n,0.0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                tich[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return tich;
}
// Cau 1: b)
maTran donVi(int n) {
    maTran I(n, vector<float>(n,0.0));
    for(int i = 0; i < n; i++) {
        I[i][i] = 1.0;
    }
    return I;
}
maTran luyThuaMaTran(maTran &A,int n, int mu_k) {
    maTran ketQua = donVi(n);
    while(mu_k--) {
        ketQua = TichHaiMaTran(ketQua,A,n);
    }
    return ketQua;
}
maTran luyThuaMaTranDeQuy(maTran &A, int n, int mu_k){
    if(mu_k == 0) return donVi(n);
    maTran ketQua = luyThuaMaTranDeQuy(A, n, mu_k-1);
    return TichHaiMaTran(A,ketQua,n);
}


void solve() {

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}