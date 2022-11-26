436. Find Right Interval
https://leetcode.com/problems/find-right-interval/
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        int n = intervals.size();
        vector<pair<int,int>> start_indx;
        for(int i = 0; i < n; i++){
          start_indx.push_back({intervals[i][0],i});
        }
        sort(start_indx.begin(),start_indx.end());
		
        for(int i = 0; i < n; i++){
            int l = 0, r = n - 1, ans = -1;
            while(l <= r){
              int mid = l + (r - l) / 2;
              if(start_indx[mid].first >= intervals[i][1]){
                ans = start_indx[mid].second;
                r = mid - 1;
              }
              else l = mid + 1;
            }
          res.push_back(ans);
        }
      return res;
    }
};
