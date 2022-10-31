2331. Evaluate Boolean Binary Tree
https://leetcode.com/problems/evaluate-boolean-binary-tree/
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val==0||root->val==1)return root->val;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val==2)return (left|right);
        return left&right;
    }
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return root->val == 3 ? left && right : left || right;
    }
};
