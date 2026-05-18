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
    int sum_val(TreeNode* root) {
        if(!root) return 0;
        return root->val + sum_val(root->left) + sum_val(root->right);
    }
    int tiltValue(TreeNode* root) {
        if(!root) return 0;
        return abs(sum_val(root->left) - sum_val(root->right));
    }
    int sum = 0;
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        findTilt(root->left);
        sum += tiltValue(root);
        findTilt(root->right);
        return sum;
    }
};