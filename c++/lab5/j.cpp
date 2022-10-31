#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    string t = s + s[0];
    string k = t;
    reverse(k.begin(), k.end());
    if(t == k) cout << "YES";
    else cout << "NO";
}