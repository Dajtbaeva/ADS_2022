108. Convert Sorted Array to Binary Search Tree
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

The above tree is AVL because differences between heights of left and right subtrees for every node is less than or equal to 1.
The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree 
https://www.youtube.com/watch?v=0K0uCMYq5ng&ab_channel=NeetCode

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode * helper(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode * root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m - 1);
        root->right = helper(nums, m + 1, r);
        return root;
    }
};

class Solution { // DFS
public:
    
    int recur(TreeNode* root,bool &ans)
    {
        if(root == NULL || ans == false)
        {
            return 0;
        }
        int leftN = recur(root->left,ans);
        int rightN = recur(root->right,ans);
        if(abs(leftN - rightN) > 1)
        {
            ans = false;
        }
        return 1 + max(leftN,rightN);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int x = recur(root,ans);
        return ans;
    }
};
