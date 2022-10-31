1290. Convert Binary Number in a Linked List to Integer
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
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
    int getDecimalValue(ListNode* head) {
        if(head == 0) return 0;
        int res = 0;
        int l = 0;
        ListNode * cur = head;
        while(cur != NULL){
            l++;
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL){
            res += (pow(2, l - 1) * (cur->val));
            l--;
            cur = cur->next;
        }
        return res;
    }
};

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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while( head != NULL ){
            res = res * 2 + head -> val;
            head = head -> next;
        } return res;
   
    }
};