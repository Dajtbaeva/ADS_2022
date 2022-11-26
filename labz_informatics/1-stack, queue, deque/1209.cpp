1209. Remove All Adjacent Duplicates in String II
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
"yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy"
4

class Solution {
public:
string removeDuplicates(string s, int k){
    vector<pair<char,int> > st;
    for(auto &x : s){
        if(!st.empty() && st.back().first == x) ++st.back().second;
        else st.push_back({x,1});
        if(st.back().second == k) st.pop_back();
    }
    string res = "";
    for(auto &x: st) res.append(x.second,x.first); // сколько штук и куда
    return res;
}
};