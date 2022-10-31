// 1700. Number of Students Unable to Eat Lunch
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(int i = 0; i < students.size(); i++) q.push(students[i]);
        int cnt = 0;
        int i = 0;
        while(!q.empty()){
            if(cnt == q.size()){
                return q.size();
            }
            int k = q.front();
            q.pop();
            if(k == sandwiches[i]){
                i++;
                cnt = 0;
            }else{
                cnt++;
                q.push(k);
            }
        }
        return cnt;

    }
};