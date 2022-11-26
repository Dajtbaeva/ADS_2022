167. Two Sum II - Input Array Is Sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int tar = target - numbers[i];
            int l = i + 1, r = n - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(numbers[mid] == tar){
                    ans.push_back(i + 1);
                    ans.push_back(mid + 1);
                    return ans;
                } else if(numbers[mid] < tar) l = mid + 1;
                else r = mid - 1;
            }
        }
        return ans;
    }
};
