#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;


        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        int root_i = 0;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[root_i] == root_val) break;
            root_i++;
        }
        // [left_inor] , root_i , [right_inor]
        vector<int> left_inorder(inorder.begin(), inorder.begin() + root_i);
        vector<int> right_inorder(inorder.begin() + root_i + 1, inorder.end());
        // i, [left_preor] , [right_preor] 
        
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        
        // 1, [left_inor.size] , that -> [preor.end]
        vector<int> right_preorder(preorder.begin()+1+left_inorder.size(), preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};