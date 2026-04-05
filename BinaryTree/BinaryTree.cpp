#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// Extra essential function here
struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
    // Nên viêt hàm constructor
    Node(int X) {
        data = X;
        pLeft = pRight = NULL;
    }
};

// Node* new Node(int X) {
//     Node* newNode = new Node();
//     newNode->data = X;
//     newNode->pLeft = newNode->pRight = NULL;
// }

void inorder(Node* root) { // duyệt giữa
    if(root == NULL) return; // ->> Lệnh dừng tree đệ quy đơn giản
    inorder(root->pLeft);
    cout << root->data << " ";
    inorder(root->pRight);
}

void makeRoot(Node* root, int u, int v, char c) { 
    if(c == 'L') root->pLeft = new Node(v);
    else root->pRight = new Node(u);
}
// v là node con của u
void insertNode(Node* root, int u, int v, char c) {
    // Hàm này insert cho tất cả các node có giá trị u một node mới có giá trị v ở vị trí c của u
    // Nếu muốn hàm chỉ insert 1 lần rồi break thì sao?
    if(root == NULL) return; // ->> Lệnh dừng tree đệ quy đơn giản
    if(root->data == u) {
        makeRoot(root, u,v,c);
    }
    else {
        insertNode(root->pLeft, u,v,c);
        insertNode(root->pRight,u,v,c);
    }
}
void printTreeLevels(Node *root) {
}
int main() {
    Node *root = new Node(1);
    root->pLeft = new Node(2);
    root->pRight = new Node(3);
    Node *temp = root->pLeft;
    temp->pLeft = new Node(4);
    temp->pRight = new Node(5);
    Node *rtemp = root->pRight;
    rtemp->pLeft = new Node(7);
    rtemp->pRight = new Node(6);
    cout << "LEVEL 1: " << root->data << endl;
    cout << "LEVEL 2: " << root->pLeft->data << " " << root->pRight->data << endl;
    cout << "LEVEL 3: " << temp->pLeft->data << " " << temp->pRight->data << " " << rtemp->pLeft->data << " " << rtemp->pRight->data << endl;
    return 0;
}