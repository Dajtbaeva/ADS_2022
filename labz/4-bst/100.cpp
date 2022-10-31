100. Same Tree
https://leetcode.com/problems/same-tree/
Input: p = [1,2,3], q = [1,2,3]
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        if(p->val != q->val) return false;
        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }
};