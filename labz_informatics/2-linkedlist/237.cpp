237. Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

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
    void deleteNode(ListNode* node) {
        ListNode * temp = node -> next;
        node -> val = temp -> val;
        node -> next = temp -> next;
        delete temp;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
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
    void deleteNode(ListNode* node) {
        ListNode * prev;
        while(node -> next){
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
        delete node;
    }
};