#include <bits/stdc++.h>
using namespace std;


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
    int maxDepth(Node* root) {
        if(!root) return 0;
        if(root->children.size() == 0) return 1;
        int ans = 0;
        for(Node* it : root->children) {
            ans = max(ans, maxDepth(it));
        }
        return ans + 1;
    }
};