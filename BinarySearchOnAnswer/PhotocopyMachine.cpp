#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkMid(int n, int x, int y, ll current_available_time) {
    current_available_time -= min(x,y);
    if(current_available_time < 0) return false; // ràng buộc n > 0 sẵn rồi
    return current_available_time / x + current_available_time / y >= n - 1;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    ll left = 0, right = 1ll * n * max(x, y);
    ll ans = 0;
    while(left <= right) {
        // lưu ý ở bài này là mình dịch chuyển thời gian
        // sao cho đồng thời với Lượng thời gian này
        // tạo ra số lượng bản copy >= n - 1 ( dành thời gian ra để photo 1 bản cho máy 2)
        // Thời gian cũng bị hao hụt một lượng min(x,y)
        ll mid = (left+right)/2;

        if(checkMid(n,x,y,mid)) { // sum_time >= time -> Thời gian ít nhất cần để photo n bản
            // đáp án nằm ở nửa trái -> dịch trỏ right
            ans = mid; 
            right = mid - 1; // đủ thời gian để copy n bản rồi, giảm xuống
        } else {
            left = mid + 1; // thời gian chưa đủ, phải tăng lên
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}