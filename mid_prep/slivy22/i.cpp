#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

string binary(ull x){
    string s = "";
    while(x > 0){
        s = char(x % 2 + 48) + s;
        x /= 2;
    }
    return s;
}

bool ans(ull x){
    string res = binary(x);
    stack<char> st;
    for(int i = 0; i < res.size(); i++){
        if(!st.empty() && st.top() == '1' && res[i] == '0') st.pop();
        else st.push(res[i]);
    }
    return st.empty();
}

int main(){
    ull n; cin >> n;
    for(int i = 0; i < n; i++){
        ull x; cin >> x;
        ans(x) ? cout << "YES" : cout << "NO";
        cout << "\n";
    }
}