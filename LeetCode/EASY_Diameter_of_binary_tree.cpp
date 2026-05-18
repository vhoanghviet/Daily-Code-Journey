#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int d = 0;

    int getHeight(TreeNode* root) {
        if(root == NULL) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        d = max(d, l+r);
        return max(l,r)+ 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        getHeight(root);
        return d;
    }
};