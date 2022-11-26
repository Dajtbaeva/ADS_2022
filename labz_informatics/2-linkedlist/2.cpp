2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode(0);
        ListNode * cur = ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sumi = carry + a + b;
            carry = sumi / 10;
            cur -> next = new ListNode(sumi % 10);
            cur = cur -> next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }             
        return ans->next;
    }
};