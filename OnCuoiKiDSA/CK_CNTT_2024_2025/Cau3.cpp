#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Ref;

void storeInOrder(Ref root, vector<int> & nodes) {
    if(root == NULL) return;
    storeInOrder(root->pLeft, nodes);
    nodes.push_back(root->data);
    storeInOrder(root->pRight, nodes);
}

void copyInOrder(Ref root,vector<int> & nodes, int& index ){
    if(root == NULL) return;
    copyInOrder(root->pLeft, nodes, index);
    root->data = nodes[index++];
    copyInOrder(root->pRight, nodes, index);
}

void convertTree(Ref root) {
    if(root == NULL) return;
    vector<int> nodes;
    storeInOrder(root, nodes); // Mảng nodes giờ giữ những giá trị của cây *theo Duyệt Giữa

    sort(nodes.begin(), nodes.end());
    int index = 0;
    copyInOrder(root, nodes, index);
}

int main() {
    return 0;
}