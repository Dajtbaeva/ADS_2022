2181. Merge Nodes in Between Zeros
https://leetcode.com/problems/merge-nodes-in-between-zeros/
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * cur = head -> next;
        ListNode * res = new ListNode(-1);
        ListNode * ans = res;
        bool ok = false;
        int sumi = 0;
        while(cur){
            if(cur -> val == 0){
                ListNode * node = new ListNode(sumi);
                res -> next = node;
                res = res -> next;
                sumi = 0;
            }else sumi += cur -> val;
            cur = cur -> next;
        }
        return ans -> next;
    }
};