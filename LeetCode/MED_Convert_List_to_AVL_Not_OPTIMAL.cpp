#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    typedef TreeNode* Ref;
    int getHeight(Ref r) {
        if(r == NULL) return 0;
        return 1 + max(getHeight(r->left),getHeight(r->right));
    }
    int getBalanceFactor(Ref r) {
        if(r == NULL) return 0;
        return getHeight(r->left) - getHeight(r->right); 
    }
    void rotate_R(Ref &r) {
        Ref temp = r->left;
        r->left = temp->right;
        temp->right = r;
        r = temp;
    }
    void rotate_L(Ref &r) {
        Ref temp = r->right;
        r->right = temp->left;
        temp->left = r;
        r = temp;
    }
    void balanceTree(Ref & r) {
        if(r == NULL) return;
        int balance = getBalanceFactor(r);

        if(balance > 1) {
            if(getBalanceFactor(r->left) > 0) {
                rotate_R(r); // LL
            } else { // LR
                rotate_L(r->left);
                rotate_R(r);
            }
        } else if(balance < -1) {
            if(getBalanceFactor(r->right) < 0) {
                rotate_L(r); // RR
            } else { // RL
                rotate_R(r->right);
                rotate_L(r);
            }
        }
    }
    void insertBST(Ref &r,int val) {
        if(r == NULL) {
            r = new TreeNode(val);
            return;
        }
        if(r->val < val) insertBST(r->right,val);
        else insertBST(r->left,val);
        balanceTree(r);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        Ref ans = NULL;
        while(head != NULL) {
            insertBST(ans, head->val);
            head = head->next;
        }
        return ans;
    }
};