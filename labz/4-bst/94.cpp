// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    static void inOrder(vector<int> &ans, TreeNode * root){
        if(root == NULL) return;
        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(res, root);
        return res;
    }
};

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
    vector<int> inorderTraversal(TreeNode* root) { // BFS
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode * node = root;
        while(true){
            if(node != NULL){
                s.push(node);
                node = node->left;
            }else{
                if(s.empty()) break;
                node = s.top(); s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
