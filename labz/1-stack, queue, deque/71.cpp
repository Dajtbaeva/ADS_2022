// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res = "";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/') continue;
            string temp = "";
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.size() == 0) return "/";
        else return res;
    }
};
