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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int nq;
    cin >> nq;

    for (int i = 0; i < nq; i++)
    {
        int X; cin >> X;
        int left = 0, right = n - 1;
        bool found = false;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] == X)
            {
                found = true;
                break; // Cực kì quan trọng.
            }
            else if (a[mid] > X)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (found)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
