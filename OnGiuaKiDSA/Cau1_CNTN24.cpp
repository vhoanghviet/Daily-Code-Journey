#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

void insertionSort(int a[N], int left, int right) {
    for(int i = left + 1; i <= right; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= left && a[j] >= key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void merge(int a[N], int left, int mid, int right) {
    int temp[N];
    int i = left, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= right) temp[k++] = a[j++];
    // Mảng p hiện tại (đã sort) : 0-> k-1
    // Sao chép vào mảng a : left -> right
    // a[left + p] = temp[p]
    for(int p = 0; p < k ; p++) {
        a[left+p] = temp[p];
    }
}

void enhanceMergeSort(int a[N], int left, int right) {
    if(left >= right) return;
    if(right - left + 1 <= 10) {
        insertionSort(a,left,right);
        return;
    }
    int mid = left + (right - left) / 2;
    enhanceMergeSort(a,left,mid);
    enhanceMergeSort(a,mid+1,right);
    merge(a,left,mid,right);
}

int main() {
    return 0;
}