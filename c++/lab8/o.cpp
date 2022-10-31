#include <bits/stdc++.h>

using namespace std;

int main(){
    string t;
    cin >> t;
    set<char> s;
    for(int i = 0; i < t.size(); i++){
        t[i] = tolower(t[i]);
    }
    for(int i = 0; i < t.size(); i++){
        s.insert(t[i]);
    }
    set<char> :: iterator it;
    cout << s.size() << '\n';
    for(it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }
}
