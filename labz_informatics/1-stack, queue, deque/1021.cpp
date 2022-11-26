// 1021. Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(!st.empty()) res += '(';
                st.push('(');
            }else{
                st.pop();
                if(!st.empty()) res += ')';
            }
        }
        return res;
    }
};