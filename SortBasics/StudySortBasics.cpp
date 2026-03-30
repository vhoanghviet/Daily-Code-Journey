#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void bubbleSort(int a[], int n) { // Sort tăng dần - Nổi bọt cuối mảng
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                int aj = a[j];
                a[j] = a[j+1];
                a[j+1] = aj;
            }
        }
    }
}
void insertionSort(int a[], int n ) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) { // Vị trí cần chèn: 0 hoặc vị trí đầu tiên <= key
            a[j+1] = a[j]; // Đẩy các phần tử ở index j về trước 1 đơn vị
            j--; // cập nhật lùi j đến khi đến vị trí cần chèn
        }
        a[j+1] = key;
    }
}


void merge(vector<int> &t, int l, int mid, int r) { 
    // Hàm này là trộn 2 mảng đã được sắp xếp tăng dần
    // Nó cũng hoạt động với 2 mảng có 1 phần tử nên dùng đệ quy là ngon
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        // Dùng 2 con trỏ để sắp xếp từ l tới r
        if(t[i] <= t[j]) temp.push_back(t[i++]);
        else temp.push_back(t[j++]);
    }
    // Xong loop này thì có 1 trong 2 mảng đã vượt chỉ số
    // Đưa nốt tất cả các phần tử của mảng còn lại vào temp ( các phần tử này cũng đã được sắp xếp)
    while(i <= mid) temp.push_back(t[i++]);
    while(j <= r) temp.push_back(t[j++]);
    for(int k = l; k <= r; k++) t[k] = temp[k-l];
}
void mergeSort(vector<int> &t, int l, int r) {
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(t, l, mid);
    mergeSort(t, mid+1, r);
    merge(t, l, mid, r);
}
void quickSort() {}
int main() {
    srand(time(NULL));
    cout << "So Phan Tu Cua Mang Ban Muon Test: ";
    int n; cin >> n;
    vector<int> a(n);
    cout << "Mang Chua Duoc Sap Xep:\n";
    for(int i = 0; i < n; i++) {
        a[i] = rand();
        cout << a[i];
        if(i != n-1) cout << " & ";
    }
    cout << endl;
    mergeSort(a,0,n-1);
    cout << "Mang Da Duoc Sap Xep:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i];
        if(i != n-1) cout << " < ";
    }

    return 0;
}


