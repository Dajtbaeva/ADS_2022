2357. Make Array Zero by Subtracting Equal Amounts
https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq; // MIN HEAP, MIN AT THE TOP OF HEAP
        int cnt = 0, cur = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) pq.push(nums[i]);
        }
        while(!pq.empty()){
            if(pq.top() != cur){
                cnt++;
                cur = pq.top();
            }
            pq.pop();
        }
        return cnt;
    }
};