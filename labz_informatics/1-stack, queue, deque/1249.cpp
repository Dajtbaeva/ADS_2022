1249. Minimum Remove to Make Valid Parentheses
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int sz = s.size();
        stack<int> st;
        vector<int> v;
        for(int i=0; i<sz; ++i){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')') if(!st.empty()) st.pop();
            else v.push_back(i);
        }
        while(!st.empty()){
            s.erase(st.top(), 1);
            st.pop();
        }
        vector<int>::reverse_iterator b;
        for( b=v.rbegin(); b!=v.rend(); ++b) s.erase(*b, 1);
        return s;
   
    }
};