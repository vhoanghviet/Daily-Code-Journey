#include <bits/stdc++.h>
using namespace std;


int partition(double a[], int left, int right) {
    double pivot = a[right];
    int i = left;
    for(int j = left; j < right; j++) {
        if(a[j] <= pivot) {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[right]);
    return i;    
}

double quickSelect(double a[], int left, int right, int k){
    if(left > right) return -1;
    int p = partition(a,left,right);
    if(p == k-1) {
        return a[p];
    } else if(p > k - 1) {
        return quickSelect(a,left,p-1,k);
    } else {
        return quickSelect(a,p+1,right,k);
    }
}

double kthElement(double a[], int n, int k) {
    return quickSelect(a,0,n-1,k);
}







int main() {
    return 0;
}