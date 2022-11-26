2236. Root Equals Sum of Children
https://leetcode.com/problems/root-equals-sum-of-children/
Input: root = [10,4,6]
Output: true

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
    bool checkTree(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->val == root->left->val + root->right->val) return true;
        else return false;
    }
};