// SinhHoanVi.cpp



#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n, a[100], final = 0;

void ktao() {
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    a[n+1] = -1;
}
void sinh() {
    int i = n-1;
    while(i >= 1 && a[i] >= a[i+1]) {
        i--;
    }
    if(i == 0) {
        final = 1;
    } else {
        int j = n;
        while(a[j] <= a[i]) j--;
        swap(a[j],a[i]);
        reverse(a+i+1,a+n+1);
    }
}

int main() {
    cout << "N = ";
    cin >> n;
    ktao();
    while(final == 0) {
        for(int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}