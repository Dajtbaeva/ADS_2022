1283. Find the Smallest Divisor Given a Threshold
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    // 00001111
    bool check(int mid, vector<int> &nums, int threshold){
        int sumi = 0;
        for(int i = 0; i < nums.size(); i++){
            sumi += ceil(double(nums[i]) / double(mid));
        }
        return sumi <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        while(r - l >= 1){
            int m = l + (r - l) / 2;
            if(check(m, nums, threshold)) r = m;
            else l = m + 1;
        }
        return r;
    }
};

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
