#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 3.1

int maxPeople(int A[], int d, int n) { // xem như mảng A đã sort, có size n.
    int cnt = 0;
    int cur_sum = 0;
    for(int i = 0; i < n; i++) {
        if(cur_sum + A[i] > d) {
            return cnt;
        }
        cnt++;
        cur_sum += A[i];
    }
    return cnt;
}

// 3.2

const int maxCol = 100;



int findX(int A[][maxCol], int n, int m, int x, int &r, int &c) {
    int l1 = 0, r1 = n - 1;
    while(l1 <= r1) {
        int mid = l1 + (r1 - l1) / 2;
        if(A[mid][m-1] == x) {
            r = mid; c = m - 1; return 1;
        }
        if(A[mid][0] == x) {
            r = mid, c = 0; return 1;
        }
        if(A[mid][m-1] > x && A[mid][0] < x) {
            r = mid;
            break;
        } else if (A[mid][m-1] > x) {
            r1 = mid - 1;
        } else {
            l1 = mid + 1;
        }
    }
    int l2 = 0, r2 = m - 1;
    while(l2 <= r2) {
        int mid = l2 + (r2 - l2) / 2;
        if(A[r][mid] == x) {
            c = mid;
            return 1;
        } else if(A[r][mid] < x) {
            l2 = mid + 1;
        } else {
            r2 = mid - 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}