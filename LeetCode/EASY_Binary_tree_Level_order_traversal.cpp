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
    typedef vector<vector<int>> vii;
    typedef vector<int> vi;
    vii ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vi temp;
            int size = q.size();
            for(int i = 0; i < size ; i++) {
                TreeNode* current = q.front(); 
                q.pop();
                temp.push_back(current->val);
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};