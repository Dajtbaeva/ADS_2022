#include <bits/stdc++.h>

using namespace std;

int res = 0;
int sumi(string t, int i){
    if(i == t.size()) return res;
    res += (t[i] - 48);
    return sumi(t, i + 1);
}

int main(){
    string s;
    cin >> s;
    cout << sumi(s, 0);
}