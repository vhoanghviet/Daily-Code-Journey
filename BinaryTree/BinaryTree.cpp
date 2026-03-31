#include <bits/stdc++.h>

// Buổi 22: 1:13:47 //

using namespace std;
struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};
Node* createNode(int X) {
    Node *newNode = new Node;
    newNode->data = X;
    newNode->pLeft = newNode->pRight = NULL; //Important
    return newNode;
}
void printTreeLevels(Node *root) {
}
int main() {
    Node *root = createNode(1);
    root->pLeft = createNode(2);
    root->pRight = createNode(3);
    Node *temp = root->pLeft;
    temp->pLeft = createNode(4);
    temp->pRight = createNode(5);
    Node *rtemp = root->pRight;
    rtemp->pLeft = createNode(7);
    rtemp->pRight = createNode(6);
    cout << "LEVEL 1: " << root->data << endl;
    cout << "LEVEL 2: " << root->pLeft->data << " " << root->pRight->data << endl;
    cout << "LEVEL 3: " << temp->pLeft->data << " " << temp->pRight->data << " " << rtemp->pLeft->data << " " << rtemp->pRight->data << endl;
    return 0;
}