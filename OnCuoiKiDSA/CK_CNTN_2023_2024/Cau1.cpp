#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

typedef Node* Ref;

void storeInOrder(Ref r, vector<int>& val) {
    if(r == NULL ) return ;
    storeInOrder(r->pLeft, val);
    val.push_back(r->data);
    storeInOrder(r->pRight, val);
}

bool isEquivalent(Ref r1, Ref r2) {
    if(r1 == NULL && r2 == NULL) return true;
    if( r2 == NULL || r1 == NULL) return false;
    vector<int> r1_val, r2_val;
    storeInOrder(r1,r1_val);
    storeInOrder(r2,r2_val);
    
    return r1_val == r2_val;
}

int main() {
    return 0;
}