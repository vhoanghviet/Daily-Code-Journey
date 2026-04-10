#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

void selection_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if(i != min_index) swap(a[i],a[min_index]);
    }
}
void insertion_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 1; i < n ; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && key < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void bubble_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;
    if(i != largest) {
        swap(a[i],a[largest]);
        heapify(a,n, largest);
    }
}
void build_max_heap(vector<int> &a, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(a,n,i);
    }
}
void heap_sort(vector<int> &a, int l, int r) {
    int n = a.size();
    build_max_heap(a,n);
    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i , 0);
        // Vun đống lại tại 0 -> Đưa root chìm xuống dưới đúng vị trí
        // với mảng kích thước i
    }
}

int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j < r; j++) { // j chỉ chạy đến r - 1 vì r là pivot luôn rồi
        if(a[j] <= pivot) { // Cho con trỏ j chạy để tìm ptu đầu tiên > pivot
            i++;
            swap(a[i], a[j]);
        }
    }
    // [<=, <=, <=, i (<=), >cần chèn pivot<, >=, >=, >=, r >pivot<];
    swap(a[i+1], a[r]); // i + 1 là vị trí cần chèn pivot vào
    return i+1;
}
void quick_sort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int p = partition(a,l,r);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
}
int hoare_partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l - 1, j = r + 1;
    while(true){
        do {
            i++;
        } while(a[i] < pivot);
        do {
            j--;
        } while(a[j] > pivot);
        if(i < j) {
            swap(a[i], a[j]);
        } else return j;
    }
}

void hoare_quick_sort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int p = hoare_partition(a,l,r);
    hoare_quick_sort(a,l,p);
    hoare_quick_sort(a,p+1,r);
}

void merge(vector<int> &a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = l ; k <= r; k++) a[k] = temp[k-l];
}
void merge_sort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
}

int get_max(vector<int> &a) {
    int m = a[0];
    for(int i = 1; i < a.size(); i++) {
        if(m < a[i]) m = a[i];
    }
    return m;
}
void counting_sort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n);
    vector<int> count(10,0);
    for(int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    for(int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    a = output;
}
void radix_sort(vector<int> &a) {
    if(a.empty()) return;
    int m = get_max(a);
    for(int exp = 1; (m / exp) > 0; exp *= 10) {
        counting_sort(a, exp);
    }
}
void printA(vector<int> &a) {
    for(int x: a) cout << x << " ";
    cout << endl << endl;
}

int main() {
    srand(time(NULL));

    cout << "Nhap so luong phan tu trong mang A ban muon sap xep = ";
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }
    cout << "Mang chua sap xep:\n\n";
    printA(a);
    radix_sort(a);
    cout << "Mang da sap xep:\n\n";
    printA(a);
    return 0;
}