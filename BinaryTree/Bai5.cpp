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

// void levelOrder(Node* root, int x, int y, char z, int &cnt){
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()) {
//         Node* tmp = q.front(); q.pop();
//         if(tmp->pLeft != NULL) {
//             q.push(tmp->pLeft);
//             // cout << tmp->pLeft->data << " ";
//         }
//         if(tmp->pRight != NULL) {
//             q.push(tmp->pRight);
//             // cout << tmp->pRight->data << " ";
//         }
//         if(tmp->pLeft != NULL || tmp->pRight != NULL) cnt++;
//     }
// }

int count(Node *root) {
    if(root == NULL) return -1;
    return max(count(root->pLeft) + 1, count(root->pRight) + 1);
}

void solve() 
{
    // Solution here
    int n; cin >> n;
    int x,y; char z;
    cin >> x >> y >> z;
    
    int cnt = 0;

    Node* root = new Node(x);
    insertNode(root,x,y,z);
    while(n--) {
        cin >> x >> y >> z;
        insertNode(root,x,y,z);
    }
    
    cout << count(root);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
