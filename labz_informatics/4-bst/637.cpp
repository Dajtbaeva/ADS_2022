637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

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
    vector<double> averageOfLevels(TreeNode* root) { // BFS
        if(root == NULL) return {};
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sumi = 0;
            for(int i = 0; i < n; i++){
                TreeNode * node = q.front(); q.pop();
                sumi += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            ans.push_back(sumi / n);
        }
        return ans;
    }
};  

class Solution { // DFS
public:
    void doDFS(TreeNode* root,vector<double> &sum,vector<double> &count,int i){        
        if(root == NULL) return;
        if(sum.size() <= i){
            sum.push_back(root->val);
            count.push_back(1);
        }else{
            sum[i] += root->val;
            count[i]++;
        }
        doDFS(root->left, sum, count, i + 1);
        doDFS(root->right, sum, count, i + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum, count, ans;
        doDFS(root, sum, count, 0);
        for(int i = 0; i < sum.size(); i++) ans.push_back(sum[i] / count[i]);
        return ans;
    }
};
