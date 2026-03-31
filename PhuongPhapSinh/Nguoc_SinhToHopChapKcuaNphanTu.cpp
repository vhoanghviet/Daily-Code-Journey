/*
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, k, a[100];
int final = 0;

void ktao() {
    for(int i = 1; i <= k; i++) {
        a[i] = n-k+i;
    }
}
void sinh() {
    int i = 1;
    while(i <= k && a[i] == i) {
        i++;
    }
    if(i == k + 1) {
        final = 1;
    } else {
        a[i]--;
    }
}

int main() {
    cout << "N = "; cin >> n;
    cout << "K = "; cin >> k;
    ktao();
    while(final == 0) {
        for(int i = 1; i <= k; i++) {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}

*/
// ......._______---------^^^^^<<<<<<< CÁCH - 2 >>>>>>>>^^^^^-----_______....... //
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, k, a[100], final = 0;

void ktao() {
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) {
        i--;    
    }
    if(i == 0) {
        final = 1;
    } else {
        a[i]++;
    }
}

vector<vector <int>> res;

void printVector(vector<int> a) {
    for(int x : a) cout << x;
}

int main() {
    cout << "N = ";
    cin >> n;
    cout << "K = ";
    cin >> k;
    ktao();
    while(final == 0) {
        vector<int> tmp;
        for(int i = 1; i <= k; i++) {
            tmp.push_back(a[i]);
        }
        res.push_back(tmp);
        sinh();
    }
    for(auto it = res.rbegin(); it != res.rend(); it++) {
        printVector(*it);
        cout << endl;
    }

}