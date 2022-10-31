429. N-ary Tree Level Order Traversal
https://leetcode.com/problems/n-ary-tree-level-order-traversal/
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                temp.push_back(q.front()->val);
                
                Node* cur = q.front();
                q.pop();
                
                for(Node* child : cur->children)
                q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
