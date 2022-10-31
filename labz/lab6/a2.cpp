#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> v;
    for(int i = 0; i < s.size(); i++){
        if(s.substr(i, t.size()) == t) v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}