1721. Swapping Nodes in a Linked List
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * left = head, * right = head, * curr = head;
        int i = 1;
        while(curr != NULL){
            if(i < k) left = left -> next;
            if(i > k) right = right -> next;
            curr = curr -> next;
            i++;
        }
        swap(left -> val, right -> val);
        return head;

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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode * cur = head;
        while(cur){
            v.push_back(cur -> val);
            cur = cur -> next;
        }
        int n = v.size();
        swap(v[k - 1], v[n - k]);

        ListNode * ans = new ListNode(0);
        ListNode * res = ans;
        for(int i = 0; i < v.size(); i++){
            ans -> next = new ListNode(v[i]);
            ans = ans -> next;
        }
        return res -> next;
    }
};