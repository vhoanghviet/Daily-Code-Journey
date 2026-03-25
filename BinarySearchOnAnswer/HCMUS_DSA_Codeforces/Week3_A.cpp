#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> array(n);
    vector<int> q_array(q);
    int pivot_index = 0;
    for(int i =0; i < n; i++) {
        cin >> array[i];
    }
    for(int i = 0; i < n - 1; i++) {
        if(array[i] > array[i+1]) pivot_index = i+1;
    }
    for(int i = 0; i < q; i++) {
        cin >> q_array[i];
    }
    for(int i = 0 ; i < q; i++) {
        ll left = 0, right = n-1;
        ll ans = -1;
        while(left <= right) {
            ll tempMid = (left + right) /2;
            ll mid = (tempMid + pivot_index + n) % n;
            if(array[mid] == q_array[i]) {
                ans = mid;
                break;
            } else if(array[mid] < q_array[i]) {
                left = tempMid + 1;
            } else {
                right = tempMid - 1;
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