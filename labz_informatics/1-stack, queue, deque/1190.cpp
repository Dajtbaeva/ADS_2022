1190. Reverse Substrings Between Each Pair of Parentheses
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1


class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>reverse;
        string sub="";
        string result="";
        for(char ch:s)
        {
            if(reverse.empty()&&ch!='(')
                result+=ch;
            else{
            if(ch!=')')
                reverse.push(ch);
            else{
                
         sub="";
                while(reverse.top()!='(')
                {
                    
                sub+=reverse.top();
                    reverse.pop();
                
                }
                
                reverse.pop();
                
                if(!reverse.empty())
                {
                    int i=0;
                    while(i<sub.size())
                    {
                        reverse.push(sub[i]);
                        i+=1;
                    }
                }else
                   result+=sub;
            }}
        }
        return result;
    }
};
