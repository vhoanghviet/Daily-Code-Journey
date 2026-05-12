#include <iostream>
#include <cmath>
using namespace std;

int mySqrt(int n) {
    if(n < 0) return -1;
    int res = 0;
    for(int i = 0; i*i <= n; i++) {
        res = i;
    }
    return res;
}

int leap(int k) {
    return k * (int)sqrt(k) + (k + 1) / 2;
}

// (k+1)/2 = ceil((float)k/2)
// ceil(k/n) = (k + n - 1) / n

int findLastIndex(int a[], int X, int L, int R) {
    int res = L;
    while(L <= R) {
        int mid = L + (R - L) / 2;
        if(a[mid] == X) {
            res = mid;
            L = mid + 1;
        } else if(a[mid] < X) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return res;
}

int numOfDistintInts(int a[], int L, int R) {
    if(L > R) return 0;
    int count = 0;
    int i = L;
    while(i <= R) {
        count++;
        int last = findLastIndex(a,a[i],i,R);
        i = last + 1;
    }
    return count;
}

// int numOfDistinctInts(int a[], int L, int R) {
//     int prev = -1;
//     int count = 0;
//     int i = L;
//     while(i <= R) {
//         int k = a[i];
//         if(k != prev) {
//             count++;
//             prev = k;
//         }
//         i += k * (int)sqrt(k) + (k+1)/2;
//         if(i >= R) {
//             if(k != a[R]) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int main() {
    return 0;
}