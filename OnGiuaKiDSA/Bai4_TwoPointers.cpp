#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    int a[N+1];
    for(int i = 0; i < N; i++) cin >> a[i];
    int i = 0, j = 1;
    int ans = -1;
    int cnt = 0;
    int sum = a[0];
    while(i < N) {
        if(sum <= S) {
            cnt++;
            if(ans < cnt) ans = cnt;
            sum += a[j];
            j++;
        } else {
            cnt--;
            sum = sum - a[j] - a[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}