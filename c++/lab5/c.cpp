#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        if(s.substr(i, t.size()) == t){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}