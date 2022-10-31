#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool pali = true; //abba
    for(int i = 0; i < s.size() / 2; i++){
        if(s[i] != s[s.size() - i - 1]) pali = false;
    }
    if(pali) cout << "yes";
    else cout << "no";
}