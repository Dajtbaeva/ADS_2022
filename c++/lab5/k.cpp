#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o') res ++;
    }
    cout << res;
}