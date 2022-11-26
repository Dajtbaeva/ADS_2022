// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    string solve(string s){
    string temp="";
    for(auto c:s){
        if(c=='#' and temp.size() > 0) temp.pop_back();
        else if(c!='#'){
            temp+=c;
        }
    }
    return temp;
    }
    bool backspaceCompare(string s, string t) {
        if (solve(s)==solve(t))return true;
        return false;
    }
};