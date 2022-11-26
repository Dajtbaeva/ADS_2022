700. Search in a Binary Search Tree
https://leetcode.com/problems/search-in-a-binary-search-tree/
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

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
    TreeNode* searchBST(TreeNode* root, int x) {
        if(root == NULL) return NULL;
        if(root -> val == x) return root;
        if(root -> val > x) return searchBST(root->left,x);
        else return searchBST(root->right,x);
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
class Solution { // BFS
public:
    TreeNode* searchBST(TreeNode* root, int x) {
        if(root == NULL) return NULL;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode * node = q.front(); q.pop();
                if(node->val == x) return node;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return NULL;
    }
    
};