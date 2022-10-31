#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(97 <= char(s[i]) && char(s[i]) <= 122) s[i] -= 32;
        cout << s[i];
    }
}