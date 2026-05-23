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
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root || (!root->left && !root->right)) return false;
        inorder(root);
        // sort(ans.begin(), ans.end()); 
        // Vì là BST nên không cần sort mảng thì inorder mảng vẫn tăng dần.
        int i = 0, j = ans.size() -1;
        while(i < j) {
            int sum = ans[i] + ans[j];
            if(sum == k) {
                return true;
                break;
            } else if(sum < k) {
                i++;
            } else { // sum > k
                j--;
            }
        }
        return false;
    }
};