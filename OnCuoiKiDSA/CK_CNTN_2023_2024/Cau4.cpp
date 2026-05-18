#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

typedef Node* Ref;

int findX(Ref r, int k) {
    int best_x = r->data;
    Ref cur = r;
    while(cur != NULL) {
        if(abs(k - cur->data) < abs(k - best_x)) {
            best_x = cur->data;
        }
        if(k == cur->data) {
            return best_x;
        } else if(k < cur->data) {
            cur = cur->pLeft;
        } else {
            cur = cur->pRight;
        }
    }
    return best_x;
}