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

    void count_freq_val(TreeNode* root, unordered_map<int,int> &freq) {
        if(!root) return;
        freq[root->val]++;
        count_freq_val(root->left, freq);
        count_freq_val(root->right, freq);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        unordered_map<int,int> freq;
        count_freq_val(root,freq);
        int max_freq = -1;
        for(auto it : freq) {
            max_freq = max(max_freq, it.second);
        }
        for(auto it: freq) {
            if(it.second == max_freq) {
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};