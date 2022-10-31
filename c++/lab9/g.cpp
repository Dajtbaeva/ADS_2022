#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') st.push('0');
        else{
            if(!st.empty() && st.top() == '1') st.pop();
            else st.push('1');
        }
    }
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    cout << res;
}