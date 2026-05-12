#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

void insertion_sort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}
// Dùng khi mảng có kích thước nhỏ hoặc mảng gần như đã sắp xếp.

void selection_sort(vector<int>& a) {
    for (int i = 0; i < (int)a.size() - 1; i++) {
        int m = i;
        for (int j = i + 1; j < a.size(); j++) if (a[j] < a[m]) m = j;
        swap(a[i], a[m]);
    }
}
// Dùng khi muốn tối thiểu hóa số lần ghi vào bộ nhớ (số lần swap ít).

void bubble_sort(vector<int>& a) {
    for (int i = 0; i < (int)a.size() - 1; i++)
        for (int j = 0; j < (int)a.size() - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}
// Dùng khi mục đích chính là giáo dục hoặc kiểm tra mảng đã sắp xếp chưa.

int partition_lomuto(vector<int>& a, int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++) if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}
// Dùng khi cần cài đặt phân đoạn Quick Sort một cách đơn giản, dễ hiểu.

int partition_hoare(vector<int>& a, int l, int r) {
    int p = a[l], i = l - 1, j = r + 1;
    while (true) {
        do { i++; } while (a[i] < p);
        do { j--; } while (a[j] > p);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}
// Dùng khi cần hiệu suất phân đoạn tốt hơn và ít số lần swap hơn Lomuto.

void quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = partition_lomuto(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}
// Dùng khi cần thuật toán sắp xếp nhanh trên trung bình và bộ nhớ phụ ít.

void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int r_idx = l + rand() % (r - l + 1);
        swap(a[r_idx], a[r]);
        int p = partition_lomuto(a, l, r);
        randomized_quick_sort(a, l, p - 1);
        randomized_quick_sort(a, p + 1, r);
    }
}
// Dùng khi muốn tránh trường hợp xấu nhất O(n^2) khi mảng đầu vào có tính chất đặc biệt.

void median_of_three_quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < a[l]) swap(a[mid], a[l]);
        if (a[r] < a[l]) swap(a[r], a[l]);
        if (a[r] < a[mid]) swap(a[r], a[mid]);
        swap(a[mid], a[r]);
        int p = partition_lomuto(a, l, r);
        median_of_three_quick_sort(a, l, p - 1);
        median_of_three_quick_sort(a, p + 1, r);
    }
}
// Dùng khi muốn chọn pivot tốt hơn để tối ưu hóa hiệu suất Quick Sort.

void heapify(vector<int>& a, int n, int i) {
    int g = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[g]) g = l;
    if (r < n && a[r] > a[g]) g = r;
    if (g != i) { swap(a[i], a[g]); heapify(a, n, g); }
}
void heap_sort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) { swap(a[0], a[i]); heapify(a, i, 0); }
}
// Dùng khi cần đảm bảo thời gian O(n log n) trong mọi trường hợp và bộ nhớ O(1).

void thap_ha_noi(int n, char a, char b, char c, int disk_num) {
    if (n == 1) cout << "Move disk " << disk_num << " from " << a << " to " << c << endl;
    else {
        thap_ha_noi(n - 1, a, c, b, n - 1);
        thap_ha_noi(1, a, b, c, n);
        thap_ha_noi(n - 1, b, a, c, n - 1);
    }
}
// Dùng khi giải bài toán chuyển đĩa kinh điển bằng phương pháp đệ quy.

void cycle_sort(vector<int>& a) {
    for (int cs = 0; cs < (int)a.size() - 1; cs++) {
        int item = a[cs], pos = cs;
        for (int i = cs + 1; i < a.size(); i++) if (a[i] < item) pos++;
        if (pos == cs) continue;
        while (item == a[pos]) pos++;
        swap(item, a[pos]);
        while (pos != cs) {
            pos = cs;
            for (int i = cs + 1; i < a.size(); i++) if (a[i] < item) pos++;
            while (item == a[pos]) pos++;
            swap(item, a[pos]);
        }
    }
}
// Dùng khi muốn tối thiểu hóa số lần ghi vào mảng (tối ưu nhất về số lần ghi).

int quick_select(vector<int>& a, int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int p = partition_lomuto(a, l, r);
        if (p - l == k - 1) return a[p];
        if (p - l > k - 1) return quick_select(a, l, p - 1, k);
        return quick_select(a, p + 1, r, k - (p - l + 1));
    }
    return -1;
}
// Dùng khi cần tìm phần tử nhỏ thứ k trong mảng mà không cần sắp xếp toàn bộ.

void counting_sort(vector<int>& a) {
    if (a.empty()) return;
    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    int range = max_val - min_val + 1;
    vector<int> count(range), out(a.size());
    for (int x : a) count[x - min_val]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = a.size() - 1; i >= 0; i--) { out[count[a[i] - min_val] - 1] = a[i]; count[a[i] - min_val]--; }
    a = out;
}
// Dùng khi mảng có phạm vi giá trị (range) nhỏ so với số lượng phần tử.

