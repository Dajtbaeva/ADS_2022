1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. 
The answer is the yellow node from the cloned tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * ans;
    void inOrder(TreeNode* root, TreeNode* target){
        if(root == NULL) return;
        inOrder(root->left, target);
        if(root->val == target->val){
            ans = root;
            return;
        }else inOrder(root->right, target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ans = NULL;
        inOrder(cloned, target);
        return ans;
    }
};