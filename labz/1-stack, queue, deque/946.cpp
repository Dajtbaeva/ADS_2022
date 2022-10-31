946. Validate Stack Sequences
https://leetcode.com/problems/validate-stack-sequences/
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int k = 0;
        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            while(!st.empty() && k < popped.size() && st.top() == popped[k]){
                st.pop();
                k++;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};