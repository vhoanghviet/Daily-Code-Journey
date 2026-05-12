#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int findSecondMax(int a[], int n) {
    if(n < 2) return INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    bool found = false;
    int ans = INT_MIN;
    for(int i = n - 1; i > 0 ; i--) {
        if(a[i] != a[i-1]) {
            found = true;
        }
        if(found) {
            ans = a[i-1];
            return ans;
        }
    }
    return ans;
}


int main() {
    return 0;
}