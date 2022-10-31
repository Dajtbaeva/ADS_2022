// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

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
    // TreeNode* ans = new TreeNode(roo1->val + root2->val);
    // ans -> left = mergeTrees(root1->left, root2->left);
    // ans -> right = mergeTrees(root1->right, root2->right);
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        else if(root2 == NULL) return root1;
        else if(root1 == NULL && root2 == NULL) return NULL;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
// BFS
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
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        else if(root2 == NULL) return root1;
        else if(root1 == NULL && root2 == NULL) return NULL;
        queue<pair<TreeNode*, TreeNode*> > q;
        q.push({root1, root2});
        while(!q.empty()){
            pair<TreeNode*, TreeNode*> p = q.front(); q.pop();
            p.first->val += p.second->val;
            
            if(p.first->left && p.second->left)
                q.push({p.first->left, p.second->left});
            else if(p.second->left) p.first->left = p.second->left;
            
            if(p.first->right && p.second->right)
                q.push({p.first->right, p.second->right});
            else if(p.second->right) p.first->right = p.second->right;
        }
        return root1;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return 0;
        
        if(!root1)
            return root2;
        
        if(!root2)
            return root1;
       
        root1->val=root1->val+root2->val;
        
        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};
