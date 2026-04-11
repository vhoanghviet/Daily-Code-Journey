#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int X)
{
    Node *newNode = new Node;
    newNode->key = X;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void addNode(Node *&root, int x)
{
    if (root == NULL)
    {
        root = createNode(x);
        return;
    }
    if (root->key == x)
        return;
    if (x < root->key)
        addNode(root->left, x);
    else
        addNode(root->right, x);
}

Node *search(Node *root, int x)
{
    Node *found = root;
    while (found != NULL)
    {
        if (found->key == x)
            return found;
        if (x < found->key)
            found = found->left;
        else
            found = found->right;
    }
    return NULL;
}
// Duyệt trước
void NodeLeftRight(Node *&root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    NodeLeftRight(root->left);
    NodeLeftRight(root->right);
}
void LeftNodeRight(Node *&root)
{
    if (root == NULL)
        return;
    LeftNodeRight(root->left);
    cout << root->key << " ";
    LeftNodeRight(root->right);
}
void printA(vector<int> a)
{
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

void replaceNodeY(Node *&X, Node *&Y)
{
    if (Y->left != NULL)
    {
        replaceNodeY(X, Y->left);
    }
    else
    {
        X->key = Y->key;
        Node *temp = Y;
        Y = Y->right;
        delete temp;
    }
}
void deleteNode(Node *&root, int x)
{
    if (root == NULL)
        return;

    if (x < root->key)
    {
        deleteNode(root->left, x);
    }
    else
    {
        if (root->key < x)
        {
            deleteNode(root->right, x);
        }
        else
        {
            // Tìm được vị trí cần xóa root
            Node *toDelete = root;

            if (root->left == NULL)
            {
                root = root->right;
                delete toDelete;
            }
            else if (root->right == NULL)
            {
                root = root->left;
                delete toDelete;
            }
            else
            {
                replaceNodeY(root, root->right);
            }
        }
    }
}

// Khi duyệt giữa BST -> cây sẽ in ra giá trị tăng dần

int main()
{
    srand(time(NULL));
    Node *root = NULL;
    vector<int> a(20);
    for (int i = 0; i < 20; i++)
    {
        a[i] = rand() % 1000;
        addNode(root, a[i]);
    }
    cout << "Mang ban dau : ";
    printA(a);
    int x;
    cin >> x;
    if (search(root, x))
    {
        cout << x << " ton tai!\n";
        cout << "TH1: Neu " << x << " khong bi xoa khoi cay.\n";
        LeftNodeRight(root);
        cout << endl;

        cout << "TH2: Neu " << x << " bi xoa khoi cay.\n";
        deleteNode(root, x);
        LeftNodeRight(root);
        cout << endl;
    }
    else
    {
        cout << x << " khong ton tai trong cay!\n";
    }
    cout << endl;

    return 0;
}