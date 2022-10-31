// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int k = 0;
        for(char c : s){
            if(c == '(') k++;
            if(c == ')') k--;
            res = max(res, k);
        }
        return res;
    }
};