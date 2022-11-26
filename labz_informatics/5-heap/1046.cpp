1046. Last Stone Weight
https://leetcode.com/problems/last-stone-weight/
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.'

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.size() == 1) return stones[0];
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(x != y) pq.push(y - x);
            if(pq.size() == 1) return pq.top();
        } return 0;
    }
};