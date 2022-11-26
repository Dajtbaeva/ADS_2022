111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Input: root = [3,9,20,null,null,15,7]
Output: 2

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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        else if(root->left == NULL) return minDepth(root->right) + 1;
        else if(root->right == NULL) return minDepth(root->left) + 1;

        int left = minDepth(root->left) + 1;
        int right = minDepth(root->right) + 1;
        return min(left,right);    
    }
};