#include <iostream>
#include <vector>
using namespace std;

void in_ra_ket_qua(int i, int j) {
    if (i <= j) cout << i << " " << j << "\n";
    else cout << j << " " << i << "\n";
}
int partition(vector<int>& a, int l, int r) {
    int mid = (l + r) / 2;
    int pivot = a[mid];
    int i = l, j = r;
    while (true) {
        while (true) {
            in_ra_ket_qua(i, mid);
            if (a[i] >= pivot) break;
            i++;
        }
        while (true) {
            in_ra_ket_qua(mid, j);
            if (a[j] <= pivot) break;
            j--;
        }
        if (i >= j) return j;
        swap(a[i], a[j]);
        if (i == mid) mid = j;
        else if (j == mid) mid = i;
        i++;
        j--;
    }
}

void quicksort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    quicksort(a, 0, n - 1);
    return 0;
}