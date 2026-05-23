#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

// Hàm duyệt Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void makeRoot(Node* root, int u, int v, char c) { 
    if (c == 'L') root->left = new Node(v);
    else root->right = new Node(v); // Sửa từ u thành v ở đây
}

// Hàm đệ quy tìm node cha u để chèn node con v
void insertNode(Node* root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->val == u) {
        makeRoot(root, u, v, c);
    }
    else {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

int main() {
    int n; 
    cin >> n;
    Node* root = NULL;
    while(n--) {
        int u, v; char c;
        cin >> u >> v >> c;
        // Nếu chưa có root thì u đầu tiên chính là root
        if(root == NULL) {
            root = new Node(u);
        }
        // Chèn v vào làm con của u
        insertNode(root, u, v, c);
    }
    // Duyệt và in kết quả


    
    inorder(root);
    
    return 0;
}