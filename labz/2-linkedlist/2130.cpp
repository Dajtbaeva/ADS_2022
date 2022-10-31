2130. Maximum Twin Sum of a Linked List
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode * cur = head;
        while(cur){
            v.push_back(cur -> val);
            cur = cur -> next;
        }
        int n = v.size();
        int k = 0;
        vector<int> w;
        for(int i = 0; i < v.size() / 2; i++){
            int sumi = v[i] + v[n - 1 - i];
            w.push_back(sumi);
        }
        return *max_element(w.begin(), w.end());
    }
};