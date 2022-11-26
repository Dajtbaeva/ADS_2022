// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * cur = head;
        while(cur != NULL){
            if((cur->next != NULL) && cur->val == cur->next->val) cur->next = cur->next->next;
        // if next element exists then we check if current and next values equal we set this element to the next element; 
            else cur= cur->next;
        }
        return head;
    }
};