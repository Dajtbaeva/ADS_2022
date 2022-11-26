// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Input: nums = [1,3,5,6], target = 5
// Output: 2


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
           if(nums[i] < target) ans = i + 1;
    }
        return ans;
    }
}; 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};