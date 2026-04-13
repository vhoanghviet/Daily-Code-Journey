#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, vector<int> &p, int l, int m, int r) {
    vector<int> temp_a, temp_p;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp_p.push_back(p[i]); 
            temp_a.push_back(a[i++]);
        }
        else {
            temp_p.push_back(p[j]);
            temp_a.push_back(a[j++]);
        }
    }

    while (i <= m) {
        temp_p.push_back(p[i]);
        temp_a.push_back(a[i++]);
    }

    while (j <= r) {
        temp_p.push_back(p[j]);
        temp_a.push_back(a[j++]);
    }

    for (int k = l; k <= r; k++) {
        a[k] = temp_a[k-l];
        p[k] = temp_p[k-l];
    }
}

void merge_sort(vector<int> &a, vector<int> &p, int l, int r) {
    if (l >= r) return;
    int m = (r+l)/2;
    merge_sort(a,p,l,m);
    merge_sort(a,p,m+1,r);
    merge(a,p,l,m,r);
}

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i; 
    }
    merge_sort(a, p, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}