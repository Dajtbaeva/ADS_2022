1351. Count Negative Numbers in a Sorted Matrix
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0, n = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            int l = 0;
            int r = grid[i].size() - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(grid[i][mid] < 0) r = mid - 1;
                else l = mid + 1;
            }
            cnt += n - l;
        } 
        return cnt;
    }
};
