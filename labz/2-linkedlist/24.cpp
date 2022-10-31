24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/
Input: head = [1,2,3,4]
Output: [2,1,4,3]

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode * temp = head;
        while(temp && temp -> next){
            swap(temp->val, temp->next->val);
            temp = temp -> next -> next;
        }
        return head;
    }
};