#include <iostream> 
#include <vector>
using namespace std;

void merge(vector<int> &a, vector<int> &b, int l, int m, int r) {
    vector<int> temp, temp_b;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            temp_b.push_back(b[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            temp_b.push_back(b[j]);
            j++;
        }
    }
    while(i <= m) {
        temp.push_back(a[i]);
        temp_b.push_back(b[i]);
        i++;
    }
    while(j <= r) {
        temp.push_back(a[j]);
        temp_b.push_back(b[j]);
        j++;
    }
    for(int k = l; k <= r; k++) {
        a[k] = temp[k-l];
        b[k] = temp_b[k-l];
    }
}
void mergeSort(vector<int> &a, vector<int> &b, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(a,b,l,m);
    mergeSort(a,b,m+1,r);
    merge(a,b,l,m,r);
}
void printA(vector<int> &a) {
    for(auto x : a) cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    // cout << "Mang a: " << endl; printA(a);
    // cout << "Mang b: " << endl; printA(b);
    mergeSort(a,b,0,n-1);
    int good_pairs = 0;
    // cout << "Mang a: " << endl; printA(a);
    // cout << "Mang b: " << endl; printA(b);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] > b[i] + b[j]) {
                good_pairs++;
            }
        }
    }
    cout << good_pairs;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}