void bucket_sort(vector<float>& a) {
    int n = a.size();
    vector<float> b[n];
    for (int i = 0; i < n; i++) b[(int)(n * a[i])].push_back(a[i]);
    for (int i = 0; i < n; i++) sort(b[i].begin(), b[i].end());
    int idx = 0;
    for (int i = 0; i < n; i++) for (float x : b[i]) a[idx++] = x;
}
// Dùng khi dữ liệu đầu vào được phân bố đều trong một khoảng.

void lsd_radix_sort(vector<int>& a) {
    int m = *max_element(a.begin(), a.end());
    for (int exp = 1; m / exp > 0; exp *= 10) {
        vector<int> out(a.size()), count(10, 0);
        for (int x : a) count[(x / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = a.size() - 1; i >= 0; i--) { out[count[(a[i] / exp) % 10] - 1] = a[i]; count[(a[i] / exp) % 10]--; }
        a = out;
    }
}
// Dùng khi cần sắp xếp các số nguyên dựa trên các chữ số từ hàng thấp đến hàng cao.

void msd_radix_sort_recursive(vector<int>& a, int l, int r, int exp) {
    if (l >= r || exp <= 0) return;
    vector<int> count(12, 0), temp(r - l + 1);
    for (int i = l; i <= r; i++) count[(a[i] / exp) % 10 + 1]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = l; i <= r; i++) temp[count[(a[i] / exp) % 10]++] = a[i];
    for (int i = l; i <= r; i++) a[i] = temp[i - l];
    for (int i = 0; i < 10; i++) {
        int start = (i == 0) ? 0 : count[i - 1];
        int end = count[i] - 1;
        msd_radix_sort_recursive(a, l + start, l + end, exp / 10);
    }
}

// Dùng khi sắp xếp các chuỗi hoặc số nguyên theo thứ tự từ điển từ chữ số cao nhất.

int char_at(string s, int d) {
    if (d < s.length()) return (int)s[d];
    return -1;
}
void msd_radix_sort_string(vector<string>& a, int l, int r, int d) {
    if (l >= r) return;
    const int R = 256; 
    vector<string> aux(r - l + 1);
    vector<int> count(R + 2, 0);
    for (int i = l; i <= r; i++) {
        count[char_at(a[i], d) + 2]++;
    }
    for (int i = 0; i < R + 1; i++) {
        count[i + 1] += count[i];
    }
    for (int i = l; i <= r; i++) {
        aux[count[char_at(a[i], d) + 1]++] = a[i];
    }
    for (int i = l; i <= r; i++) {
        a[i] = aux[i - l];
    }
    for (int i = 0; i < R; i++) {
        msd_radix_sort_string(a, l + count[i], l + count[i + 1] - 1, d + 1);
    }
}
// Dùng khi cần sắp xếp danh sách chuỗi văn bản theo thứ tự từ điển (alphabetical order).
using  Matran = vector<vector<int>>;
Matran matrix_multiply(const Matran& A, const Matran& B) {
    int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
    Matran C(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++)
        for (int k = 0; k < c1; k++)
            for (int j = 0; j < c2; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
// Dùng khi cần tính tích của hai ma trận trong các bài toán đại số tuyến tính.

int binary_search_recursion(const vector<int>& a, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) return binary_search_recursion(a, l, mid - 1, x);
        return binary_search_recursion(a, mid + 1, r, x);
    }
    return -1;
}
// Dùng khi cần tìm kiếm một phần tử trong mảng đã sắp xếp bằng đệ quy.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

void create_initial_runs(string input_file, int run_size, int &num_runs) {
    ifstream in(input_file);
    bool has_more = true;
    num_runs = 0;
    while (has_more) {
        vector<int> buffer;
        int val;
        for (int i = 0; i < run_size; i++) {
            if (in >> val) buffer.push_back(val);
            else { has_more = false; break; }
        }
        if (buffer.empty()) break;
        sort(buffer.begin(), buffer.end());
        ofstream out("run_" + to_string(num_runs++) + ".txt");
        for (int x : buffer) out << x << " ";
        out.close();
    }
    in.close();
}

struct Node {
    int val;
    int run_idx;
    bool operator>(const Node& other) const { return val > other.val; }
};

void merge_runs(string output_file, int num_runs) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<ifstream*> runs(num_runs);
    for (int i = 0; i < num_runs; i++) {
        runs[i] = new ifstream("run_" + to_string(i) + ".txt");
        int val;
        if (*runs[i] >> val) pq.push({val, i});
    }
    ofstream out(output_file);
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        out << curr.val << " ";
        int next_val;
        if (*runs[curr.run_idx] >> next_val) pq.push({next_val, curr.run_idx});
    }
    for (int i = 0; i < num_runs; i++) {
        runs[i]->close();
        delete runs[i];
    }
    out.close();
}

void external_merge_sort(string input_file, string output_file, int run_size) {
    int num_runs = 0;
    create_initial_runs(input_file, run_size, num_runs);
    merge_runs(output_file, num_runs);
}
// Dùng khi dữ liệu quá lớn không thể nạp toàn bộ vào bộ nhớ RAM.


int main() {
    return 0;
}