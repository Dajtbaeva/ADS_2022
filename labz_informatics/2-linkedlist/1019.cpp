// 1019. Next Greater Node In Linked List
// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * cur = head;
        ListNode * temp = head;
        vector<int> res;
        while(cur){
            temp = cur -> next;
            while(temp){
                if(temp -> val > cur -> val){
                    res.push_back(temp -> val);
                    break;
                }
                temp = temp -> next;
                if(!temp) res.push_back(0);
            }
            cur = cur -> next;
        }
        res.push_back(0);
        return res;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        
        stack<pair<int,int>> s;
        ListNode* fast = head;
        
        int n = 0;
        while(fast)
        {
            n++;
            fast = fast->next;
        }
        
        vector<int> ans(n,0);
        fast = head;
        // s.push({0,head->val});
        int index = 0;
        while(fast)
        {
            
            while(!s.empty() && s.top().second < fast->val)
            {
                ans[s.top().first] = fast->val;
                s.pop();
            }
            s.push({index,fast->val});
            fast = fast->next ;
            index++;
            
        }
        return ans;
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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * cur = head;
        ListNode * temp = head;
        vector<int> res;
        stack<int> st;
        while(cur){
            st.push(cur -> val);
            temp = cur -> next;
            while(temp){
                if(temp -> val > st.top()){
                    st.push(temp -> val);
                    break;
                } 
                temp = temp -> next;
            }
            if(st.size() == 1) res.push_back(0);
            else{
                res.push_back(st.top());
                st.pop();
            } 
            st.pop();
            cur = cur -> next;
        }
        // res.push_back(0);
        return res;
    }
};