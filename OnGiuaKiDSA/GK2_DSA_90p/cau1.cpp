#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int weight;
    Node* pNext;
};
struct List {
    Node *pHead;
};

void mergeList(List &l1, List l2) {
    Node dummy;
    dummy.pNext = l1.pHead;
    Node* prev = &dummy;

    Node* p1 = l1.pHead;
    Node* p2 = l2.pHead;

    while(p1 != NULL && p2 != NULL) {
        if(p1->value == p2->value) {
            p1->weight += p2->weight;
            p2 = p2->pNext;
            prev = p1;
            p1 = p1->pNext;
        } else if(p1->value < p2->value) { 
            prev = p1;
            p1 = p1->pNext;
        } else { 
            // p2 nhỏ hơn p1
            prev->pNext = p2;
            Node* temp = p2->pNext; // Giữ list 2
            p2->pNext = p1;
            // Hoàn tất nối chuỗi
            prev = prev->pNext;
            p2 = temp;
            // Cập nhật prev và p2
            // không tiến p1 vì p1 cần so sánh với p2 mới
        }
    }
    if(p2 != NULL) prev->pNext = p2;
    l1.pHead = dummy.pNext;
}

int main() {
    return 0;
}