1161. Maximum Level Sum of a Binary Tree
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    void dfs(TreeNode * node, int lvl, vector<int> & sums){
        if(!node) return;
        if(lvl >= sums.size()){
            sums.push_back(0);
        }
        sums[lvl] += node -> val;
        dfs(node -> left, lvl + 1, sums);
        dfs(node -> right, lvl + 1, sums);
        
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        int maxSum = INT_MIN, index = -1;
        dfs(root, 0, sums);
        for(int i = 0; i < sums.size(); i++){
            if(maxSum < sums[i]){
                maxSum = sums[i];
                index = i + 1;
            } 
        }
        return index;
    }
};