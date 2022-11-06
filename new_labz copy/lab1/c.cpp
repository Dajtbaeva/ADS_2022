#include <bits/stdc++.h>

using namespace std;

int main(){
    int a = 2;
    stack<char> st;
    string s, t, s1 = "", t1 = "";
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#') st.pop();
        else st.push(s[i]);
    }
    while(!st.empty()){
        s1 += st.top();
        st.pop();
    }

    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#') st.pop();
        else st.push(t[i]);
    }
    while(!st.empty()){
        t1 += st.top();
        st.pop();
    }
    if(s1 == t1) cout << "Yes";
    else cout << "No";
}