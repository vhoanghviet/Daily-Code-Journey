#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm "vun đống": Biến một cây con có gốc tại i thành Max Heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;    // Khởi tạo node lớn nhất là gốc
    int left = 2 * i + 1;  // Chỉ số con trái: 2*i + 1
    int right = 2 * i + 2; // Chỉ số con phải: 2*i + 2

    // Nếu con trái tồn tại và lớn hơn phần tử lớn nhất hiện tại
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải tồn tại và lớn hơn phần tử lớn nhất hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu node lớn nhất không phải là gốc ban đầu
    if (largest != i) {
        swap(arr[i], arr[largest]); // Đổi chỗ để đưa số lớn lên trên

        // Đệ quy vun đống lại cho cây con bị ảnh hưởng bởi sự thay đổi
        heapify(arr, n, largest);
    }
}

// Hàm thực hiện thuật toán Heapsort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Bước 1: Xây dựng Max Heap ban đầu (Build Heap)
    // Duyệt từ node nội bộ cuối cùng (n/2 - 1) ngược lên gốc
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Bước 2: Trích xuất từng phần tử từ Heap
    for (int i = n - 1; i > 0; i--) {
        // Đổi chỗ gốc (số lớn nhất) với phần tử cuối cùng của mảng hiện tại
        swap(arr[0], arr[i]);

        // Gọi heapify lên phần mảng chưa sắp xếp (độ dài i) để duy trì cấu trúc Heap
        heapify(arr, i, 0);
    }
}


// Tự viết

void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;

    if(largest != i) {
        swap(a[largest], a[i]);
        heapify(a,n,largest);
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();
    for(int i = (n-1)/2 ; i >= 0; i--) {
        heapify(a,n,i);
    }
    for(int i = n-1; i > 0; i--) {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}


// Quick sort

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Mang ban dau: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "Mang sau khi sap xep: ";
    for (int x : arr) cout << x << " ";
    
    return 0;
}