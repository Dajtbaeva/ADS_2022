#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    bool res = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else{
            if(st.empty()){
                res = false;
                break;
            }else st.pop();
        }
    }
    if(res && st.empty()) cout << "YES";
    else cout << "NO"; 
}