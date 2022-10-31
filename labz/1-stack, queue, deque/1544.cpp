// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()) st.push(s[i]);
            else if(tolower(s[i])==tolower(st.top()) && (isupper(s[i]) && islower(st.top()) || islower(s[i]) && isupper(st.top()))) st.pop();
            else st.push(s[i]);
        }   
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};