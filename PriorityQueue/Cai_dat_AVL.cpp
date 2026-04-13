#include <iostream>
#include <algorithm>
using namespace std;

// Cấu trúc của một node trong cây
struct Node {
    int key;
    Node *left, *right;
    int height;
};

// Hàm lấy chiều cao của node (nút)
int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

// Hàm tính hệ số cân bằng ( Đệ quy getHeight trái trừ đệ quy getHeight phải)
int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Tạo nút mới
Node* createNode(int x) {
    Node* node = new Node();
    node->key = x;
    node->left = node->right = NULL;
    node->height = 1; // Nút mới thêm vào là nút lá nên độ cao nút lá là 1
    return node;
}

// Phép xoay phải (Right Rotate)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thực hiện xoay
    x->right = y;
    y->left = T2;

    // Cập nhật lại chiều cao
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Node Gốc mới
}

// Phep xoay trai (Left Rotate)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Thuc hien xoay
    y->left = x;
    x->right = T2;

    // Cap nhat lai chieu cao
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Goc moi
}

// Ham them nut vao cay AVL
Node* insert(Node* node, int x) {
    // 1. Thuc hien chen nhu cay BST thong thuong
    if (node == NULL) return createNode(x);

    if (x < node->key)
        node->left = insert(node->left, x);
    else if (x > node->key)
        node->right = insert(node->right, x);
    else return node; // Khong cho phep trung key

    // 2. Cap nhat chieu cao cua nut to tien nay
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Kiem tra su can bang
    int balance = getBalance(node);

    // Truong hop Left Left
    if (balance > 1 && x < node->left->key)
        return rotateRight(node);

    // Truong hop Right Right
    if (balance < -1 && x > node->right->key)
        return rotateLeft(node);

    // Truong hop Left Right
    if (balance > 1 && x > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Truong hop Right Left
    if (balance < -1 && x < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Tim nut co gia tri nho nhat (phuc vu xoa nut)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

// Duyet cay theo thu tu InOrder
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->key << " ";
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int data[] = {10, 20, 30, 40, 50, 25};
    
    for(int x : data) {
        root = insert(root, x);
    }

    cout << "Duyet cay AVL (InOrder): ";
    printInOrder(root);
    return 0;
}