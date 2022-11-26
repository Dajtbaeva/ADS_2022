506. Relative Ranks
https://leetcode.com/problems/relative-ranks/
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push(score[i]);
        }
        vector<string> ans;
        map<int, string> m;
        int i = 1;
        while(!pq.empty()){
            if(i == 1) m[pq.top()] = "Gold Medal";
            else if(i == 2) m[pq.top()] = "Silver Medal";
            else if(i == 3) m[pq.top()] = "Bronze Medal";
            else m[pq.top()] = to_string(i);
            i++;
            pq.pop();
        }
        for(int i = 0; i < score.size(); i++){
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
};