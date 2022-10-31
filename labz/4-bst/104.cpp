104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
class Solution { // DFS
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

class Solution { // BFS
public:
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            } cnt++;
        }
        return cnt;
    }
};