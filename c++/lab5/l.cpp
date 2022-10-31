#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    for(int i = 0; i < s.size(); i++){
        t += char(i + 97);
    }
    if(s == t) cout << "YES";
    else cout << "NO";
}