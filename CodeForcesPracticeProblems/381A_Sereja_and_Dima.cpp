// 381A : Sereja and Dima
// Two pointers
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    int i = 0, j = n-1;
    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    int sereja = 0, dima = 0;
    while(i <= j) {
        if(i == j) {
            sereja += a[i];
            break;
        }
        if(a[i] < a[j]) {
            //sereja pick largest
            sereja += a[j];
            j--;
            //dima pick largest

            if(a[i] <= a[j]) {
                dima += a[j];
                j--;
            } else {
                dima += a[i];
                i++;
            }
        } else if (a[i] == a[j]) {
            sereja += a[i];
            dima += a[j];
            i++;
            j--;
        } else {
            //sereja pick largest
            sereja += a[i];
            i++;
            //dima pick largest
            if(a[i] <= a[j]) {
                dima += a[j];
                j--;
            } else {
                dima += a[i];
                i++;
            }
        }
    }
    cout << sereja << " " << dima;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}