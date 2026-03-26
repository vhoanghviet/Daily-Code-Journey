#include <bits/stdc++.h>
using ll = long long;
using namespace std;



int sumDigit(int x) {
    int sum = 0;
    while(x > 0) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

bool cmp(int a, int b)
{
    int na = sumDigit(a), nb = sumDigit(b);
    if(na == nb) return a < b;
    else return na <nb;
}
void solve() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

