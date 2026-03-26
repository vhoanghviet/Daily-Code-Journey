#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// Extra essential function here

void solve() 
{
    // Solution here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    int nq;
    cin >> nq;
    vector<int> q(nq);
    int temp;
    for(int i = 0; i < nq; i++) {
        cin >> q[i];
    }
    for(int i : q) {
        int left = 0 , right = n-1;
        bool found = false;
        while(left <= right) {
            int mid = (left+right) /2;
            if(a[mid] == i) {
                found = true;
            } else if(a[mid] < i) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(found) cout << "YES";
        else cout << "NO";

        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
