#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

typedef Node* Ref;


void storeInOrder(Ref root, vector<int>& nodes) {
    if(root == NULL) return;
    storeInOrder(root->pLeft, nodes);
    nodes.push_back(root->data);
    storeInOrder(root->pRight,nodes);
}
void copyInOrder(Ref root, vector<int>& nodes, int &index) {
    if(root == NULL) return;
    copyInOrder(root->pLeft, nodes,index);
    root->data = nodes[index++];
    copyInOrder(root->pRight, nodes, index);
}

void insertion_sort(vector<int> & nodes) {
    int n = nodes.size();
    for(int i = 1; i < n; i++) {
        int key = nodes[i];
        int j = i-1;
        while(j >= 0 && nodes[j] > key) {
            nodes[j+1] = nodes[j];
            j--;
        }
        nodes[j+1] = key;
    }
}

void convertTree(Ref root) {
    vector<int> nodes;
    storeInOrder(root, nodes);
    insertion_sort(nodes);
    int index = 0;
    copyInOrder(root, nodes, index);
}