#include <bits/stdc++.h>

using namespace std;
int ketQua1(int a[],int n, int X) { 
    int res = -1, l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r) / 2;
        if(a[mid] == X) {
            res = mid;
            r = mid - 1;
        } else if(a[mid] > X) { 
            r = mid - 1;
        } else { 
            l = mid + 1;
        }
    }
    return res;
}
int ketQua2(int a[],int n, int X) { 
    int res = -1, l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] == X) {
            res = mid;
            l = mid + 1;
        } else if( a[mid] > X) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int ketQua3(int a[], int n, int X) {
    int res = -1, l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] >= X) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int ketQua4(int a[], int n, int X) {
    int res = -1, l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(a[mid] > X) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int ketQua5(int a[], int n, int X) {
    if(ketQua1(a,n,X) == -1) return 0;
    return ketQua2(a,n,X) - ketQua1(a,n,X) + 1;
}

int main() {
    int N, X;
    cin >> N >> X;
    int a[N+1];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << ketQua1(a,N,X) << endl;
    cout << ketQua2(a,N,X) << endl;
    cout << ketQua3(a,N,X) << endl;
    cout << ketQua4(a,N,X) << endl;
    cout << ketQua5(a,N,X) << endl;

    return 0;
}