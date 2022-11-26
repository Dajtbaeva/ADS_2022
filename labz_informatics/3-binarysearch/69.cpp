// 69. Sqrt(x)
// Given a non-negative integer x, compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
        int ans = sqrt(x);
        return trunc(ans);
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int res = -1;
        while(l <= r){
            long long int mid = l + (r - l) / 2;
            long long int sq = mid * mid;
            if(sq == x) return mid;
            if(sq < x){
                res = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        return res;
    }
};