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
        isValidBST(root->left);
        a.push_back(root->val);
        isValidBST(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrderTravBST(root);
        for(int i = 1; i < a.size() ; i++) {
            if(a[i] <= a[i-1]) {
                return false;
            }
        }
        return true;
    }
    // bool isValidBST(TreeNode* root) {
    //     if(root == NULL) return true;
    //     if(root->left != NULL) {
    //         if(root->left->val >= root->val) {
    //             return false;
    //         }
    //     }
    //     if(root->right != NULL) {
    //         if(root->right->val <= root->val) {
    //             return false;
    //         }
    //     }
    //     return isValidBST(root->left) && isValidBST(root->right);
    // }
};