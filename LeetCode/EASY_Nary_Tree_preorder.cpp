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
    vector<int> po;
    vector<int> preorder(Node* root) {
        if(!root) return po;
        po.push_back(root->val);
        for(auto it : root->children) {
            preorder(it);
        }
        return po;
    }
};