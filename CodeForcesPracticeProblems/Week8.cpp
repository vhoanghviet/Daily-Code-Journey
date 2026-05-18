#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};
void swap(int& a,int &b) {
    int t = a; a = b ; b = t;
}
Node* newNode(int data) {
    Node* new_node = new Node();
    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int data) {
    if (!root) return newNode(data);
    
    if (data < root->key) {
        root->left = insert(root->left, data);
    } else if (data > root->key) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data) {
    if (!root || root->key == data) return root;
    if (data < root->key) return search(root->left, data);
    return search(root->right, data);
}

Node* mostLeft(Node* root_right) {
    if(!root_right->left) return root_right;
    return mostLeft(root_right->left);
}
Node* remove(Node* root, int data) {
    if (!root) return NULL;

    if (data < root->key) {
        root->left = remove(root->left, data);
    } else if (data > root->key) {
        root->right = remove(root->right, data);
    } else {
        if (!root->left && !root->right) { 
            delete root;
            return NULL;
        } 
        else if (!root->left) { 
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) { 
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else { 
            Node* alter = mostLeft(root->right);
            root->key = alter->key; 
            root->right = remove(root->right, alter->key); 
        }
    }
    return root;
}
void NLR(Node* root) {
    if(!root) return;
    cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
}
void LNR(Node* root) {
    if(!root) return;
    LNR(root->left);
    cout << root->key << " ";
    LNR(root->right);
}
void LRN(Node* root) {
    if(!root) return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << " ";
}

void levelOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty() ) {
        Node* x = q.front(); q.pop();
        cout << x->key << " ";
        if(x->left) q.push(x->left);
        if(x->right) q.push(x->right);
    }
}

int main() {
    int command;
    string task;
    Node* root = NULL;
    while(cin >> command >> task) {
        if (command == 1) {
            int val = stoi(task);
            root = insert(root, val);
        }
        if (command == 2) {
            int val = stoi(task);
            if (search(root, val)) {
                root = remove(root, val);
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }
        if(command == 3) {
            if(task == "NLR") NLR(root);
            if(task == "LNR") LNR(root);
            if(task == "LRN") LRN(root);
            if(task == "LevelOrder") levelOrder(root);
            cout << endl;
        }
        if(command == 4) {
            Node* check = search(root, stoi(task));
            if(!check) cout << "false\n";
            else cout << "true\n";
        }
    }
    return 0;
}