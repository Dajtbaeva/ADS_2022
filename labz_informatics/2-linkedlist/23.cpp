// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> res;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i] != NULL){
                res.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(res.begin(), res.end());
        ListNode * ans = new ListNode(0);
        ListNode * temp = ans;
        for(int i = 0; i < res.size(); i++){
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        return ans->next;
    }
};