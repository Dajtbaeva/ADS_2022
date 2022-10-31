#include <bits/stdc++.h>

using namespace std;

bool pali(string t, int i){
    if(i == t.size()) return true;
    if(t[i] != t[t.size() - i - 1]) return false;
    return pali(t, i + 1);
}

int main(){
    string s;
    cin >> s;
    pali(s, 0) ? cout << "Yes" : cout << "No";
}