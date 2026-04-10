// 1650A : Deletions of two adjacent letter
// Sliding window

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int test_cases;
    cin >> test_cases;
    while(test_cases--) {
        string s;
        cin >> s;
        char t;
        cin >> t;
        int n = s.size();
        bool can_convert = false;
        for(int i = 0; i < n; i++) {
            if (s[i] == t) {
                int length_left = i;
                if (length_left % 2 == 0){
                    can_convert = true;
                    cout << "YES\n";
                    break;
                }
            }
        }
        if(can_convert == false) cout << "NO\n";

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}