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
    void dfs(TreeNode* root, string root_to_leaf_path, vector<string> &AllPaths) {
        if(!root) return;
        root_to_leaf_path += to_string(root->val);
        if(!root->left && !root->right) { // leaf
            AllPaths.push_back(root_to_leaf_path);
        }
        // not leaf
        if(root->left) dfs(root->left, root_to_leaf_path + "->", AllPaths);
        if(root->right) dfs(root->right, root_to_leaf_path + "->", AllPaths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allpath;
        if(!root) return allpath;
        string path;
        dfs(root, path, allpath);
        return allpath;
    }
};