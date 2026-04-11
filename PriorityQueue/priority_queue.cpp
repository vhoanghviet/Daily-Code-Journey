#include <bits/stdc++.h>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}
// Đây là hàm vun đống từ dưới lên, Mục đích : dùng khi push
// Chú ý: thuật toán vun đống hiện tại là đưa phần tử giá trị lớn nhất lên đầu.
void heapify_up(vector<int> &heap, int index) {
    if(index == 0) return; // đã lên tới gốc
    int parent = (index - 1)/2; // index tại node cha trong heap
    if(heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapify_up(heap, parent); 
        // Đệ quy để vun đống lên top tới khi nào node parent là node root
    }

}
// Vun đống từ trên xuống ( dùng khi pop ) để giữ thứ tự max Heap cho Priority queue
void heapify_down(vector<int> &heap, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < heap.size() && heap[left] > heap[largest]) largest = left;
    if(right < heap.size() && heap[right] > heap[largest]) largest = right;
    if(largest != index) {
        swap(heap[largest], heap[index]);
        heapify_down(heap, largest);
    }
}

// Thêm 1 phần tử vào hàng đợi
void push(vector<int> &heap, int value) {
    heap.push_back(value); // giờ cuối danh sách là phần tử giá trị value
    heapify_up(heap, heap.size() - 1);
    // Trong mảng heap bây giờ phần tử giá trị value đang ở
    // index là "heap.size() - 1"
}
// Xóa phần tử ưu tiên : cao nhất hàng đợi
void pop(vector<int> &heap) {
    if(heap.empty()) return;
    // Đưa phần tử cuối cùng lên đầu HÀNG ĐỢI để thay thế
    heap[0] = heap.back();
    heap.pop_back();
    if(!heap.empty()) {
        heapify_down(heap, 0);
    }
}
int top(const vector<int> &heap) {
    return heap[0];
}


int main() {
    
    return 0;
}