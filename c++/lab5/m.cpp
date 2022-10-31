#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    char c;
    int n;
    cin >> s >> c >> n;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c) res++;
    }
    if(res == n) cout << "YES";
    else cout << "NO";
}