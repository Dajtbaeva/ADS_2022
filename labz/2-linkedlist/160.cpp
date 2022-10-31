// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while(l1 != l2){
            l1 ? l1 = l1->next : l1 = headB;
            l2 ? l2 = l2->next : l2 = headA;
        }
        return l1;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currentA = headA;
        int nA = 0;        
        while(currentA){
            nA++;
            currentA = currentA->next; 
        }
        ListNode* currentB = headB;
        int nB = 0;        
        while(currentB){
            nB++;
            currentB = currentB->next; 
        }
        int extra_nodes;
        
        if(nA > nB) extra_nodes = nA-nB;
        else extra_nodes = nB-nA;
        
        if(nA > nB){
            for(int i = 0; i < extra_nodes; i++)
                headA = headA->next;
        }else{
            for(int i=0; i<extra_nodes; i++)
                headB = headB->next;
        }
        
        while(headA!=headB and headA!=NULL){
            headA = headA->next;
            headB = headB->next;
        }
        if(headA == headB) return headA;
        return NULL;        
    }
};

