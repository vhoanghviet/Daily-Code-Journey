#include <iostream>
#include <vector>
using namespace std;

void printA(vector<int> &a) {
    for(int x : a) cout << x << " ";
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

void insertion_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && key < a[j]) // dịch j và copy
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubble_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}
// Thuật toán Build Max Heap.
void buildMaxHeap(vector<int> &a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void heap_sort(vector<int> &a, int n)
{
    buildMaxHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
// Trả về chốt phân hoạch ( pivot )
int partition(vector<int> &a, int l, int r) {
    // Bước 1, khai báo chốt (pivot), khởi tạo i về trái của left 1 đơn vị
    int pivot = a[r]; // phần tử cuối cùng
    int i = l - 1;
    // Bước 2: Lặp để chia thành hai mảng trái phải hoàn toàn (Chưa xử lí pivot)
    for(int j = l; j < r; j++) { // không xét khi j = r
        if(a[j] <= pivot) { 
            i++; 
            swap(a[i], a[j]);
        }
    }
    // Bước 3: Đưa chốt (a[r] = pivot ) về giữa và trả về chỉ số i (i lúc này trỏ vào pivot sẽ swap)
    i++;
    swap(a[i], a[r]);
    return i;
}



void quick_sort(vector<int> &a, int l, int r) {
    if(l >= r) return; // Lời gọi đệ quy dừng khi l >= r
    int p = partition(a,l,r);
    quick_sort(a,l, p-1);
    quick_sort(a,p+1,r);
}

int hoare_partition(vector<int> &a, int l, int r) {
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(true) {
        do {
            ++i;
        } while(a[i] < pivot); // tìm i đầu tiên : a[i] >= pivot -> đưa nó về phải
        do {
            --j;
        } while(a[j] > pivot); // tìm j đầu tiên : a[j] <= pivot -> đưa nó về trái
        if(i < j) {
            swap(a[i],a[j]);
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
    while ( i <= m && j <= r) {
        if(a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while( i <= m ) temp.push_back(a[i++]);
    while ( j <= r ) temp.push_back(a[j++]);
    for(int k = l; k <= r; k++) a[k] = temp[k-l];
}
void merge_sort(vector<int> &a, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
}

int getMax(vector<int> &a) {
    if(a.empty()) return -1;
    int m = a[0];
    for(int i = 1; i < a.size(); i++) {
        if( m < a[i] )  m = a[i];
    }
    return m;
}
// Phải thuộc counting_sort để dùng nó sort từng chữ số
void counting_sort(vector<int> &a, int exp) {
    if(a.empty()) return;
    int n = a.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    
    // Bước 1 : Đếm số lần xuất hiện của các chữ số tại hàng thập phân 'exp' đang xét
    for(int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    // Bước 2 : cộng dồn mảng đếm để sau này duyệt ngược ổn định
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // Bước 3 : Đổ dữ liệu vào output
    // Duyệt ngược ổn định :
    for(int i = n - 1; i >= 0 ; i--) {

        int digit = (a[i] / exp ) % 10;
        output[count[digit] - 1] = a[i];

        count[digit]--;
    }
    a = output;
}
void radix_sort(vector<int> &a) {
    if(a.empty()) return;
    // Bước 1 : Tìm GTLN trong a để biết số lượng chữ số tối đa cho vòng lặp
    int max_val = getMax(a);
    // Bước 2 : Thực hiện counting sort cho từng chữ số của mỗi phần tử
    for(int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort(a, exp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    radix_sort(a);
    cin.tie(NULL);
    return 0;
}