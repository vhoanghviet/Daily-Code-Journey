#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int f(char x) {
    return x - 'a';
}

void solve() {
    string s;
    cin >> s;
    vector<int> freq(256, 0);
    int f_max = 0;
    char key_max = 'a';
    for(char x : s) {
        freq[f(x)]++;
        if(f_max < freq[f(x)]) {
            f_max = freq[f(x)];
            key_max = x;
        }
    }
    cout << key_max << " "<< f_max;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}