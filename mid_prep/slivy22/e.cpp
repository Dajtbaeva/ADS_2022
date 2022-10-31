#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ull n; cin >> n;
    stack<ull> st;
    vector<ull> v;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "add"){
            ull x; cin >> x;
            v.push_back(x);
            st.push(x);
        }
        else if(s == "delete"){
            st.pop();
            v.pop_back();
        }
        else if(s == "getmax"){
            if(!st.empty()){
                ull a = *max_element(v.begin(), v.end());
                cout << a << "\n";
            }
            else cout << "error\n";
        }
        else{
            if(!st.empty()){
                cout << st.top() << "\n";
            }
            else cout << "error\n";
            
        }
    }
}