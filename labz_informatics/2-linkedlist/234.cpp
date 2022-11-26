// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
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
STACK 
class Solution {
public:
    ListNode * middle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n = NULL;
        
        while(c != NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode * mid = middle(head);
        ListNode * second_head = reverse(mid);
        
        bool res = true;
        while(second_head){
            if(head -> val != second_head -> val){
                return false;
            }
            head = head -> next;
            second_head = second_head -> next;
        }
        return res;
    }
};

class Solution {
public:
    ListNode* temp;
    
    bool check(ListNode* head) {
        if (NULL == head) return true;
        bool res = check(head->next) & (temp->val == head->val);
        temp = temp->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
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
    ListNode * reversed(ListNode* root){
        vector<int> rave;
        ListNode * cur = root;
        while(cur != nullptr){
            rave.push_back(cur -> val);
            cur = cur -> next;
        }
        cur = root;
        int i = rave.size() - 1;
        while(cur != nullptr){
            cur -> val = rave[i];
            cur = cur -> next;
            i--;
        }
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode * temp = reversed(head);
        bool ok = true;
        while(temp != NULL && head != NULL){
            if(head->val != temp->val){
                return false;
            }
            temp = temp->next;
            head = head->next;
        }
        return true;
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int r = v.size() - 1;
        while(l < r){
            if(v[l] != v[r])return false;
            l++;
            r--;
        }
        return true;
    }
};