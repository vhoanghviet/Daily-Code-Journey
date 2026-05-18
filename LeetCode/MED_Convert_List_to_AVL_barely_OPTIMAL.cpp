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
    Ref sortedArrayToBST(vector<int> nums, int left, int right) {
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        Ref root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};