#include <bits/stdc++.h>
using namespace std;

/* Hàm phân hoạch (Partition): 
   Chọn pivot là phần tử cuối, đưa các phần tử nhỏ hơn pivot sang trái, 
   và các phần tử lớn hơn pivot sang phải.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn pivot
    int i = (low - 1);    // Chỉ mục của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/*
   Hàm Quick Sort chính
   low: Chỉ số bắt đầu, high: Chỉ số kết thúc
*/
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi là chỉ số nơi pivot đứng sau khi phân hoạch
        int pi = partition(arr, low, high);

        // Gọi đệ quy sắp xếp hai phần tử trước và sau partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}