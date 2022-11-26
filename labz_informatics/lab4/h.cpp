// Задача №764. Сбалансированность
// https://informatics.msk.ru/mod/statements/view.php?id=54818&chapterid=764#1

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