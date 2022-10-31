102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        vector<int> ans2;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop(); 
            ans2.push_back(temp -> val);
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
        return ans;
    }
}
