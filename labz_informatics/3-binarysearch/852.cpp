852. Peak Index in a Mountain Array
https://leetcode.com/problems/peak-index-in-a-mountain-array/
Input: arr = [0,10,5,2]
Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(arr[mid] < arr[mid + 1]) l = mid + 1; // двигаемся вправо
            else r = mid; // берем левую часть
        }
        return l;
    }
};