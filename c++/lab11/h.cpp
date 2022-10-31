#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<char> v;
    for(int i = 0; i < s.size(); i++){
                char c = int(s[i]) + n;
        if(int(c) > 90){
            c = char(int(c) - 'Z' - 1 + 'A');
        }
        v.push_back(c); 
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
}