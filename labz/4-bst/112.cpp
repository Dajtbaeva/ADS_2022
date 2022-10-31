112. Path Sum
https://leetcode.com/problems/path-sum/
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum -= root -> val;
        if(targetSum == 0 && !root -> right && !root -> left) return true;
        return hasPathSum(root -> right, targetSum) || hasPathSum(root -> left, targetSum);
    }
};



class Solution {
public:
    bool solve(TreeNode* root,int sum){
        if(!root) return false;
        if( sum==root->val && !root->left && !root->right) return true;
        return solve(root->left,sum-root->val)||solve(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};



class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        targetSum -= root->val;
        // check if the path sum is equal to target or not
        if(!root->left && !root->right) 
            return targetSum == 0;    
        
        return hasPathSum(root->left, targetSum) ||
            hasPathSum(root->right, targetSum);
    }
};
