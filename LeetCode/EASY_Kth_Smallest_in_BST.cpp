#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> a;
    void inOrderTravBST(TreeNode* root) {
        if(root == NULL) return;
        inOrderTravBST(root->left);
        a.push_back(root->val);
        inOrderTravBST(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTravBST(root);
        return a[k-1];
    }
};