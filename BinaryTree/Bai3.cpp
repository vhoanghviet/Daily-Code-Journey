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
// Extra essential function here

void makeRoot(Node* root, int y, char z) {
    if(z == 'L') root->pLeft = new Node(y);
    else root->pRight = new Node(y);
}

void insertNode(Node* root, int x, int y, char z) {
    if(root == NULL ) return;

    if(root->data == x) {
        makeRoot(root,y,z);
    } else {
        insertNode(root->pLeft,x,y,z);
        insertNode(root->pRight,x,y,z);
    }
}

void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->pLeft);
    postOrder(root->pRight);
    cout << root->data << " ";
}


void solve() 
{
    // Solution here
    int n; cin >> n;
    int x,y; char z;
    cin >> x >> y >> z;
    
    Node* root = new Node(x);
    insertNode(root,x,y,z);
    while(n--) {
        cin >> x >> y >> z;
        insertNode(root,x,y,z);
    }
    postOrder(root);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
