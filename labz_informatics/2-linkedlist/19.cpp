19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int sz = 0;
        ListNode * cur = head;
        while(cur){
            cur = cur -> next;
            sz++;
        }
        if(sz == 1 && n == 1){
            ListNode * temp = NULL;
            return temp;
        }   
        cur = head;
        int a = sz - n;
        for(int i = 1; i <= sz; i++){
            if(sz - n == 0){
                head = head -> next;
                break;
            }
            if(i == a){
                cur -> next = cur -> next -> next;
                break;
            } 
            cur = cur -> next;
        }
        return head;
    }
};