938. Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

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
    void ascOrder(TreeNode * cur, vector<int> &w){
            if(cur == nullptr) return;
            ascOrder(cur -> left, w);
            w.push_back(cur -> val); // if()
            ascOrder(cur -> right, w);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> v;
        int sumi = 0;
        ascOrder(root, v);
        for(int i = 0; i < v.size(); i++){
            if(low <= v[i] && v[i] <= high) sumi += v[i];   
        }
        return sumi;  
    }
    
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int ans = 0;
        if(low <= root->val && root->val <= high) ans += root->val;
        return ans + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};