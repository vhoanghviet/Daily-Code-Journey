#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

bool check(vector<int> &a, int n, int x, ll best_possible_h) {
    ll sum_water_blocks = 0;
    for(int i = 0; i < n; i++) {
        if(best_possible_h > a[i]) sum_water_blocks += best_possible_h - a[i];
        if(sum_water_blocks > x) return false;
    }
    if(sum_water_blocks <= x) {
        return true;
    } else {
        return false;
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0 ; i < n; i++) {
            cin >> a[i];
        }

        ll left = 0, right = 2e5 * 1e9;
        ll ans = 0;
        while(left <= right) {
            ll mid = (left + right) / 2;
            if(check(a, n, x, mid)) {
                ans = mid;
                // Tìm chiều cao tối đa có thể đổ đủ ( <= ) x block nước
                // Dịch trỏ trái để tìm chiều cao lớn hơn nếu khả thi
                left = mid + 1;
            } else {
                // Dịch trỏ phải để tìm chiều cao đủ khả thi cho x block nước được đổ đủ
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}