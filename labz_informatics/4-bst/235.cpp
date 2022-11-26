235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p -> val == root -> val || q -> val == root -> val) return root;
        if(p -> val < root -> val && q -> val > root -> val) return root;
        if(p -> val > root -> val && q -> val < root -> val) return root;
        if(p -> val < root -> val && q -> val < root -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }else return lowestCommonAncestor(root -> right, p, q);
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * lca;
        if(root -> val > min(p -> val, q -> val) && root -> val < max(p -> val, q -> val)){
            lca = root;
        }else if(root -> val > p -> val && root -> val > q -> val){
            lca = lowestCommonAncestor(root -> left, p, q);
        }else if(root -> val < p -> val && root -> val < q -> val){
            lca = lowestCommonAncestor(root -> right, p, q);
        }
        return lca;
    }
};