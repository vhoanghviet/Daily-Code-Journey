#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> ans;
    void postorderInput(Node* root) {
        if(!root) return;
        for(Node* it: root->children) {
            postorderInput(it);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        postorderInput(root);
        return ans;
        
    }
};