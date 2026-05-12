#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

void insertion_sort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void selection_sort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i+1; j < n; j++) {
            if(a[min_index] > a[j])
                min_index = j;
        }
        if(min_index != i) {
            swap(a[i], a[min_index]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}