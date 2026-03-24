#include <bits/stdc++.h>
using ll = long long;
using namespace std;
bool checkMid(vector<int> &x, int n, int k, ll sum) {
    int dem = 1;
    ll tong = 0;
    for(int i =0; i < n; i++) {
        tong += x[i];
        if(tong > sum) {
            dem++;
            tong = x[i];
        }
    }
    return dem <= k; // dem = k + 1 thì false để dịch con trỏ left lên
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        x.push_back(temp);
    }
    ll left = 1ll * *max_element(x.begin(),x.end()), right = 1e9*2*1e5;
    ll min_possible_sum = 0;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if(checkMid(x, n, k, mid)) { 
            // Bài này mình muốn max_sum là nhỏ nhất nên
            // khi k dịch từ targetK xuống targetK-1 -> điều này chứng mình rằng có một mảng có tổng lớn nhất bị vỡ trong quá
            // trình chia vào các hộp một cách tham lam nhất (ít tốn tiền hộp nhất).
            // nên cái tổng đó chính là giá trị targetSum là mid khi targetK thỏa với mid nhỏ nhất.
            min_possible_sum = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << min_possible_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}