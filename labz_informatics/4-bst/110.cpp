// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// двоичное дерево, в котором левое и правое поддеревья каждого узла отличаются по высоте не более чем на 1.

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
    int hh(TreeNode * cur){
        if(cur == NULL) return 0;
        return max(hh(cur -> right), hh(cur -> left)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(hh(root->left) - hh(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool marker = true;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight =  height(root->left);
        int rightHeight = height(root->right);
        if(abs(leftHeight-rightHeight)>1){
            marker=false;
        }
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return marker;
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