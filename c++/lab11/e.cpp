#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    map<char, int> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        set<char> st;
        for(int i = 0; i < s.size(); i++){
            st.insert(s[i]);
        }
        set<char> :: iterator it;
        for(it = st.begin(); it != st.end(); it++){
            m[(*it)]++;
        }
    }
    bool ok = false;
    map<char, int> :: iterator itm;
    for(itm = m.begin(); itm != m.end(); itm++){
        if((*itm).second == n){
            cout << (*itm).first << " ";
            ok = true;
        }
    }
    if(!ok) cout << "NO COMMON CHARACTERS";
}