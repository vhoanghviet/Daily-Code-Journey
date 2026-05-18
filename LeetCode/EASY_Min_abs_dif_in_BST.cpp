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
    int min_dif = 1e9;
    vector<int> value;
    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        value.push_back(root->val);
        inOrder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        sort(value.begin(), value.end());
        for(int i = 1; i < value.size(); i++) {
            min_dif = min(min_dif, abs(value[i] - value[i-1]));
        }
        return min_dif;
    }
};