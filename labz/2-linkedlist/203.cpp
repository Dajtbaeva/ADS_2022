203. Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

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
    ListNode* removeElements(ListNode* head, int val){
        while(head && head -> val == val){
            head = head -> next;
        }
        if(head == NULL) return NULL;
        ListNode * prev;
        ListNode * cur = head;
        while(cur){
            if(cur -> val == val){
                prev -> next = cur -> next;
                cur = prev -> next;
            }else{
                prev = cur;
                cur = cur -> next;
            }
        }
        return head;
    }
};