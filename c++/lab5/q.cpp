#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    string res = "";
    for(int i = 0; i < t.size(); i += s.size()){
        res += s;
    }
    if(res == t) cout << "YES";
    else cout << "NO";
}