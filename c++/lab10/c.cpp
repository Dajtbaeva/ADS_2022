#include <bits/stdc++.h>

using namespace std;

bool check(char s, char t){
    int k = (s - 48) * 10 + (t - 48);
    int x = sqrt(k);
    return x * x == k;
}

int main(){
    string s;
    stack<char> st;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
            if(!st.empty()){
                if(check(st.top(), s[i])) st.pop();
                else st.push(s[i]);
            }else st.push(s[i]);
    }
    if(st.empty()) cout << "Stack is empty";
    else{
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }
}