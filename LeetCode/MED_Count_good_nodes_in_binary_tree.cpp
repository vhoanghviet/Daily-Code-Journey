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
    int dem = 1;
    void demGoodNode(TreeNode* root, int max) {
        if(root == NULL) return;
        if(root->val >= max) {
            dem++;
            max = root->val;
        }
        demGoodNode(root->left, max);
        demGoodNode(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        demGoodNode(root->left, root->val);
        demGoodNode(root->right, root->val);
        return dem;
    }
};