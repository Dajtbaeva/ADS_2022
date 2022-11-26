735. Asteroid Collision
https://leetcode.com/problems/asteroid-collision/

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int i = 0;
        while(i < asteroids.size()){
            if(st.empty()){
                st.push(asteroids[i]);
                i++;
            }
            else if(st.size() > 0){
                int cur = asteroids[i];
                if((st.top() < 0 && cur > 0) ||(st.top() > 0 && cur < 0)){
                    if(st.top() < 0 && cur > 0){
                        st.push(cur);
                        i++;
                        continue;
                    }
                    else if(abs(st.top()) > abs(cur)) i++;
                    else if(abs(st.top()) < abs(cur)) st.pop();
                    else if(abs(st.top()) == abs(cur)){
                        st.pop();
                        i++;
                    }
                }else{
                    st.push(asteroids[i]);
                    i++;
                }
                
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution(object):
    def asteroidCollision(self, asteroids):
        ans = []
        for new in asteroids:
            while ans and new < 0 < ans[-1]:
                if ans[-1] < -new:
                    ans.pop()
                    continue
                elif ans[-1] == -new:
                    ans.pop()
                break
            else:
                ans.append(new)
        return ans
