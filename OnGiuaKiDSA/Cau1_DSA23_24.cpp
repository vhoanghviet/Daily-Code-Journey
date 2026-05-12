#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Athlete {
    string mssv;
    string ho_ten;
    int nam_sinh;
    string mon_thi_dau;
    float chieu_cao;
    int can_nang;
};
struct Node {
    Athlete data;
    Node* pNext;
};
struct List {
    Node* pHead;
};

int dem_BongDa(List &danhSach) {
    int cnt = 0;
    Node* t = danhSach.pHead;
    while(t!=NULL) {
        if(t->data.mon_thi_dau == "Bong da") cnt++;
        t = t->pNext;
    }
    return cnt;
}

void dem_C(List &danhSach) {
    Node* t = danhSach.pHead;
    while(t!= NULL) {
        if(2024 - t->data.nam_sinh > 15 && abs(t->data.chieu_cao - 1.65) < 1e-9 ) {
            cout << t->data.ho_ten << endl;
        }
        t = t->pNext;
    }
}




int main() {
    return 0;
}