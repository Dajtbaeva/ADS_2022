682. Baseball Game
https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C") s.pop();
            else if(ops[i] == "D"){
                int a = s.top();
                s.push(2 * a);
            }
            else if(ops[i] == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            }else s.push(stoi(ops[i]));
        }
        int res = 0;
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        return res;
    }
};