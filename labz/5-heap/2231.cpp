2231. Largest Number After Digit Swaps by Parity
https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/   
Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        stack<char> s;
        string res = "";
        while(num > 0){
            int d = num % 10;
            if(d % 2 == 0){
                s.push('e');
                even.push(d);
            }else{
                s.push('o');
                odd.push(d);
            }
            num /= 10;
        }
        while(!s.empty()){
            if(s.top() == 'e'){
                res += to_string(even.top());
                even.pop();
            }else{
                res += to_string(odd.top());
                odd.pop();
            }
            s.pop();
        }
        return stoi(res);
    }
};