92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii/
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* cur = head;
        int sz = 0;
        while(cur){
            sz++;
            cur = cur -> next;
        }
        cur = head;
        for(int i = 1; i <= sz; i++){
            if(i >= left && i <= right) v.push_back(cur->val);
            cur = cur -> next;
        }
        cur = head;
        int end = v.size() - 1;
        for(int i = 1; i <= right; i++){
            if(i >= left){
                cur -> val = v[end];
                end--;
            }
            cur = cur -> next;
        }
        return head;
    }
};