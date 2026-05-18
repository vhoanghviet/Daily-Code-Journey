#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int dem = 0;

        while(!q.empty()) {
            dem++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* r = q.front(); q.pop();
                if(isLeaf(r)) return dem;
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
        }
        return dem;
    }
};