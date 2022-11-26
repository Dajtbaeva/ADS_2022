// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty()){
                if(s[i] == st.top()) st.pop();
                else st.push(s[i]);
            }else st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};