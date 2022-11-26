// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

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
    TreeNode* invertTree(TreeNode* root) { // DFS
        if(root == NULL) return NULL;
        TreeNode * node = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(node);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // BFS
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* node = q.front(); q.pop();
                swap(node->left, node->right);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};