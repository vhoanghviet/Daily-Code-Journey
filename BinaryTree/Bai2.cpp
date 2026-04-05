#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
    Node(int X)
    {
        data = X;
        pLeft = pRight = NULL;
    }
};

void makeRoot(Node *root, int v, char c)
{
    if (c == 'L')
        root->pLeft = new Node(v);
    else
        root->pRight = new Node(v);
}

void insertNode(Node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeRoot(root, v, c);
    }
    else
    {
        insertNode(root->pLeft, u, v, c);
        insertNode(root->pRight, u, v, c);
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->pLeft);
    preOrder(root->pRight);
}

// Extra essential function here

void solve()
{
    // Solution here
    int n;
    cin >> n;
    int x, y;
    char z;

    cin >> x >> y >> z;
    Node *root = new Node(x);
    insertNode(root, x, y, z);

    while (n--)
    {
        cin >> x >> y >> z;
        insertNode(root, x, y, z);
    }
    preOrder(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
