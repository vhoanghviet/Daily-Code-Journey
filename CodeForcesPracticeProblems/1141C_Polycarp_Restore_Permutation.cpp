#include <iostream>
#include <vector>

using namespace std;
long long getMax(vector<long long> &a) {
    long long m = a[0];
    for(long long i = 1; i < (long long)a.size(); i++) {
        if(m < a[i]) m = a[i];
    }
    return m;
}

void countingSort(vector<long long> &a, long long exp) {
    long long n = a.size();
    vector<long long> output(n);
    vector<long long> count(10,0);

    // Xây dựng mảng count đếm số lần xuất hiện của digit
    for(long long i = 0; i < n; i++) {
        long long digit = (a[i]/exp) % 10;
        count[digit]++;
    }
    // Xây dựng mảng count cộng dồn để lưu trữ VỊ TRÍ CUỐI CÙNG của phần tử có DIGIT
    for(long long i = 1; i < 10; i++) { 
        count[i] += count[i-1];
    }
    // Xây dựng mảng output để ghi kết quả:
    for(long long i = n-1; i >= 0; i--) {
        long long digit = (a[i]/exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    // Copy output paste cho a
    a = output;
}
void printArrayIndex1(vector<long long> a) {
    for(long long i = 1; i <= a.size() - 1 ; i++) cout << a[i] << " ";
    cout << endl;
}
void radixSort(vector<long long> &a) {
    if(a.empty()) return;
    long long n = a.size();
    long long m = getMax(a);

    for(long long exp = 1; m / exp > 0; exp *= 10) {
        countingSort(a, exp);
    }
}
bool checkPermutation(vector<long long> a) {
    long long min_p = a[0];
    for(long long x: a) if(x < min_p) min_p = x;
    long long n = a.size();
    vector<long long> p(n);
    p = a;
    for(long long i = 1; i <= n-1; i++) {
        p[i] = p[i] - min_p;
    }
    radixSort(p);

    for(long long i = 2; i < n; i++) {
        if(p[i] != p[i-1] + 1) {
            return false;
        }
    }
    
    return true;
}



void solve() {
    long long n;
    cin >> n;
    vector<long long> q(n); // Mảng q có n-1 phần tử
    vector<long long> mang_cong_don(n+1, 0); // pref sum có n phần tử
    mang_cong_don[2] = 1; 
    long long max_mcd = -1e9;
    for(long long i = 1; i <= n; i++) {
        if(i != n) cin >> q[i];
        if(i < 2) {
            mang_cong_don[i] = mang_cong_don[i+1] - q[i];
        } else if(i > 2) {
            mang_cong_don[i] = mang_cong_don[i-1] + q[i-1];
        }
        if(max_mcd < mang_cong_don[i]) max_mcd = mang_cong_don[i];
    }
    // printArrayIndex1(mang_cong_don);

    if(checkPermutation(mang_cong_don) == false) {
        cout << -1;
        return;
    }
    else {
        // cout << "Mang cong don hien tai: "; printArrayIndex1(mang_cong_don); cout << endl;
        // cout << "Mang q hien tai: "; printArrayIndex1(q); cout << endl;
        long long dif = n - max_mcd;
        for(long long i = 1; i <= n; i++) {
            cout << mang_cong_don[i] + dif << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}