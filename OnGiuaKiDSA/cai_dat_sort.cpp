#include <bits/stdc++.h>
using namespace std;

void swap(int&a,int&b) {
    int temp = a; a = b; b = temp;
}
void selection_sort(int a[], int n) {
    for(int i = 0; i < n  - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if(i != min_index) {    
            swap(a[i], a[min_index]);
        }
    }
}
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
void quick_sort(int a[], int l, int r) {
    if(l >= r) return;
    int p = partition(a,l,r);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
}
int median_of_three(int a[], int left, int right) {
    int mid = left + (right - left) /2;
    if(a[left] > a[mid]) swap(a[left],a[mid]);
    if(a[left] > a[right]) swap(a[left], a[right]);
    if(a[mid] > a[right]) swap(a[mid], a[right]);
    // Chỉnh thứ tự: left <= mid <= right -> Chọn pivot mid
    // Đưa chốt pivot về vị trí right - 1 để ẩn nó đi trong lúc partition
    swap(a[mid], a[right-1]);
    return a[right-1]; // giờ pivot là a[right-1]
}
void quick_sort_Median(int a[], int left, int right) {
    if(left + 1 >= right) {
        if(left < right && a[left] > a[right]) {
            swap(a[left], a[right]);
        }
    } 
    int pivot = median_of_three(a, left, right);
    int i = left;
    int j = right - 1;
    while(true) {
        while (a[++i] < pivot); // Tìm phần tử >= pivot bên trái
        while (a[--j] > pivot); // Tìm phần tử <= pivot bên phải
        
        if (i < j) {
            swap(a[i], a[j]);
        } else {
            break;
        }
    }
    // Đưa chốt về đúng vị trí của nó (vị trí i)
    swap(a[i], a[right - 1]);
    // 3. Đệ quy hai bên
    quick_sort_Median(a, left, i - 1);
    quick_sort_Median(a, i + 1, right);
}
int binary_search_recursion(int a[], int left, int right, int target) {
    if(left > right) return -1;

    int mid = left + (right - left) / 2;
    if(a[mid] == target) {
        return mid;
    } else if(a[mid] < target) {
        return binary_search_recursion(a, mid + 1, right,target);
    } else {
        return binary_search_recursion(a, left, mid - 1,target);
    }
}
void heapify(int a[],int n, int i) {
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
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(a,n,i);
    }
}
void heap_sort(int a[], int n) {
    buildMaxHeap(a,n);
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void cycle_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[arr[i]]) {
            swap(arr[i],arr[arr[i]]);
        }
    }
}
int partition(int a[], int left, int right) {
    int pivot = a[right]; // Chọn phần tử cuối làm chốt
    int i = left;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i; // Trả về vị trí thực sự của pivot sau khi phân hoạch
}
int quickSelect(int a[], int left, int right, int k) {
    // Nếu mảng chỉ còn 1 phần tử
    if (left == right) {
        return a[left];
    }

    // Phân hoạch mảng và lấy vị trí của pivot
    int pivotIndex = partition(a, left, right);

    // Nếu vị trí pivot đúng bằng k, ta đã tìm thấy
    if (k == pivotIndex) {
        return a[k];
    }
    // Nếu k nhỏ hơn, tìm bên trái
    else if (k < pivotIndex) {
        return quickSelect(a, left, pivotIndex - 1, k);
    }
    // Nếu k lớn hơn, tìm bên phải
    else {
        return quickSelect(a, pivotIndex + 1, right, k);
    }
}
// Hàm bổ trợ thực hiện Counting Sort dựa trên một chữ số cụ thể (exp)
void countingSortForLSD(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Đếm số lần xuất hiện của chữ số tại hàng exp (1, 10, 100,...)
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cộng dồn để xác định vị trí trong mảng output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Xây dựng mảng output (Duyệt ngược để đảm bảo tính ổn định)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Gán lại vào mảng gốc
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void LSDRadixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());

    // Chạy Counting Sort cho từng chữ số: 1, 10, 100,...
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortForLSD(arr, exp);
}
// Hàm lấy giá trị ASCII tại vị trí d, trả về -1 nếu chuỗi ngắn hơn d
int charAt(const string& s, int d) {
    if (d < s.length()) return (unsigned char)s[d];
    return -1;
}
void MSDRadixSort(vector<string>& a, int lo, int hi, int d, vector<string>& aux) {
    // Điều kiện dừng: Khi đoạn mảng chỉ còn 0 hoặc 1 phần tử
    if (hi <= lo) return;
    // R = 256 (bảng mã mở rộng), +2 để dự phòng cho ký tự -1 (kết thúc chuỗi)
    const int R = 256;
    vector<int> count(R + 2, 0);
    // 1. Đếm tần suất
    for (int i = lo; i <= hi; i++) {
        count[charAt(a[i], d) + 2]++;
    }
    // 2. Chuyển đổi tần suất thành chỉ số (vị trí đầu thùng)
    for (int r = 0; r < R + 1; r++) {
        count[r + 1] += count[r];
    }
    // 3. Phân phối vào mảng phụ aux
    for (int i = lo; i <= hi; i++) {
        aux[count[charAt(a[i], d) + 1]++] = a[i];
    }
    // 4. Chép ngược lại mảng gốc
    for (int i = lo; i <= hi; i++) {
        a[i] = aux[i - lo];
    }
    // 5. Đệ quy cho từng thùng (trừ thùng ký tự kết thúc -1)
    for (int r = 0; r < R; r++) {
        MSDRadixSort(a, lo + count[r], lo + count[r + 1] - 1, d + 1, aux);
    }
}
// Hàm wrapper để gọi MSD
void sortStrings(vector<string>& a) {
    int n = a.size();
    vector<string> aux(n);
    MSDRadixSort(a, 0, n - 1, 0, aux);
}
void quickSort3Way(vector<int>& a, int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo, i = lo + 1, gt = hi;
    int pivot = a[lo];
    while (i <= gt) {
        if (a[i] < pivot) {
            swap(a[lt++], a[i++]);
        } else if (a[i] > pivot) {
            swap(a[i], a[gt--]);
        } else {
            i++;
        }
    }
    // Sau vòng lặp:
    // a[lo..lt-1] < pivot
    // a[lt..gt] == pivot  <-- Vùng này đã xong!
    // a[gt+1..hi] > pivot
    quickSort3Way(a, lo, lt - 1);
    quickSort3Way(a, gt + 1, hi);
}
int main() {
    return 0;
}