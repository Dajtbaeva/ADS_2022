#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<string> s;
    string t;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(s.find(t) == s.end()){
            s.insert(t);
            cout << "new user added\n";
        }else cout << "user already exists\n";

    }
}