2089. Find Target Indices After Sorting Array
https://leetcode.com/problems/find-target-indices-after-sorting-array/
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

class Solution {
public:
    
    vector<int> v;
    
    void binarySearch(int left, int right, vector<int>& nums, int target){
        if(left > right){
            return;
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            v.push_back(mid);
        }
        if(target == nums[mid]){
            binarySearch(left, mid - 1, nums, target);
            binarySearch(mid + 1, right, nums, target);
        }
        else if(target < nums[mid]){
            binarySearch(left, mid - 1, nums, target);
        }
        else{
            binarySearch(mid + 1, right, nums, target);
        }
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        binarySearch(0, nums.size() - 1, nums, target);
        sort(v.begin(), v.end());
        return v;
    }
};


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        int firstOccu = first(nums,target);
        int lastOccu = last(nums,target);
        if(firstOccu==-1 && lastOccu==-1) return {};
        for(int i=firstOccu; i<=lastOccu;i++){
            v.push_back(i);
        }
        return v;
    }
    
    int first(vector<int>& nums, int target){
        int start=0,end=nums.size()-1,res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]){
                res=mid;
                end=mid-1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
    int last(vector<int>& nums, int target){
        int start=0,end=nums.size()-1,res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]){
                res=mid;
                start=mid+1;
            }
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return res;
    }
};


class Solution {
public:
    
    int firstOccurence(vector<int>&nums,int target){
        int start = 0, end = nums.size() - 1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
    int lastOccurence(vector<int>&nums,int target){
        int start = 0, end = nums.size() - 1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int f = firstOccurence(nums,target);
        if(f==-1) return ans;
        int l = lastOccurence(nums,target);
        for(int i = f; i<=l; i++)
            ans.push_back(i);
        return ans;
    }
};
