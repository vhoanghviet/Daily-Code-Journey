#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// Extra essential function here
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
    // Nên viêt hàm constructor
    Node(int X)
    {
        data = X;
        pLeft = pRight = NULL;
    }
};

void makeRoot(Node *root, int y, char z)
{
    if (z == 'L')
        root->pLeft = new Node(y);
    else
        root->pRight = new Node(y);
}
void insertNode(Node *root, int x, int y, char z)
{
    if (root == NULL)
        return;
    if (root->data == x)
    {
        makeRoot(root, y, z);
    }
    else
    {
        insertNode(root->pLeft, x, y, z);
        insertNode(root->pRight, x, y, z);
    }
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->pLeft);
    cout << root->data << " ";
    inOrder(root->pRight);
}

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
    inOrder(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
