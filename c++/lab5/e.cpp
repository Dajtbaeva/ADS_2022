#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sumi1 = 0;
    int sumi2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0) sumi1 += int(s[i]); //stoi
        else sumi2 += int(s[i]);
    }
    if(sumi1 == sumi2) cout << "YES";
    else cout << "NO";
}