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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        if(root == NULL) return NULL;
        TreeNode* explore_left = lowestCommonAncestor(root->left,p,q);
        TreeNode* explore_right = lowestCommonAncestor(root->right,p,q);
        if(explore_left == NULL) {
            root = explore_right;
        } else if(explore_right == NULL) {
            root = explore_left;
        }
        return root;
    }
};