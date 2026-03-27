#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// Extra essential function here
void solve2(vector<int> &a, int X) {

}
void solve1(vector<int> &a, int X) {
    int left = 0, right = INT_MAX;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == X) {
            ans = mid;
            break;
        } else if (a[mid] < X) {
            // Mảng tăng dần
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}


void solve() 
{
    // Solution here
    int n; cin >> n;
    int X; cin >> X;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    solve1(a,X);
    solve2(a,X);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
