#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// Extra essential function here

void solve() 
{
    // Solution here
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int key; cin >> key;
        mp[key]++;
        // Thêm số lần xuất hiện cho phần tử key
    }
    int max_freq = 0;
    int res_val = 0;
    for(auto [val,freq] : mp) {
        if(max_freq < freq) { 
            // TH tìm được key lớn hơn với cùng freq, max_freq không cập nhật nên res_val sẽ nhỏ nhất
            // Vì key được sắp xếp tăng dần sẵn
            max_freq = freq;
            res_val = val;
        }
    }
    cout << res_val << " " << max_freq;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
