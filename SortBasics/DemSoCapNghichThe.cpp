#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void merge(vector<int> &t, int l, int mid, int r, int &soCapNghichThe) { 
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(t[i] <= t[j]) {
            temp.push_back(t[i++]);
        } else {
            // Cách 2: 
            soCapNghichThe += mid+1 - i;
            temp.push_back(t[j++]);
            // Cách 1: lặp để đếm cặp nghịch thế
            // int k = mid + 1;
            // while(k <= r && t[k] < t[i]) {
            //     soCapNghichThe += 1;
            //     k++;
            // }

            
        }
    }
    while(i <= mid) temp.push_back(t[i++]);
    while(j <= r) temp.push_back(t[j++]);
    for(int k = l; k <= r; k++) t[k] = temp[k-l];
}
void mergeSort(vector<int> &t, int l, int r, int &soCapNghichThe) {
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(t, l, mid, soCapNghichThe);
    mergeSort(t, mid+1, r, soCapNghichThe);
    merge(t, l, mid, r, soCapNghichThe);
}

int main() {
    srand(time(NULL));
    cout << "So Phan Tu Ban Muon Test:\n";
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++) a[i] = rand();
    cout << "Mang Ban Dau:\n";
    // int n = a.size();
    for(int i = 0; i < n;i++) {
        cout << a[i];
        if(i != n-1) cout << " & ";
    }
    int soCapNghichThe = 0;
    mergeSort(a,0,n-1,soCapNghichThe);
    cout << "\nSo Cap Nghich The: " << soCapNghichThe << endl;
    cout << "Mang Da Sap Xep:\n";
    for(int i = 0; i < n;i++) {
        cout << a[i];
        if(i != n-1) cout << " < ";
    }
}