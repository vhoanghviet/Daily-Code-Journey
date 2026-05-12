#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap(a[i], a[min_index]);
        }
    }
}

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(a[j] <= pivot) {
            ++i;
            swap(a[i],a[j]);
        }  
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(int a[], int l, int r) {
    if(l >= r) return;
    int p = partition(a,l,r);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a,n,largest);
    }
}
void buildMaxHeap(int a[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(a,n,i);
    }
}
void heap_sort(int a[], int n) {
    buildMaxHeap(a,n);
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}



int main() {
    return 0;
}