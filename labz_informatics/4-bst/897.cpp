897. Increasing Order Search Tree
https://leetcode.com/problems/increasing-order-search-tree/
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// DFS
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
    TreeNode * first = new TreeNode(-999);
    TreeNode * temp = first;
    
    void ascOrder(TreeNode * cur){
        if(cur != nullptr){
            ascOrder(cur -> left);
            first -> right = new TreeNode(cur -> val);
            // first -> left = nullptr;
            first = first -> right;
            ascOrder(cur -> right);
        }else return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        ascOrder(root);
        return temp -> right;
    }
};

class Solution { // BFS
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto node = q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        sort(v.begin(),v.end());
        TreeNode *ans = new TreeNode(-1);
        TreeNode* temp = ans;
        for(int i=0;i < v.size(); i++){
            temp->right = new TreeNode(v[i]);
            temp=temp->right;
        }
        return ans->right;
    }
};
