// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL || head -> next -> next == NULL) return head;
        ListNode* oddhead = head;
        ListNode* evenhead = head -> next;
        ListNode* oddtail = head;
        ListNode* eventail = head -> next;
        while(oddtail -> next != NULL && eventail -> next != NULL){
            oddtail -> next = oddtail -> next -> next;
            oddtail = oddtail -> next;
            eventail -> next = eventail -> next -> next;
            eventail = eventail -> next;
        }
        oddtail -> next = evenhead;
        return oddhead;
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * odd = head;
        ListNode * even = head -> next;
        ListNode * evenHead = even;
        
        while(even && even -> next){
            odd -> next = even -> next;
            odd = even -> next;
            
            even -> next = odd -> next;
            even = odd -> next;
        }
        odd -> next = evenHead;
        return head;
    }
};