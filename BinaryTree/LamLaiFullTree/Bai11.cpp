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




int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<int> inorder, preorder;
    
    for(int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        preorder.push_back(x);
    }
    for(int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        inorder.push_back(x);
    }

    


    return 0;
}