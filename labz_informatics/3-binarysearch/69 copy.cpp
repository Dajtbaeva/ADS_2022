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
        int l = 0, r = x;
        unsigned long long mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(mid * mid == x || ((mid + 1) * (mid + 1) > x && mid * mid < x)) return mid;
            else if(mid * mid > x){
                r = mid - 1;
            }else if(mid * mid < x){
                l = mid + 1;    
            }
        }
        return -1;
    }
};