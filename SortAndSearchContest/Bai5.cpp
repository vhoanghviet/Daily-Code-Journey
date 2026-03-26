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
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        mp[key]++;
    }
    int res_val = 0;
    int max_freq = 0;
    for(auto [key,freq] : mp) {
        if(max_freq < freq) {
            max_freq = freq;
            res_val = key;
        }
    }
    cout << res_val << " "<< max_freq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
