#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n) , b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(b[i] < b[j]) {
                    int temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
        }
        
        int i = 0;
        int j = 0;
        while(k-- && j < n && i < n) {
            if(a[i] < b[j]) {
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
                i++; j++;
            } else {
                j++;
            }
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        cout << sum << endl;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}