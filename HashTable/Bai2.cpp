#include <iostream>
#include <cmath>
using namespace std;

const int M = 300007;
long long hashTable[M];
bool visited[M];

int f(long long X) {
    return abs(X) % M;
}


bool insert(long long X, long long value) {
    long long target = X - value;
    int check = f(target);
    while(visited[check]) {
        if(hashTable[check] == target) return false;
        check = (check + 1) % M;
    }
    int h = f(value);
    while(visited[h]) {
        if(hashTable[h] == value) return true;
        h = (h + 1) % M;
    }
    hashTable[h] = value;
    visited[h] = true;
    return true;
}

void solve() {
    int n;
    long long X;
    cin >> n >> X;
    int count = 0;
    for(int i = 0; i < n; i++) {
        long long value;
        cin >> value;
        if(insert(X, value)) {
            count++;
        }
    }
    if(count != n) cout << "YES";
    else cout << "NO";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}